#include "LinarySystem.h"
#include <cmath>

SolutionType LinearSystem::solve(double& x, double& y) const {

    // Wyznacznik  W
    double W = a1 * b2 - a2 * b1;
    // Wyznaczniki Wx, Wy
    double Wx = c1 * b2 - c2 * b1;
    double Wy = a1 * c2 - a2 * c1;

    //  1 rozw W != 0
    if (W !=0 ) {
        x = Wx / W;
        y = Wy / W;
        return SolutionType::jedno_rozw;
    }

    // nieskonczone: W == 0 oraz Wx == 0 i Wy == 0
    if (Wx == 0 && Wy == 0) {
        return SolutionType::nieskonczenie_wiele_rozw;
    }

    // 0 rozw: W == 0 oraz przynajmniej jeden Wx/Wy != 0
    return SolutionType::brak_rozw;
}