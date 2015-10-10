#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

const int WIDTH = 800;
const int HEIGHT = 600;

bool keys[] = {false, false, false, false, false, false, false, false};
enum KEYS{UP, DOWN, LEFT, RIGHT, W, S, D, A};

int main(void)
{
	//variables
	bool done = false;
	bool render = false;	

	int xOff = 0;
	int yOff = 0;

	int mapColumns = 10;
	int mapSize = 100;
	int tileSize = 128;

	int map[] =	{0, 0, 1, 1, 0, 0, 1, 1, 0, 0,
				 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 
				 1, 0, 0, 0, 1, 1, 0, 0, 0, 1,
				 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 
				 0, 0, 1, 1, 0, 0, 1, 1, 0, 0,
				 0, 0, 1, 1, 0, 0, 1, 1, 0, 0,
				 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 
				 1, 0, 0, 0, 1, 1, 0, 0, 0, 1,
				 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 
				 0, 0, 1, 1, 0, 0, 1, 1, 0, 0};


	//allegro variable
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer;
	ALLEGRO_BITMAP *bgSheet = NULL;
	
	//program init
	if(!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(WIDTH, HEIGHT);			//create our display object

	if(!display)										//test display object
		return -1;

	//addon init
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();

	bgSheet = al_load_bitmap("background.png");
	
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	ALLEGRO_BITMAP *image = al_load_bitmap("82316.jpg");	
	ALLEGRO_TRANSFORM camera;
	float degrees = 0;
	float scale = 1.0;

	int x = 0;
	int y = 0;

	al_start_timer(timer);
	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_W:
				keys[W] = true;	
				break;
			case ALLEGRO_KEY_S: 
				keys[S] = true;
				break;
			case ALLEGRO_KEY_D: 
				keys[D] = true;
				break;
			case ALLEGRO_KEY_A: 
				keys[A] = true;
				break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_W: 
				keys[W] = false;
				break;
			case ALLEGRO_KEY_S: 
				keys[S] = false;
				break;
			case ALLEGRO_KEY_D: 
				keys[D] = false;
				break;
			case ALLEGRO_KEY_A: 
				keys[A] = false;
				break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			if(keys[DOWN])
			{
				// if the player isn't going out of bounds
				if(y + 20 < HEIGHT)
				{
					int corner1_x = (-xOff + x) / 128;
					int corner_y = (-yOff + y + 20 + 5) / 128; // the y is shared
					int corner2_x = (-xOff + x + 20) / 128;

					int index1 = mapColumns * corner_y + corner1_x;
					int index2 = mapColumns * corner_y + corner2_x;

					// we check for both corners because what if the player is one half 
					// in one tile and one half in another? 
					// we have to check for both tiles below the player!
					if(map[index1] != 1 && map[index2] != 1)
					{
						// do we move the camera or not?
						if(y > HEIGHT / 2 - 20/2)
						{
							// if the camera isn't going out of bounds, move it
							if(yOff > -(mapColumns * tileSize - HEIGHT)	)
								yOff -= keys[DOWN] * 5;
							// else just move the player
							else 
								y += 5;
						}
						// the player is going to move, but the camera isn't
						else
						{
							y += 5;
						}
					}
				}		
			}
			else if(keys[UP])
			{
				if(y > 0)
				{
					int destination_x = (-xOff + x) / 128;
					int destination_y = (-yOff + y - 5) / 128;
					int index = mapColumns * destination_y + destination_x;
					if(map[index] != 1)
					{
						if(y < HEIGHT/2 - 100)
						{
							if(yOff < 0)
							{
								yOff += keys[UP] * 5;
							}
							else 
								y -= 5;
						}
						else
						{
							y -= 5;
						}
					}
					
				}
			}
			else if(keys[LEFT])
			{
				if(x > 0)
				{
					int destination_x = (-xOff + x - 5) / 128;
					int destination_y = (-yOff + y) / 128;
					int index = mapColumns * destination_y + destination_x;
					if(map[index] != 1)
					{
						if(x < WIDTH/2 - 150)
						{
							if(xOff < 0)
								xOff += keys[LEFT] * 5;
							else
								x -= 5;
						}
						else
							x -= 5;
					}
				}
			}
			else if(keys[RIGHT])
			{
				// the additional five pixels aren't that necessary
				// but the player would sometimes refuse to move anymore when right at the screen width
				// why? I have no bloody idea, but I just limited the player's movement, everything is ok
				if(x + 20 + 5 < WIDTH)
				{
					if(x > WIDTH/2 + 150)
					{
						if(xOff > -(mapColumns * tileSize - WIDTH))
							xOff -= keys[RIGHT] * 5;
						else
							x += 5;
					}
					else
					{
						x += 5;
					}
				}
			}

			//printf("xOff = %d, yOff = %d\n", xOff, yOff);

			if(keys[W])
				++degrees;
			if(keys[S])
				--degrees;
			if(keys[D])
				scale += 0.01f;
			if(keys[A])
				scale -= 0.01f;

			render = true;
		}

		if(render && al_is_event_queue_empty(event_queue))
		{
			render = false;

			for(int i = 0; i < mapSize; i++)
			{
				al_draw_bitmap_region(bgSheet, tileSize * map[i], 0, tileSize, tileSize, 
					xOff + tileSize * (i % mapColumns), yOff + tileSize * (i / mapColumns), 0);
			}

			//al_draw_bitmap(image, xOff, yOff, 0);

			al_identity_transform(&camera);
			al_scale_transform(&camera, scale, scale);
			al_rotate_transform(&camera, degrees * 3.1415 / 180);
			al_use_transform(&camera);

			al_draw_filled_rectangle(x, y, x+20, y+20, al_map_rgb(255,0,0));

			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
	}

	al_destroy_bitmap(bgSheet);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						//destroy our display object

	return 0;
}
