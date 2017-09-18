#include "Input.h"

Input *Input::instance = nullptr;

Input::Input()
{
}


Input::~Input()
{
}

void Input::Initialize()
{
	if(instance == nullptr)
		instance = new Input();
}

bool Input::IsKeyDown(int keycode)
{
	if (instance == nullptr) return false;

	if(keycode >= 0 && keycode < ALLEGRO_KEY_MAX)
		return instance->m_PressedKeys[keycode];

	return false;
}

void Input::OnKeyEvent(bool down, int keycode)
{
	instance->m_PressedKeys[keycode] = down;
}
