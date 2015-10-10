#include <allegro5/allegro.h>
#include "asteroid.h"
#include "spaceship.h" 
#include "spaceship_sprite.h" // for screen width and height

void init_asteroid(struct asteroid *a)
{
	a->x = 0;
	a->y = 0;
	a->live = 0;
	a->speed = 2;
	a->bound_left = 0;
	a->bound_right = 0;
	a->bound_up = 0;
	a->bound_down = 0;
	a->image = NULL;
}

void start_asteroid(struct asteroid *a)
{
	a->live = 1;

	int random = rand() % 6;
	char name[13] = "asteroid";
	name[8] = random+'0';
	name[9] = '.'; name[10] = 'p'; name[11] = 'n'; name[12] = 'g';
	
	a->image = al_load_bitmap(name);
	al_convert_mask_to_alpha(a->image, al_map_rgb(255, 0, 255));
	
	a->x = (rand() % (screen_width-al_get_bitmap_width(a->image))) + al_get_bitmap_width(a->image) - 10;
	a->y = 0;
	
	a->bound_left = a->x;
	a->bound_right = a->x + al_get_bitmap_width(a->image);
	
	// to-do: add varying speed depending on asteroid size
}

void draw_asteroid(struct asteroid a)
{
	al_draw_bitmap(a.image, a.x, a.y, 0);
}

void update_asteroid(struct asteroid *a, struct spaceship *ship)
{
	a->y += a->speed;
	
	a->bound_up = a->y;
	a->bound_down = a->y + al_get_bitmap_height(a->image);
	
	if(a->y >= screen_height)
	{
		a->live = false; 
		ship->lives--;
	}
}

void destroy_asteroid(struct asteroid *a)
{
	al_destroy_bitmap(a->image);
}
