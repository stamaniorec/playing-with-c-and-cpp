#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

using namespace std;

int main()
{
	int x = 500;
	int y = 240;
	int radius = 50;
	int width = 640;
	int height = 480;

	/*
	 * radius - 25 to 75 
	 * 
	 * */

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

	float var1 = (float)radius / 5;
	float var2 = (float)radius / 2;
	float var3 = radius * 1.4;
	float var4 = radius * 0.8;
	float var5 = radius * 1.8;

	al_draw_filled_circle(x, y, radius, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(x, y-radius+var1, x+radius, y+radius-var1, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(x+radius, y-radius+var2, x+var3, y+radius-var2, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(x+var3, y-radius+var4, x+var5, y+radius-var4, al_map_rgb(255, 0, 0));

	al_draw_line(x, y, x-radius, y, al_map_rgb(0, 0, 0), 3.0); // x-radius -> back boundary
	al_draw_line(x, y, x+radius*1.8, y, al_map_rgb(255, 255, 255), 3.0); // x+radius*1.5 -> front boundary
	al_draw_line(x, y, x, y-radius, al_map_rgb(255, 255, 255), 3.0); // y-radius*0.2 -> upper boundary
	al_draw_line(x, y, x, y+radius, al_map_rgb(255, 255, 255), 3.0); // y+radius*0.2 -> lower boundary

	al_flip_display();
	al_rest(6.0);
	al_destroy_display(display);

	return 0;
}
