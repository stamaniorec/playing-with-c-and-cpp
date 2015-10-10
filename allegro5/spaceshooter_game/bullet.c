#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "spaceship.h"
#include "bullet.h"

void init_bullet(struct bullet *b)
{
	b->x = 0;
	b->y = 0;
	b->live = 0;
	b->speed = 10;
}

void fire_bullet(struct bullet *b, struct spaceship ship)
{
	b->x = ship.x + 20;
	b->y = ship.y;
	b->live = 1;
}

void draw_bullet(struct bullet b)
{
	al_draw_filled_circle(b.x, b.y, 2, al_map_rgb(255, 255, 255));
}

void update_bullet(struct bullet *b)
{
	if(b->y <= 0)
	{
		b->live = 0;
	}
	b->y -= b->speed;
}