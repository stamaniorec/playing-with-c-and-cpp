#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

const int screen_width = 640;	
const int screen_height = 480;

class Ball
{
	private:
		int x;
		int y;
		int radius;
		int speed_x;
		int speed_y;
	public:
		Ball() : x(50), y(50), radius(10), speed_x(3), speed_y(3){};
		void move_ball()
		{
			x += speed_x;
			y += speed_y;

			if(y >= screen_height - radius || y <= radius)
			{
				speed_y *= -1;
			}
		}
		void draw_ball()
		{
			al_draw_circle(x, y, radius, al_map_rgb(255, 255, 255), 2);
		}
		int get_x() { return x; }
		int get_y() { return y; }
		int get_radius() { return radius; }
		int get_speed_x() { return speed_x; }
		void change_direction_x() { speed_x *= -1; }
};

class Pad
{
	protected: 
		int x;
		int y;
		int height;
		int width;
		float speed;
		Pad()
		{
			height = 70;
			width = 15;
			y = screen_height/2 - height / 2;
			speed = 3;		
		}
	public: 
		void move_pad_up()
		{
			if(y >= 5)
			{
				y -= speed;
			}
		}
		void move_pad_down()
		{
			if(y <= screen_height - 5 - height)
			{
				y += speed;
			} 
		}
		virtual void draw_pad()
		{
			al_draw_rectangle(x, y, x+width, y+height, al_map_rgb(255, 255, 255), 0);
		}
		int get_x() { return x; }
		int get_y() { return y; }
		int get_height() { return height; }
		int get_width() { return width; }
		void set_speed(int speed) { this->speed = speed; }
};

class Enemy_Pad : public Pad
{
	private: 
		int target_y;
	public: 
		Enemy_Pad(Ball ball) : Pad()
		{
			target_y = target_y_on_reaching_end(ball);
			x = screen_width - 10 - width;
		}
		void set_target_y(int y)
		{
			target_y = y;
		}
		void collision(Ball &ball)
		{
			if(ball.get_x() + ball.get_radius() >= x)
			{
				if(ball.get_y() + ball.get_radius() > y &&
					ball.get_y() - ball.get_radius() < y + height)
				{
					ball.change_direction_x();
				}
			}
		}
		// # of iterations (timer ticks) until the ball hits the width
		/*int number_of_iterations(Ball ball)
		{
			int cur_x = ball.get_x();
			int num_iterations = 0;
			std::cout << "one" << std::endl;
			while(cur_x <= screen_width - ball.get_radius())
			{
				cur_x += ball.get_speed_x();
				++num_iterations;
			}
			return num_iterations;
		}*/
		// working with local copy
		int target_y_on_reaching_end(Ball ball)
		{
			while(ball.get_x() + ball.get_radius() <= screen_width - height/2)
			{
				ball.move_ball();
			}
			return ball.get_y();
		}
		void move_enemy_pad()
		{
				if(speed > 0)
				{
					if(target_y >= y + height/2)
					{
						y += speed;
					}
				}
				else if(speed < 0)
				{
					if(target_y <= y + height/2)
					{
						y += speed;
					}
				}
		}
		void draw_pad()
		{
			al_draw_rectangle(x, y, x+width, y+height, al_map_rgb(255, 255, 255), 0);
		}
};

class Player_Pad : public Pad
{
	public:
		Player_Pad() : Pad()
		{
			x = 10;	
		}
		void collision(Ball &ball, Enemy_Pad &pad)
		{
			if(ball.get_x() - ball.get_radius() <= x + width)
			{
				if(ball.get_y() + ball.get_radius() >= y &&
					ball.get_y() - ball.get_radius() <= y + height)
				{
					ball.change_direction_x();
					if(pad.target_y_on_reaching_end(ball) < pad.get_y())
					{					
						pad.set_speed(-3);
					}
					else if(pad.target_y_on_reaching_end(ball) > pad.get_y() + pad.get_height())
					{
						pad.set_speed(3);
					}
					else
					{
						pad.set_speed(0);
					}
					pad.set_target_y(pad.target_y_on_reaching_end(ball));
				}
			}
		}
		bool has_game_finished(Ball ball)
		{
			return ball.get_x() - ball.get_radius() <= ball.get_radius() || //x + width || 
				ball.get_x() + ball.get_radius() > screen_width - width - 5;// ball.get_radius();
		}
};

int main(int argc, char const *argv[])
{
	const int FPS = 60;
	bool done = false;
	bool redraw = true;

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

	al_init_font_addon(); // for whatever reason this function is void returning

	if(!al_init_ttf_addon())
	{
		al_show_native_message_box(display, "Error", "Error", 
			"Could not initialize ttf addon.", 0, ALLEGRO_MESSAGEBOX_ERROR);
	}

	al_install_keyboard();

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_init_primitives_addon();

	ALLEGRO_KEYBOARD_STATE keystate;

	Ball ball;
	Player_Pad p_pad;
	Enemy_Pad e_pad(ball);

	al_start_timer(timer);

	while(!done)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);

		if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = 1;
		}
		if(event.type == ALLEGRO_EVENT_TIMER)
		{	
			ball.move_ball();

			al_get_keyboard_state(&keystate);
			if(al_key_down(&keystate, ALLEGRO_KEY_UP)) 
				p_pad.move_pad_up();
			else if(al_key_down(&keystate, ALLEGRO_KEY_DOWN))
				p_pad.move_pad_down();

			e_pad.move_enemy_pad();

			if(p_pad.has_game_finished(ball))
				done = true;

			p_pad.collision(ball, e_pad);
			e_pad.collision(ball);

			redraw = true;
		}

		if(redraw)
		{
			redraw = false;

			ball.draw_ball();
			p_pad.draw_pad();
			e_pad.draw_pad();			
	
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);

	return 0;
}
