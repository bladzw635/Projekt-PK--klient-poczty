#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double start_x, double start_y, double szer, double wys) {
    x = start_x;
    y = start_y;
    szerokosc = szer;
    wysokosc = wys;
}


void Rectangle::draw() {
    std::cout << "Prostokat: wspolrzedne (" << x << ", " << y
        << "), wymiary " << szerokosc << "x" << wysokosc << "\n";
}

void Rectangle::move(double delta_x, double delta_y) {
    x += delta_x;
    y += delta_y;
}

IShape* Rectangle::clone() {
    return new Rectangle(*this);
}