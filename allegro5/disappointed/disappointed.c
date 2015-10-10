#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
	al_init();
	ALLEGRO_DISPLAY *display = al_create_display(640, 480);

	al_init_primitives_addon();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	srand(time(NULL));

	char* disappointed[] = {" Razocharovana sum!", " Tolkova losho kontrolno ne sum vijdala!", 
		"Golqm murzel vi e nalegnal...", " Potresavashto!!"};
	
	ALLEGRO_BITMAP *image = al_load_bitmap("pic.bmp");

	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_TIMER *timer = al_create_timer(1/60.0);
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	ALLEGRO_FONT *font = al_load_font("Arial.ttf", 20, 0);
	
	int done = 0;
	int render = 0;

	int x = 375;
	int y = 340;
	int traveled_y = 0;

	int delay = 120;
	int time_elapsed = 0;
	int dir = -1;
	int move_left = 0;
	int traveled_x = 0;
	int time_elapsed2 = 0;
	int draw_text = 0;
	int random = 0;
	int should_draw_text = 0;

	al_start_timer(timer);

	while(!done)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);

		if(event.type == ALLEGRO_EVENT_TIMER)
		{
			if(x < 50)
				done = 1;
			if(traveled_y >= 75)
			{
				if(!draw_text)
				{
					random = rand() % 4;
					if(y < 350)
						should_draw_text = 1;
				}
				draw_text = 1;
				if(++time_elapsed >= delay)
				{
					traveled_y = 0;
					time_elapsed = 0;
					if(y <= 60 || y >= 375)
					{
						if(!move_left)
						{
							if(y <= 60)
							{
								if(traveled_x >= 50)
								{
									if(++time_elapsed2 >= delay)
									{
										traveled_x = 0;
										time_elapsed2 = 0;
										move_left = 1;
									}
								}
								else
								{
									x -= 3;
									traveled_x += 3;
								}									
							}
							else if(y >= 375)
							{
								should_draw_text = 0;
								if(traveled_x >= 140)
								{
									if(++time_elapsed2 >= delay)
									{
										traveled_x = 0;
										time_elapsed2 = 0;
										move_left = 1;
									}
								}
								else
								{
									x -= 3;
									traveled_x += 3;
								}
							}
							time_elapsed = 120;
							traveled_y = 75;
						}
						else
						{
							dir *= -1;
							move_left = 0;
						}
					}
				}				
			}
			else 
			{
				draw_text = 0;
				should_draw_text = 0;
				y += 3 * dir;
				traveled_y += 3;
			}
			render = 1;
		}

		if(render)
		{
			al_draw_bitmap(image, 0, 0, 0);
			al_draw_pixel(x, y, al_map_rgb(255, 0, 0));
			if(should_draw_text)
			{
				al_draw_text(font, al_map_rgb(255, 255, 255), 10, 450, 0, disappointed[random]);
			}
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			render = 0;
		}
	}

	al_destroy_display(display);
	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);

	return 0;
}
