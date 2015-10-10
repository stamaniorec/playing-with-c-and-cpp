#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>

const int screen_width = 640;
const int screen_height = 480;

enum Directions { DOWN, LEFT, RIGHT, UP };

struct Sprite
{
	double x;
	double y;
	double speed;
	
	int dir;		
	int animation_direction; // not really needed here but just to make the struct more general
	
	int cur_frame;
	int max_frame;
	int frame_delay;
	int frame_count;

	int frame_width;
	int frame_height;

	ALLEGRO_BITMAP *image;
};

void init_sprite(Sprite &player, ALLEGRO_BITMAP *image)
{
	player.x = 0;
	player.y = 10;
	player.speed = 5;
	
	player.dir = 0;
	player.animation_direction = 1;

	player.cur_frame = 0;
	player.max_frame = 12;
	player.frame_delay = 8;
	player.frame_count = 0;

	player.frame_width = 32;
	player.frame_height = 32;

	player.image = image;
}

void update_sprite(Sprite &player)
{
	if(++player.frame_count >= player.frame_delay)
	{
		player.cur_frame += player.animation_direction;
		if(player.cur_frame >= player.max_frame)
		{
			player.cur_frame = 0;
		}
		player.frame_count = 0;
	}
}

void draw_sprite(const Sprite &player)
{
	al_draw_bitmap_region(player.image, player.cur_frame * player.frame_width, player.dir * player.frame_height, player.frame_width, player.frame_height, player.x, player.y, 0);
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

	ALLEGRO_BITMAP *image = al_load_bitmap("blank_sprite.png");

	if(!image)
	{
		al_show_native_message_box(display, "Error", "Error", "Image problem", 0, ALLEGRO_MESSAGEBOX_ERROR);
	}

	Sprite player;
	init_sprite(player, image);

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
				player.y += player.speed;
				player.dir = DOWN;
			}
			else if(al_key_down(&keystate, ALLEGRO_KEY_UP))
			{
				player.y -= player.speed;
				player.dir = UP;
			}
			else if(al_key_down(&keystate, ALLEGRO_KEY_RIGHT))
			{
				player.x += player.speed;
				player.dir = RIGHT;
			}
			else if(al_key_down(&keystate, ALLEGRO_KEY_LEFT))
			{
				player.x -= player.speed;
				player.dir = LEFT;
			}
			else 
			{
				active = false;
			}

			if(active)
				update_sprite(player);
			
			render = true;
		}

		if(render)
		{
			draw_sprite(player);
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
