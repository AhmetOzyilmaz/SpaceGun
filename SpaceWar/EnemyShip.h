#pragma once
#include "GameObject.h"
class EnemyShip : public GameObject
{
public:
	EnemyShip(vector2f pos);
	~EnemyShip();

	void Update() override;
	void Draw() override;

	void Damage(int damage);

private:
	float speed;

	int hp;
	int maxhp;
};

