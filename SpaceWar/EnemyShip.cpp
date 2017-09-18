#include "EnemyShip.h"
#include "Game.h"
#include "PlayerShip.h"
#include <list>
#include <allegro5/allegro_primitives.h>


EnemyShip::EnemyShip(vector2f pos) : GameObject(Texture::Load("enemy.png", 0.15), pos)
{
	speed = 0.5;

	radius = 30;

	type = ENEMY;

	maxhp = 5;
	hp = maxhp;
}


EnemyShip::~EnemyShip()
{
}

void EnemyShip::Update()
{
	position += vector2f(0, 1) * speed;

	auto contacts = Game::instance->GetContacts(this);
	for (auto& contact : contacts) {
		if (dynamic_cast<PlayerShip*>(contact) != nullptr) {
			Game::instance->RemoveGameObject(contact);
			Game::instance->RemoveGameObject(this);
		}
	}
}

void EnemyShip::Draw()
{
	GameObject::Draw();

	float a = (3.14 * (1-(hp*1.0 / maxhp))) / 2.0;

	al_draw_arc(position.x, position.y, radius, a, 3.14-2*a, { 50,50,255 }, 3);
}

void EnemyShip::Damage(int damage)
{
	hp -= damage;

	if (hp <= 0) {
		Game::instance->RemoveGameObject(this);
	}
}
