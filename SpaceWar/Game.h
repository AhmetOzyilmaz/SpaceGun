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

	template<class T>
	T* GetContactByType(GameObject* object);

private:
	list<GameObject*> objects;

	// adding and removing
	list<GameObject*> objectsToAdd;
	list<GameObject*> objectsToRemove;
};

template<class T>
inline T* Game::GetContactByType(GameObject * object)
{
	auto contacts = GetContacts(object);
	for (auto& contact : contacts) {
		if (dynamic_cast<T*>(contact) != nullptr) {
			return dynamic_cast<T*>(contact);
		}
	}
	return nullptr;
}
