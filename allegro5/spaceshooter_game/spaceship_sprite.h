#ifndef SPACESHIP_SPRITE_H
#define SPACESHIP_SPRITE_H

// I know #defines aren't a good practice
// but if I use consts 
// the compiler says that they're declared multiple times
// so I'm just not gonna bother with them	

#ifndef screen_width
#define screen_width 640
#endif

#ifndef screen_height
#define screen_height 480
#endif

enum horizontal { LEFT, CENTER, RIGHT };
enum vertical { BACK, FORWARD, NEUTRAL };

struct ship_sprite
{
	ALLEGRO_BITMAP *image;
	int frame_width;
	int frame_height;
	int dir_horizontal;
	int dir_vertical;
};

void init_ship_sprite(struct ship_sprite *sprite);
void draw_ship_sprite(struct ship_sprite sprite, int x, int y);
void destroy_sprite(struct ship_sprite *sprite);

#endif