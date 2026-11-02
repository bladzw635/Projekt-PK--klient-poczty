#pragma once

class Scene {
private:
	IShape* shapes[10];
	int n_shapes;
public:
	Scene();
	~Scene();
	bool Add(IShape* shape);
	void Draw();
	bool DuplicateSelected(int id);
};