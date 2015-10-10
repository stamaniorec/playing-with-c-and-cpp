#ifndef BULLET_H
#define BULLET_H

struct bullet
{
	int x;
	int y;
	int live;
	int speed;
};

void init_bullet(struct bullet *b);
void fire_bullet(struct bullet *b, struct spaceship ship);
void draw_bullet(struct bullet b);
void update_bullet(struct bullet *b);

#endif