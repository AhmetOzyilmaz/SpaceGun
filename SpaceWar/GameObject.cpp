#include "GameObject.h"
#include <allegro5/allegro_primitives.h>
#include "Game.h"

GameObject::GameObject(Texture* texture_, vector2f pos) :  texture(texture_), position(pos)
{

}

void GameObject::Draw()
{
	texture->Draw(position, rotation);

	al_draw_circle(position.x, position.y, radius, { 255,0,0 }, 5);
}

bool GameObject::CheckCollision(GameObject * other)
{
	vector2f diff = other->position - position;
	return diff.length() < (other->radius + radius);
}

void GameObject::Destroy()
{
	Game::instance->RemoveGameObject(this);
}
