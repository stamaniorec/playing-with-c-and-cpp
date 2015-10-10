#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "spaceship_sprite.h" // needed for line 13

struct spaceship
{
	int x;
	int y;
	int speed;
	int lives;
	int score;
	int live;
	int bound_left;
	int bound_right;
	int bound_up;
	int bound_down;
	struct ship_sprite sprite;
};

void init_ship(struct spaceship *ship);
void set_ship_coordinates(struct spaceship *ship, int a, int b);
void update_ship_boundaries(struct spaceship *ship);

#endif