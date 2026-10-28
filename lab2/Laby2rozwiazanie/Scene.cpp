#include "Scene.h"

Scene::Scene() : n_shapes(0) {
	for (int i = 0; i < 10; i++) {
		shapes[i] = nullptr;
	}
}
bool Scene::Add(IShape* shape) {
	if (n_shapes < 10) {
		shapes[n_shapes] = shape;
		n_shapes++;
		return true;
	}
	else { return false; }
}

void Scene::Draw() {
	for (int i = 0; i < n_shapes; i++) {
		shapes[i]->draw();
	}
}

bool Scene::DuplicateSelected(int id) {
	if (id < 0 || id >= n_shapes || n_shapes >= 10) {
		return false;
	}
	IShape* copy = shapes[id]->clone();
	copy->move(10.0, 10.0);
	shapes[n_shapes] = copy;
	n_shapes++;

	return true;
}
bool Scene::operator+=(IShape* shape) {
	return Add(shape);
}

void Scene::operator()() {
	Draw();
}

IShape*& Scene::operator[](int index) {
	return shapes[index];
}
Scene::~Scene() {
	for (int i = 0; i < n_shapes; i++) {
		delete shapes[i];
	}
}