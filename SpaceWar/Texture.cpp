#include "Texture.h"

#include <iostream>

map<string, Texture*> Texture::textures = map<string, Texture*>();

Texture::~Texture()
{
}

void Texture::Draw(vector2f pos, float rot)
{
	al_draw_scaled_rotated_bitmap(bitmap, cx, cy, pos.x, pos.y, scale, scale, rot, 0);
}

Texture * Texture::Load(string path, float scale)
{
	if (textures.count(path) > 0) {
		return textures[path];
	}
	else {
		ALLEGRO_BITMAP* bitmap= al_load_bitmap(path.c_str());
		if (bitmap != nullptr) {
			Texture* t = new Texture;
			t->bitmap = bitmap;

			t->scale = scale;

			t->width = al_get_bitmap_width(bitmap);
			t->height = al_get_bitmap_height(bitmap);

			t->cx = t->width / 2.0;
			t->cy = t->height / 2.0;

			textures[path] = t;

			cout << "New texture loaded " << path << endl;

			return t;
		}
		else {

			cout << "ERR: Image couldn load: " << path << endl;
		}

		return nullptr;
	}
}
