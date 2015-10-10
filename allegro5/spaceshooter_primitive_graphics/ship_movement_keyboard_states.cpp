#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

/*
 * Ok, by using the keyboard state the game loop and everything becomes
 * much more cleaner and simpler and neater 
 * BUT there's one big downside:
 * the ship can't move diagonally : (
 * */

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

int main()
{
	const int FPS = 60;
	const int number_of_bullets = 150;
	bool done = false;
	bool redraw = true;

	srand(time(NULL));
	
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

	SpaceShip ship;
	Bullet bullets[number_of_bullets];

	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	al_init_primitives_addon();
	al_install_keyboard();

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	ALLEGRO_KEYBOARD_STATE key_state;

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
		
		if ( events.type == ALLEGRO_EVENT_KEY_DOWN )
		{
			if (events.keyboard.keycode == ALLEGRO_KEY_ESCAPE )
				done = true;
		}

		if(events.type == ALLEGRO_EVENT_TIMER)
        {
            al_get_keyboard_state(&key_state);
            if(al_key_down(&key_state, ALLEGRO_KEY_DOWN))
                ship.move_ship_down();
            else if(al_key_down(&key_state, ALLEGRO_KEY_UP))
                ship.move_ship_up();
            else if(al_key_down(&key_state, ALLEGRO_KEY_RIGHT))
                ship.move_ship_right();
            else if(al_key_down(&key_state, ALLEGRO_KEY_LEFT))
                ship.move_ship_left();
            else if(al_key_down(&key_state, ALLEGRO_KEY_SPACE))
            {
				for ( i = 0; i < number_of_bullets; i++ )
				{
					if (!bullets[i].get_live())
					{
						bullets[i].fire_bullet(ship);
						break;
					}
				}
			}

			for ( i = 0; i < number_of_bullets; i++ )
			{
				if(bullets[i].get_live())
				{
					bullets[i].update_bullet();
				}
			}
 
                redraw = true;
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

			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}

	}
	
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_display(display);
	
	return 0;
}
