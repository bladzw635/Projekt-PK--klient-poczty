#include <iostream>
#include "SendEmailAction.h"

int main() {
    std::cout << "--- Prosty Klient Pocztowy ---" << std::endl;
    EmailAction* action = new SendEmailAction();
    action->execute();
    delete action;

    return 0;
}