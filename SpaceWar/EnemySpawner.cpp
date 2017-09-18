#include "EnemySpawner.h"
#include "EnemyShip.h"
#include "Game.h"
#include "Helpers.h"

EnemySpawner::EnemySpawner()
{
	srand(time(NULL) * 2);

	spawnRate = 1;
	timeLeftForSpawn = 0;
}


EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::Update()
{
	timeLeftForSpawn -= 1 / 60.0;

	if (timeLeftForSpawn <= 0) {
		Spawn();
		timeLeftForSpawn = spawnRate;
	}
}

void EnemySpawner::Spawn()
{
	EnemyShip* enemy = new EnemyShip(vector2f( Random(50, Game::instance->screenSize.x-50) , 50));

	Game::instance->AddGameObject(enemy);
}
