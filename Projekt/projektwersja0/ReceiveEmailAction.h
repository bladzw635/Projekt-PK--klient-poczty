#pragma once
#include "EmailAction.h"
#include <Poco/Net/POP3ClientSession.h>
#include <Poco/Net/MailMessage.h>
#include <Poco/Exception.h>
#include <iostream>
#include <string>
#include <algorithm>

class ReceiveEmailAction : public EmailAction {
public:
    void execute() override {
        std::string smtpServer = "pop3.wp.pl";
        std::string sender = "klient_poczty_53@wp.pl";
        std::string password = "9RX9S8XCSF6ejVb";

        try {
            std::cout << "\n Odbieranie wiadomosci: " << std::endl;
            std::cout << "Lacze z serwerem POP3: " << smtpServer << "..." << std::endl;

            // Domyœlny port POP3 bez szyfrowania to 110
            Poco::Net::POP3ClientSession session(smtpServer, 110);

            session.login(sender, password);

            int msgCount = session.messageCount();
            std::cout << "Zalogowano pomyslnie. Calkowita liczba wiadomosci: " << msgCount << "\n" << std::endl;

            if (msgCount == 0) {
                std::cout << "Skrzynka jest pusta." << std::endl;
            }
            else {
                // Zabezpieczenie, gdy w skryznce jest mniej ni¿ 3 wiadomosci
                int limit = std::min(3, msgCount);
                std::cout << "Pobieram naglowki " << limit << " najnowszych wiadomosci:\n";
                std::cout << "--------------------------------------------------\n";

                for (int i = 0; i < limit; ++i) {
                    int msgIndex = msgCount - i;
                    Poco::Net::MailMessage message;

                    session.retrieveMessage(msgIndex, message);

                    std::cout << "[" << i + 1 << "] Od: " << message.getSender() << "\n";
                    std::cout << "    Temat: " << message.getSubject() << "\n";
                    std::cout << "--------------------------------------------------\n";
                }
            }

            session.close();
            std::cout << "Zakonczono pobieranie." << std::endl;

        }
        catch (Poco::Exception& exc) {
            std::cerr << "Blad POP3: " << exc.displayText() << std::endl;
        }
    }
};
