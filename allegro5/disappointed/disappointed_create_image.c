#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
	al_init();
	ALLEGRO_DISPLAY *display = al_create_display(640, 480);

	al_init_primitives_addon();
	al_init_image_addon();
	
	ALLEGRO_BITMAP *image = al_create_bitmap(520, 500);
	al_set_target_bitmap(image);

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(10, 10, 110, 60, al_map_rgb(133, 94, 66));
	al_draw_filled_rectangle(10, 85, 110, 135, al_map_rgb(133, 94, 66));
	al_draw_filled_rectangle(10, 160, 110, 210, al_map_rgb(133, 94, 66));
	
	int i;
	int y1 = 10, y2 = 60;
	for(i = 0; i < 5; ++i)
	{
		al_draw_filled_rectangle(10, y1, 110, y2, al_map_rgb(133, 94, 66));
		y1 += 75; 
		y2 += 75;
	}

	y1 = 10; y2 = 60;

	for(i = 0; i < 5; ++i)
	{
		al_draw_filled_rectangle(210, y1, 310, y2, al_map_rgb(133, 94, 66));
		y1 += 75;
		y2 += 75;
	}

	y1 = 10; y2 = 60;

	for(i = 0; i < 5; ++i)
	{
		al_draw_filled_rectangle(410, y1, 510, y2, al_map_rgb(133, 94, 66));
		y1 += 75;
		y2 += 75;
	}
	
	al_set_target_bitmap(al_get_backbuffer(display)); 
	al_save_bitmap("pic.bmp", image);
	
	al_destroy_display(display);
	al_destroy_bitmap(image);

	return 0;
}
