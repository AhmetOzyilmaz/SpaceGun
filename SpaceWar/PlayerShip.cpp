#include "PlayerShip.h"
#include "Game.h"
#include "Bullet.h"
#include "Helpers.h"

PlayerShip::PlayerShip() : GameObject(Texture::Load("ship.png", 0.15), vector2f(0,0))
{
	position = vector2f(Game::instance->screenSize.x / 2, Game::instance->screenSize.y - 50);
	speed = 5;

	radius = 18;

	type = SHIP;

	fireRate= 0.015;
	timeLeftForFire= 0;
}


PlayerShip::~PlayerShip()
{
}

void PlayerShip::Update()
{
	vector2f direction= vector2f(0,0);

	if (Input::IsKeyDown(ALLEGRO_KEY_LEFT) || Input::IsKeyDown(ALLEGRO_KEY_A)) {
		direction += vector2f(-1, 0);
	}
	if (Input::IsKeyDown(ALLEGRO_KEY_RIGHT) || Input::IsKeyDown(ALLEGRO_KEY_D)) {
		direction += vector2f(1, 0);
	}
	if (Input::IsKeyDown(ALLEGRO_KEY_UP) || Input::IsKeyDown(ALLEGRO_KEY_W)) {
		direction += vector2f(0, -1);
	}
	if (Input::IsKeyDown(ALLEGRO_KEY_DOWN) || Input::IsKeyDown(ALLEGRO_KEY_S)) {
		direction += vector2f(0, 1);
	}

	vector2f vec = Game::instance->screenSize;

	if (position.x < 30) {
		position.x = 30;
	}
	if (position.x > vec.x- 30){
		position.x = vec.x - 30;
	}
	if (position.y < 30) {
		position.y = 30;
	}
	if (position.y > (vec.y - 30)) {
		position.y = vec.y - 30;
	}
	position += direction * speed;
	
	timeLeftForFire -= 1 / 60.0;
	if (Input::IsKeyDown(ALLEGRO_KEY_SPACE)) {
		TryFire();
	}
}

void PlayerShip::TryFire()
{
	if (timeLeftForFire <= 0) {
		Fire();
		timeLeftForFire = fireRate;
	}
}

void PlayerShip::Fire()
{
	Bullet* bullet = new Bullet(position + vector2f(Random(-6,6),0), vector2f(0, -15));
	Game::instance->AddGameObject(bullet);
}
