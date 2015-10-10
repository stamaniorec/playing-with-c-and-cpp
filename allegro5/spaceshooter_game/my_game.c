#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "spaceship.h"
#include "spaceship_sprite.h"
#include "bullet.h"
#include "asteroid.h"
#include "explosion.h"

int bullet_and_asteroid_collision(struct bullet b, struct asteroid a)
{
	return (b.x >= a.bound_left && b.x <= a.bound_right &&
		b.y >= a.bound_up && b.y <= a.bound_down);
}

int ship_and_asteroid_collision(struct spaceship ship, struct asteroid a)
{
	return (ship.bound_left <= a.bound_right && ship.bound_right >= a.bound_left && 
		ship.bound_up <= a.bound_down && ship.bound_down >= a.bound_up);
}

int main(int argc, char const *argv[])
{
	const int FPS = 60;
	const int MAX_BULLETS = 10;
	const int MAX_ASTEROIDS = 10;
	const int MAX_EXPLOSIONS = 10;
	srand(time(NULL));
	int done = 0;
	int redraw = 1;

	if(!al_init())
	{
		al_show_native_message_box(NULL, "Error", "Error", 
			"Could not initialize Allegro 5.", 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	ALLEGRO_DISPLAY *display = al_create_display(screen_width, screen_height);
	if(!display)
	{
		al_show_native_message_box(NULL, "Error", "Error", 
			"Could not create display.", 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	if(!event_queue)
	{
		al_show_native_message_box(display, "Error", "Error", 
			"Could not create event queue.", 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);
	if(!timer)
	{
		al_show_native_message_box(display, "Error", "Error", 
			"Could not create timer.", 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	if(!al_install_keyboard())
	{
		al_show_native_message_box(display, "Error", "Error", 
			"Could not install keyboard.", 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	if(!al_install_mouse())
	{
		al_show_native_message_box(display, "Error", "Error", 
			"Could not install mouse.", 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	if(!al_init_image_addon())
	{
		al_show_native_message_box(display, "Error", "Error", 
			"Could not initialize image addon.", 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	if(!al_init_primitives_addon())
	{
		al_show_native_message_box(display, "Error", "Error", 
			"Could not initialize primitives addon.", 0, ALLEGRO_MESSAGEBOX_ERROR);
	}

	al_init_font_addon(); // for whatever reason this function is void returning

	if(!al_init_ttf_addon())
	{
		al_show_native_message_box(display, "Error", "Error", 
			"Could not initialize ttf addon.", 0, ALLEGRO_MESSAGEBOX_ERROR);
	}
	
	al_hide_mouse_cursor(display);

	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	ALLEGRO_FONT *font18 = al_load_font("Arial.ttf", 18, 0);

	int prev_x = screen_width, prev_y = screen_height;
	int fps_counter = 0;
	int fps_counter2 = 0;
	int i, j, k;

	struct spaceship ship;
	init_ship(&ship);

	struct bullet bullets[MAX_BULLETS];
	for(i = 0; i < MAX_BULLETS; i++)
	{
		init_bullet(&bullets[i]);
	}

	struct asteroid asteroids[MAX_ASTEROIDS];
	for(i = 0; i < MAX_ASTEROIDS; i++)
	{
		init_asteroid(&asteroids[i]);
	}

	struct explosion explosions[MAX_EXPLOSIONS];
	for(i = 0; i < MAX_EXPLOSIONS; i++)
	{
		init_explosion(&explosions[i]);
	}

	al_start_timer(timer);

	while(!done)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);

		if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = 1;
		}
		if(event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(event.keyboard.keycode)
			{
				case ALLEGRO_KEY_Q: 
					done = 1;
					break;
				case ALLEGRO_KEY_ESCAPE:
					done = 1;
					break;
			}
		}
		if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if(event.mouse.button & 1)
			{
				for(i = 0; i < MAX_BULLETS; i++)
				{
					if(!bullets[i].live)
					{
						fire_bullet(&bullets[i], ship);
						break;
					}
				}
			}
		}
		if(event.type == ALLEGRO_EVENT_MOUSE_AXES ||
              event.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY)
		{
			set_ship_coordinates(&ship, event.mouse.x, event.mouse.y);
		}
		if(event.type == ALLEGRO_EVENT_TIMER)
		{	
			if(ship.x > prev_x)
			{	
				ship.sprite.dir_horizontal = RIGHT;
			}
			else if(ship.x == prev_x)
			{
				ship.sprite.dir_horizontal = CENTER;
			}
			else if(ship.x < prev_x) 
			{
				ship.sprite.dir_horizontal = LEFT;
			}

			if(ship.y > prev_y)
			{
				ship.sprite.dir_vertical = BACK;
			}
			else if(ship.y == prev_y)
			{
				ship.sprite.dir_vertical = NEUTRAL;
			}
			else if(ship.y < prev_y)
			{
				ship.sprite.dir_vertical = FORWARD;
			}

			if(++fps_counter >= FPS / 5)
			{
				fps_counter = 0;
				prev_x = ship.x;
				prev_y = ship.y;	
			}

			if(++fps_counter2 >= 2 * FPS)
			{
				for(i = 0; i < MAX_ASTEROIDS; i++)
				{
					if(!asteroids[i].live)
					{
						start_asteroid(&asteroids[i]);
						break;
					}
				}
				fps_counter2 = 0;
			}

			for(i = 0; i < MAX_BULLETS; i++)
			{
				if(bullets[i].live)
				{
					update_bullet(&bullets[i]);
				}
			}

			for(i = 0; i < MAX_ASTEROIDS; i++)
			{
				if(asteroids[i].live)
				{
					update_asteroid(&asteroids[i], &ship);
				}
			}

			for(i = 0; i < MAX_EXPLOSIONS; i++)
			{
				if(explosions[i].live)
				{
					update_explosion(&explosions[i]);
				}
			}

			update_ship_boundaries(&ship);

			for(i = 0; i < MAX_BULLETS; i++)
			{
				if(bullets[i].live)
				{
					for(j = 0; j < MAX_ASTEROIDS; j++)
					{
						if(asteroids[j].live)
						{
							if(bullet_and_asteroid_collision(bullets[i], asteroids[j]))
							{
								bullets[i].live = 0;
								asteroids[j].live = 0;
								ship.score += 20;
								for(k = 0; k < MAX_EXPLOSIONS; k++)
								{
									if(!explosions[k].live)
									{
										start_explosion(&explosions[k], bullets[i].x, bullets[i].y);
										break;
									}
								}
							}
						}
					}
				}
			}

			for(i = 0; i < MAX_ASTEROIDS; i++)
			{
				if(asteroids[i].live)
				{
					if(ship_and_asteroid_collision(ship, asteroids[i]))
					{
						asteroids[i].live = 0;
						for(k = 0; k < MAX_EXPLOSIONS; k++)
						{
							if(!explosions[k].live)
							{
								start_explosion(&explosions[k], ship.x, ship.y);
								break;
							}
						}
						
						ship.lives--;
					}
				}
			}

			if(!ship.lives)
			{
				done = true;
			}

			redraw = 1;
		}

		if(redraw)
		{
			redraw = 0;
			draw_ship_sprite(ship.sprite, ship.x, ship.y);
			for(i = 0; i < MAX_BULLETS; i++)
			{
				if(bullets[i].live)
				{
					draw_bullet(bullets[i]);
				}
			}
			for(i = 0; i < MAX_ASTEROIDS; i++)
			{
				if(asteroids[i].live)
				{
					draw_asteroid(asteroids[i]);
				}
			}
			for(i = 0; i < MAX_EXPLOSIONS; i++)
			{
				if(explosions[i].live)
				{
					draw_explosion(explosions[i]);
				}
			}
			al_draw_textf(font18, al_map_rgb(255, 255, 255), 50, 5, 0, 
				"Score: %d ", ship.score); // I have no idea why it doesn't print the S...
			al_draw_textf(font18, al_map_rgb(255, 255, 255), 50, 25, 0, 
				"Lives: %d", ship.lives);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	for(i = 0; i < MAX_ASTEROIDS; i++)
	{
		destroy_asteroid(&asteroids[i]);
	}
	for(i = 0; i < MAX_EXPLOSIONS; i++)
	{
		destroy_explosion(&explosions[i]);
	}
	destroy_sprite(&ship.sprite);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_font(font18);

	return 0;
}
