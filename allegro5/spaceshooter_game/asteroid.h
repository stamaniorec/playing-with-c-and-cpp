#ifndef ASTEROID_H
#define ASTEROID_H

#include "spaceship.h"

struct asteroid
{
	int x;
	int y;
	int live;
	int speed;
	int bound_left;
	int bound_right;
	int bound_up;
	int bound_down;
	ALLEGRO_BITMAP *image;
};

void init_asteroid(struct asteroid *a);
void start_asteroid(struct asteroid *a);
void draw_asteroid(struct asteroid a);
void update_asteroid(struct asteroid *a, struct spaceship *ship);
void destroy_asteroid(struct asteroid *a);

#endif