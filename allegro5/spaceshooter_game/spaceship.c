#include <allegro5/allegro.h> // needed for the ALLEGRO_BITMAP* variable in the header file 
#include "spaceship.h"

void init_ship(struct spaceship *ship)
{
	init_ship_sprite(&ship->sprite);
	ship->x = (screen_width - ship->sprite.frame_width) / 2;
	ship->y = screen_height - 100;
	ship->speed = 5;
	ship->lives = 5;
	ship->score = 0;
	ship->live = 1;
}

void set_ship_coordinates(struct spaceship *ship, int a, int b)
{
	ship->x = a;
	ship->y = b;
}

void update_ship_boundaries(struct spaceship *ship)
{
	ship->bound_left = ship->x;
	ship->bound_right = ship->x + al_get_bitmap_width(ship->sprite.image) / 3; // there are three frames in the spritesheet
	ship->bound_up = ship->y;
	ship->bound_down = ship->y + al_get_bitmap_height(ship->sprite.image) / 3;
}