#include "Bullet.h"
#include "Game.h"
#include "EnemyShip.h"


Bullet::Bullet(vector2f pos, vector2f vel) : GameObject(Texture::Load("bullet2.png", 0.35), pos), velocity(vel)
{
	//rotation = 3.14/2;

	radius = 5;
	
}


Bullet::~Bullet()
{
}

void Bullet::Update()
{
	position += velocity;	
	
	auto contacts = Game::instance->GetContacts(this);
	for (auto& contact : contacts) {
		EnemyShip* enemy = dynamic_cast<EnemyShip*>(contact);
		if (enemy != nullptr) {
			enemy->Damage(1);
			Destroy();
			return;
		}
	}

	if (position.y < 0 || position.y > Game::instance->screenSize.y) {
		Destroy();
	}
}
