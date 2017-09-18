#include "Game.h"

Game* Game::instance = nullptr;

Game::Game()
{
	instance = this;
}


Game::~Game()
{
}

void Game::AddGameObject(GameObject * obj)
{
	objectsToAdd.push_back(obj);
}

void Game::RemoveGameObject(GameObject * obj)
{
	for (auto& o : objectsToRemove) {
		if (obj == o) return;
	}
	objectsToRemove.push_back(obj);
}

void Game::UpdateAll()
{
	// update all game objects
	for (auto& obj : objects) {
		obj->Update();
	}

	// add and remove objects
	for (auto& obj : objectsToAdd) {
		objects.push_back(obj);
	}
	objectsToAdd.clear();

	for (auto& obj : objectsToRemove) {
		objects.remove(obj);
		delete obj;
	}
	objectsToRemove.clear();
}

void Game::DrawAll()
{
	for (auto& obj : objects) {
		obj->Draw();
	}
}

list<GameObject*> Game::GetContacts(GameObject * object)
{
	list<GameObject*> contacts= list<GameObject*>();

	for (auto& obj : objects) {
		if (obj != object) {
			if (obj->CheckCollision(object)) {
				contacts.push_back(obj);
			}
		}
	}

	return contacts;
}
