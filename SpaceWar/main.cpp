#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

#include "Texture.h"
#include "GameObject.h"
#include "Game.h"
#include "Input.h"
#include "PlayerShip.h"
#include "EnemyShip.h"
#include "EnemySpawner.h"

using namespace std;

const float FPS = 60;
const int WIDTH = 800;
const int HEIGHT = 600;

int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = nullptr;
	ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
	ALLEGRO_TIMER *timer = nullptr;

	bool redraw = true;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}
	display = al_create_display(WIDTH, HEIGHT);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_install_keyboard();
	al_init_image_addon();
	al_init_primitives_addon();

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	Input::Initialize();
	Game* game = new Game();
	game->screenSize = vector2f(WIDTH, HEIGHT);


	Texture* ship = Texture::Load("ship.png", 0.15);
	Texture* back = Texture::Load("back.png", 1);
	Texture* enemy = Texture::Load("enemy.png", 0.15);

	GameObject* player = new PlayerShip();

	GameObject* background = new GameObject(back, vector2f(WIDTH/2, HEIGHT / 2));

	Game::instance->AddGameObject(background);
	Game::instance->AddGameObject(player);

	EnemySpawner spawner;


	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			Input::instance->OnKeyEvent(true, ev.keyboard.keycode);
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			Input::instance->OnKeyEvent(false, ev.keyboard.keycode);
		}

		else if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			// code removed for brevity         
			redraw = true;
		}

		if (redraw && al_event_queue_is_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));

			//al_draw_pixel(100, 100, al_map_rgb(255, 0, 0));
			//ship->Draw(vector2f(100, 100), 0);
			
			spawner.Update();
			game->UpdateAll();
			game->DrawAll();

			al_flip_display();
		}
	}


	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}