#pragma once
#include <iostream>
#include <random>
#include "enum.h"

class LinearSystem {
private:
    double a1, b1, c1;
    double a2, b2, c2;

public:
    LinearSystem() {
        std::random_device rd;
        std::default_random_engine gen(rd());
        std::uniform_real_distribution<double> dist(0.0, 1.0);

        a1 = dist(gen);
        b1 = dist(gen);
        c1 = dist(gen);
        a2 = dist(gen);
        b2 = dist(gen);
        c2 = dist(gen);
    }

    LinearSystem(double a1, double b1, double c1, double a2, double b2, double c2)
        : a1(a1), b1(b1), c1(c1), a2(a2), b2(b2), c2(c2) {
    }

    double getA1() const { return a1; }
    double getB1() const { return b1; }
    double getC1() const { return c1; }
    double getA2() const { return a2; }
    double getB2() const { return b2; }
    double getC2() const { return c2; }

    void print() const {
        std::cout << a1 << "*x + " << b1 << "*y = " << c1 << "\n";
        std::cout << a2 << "*x + " << b2 << "*y = " << c2 << "\n";
    }

    SolutionType solve(double& x, double& y) const;
};