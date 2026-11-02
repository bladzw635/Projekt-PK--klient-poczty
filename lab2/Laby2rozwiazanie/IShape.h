#pragma once
class IShape {
public:
	virtual void draw() = 0;
	virtual void move(double x, double y) = 0;
	virtual IShape* clone() = 0;

	virtual ~IShape() {};
};


