#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

const int width = 800;
const int height = 600;

class SpaceShip
{
	private:
		int x;
		int y;
		int speed;
	public: 
		SpaceShip()
		{
			x = 30;
			y = height / 2;
			speed = 10;
		}

		void move_ship_up()
		{
			y -= speed;
			if ( y < 0 )
				y = 0;
		}

		void move_ship_down()
		{
			y += speed;
			if ( y >= height )
				y = height;
		}

		void move_ship_left()
		{
			x -= speed;
			if ( x < 0 )
				x = 0;
		}

		void move_ship_right()
		{
			x += speed;
			if ( x >= width )
				x = width;
		}

		void draw()
		{
			al_draw_filled_rectangle(x-10, y-5, x+40, y+10, al_map_rgb(208, 201, 201));		// ship body
			al_draw_line(x-6, y-3, x-6, y-10, al_map_rgb(250, 0, 0), 2.0);					// upper back line 1 
			al_draw_line(x-17, y-10, x-5, y-10, al_map_rgb(250, 0, 0), 2.0);				// upper back line 2
			al_draw_line(x-6, y+8, x-6, y+15, al_map_rgb(250, 0, 0), 2.0);					// lower back line 1
			al_draw_line(x-17, y+15, x-5, y+15, al_map_rgb(250, 0, 0), 2.0);				// lower back line 2
			al_draw_line(x-20, y+2.5, x-10, y+2.5, al_map_rgb(250, 0, 0), 2.0);				// middle back line
			al_draw_line(x+30, y-5, x+30, y+10, al_map_rgb(250, 0, 0), 2.0);				// front line 
			al_draw_line(x+30, y+2.5, x+40, y+2.5, al_map_rgb(250, 0, 0), 2.0);				// front middle line 
		}

		int get_x() { return x; }
		int get_y() { return y; }
};

class Bullet
{
	private:
		int x;
		int y;
		int speed;
		bool live;
	public:
		Bullet()
		{
			speed = 15;
			live = false;
		}
		
		void draw_bullet()
		{
			al_draw_filled_circle(x, y, 2, al_map_rgb(255, 255, 255));
		}

		void fire_bullet(SpaceShip ship)
		{
			x = ship.get_x() + 17;
			y = ship.get_y();
			live = true;
		}

		void update_bullet()
		{
			if ( live )
			{
				x += speed;
				if ( x >= width )
					live = false;
			}
			
		}

		bool get_live() { return live; }	
};

class Comet
{
	private:
		int x;
		int y;
		bool live;
		float speed;
		int radius;
	public:
		Comet()
		{
			x = 0; y = 0;
			live = false;
			radius = 25 + ( rand() % 50 );
			speed = (float)-2 / 25 * radius + 7;
		}

		void draw_comet()
		{
			/* I know, I know, not the best thing to do but well... */
			float coefficient1 = (float)radius / 5;
			float coefficient2 = (float)radius / 2;
			float coefficient3 = radius * 1.4;
			float coefficient4 = radius * 0.8;
			float coefficient5 = radius * 1.8;
			
			al_draw_filled_circle(x, y, radius, al_map_rgb(255, 0, 0));
			al_draw_filled_rectangle(x, y-radius+coefficient1, x+radius, y+radius-coefficient1, al_map_rgb(255, 0, 0));
			al_draw_filled_rectangle(x+radius, y-radius+coefficient2, x+coefficient3, y+radius-coefficient2, al_map_rgb(255, 0, 0));
			al_draw_filled_rectangle(x+coefficient3, y-radius+coefficient4, x+coefficient5, y+radius-coefficient4, al_map_rgb(255, 0, 0));
		}

		void create_comet()
		{
			if ( rand() % 100 == 0 )
			{
				x = width;
				y = 30 + rand() % (height - 60);
				live = true;
			}
			
		}

		void update_comet()
		{
			x -= speed;
			if ( x <= 0 )
			{
				live = false;
			}
		}

		bool get_live() { return live; }
};

int main()
{
	const int FPS = 60;
	const int number_of_bullets = 15;
	const int number_of_comets = 15;
	bool done = false;
	bool redraw = true;
	bool keys[5] = {false, false, false, false, false};
	enum { UP, DOWN, LEFT, RIGHT, SPACE };
	
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

	al_set_window_position(display, 200, 100);
    al_set_window_title(display, "Space Shooter");

	srand(time(NULL));

	SpaceShip ship;
	Bullet bullets[number_of_bullets];
	Comet comets[number_of_comets];

	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	al_init_primitives_addon();
	al_install_keyboard();

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	int i;

	while (!done)
	{
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);

		if ( events.type == ALLEGRO_EVENT_DISPLAY_CLOSE )
		{
			done = true;
		}
		else if ( events.type == ALLEGRO_EVENT_KEY_DOWN )
		{
			switch(events.keyboard.keycode)
			{
				case ALLEGRO_KEY_ESCAPE:
					done = true;
					break;
				case ALLEGRO_KEY_UP:
					keys[UP] = true;
					break;
				case ALLEGRO_KEY_DOWN:
					keys[DOWN] = true;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = true;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = true;
					break;
				case ALLEGRO_KEY_SPACE:
					keys[SPACE] = true;
					for ( i = 0; i < number_of_bullets; i++ )
					{
						if (!bullets[i].get_live())
						{
							bullets[i].fire_bullet(ship);
							break;
						}
					}
					break;
			}
		}
		else if ( events.type == ALLEGRO_EVENT_KEY_UP )
		{
			switch(events.keyboard.keycode)
			{
				case ALLEGRO_KEY_UP:
					keys[UP] = false;
					break;
				case ALLEGRO_KEY_DOWN:
					keys[DOWN] = false;
					break;
				case ALLEGRO_KEY_LEFT:
					keys[LEFT] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					keys[RIGHT] = false;
					break;
				case ALLEGRO_KEY_SPACE:
					break;
			}
		}
		else if ( events.type == ALLEGRO_EVENT_TIMER )
		{
			redraw = true;
			
			if(keys[UP])
				ship.move_ship_up();
			if(keys[DOWN])
				ship.move_ship_down();
			if(keys[LEFT])
				ship.move_ship_left();
			if(keys[RIGHT])
				ship.move_ship_right();
			if(keys[SPACE])
			{
				for ( i = 0; i < number_of_bullets; i++ )
				{
					bullets[i].update_bullet();
				}
			}

			for ( i = 0; i < number_of_comets; i++ )
			{
				if (!comets[i].get_live())
				{
					comets[i].create_comet();
					break;
				}
			}

			for ( i = 0; i < number_of_comets; i++ )
			{
				if ( comets[i].get_live() )
				{
					comets[i].update_comet();
				}
			}
			
		}

		if ( redraw && al_is_event_queue_empty(event_queue) )
		{
			redraw = false;

			ship.draw();
			for ( i = 0; i < number_of_bullets; i++ )
			{
				if (bullets[i].get_live())
				{
					bullets[i].draw_bullet();
				}
			}
			for ( i = 0; i < number_of_comets; i++ )
			{
				if (comets[i].get_live())
				{
					comets[i].draw_comet();
				}
			}

			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}

	}
	
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_display(display);
	
	return 0;
}
