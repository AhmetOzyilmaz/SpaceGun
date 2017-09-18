#pragma once
class EnemySpawner
{
public:
	EnemySpawner();
	~EnemySpawner();

	void Update();


private:
	void Spawn();

	float spawnRate;
	float timeLeftForSpawn;
};

