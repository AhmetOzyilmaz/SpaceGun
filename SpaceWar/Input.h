#pragma once
#include <allegro5/keycodes.h>

class Input
{
public:
	Input();
	~Input();

	static Input* instance;

	static void Initialize();

	static bool IsKeyDown(int keycode);

	static void OnKeyEvent(bool down, int keycode);

private:
	bool m_PressedKeys[ALLEGRO_KEY_MAX] = { false};
};

