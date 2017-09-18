#pragma once
#include <map>
#include <string>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "vector2.cpp"

using namespace std;

class Texture
{
public:
	~Texture();

	void Draw(vector2f pos, float rot);

	static Texture* Load(string path, float scale= 1);

private:
	ALLEGRO_BITMAP* bitmap;
	float scale;

	int width, height;
	float cx, cy;

	static map<string, Texture*> textures;
};


