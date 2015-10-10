#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

using namespace std;

int main()
{
	int x = 30;
	int y = 240;
	int width = 640;
	int height = 480;

	if (!al_init())
	{
		al_show_native_message_box(NULL, "Error", "Error", "Could not initialize Allegro 5. :( ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	ALLEGRO_DISPLAY *display = al_create_display(width, height);

	if (!display)
	{
		al_show_native_message_box(NULL, "Error", "Error", "Could not initialize display. :( ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	al_init_primitives_addon();

	al_draw_filled_rectangle(x-10, y-5, x+40, y+10, al_map_rgb(208, 201, 201));		// ship body
	al_draw_line(x-6, y-3, x-6, y-10, al_map_rgb(250, 0, 0), 2.0);					// upper back line 1 
	al_draw_line(x-17, y-10, x-5, y-10, al_map_rgb(250, 0, 0), 2.0);				// upper back line 2
	al_draw_line(x-6, y+8, x-6, y+15, al_map_rgb(250, 0, 0), 2.0);					// lower back line 1
	al_draw_line(x-17, y+15, x-5, y+15, al_map_rgb(250, 0, 0), 2.0);				// lower back line 2
	al_draw_line(x-20, y+2.5, x-10, y+2.5, al_map_rgb(250, 0, 0), 2.0);				// middle back line
	al_draw_line(x+30, y-5, x+30, y+10, al_map_rgb(250, 0, 0), 2.0);				// front line 
	al_draw_line(x+30, y+2.5, x+40, y+2.5, al_map_rgb(250, 0, 0), 2.0);				// front middle line 

	al_draw_line(x, y, x, y-5, al_map_rgb(250, 0, 0), 3.0); // y-5 -> upper boundary
	al_draw_line(x, y, x, y+10, al_map_rgb(250, 0, 0), 3.0); // y+10 -> lower boundary
	al_draw_line(x, y, x-10, y, al_map_rgb(250, 0, 0), 3.0); // x-10 -> back boundary
	al_draw_line(x, y, x+40, y, al_map_rgb(250, 0, 0), 3.0); // x+40 -> front boundary

	al_flip_display();
	al_rest(15.0);
	al_destroy_display(display);

	return 0;
}
