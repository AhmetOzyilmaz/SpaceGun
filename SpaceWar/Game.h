#pragma once

#include <list>

#include "GameObject.h"

using namespace std;

class Game
{
public:
	Game();
	~Game();

	void AddGameObject(GameObject* obj);
	void RemoveGameObject(GameObject* obj);

	void UpdateAll();
	void DrawAll();

	static Game* instance;

	vector2f screenSize;

	list<GameObject*> GetContacts(GameObject* object);

private:
	list<GameObject*> objects;

	// adding and removing
	list<GameObject*> objectsToAdd;
	list<GameObject*> objectsToRemove;
};

