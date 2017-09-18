#pragma once
#include "GameObject.h"
class Bullet :
	public GameObject
{
public:
	Bullet(vector2f pos, vector2f vel);
	~Bullet();

	void Update() override;

private:
	vector2f velocity;
};

