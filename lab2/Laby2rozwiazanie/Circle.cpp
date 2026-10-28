#include "Circle.h"
#include <iostream>

Circle::Circle(double start_x, double start_y, double r) {
	x = start_x;
	y = start_y;
	promien = r;

}

void Circle::draw() {
	std::cout << "Okrag; srodek w: " << x << ", " << y << " promien : " << promien << " ";
}

void Circle::move(double delta_x, double delta_y) {
	x += delta_x;
	y += delta_y;
}

IShape* Circle::clone() {
	return new Circle(*this);
}