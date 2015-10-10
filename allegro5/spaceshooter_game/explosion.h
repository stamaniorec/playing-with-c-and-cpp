#ifndef EXPLOSION_H
#define EXPLOSION_H

struct explosion
{
	int x;
	int y;
	int live;

	int frame_width;
	int frame_height;
	int current_frame;
	int frame_count;
	int max_frames;
	int frame_delay;
	int animation_columns;

	ALLEGRO_BITMAP *image;
};

void init_explosion(struct explosion *e);
void start_explosion(struct explosion *e, int x, int y);
void update_explosion(struct explosion *e);
void draw_explosion(struct explosion e);
void destroy_explosion(struct explosion *e);

#endif