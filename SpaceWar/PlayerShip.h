#pragma once
#include "GameObject.h"
#include "Input.h"
class PlayerShip :
	public GameObject
{
public:
	PlayerShip();
	~PlayerShip();

	void Update() override;

	void TryFire();
private:
	void Fire();

	float speed;

	float fireRate;
	float timeLeftForFire;
};

