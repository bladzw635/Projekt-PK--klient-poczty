#pragma once
#include "IShape.h"

class Scene {
private:
	IShape* shapes[10];
	int n_shapes;
public:
	Scene();
	bool Add(IShape* shape);
	void Draw();
	bool DuplicateSelected(int id);
	bool operator+=(IShape* shape);
	void operator()();
	IShape*& operator[](int index);

	~Scene();
};