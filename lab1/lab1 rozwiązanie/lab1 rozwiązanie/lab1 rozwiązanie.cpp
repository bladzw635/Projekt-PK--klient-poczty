#include <iostream>
#include "LinarySystem.h"
#include "enum.h"

int main() {
    LinearSystem sys(2.0, 1.0, 5.0, 1.0, -1.0, 1.0);
    sys.print();

    double x = 0.0;
    double y = 0.0;
    SolutionType wynik = sys.solve(x, y);

    if (wynik == SolutionType::jedno_rozw){
        std::cout << "Jedno rozwiazanie: x = " << x << ", y = " << y << "\n";
    }
    else if (wynik == SolutionType::nieskonczenie_wiele_rozw) {
        std::cout << "Nieskonczenie wiele rozwiazan.\n";
    }
    else {
        std::cout << "Uklad sprzeczny (brak rozwiazan).\n";
    }

    return 0;
}