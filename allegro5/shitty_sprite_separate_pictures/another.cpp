#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <sstream>

const int screen_width = 640;
const int screen_height = 480;

struct Bitmap_Array
{
	ALLEGRO_BITMAP *image[8];
	int frame_width;
	int frame_height;
};

struct Individual_Sprite
{
	int cur_frame;
	int max_frame;
	int frame_delay;
	int frame_count;

	int frame_width;
	int frame_height;

	Bitmap_Array image;
};

void init_individual_sprite(Individual_Sprite &sprite, int size)
{
	sprite.cur_frame = 0;
	sprite.max_frame = size;
	sprite.frame_delay = 5;
	sprite.frame_count = 0;

	for(int i = 0; i < 8; i++)
	{
		std::stringstream str;
		str << i+1 << ".png";
		sprite.image.image[i] = al_load_bitmap(str.str().c_str());
		
		sprite.image.frame_width = al_get_bitmap_width(sprite.image.image[i]);
		sprite.image.frame_height = al_get_bitmap_height(sprite.image.image[i]);
	}
}

void update_individual_sprite(Individual_Sprite &sprite)
{
	if(++sprite.frame_count >= sprite.frame_delay)
	{
		if(++sprite.cur_frame >= sprite.max_frame)
		{
			sprite.cur_frame = 0;
		}
		sprite.frame_count = 0;
	} 
}

void draw_individual_sprite(Individual_Sprite sprite)
{
	al_draw_bitmap(sprite.image.image[sprite.cur_frame], 0, 0, 0);
}

int main()
{
	bool done = false, render = true, active = false;

	if(!al_init())
	{
		al_show_native_message_box(NULL, "Error", "Error", "Could not initialize Allegro 5.", 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	ALLEGRO_DISPLAY *display = al_create_display(screen_width, screen_height);

	if(!display)
	{
		al_show_native_message_box(NULL, "Error", "Error", "Could not create display.", 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	al_install_keyboard();
	al_init_image_addon();

	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_TIMER *timer = al_create_timer(1.0/60);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	
	Individual_Sprite sprite;

	init_individual_sprite(sprite, 8);

	ALLEGRO_KEYBOARD_STATE keystate;

	al_start_timer(timer);
	
	while(!done)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);

		if(event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if(event.keyboard.keycode == ALLEGRO_KEY_Q)
				done = true;
		}		

		if(event.type == ALLEGRO_EVENT_TIMER)
		{
			al_get_keyboard_state(&keystate);
			active = true;

			if(al_key_down(&keystate, ALLEGRO_KEY_DOWN))
			{
			}
			else if(al_key_down(&keystate, ALLEGRO_KEY_UP))
			{
			}
			else if(al_key_down(&keystate, ALLEGRO_KEY_RIGHT))
			{
			}
			else if(al_key_down(&keystate, ALLEGRO_KEY_LEFT))
			{
			}
			else 
			{
				active = false;
			}

			if(active)
			{

			}
			else
			{
				update_individual_sprite(sprite);	
			}
						
			render = true;
		}

		if(render)
		{
			draw_individual_sprite(sprite);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			render = false;			
		}
		
	}

	return 0;
}

/*
g++ -Wall allegro.cpp `pkg-config --cflags --libs allegro-5.0 allegro_acodec-5.0 allegro_audio-5.0 allegro_color-5.0 allegro_dialog-5.0 allegro_font-5.0 allegro_image-5.0 allegro_main-5.0 allegro_memfile-5.0 allegro_physfs-5.0 allegro_primitives-5.0 allegro_ttf-5.0`


*/
