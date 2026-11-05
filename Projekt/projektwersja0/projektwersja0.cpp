#include <iostream>
#include "SendEmailAction.h"
#include "ReceiveEmailAction.h"

using namespace std;

int main() {
    std::cout << " Prosty Klient Pocztowy:  \n";
    std::cout << "1. Wyslij wiadomosc (SMTP)\n";
    std::cout << "2. Odbierz wiadomosci (POP3)\n";
    std::cout << "Wybierz opcje (1/2): ";

    int choice;
    std::cin >> choice;

    // Czyszczenie bufora po cin
    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

    EmailAction* action = nullptr;

    if (choice == 1) {
        action = new SendEmailAction();
    }
    else if (choice == 2) {
        action = new ReceiveEmailAction();
    }
    else {
        std::cout << "Nieznana opcja." << std::endl;
        return 0;
    }
    action->execute();

    delete action;

    cout << "\nNacisnij enter, aby zakonczyc...";
    cin.get();
    return 0;
}