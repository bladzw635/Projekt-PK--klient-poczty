#pragma once
#include "EmailAction.h"
#include <Poco/Net/MailMessage.h>
#include <Poco/Net/MailRecipient.h>
#include <Poco/Net/SMTPClientSession.h>
#include <Poco/Exception.h>
#include <iostream>
#include <string>

class SendEmailAction : public EmailAction {
public:
    void execute() override {
        //pozniej bede zmieniac tresc maila
        std::string smtpServer = "smtp.wp.pl"; 
        std::string sender = "klient_poczty_53@wp.pl";
        std::string password = "9RX9S8XCSF6ejVb";
        std::string recipient = "bd320603@student.polsl.pl";
        std::string subject = "Temat Maila";
        std::string content = "Wiadomosc testowa- ulegnie samozniszczeniu za 10 sekund";

        try {
            std::cout << "Tworze wiadomosc..." << std::endl;
            Poco::Net::MailMessage message;
            message.setSender(sender);
            message.addRecipient(Poco::Net::MailRecipient(Poco::Net::MailRecipient::PRIMARY_RECIPIENT, recipient));
            message.setSubject(subject);
            message.setContent(content);

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