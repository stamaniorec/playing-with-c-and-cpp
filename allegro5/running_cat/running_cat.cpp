#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>

const int screen_width = 1366;
const int screen_height = 768;

struct Sprite
{
	int frame_count;
	int current_frame;
	int frame_delay;
	int max_frames;

	int frame_width;
	int frame_height;

	int columns;
	
	ALLEGRO_BITMAP *image;
};

struct Cat
{
	double x;
	double y;
	double speed;

	Sprite cat_sprite; 
};

void sprite_init(Sprite &sprite)
{
	sprite.frame_count = 0;
	sprite.current_frame = 0;
	sprite.frame_delay = 3;
	sprite.max_frames = 8;

	sprite.frame_width = 512;
	sprite.frame_height = 256;

	sprite.columns = 2;

	sprite.image = al_load_bitmap("runningcat.png");
}

void init_object(Cat &cat)
{
	cat.x = 0;
	cat.y = 100;
	cat.speed = 15;

	sprite_init(cat.cat_sprite);
}

void sprite_update(Sprite &sprite)
{
	if(++sprite.frame_count >= sprite.frame_delay)
	{
		if(++sprite.current_frame >= sprite.max_frames)
		{
			sprite.current_frame = 0;
		}
		sprite.frame_count = 0;
	}
}

void update_object(Cat &cat)
{
	if(cat.x >= screen_width)
		cat.x = 0 - cat.cat_sprite.frame_width;
	else
		cat.x += cat.speed;
	sprite_update(cat.cat_sprite);
}

void draw_object(const Cat &cat)
{
	int fx = (cat.cat_sprite.current_frame % cat.cat_sprite.columns) * cat.cat_sprite.frame_width;
	int fy = (cat.cat_sprite.current_frame / cat.cat_sprite.columns) * cat.cat_sprite.frame_height;
	al_draw_bitmap_region(cat.cat_sprite.image, fx, fy, cat.cat_sprite.frame_width, cat.cat_sprite.frame_height, cat.x, cat.y, 0);
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
	
	Cat cat;
	init_object(cat);
	
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
				update_object(cat);
			}
						
			render = true;
		}

		if(render)
		{
			draw_object(cat);
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
