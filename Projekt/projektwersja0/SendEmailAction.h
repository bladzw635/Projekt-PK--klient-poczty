#pragma once
#include "EmailAction.h"
#include <Poco/Net/MailMessage.h>
#include <Poco/Net/MailRecipient.h>
#include <Poco/Net/SMTPClientSession.h>
#include <Poco/Exception.h>
#include <iostream>
#include <string>
#include <vector>

class SendEmailAction : public EmailAction {
public:
    void execute() override {
        std::string smtpServer = "smtp.wp.pl"; 
        std::string sender = "klient_poczty_53@wp.pl";
        std::string password = "9RX9S8XCSF6ejVb";
        std::string recipient, subject;
        std::vector<std::string> messageLines;

        std::cout << "\n--- Wysylanie nowej wiadomosci ---\n";
        std::cout << "Podaj adres odbiorcy: ";
        std::getline(std::cin >> std::ws, recipient);

        std::cout << "Podaj temat: ";
        std::getline(std::cin, subject);

        std::cout << "Wpisz tresc wiadomosci (w nowej linii wpisz 'KONIEC', aby zakonczyc i wyslac):\n";

        std::string line;
        while (std::getline(std::cin, line)) {
            if (line == "KONIEC") {
                break;
            }
            messageLines.push_back(line);
        }

        // Sklejanie zawartoœci wektora w jeden ci¹g dla MailMessage
        std::string fullContent = "";
        for (const auto& l : messageLines) {
            fullContent += l + "\r\n";
        }


        try {
            std::cout << "Tworze wiadomosc..." << std::endl;
            Poco::Net::MailMessage message;
            message.setSender(sender);
            message.addRecipient(Poco::Net::MailRecipient(Poco::Net::MailRecipient::PRIMARY_RECIPIENT, recipient));
            message.setSubject(subject);
            message.setContent(fullContent);

            std::cout << "Lacze z serwerem SMTP: " << smtpServer << "..." << std::endl;
            Poco::Net::SMTPClientSession session(smtpServer, 587);

            // Logowanie do serwera poczty
            session.login(Poco::Net::SMTPClientSession::AUTH_LOGIN, sender, password);

            std::cout << "Wysylam wiadomosc..." << std::endl;
            session.sendMessage(message);

            std::cout << "Wiadomosc wyslana pomyslnie!\n" << std::endl;
            session.close();

        }
        catch (Poco::Exception& exc) {
            std::cerr << "Blad podczas wysylania maila: " << exc.displayText() << std::endl;
        }
    }
};