#pragma once
#include "IShape.h"

class Rectangle : public IShape {
private:
    double x;
    double y;
    double szerokosc;
    double wysokosc;
public:
    Rectangle(double start_x, double start_y, double szer, double wys);
    void draw() override;
    void move(double delta_x, double delta_y) override;
    IShape* clone() override;
};