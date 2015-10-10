#include <allegro5/allegro.h>
#include "explosion.h"

void init_explosion(struct explosion *e)
{
	e->x = 0; 
	e->y = 0;
	e->live = 0;

	e->frame_width = 128;
	e->frame_height = 128;
	e->current_frame = 0;
	e->frame_count = 0;
	e->max_frames = 38;
	e->frame_delay = 1;

	e->animation_columns = 8;

	e->image = al_load_bitmap("explosion_3_40_128.png");
}

void start_explosion(struct explosion *e, int x, int y)
{
	e->x = x;
	e->y = y;
	e->live = 1;
}

void update_explosion(struct explosion *e)
{
	if(++e->frame_count >= e->frame_delay)
	{
		if(++e->current_frame >= e->max_frames)
		{
			e->current_frame = 0;
			e->live = 0;
		}
		e->frame_count = 0;
	}
}

void draw_explosion(struct explosion e)
{
	int frame_x = ( e.current_frame % e.animation_columns ) * e.frame_width;
	int frame_y = ( e.current_frame / e.animation_columns ) * e.frame_height;

	al_draw_bitmap_region(e.image, frame_x, frame_y, e.frame_width, e.frame_height, 
		e.x - e.frame_width / 2, e.y - e.frame_height / 2, 0);
}

void destroy_explosion(struct explosion *e)
{
	al_destroy_bitmap(e->image);
}
