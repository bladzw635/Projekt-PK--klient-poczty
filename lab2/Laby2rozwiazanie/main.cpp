#include <iostream>
#include <string>
#include "Scene.h"
#include "Rectangle.h"
#include "Circle.h"
int main()
{
	Scene scena;
	IShape* prostokat = new Rectangle(0.0, 0.0, 10.0, 5.0);
	//scena.Add(prostokat);
	//scena.Draw();
	scena += prostokat;
	
	IShape* kolo = new Circle(0.0, 0.0, 10.0);
	scena += kolo;
	//scena.Add(kolo);
	//scena.Draw();
	scena.DuplicateSelected(1);
	//scena.Draw();
	scena();
	scena[0]->draw();
	
	return 0;

}