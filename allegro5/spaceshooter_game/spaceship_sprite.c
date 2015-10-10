#include <allegro5/allegro.h>
#include "spaceship_sprite.h"

void init_ship_sprite(struct ship_sprite *sprite)
{
	sprite->image = al_load_bitmap("spaceship_spritesheet.png");
	al_convert_mask_to_alpha(sprite->image, al_map_rgb(255, 0, 255));
	sprite->frame_width = 41;   
	sprite->frame_height = 43; 
	sprite->dir_horizontal = CENTER;
	sprite->dir_vertical = NEUTRAL;
}

void draw_ship_sprite(struct ship_sprite sprite, int x, int y)
{
	al_draw_bitmap_region(sprite.image, sprite.dir_horizontal * sprite.frame_width, 
		sprite.dir_vertical * sprite.frame_height, 
			sprite.frame_width, sprite.frame_height, x, y, 0);
}

void destroy_sprite(struct ship_sprite *sprite)
{
	al_destroy_bitmap(sprite->image);
}