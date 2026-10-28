#pragma once
#include "IShape.h"

class Circle: public IShape{
private:
	double x;
	double y;
	double promien;
public: 
	Circle(double delta_x, double delta_y, double r);
	void draw() override;
	void move(double delta_x, double delta_y) override;
	IShape* clone() override;
};