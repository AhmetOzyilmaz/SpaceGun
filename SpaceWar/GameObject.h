#pragma once
#include "vector2.cpp"
#include "Texture.h"

enum ObjectType { SHIP, BULLET, ENEMY };

class GameObject {
public:
	GameObject(Texture* texture, vector2f pos);

	virtual void Update() {}

	virtual void Draw();

	bool CheckCollision(GameObject* other);

	void Destroy();

protected:
	ObjectType type;

	vector2f position;
	float rotation = 0;
	
	// for collision check
	float radius = 0;

	Texture* texture = nullptr;
};