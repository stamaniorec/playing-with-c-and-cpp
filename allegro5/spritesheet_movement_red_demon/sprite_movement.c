#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>

const int screen_width = 640;	
const int screen_height = 480;

struct Sprite
{
	int x; 
	int y;
	int speed;
	int dir_row;

	int frame_count;
	int frame_delay;
	int cur_frame;
	int total_frames;

	ALLEGRO_BITMAP *image;
	int frame_width;
	int frame_height;
};

void init_sprite(struct Sprite *sprite)
{
	sprite->x = 0;	
	sprite->y = 0;
	sprite->speed = 5;
	sprite->dir_row = 0;

	sprite->frame_count = 0;
	sprite->frame_delay = 5;
	sprite->cur_frame = 0;
	sprite->total_frames = 4; 

	sprite->image = al_load_bitmap("097-Monster11.png");
	sprite->frame_width = 64;
	sprite->frame_height = 64;
}

void update_sprite(struct Sprite *sprite)
{
	if(++sprite->frame_count >= sprite->frame_delay)
	{
		if(++sprite->cur_frame >= sprite->total_frames)
		{
			sprite->cur_frame = 0;
		}
		sprite->frame_count = 0;
	}
}

void draw_sprite(struct Sprite sprite)
{
	al_draw_bitmap_region(sprite.image, sprite.cur_frame * sprite.frame_width, sprite.dir_row * sprite.frame_height, 
		sprite.frame_width, sprite.frame_height, sprite.x, sprite.y, 0);
}

int main(int argc, char const *argv[])
{
	const int FPS = 60;
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

	al_install_keyboard();
	al_install_mouse();

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	ALLEGRO_KEYBOARD_STATE keystate;

	al_init_image_addon();

	struct Sprite player;
	init_sprite(&player);

	int active_player = 0;

	al_start_timer(timer);

	while(!done)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);

		if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = 1;
		}
		else if(event.type == ALLEGRO_EVENT_TIMER)
		{	
			active_player = 1;

			al_get_keyboard_state(&keystate);
			if(al_key_down(&keystate, ALLEGRO_KEY_UP)) 
			{
				player.y -= player.speed;
				player.dir_row = 3;
			}				
			else if(al_key_down(&keystate, ALLEGRO_KEY_DOWN))
			{
				player.y += player.speed;
				player.dir_row = 0;
			}
			else if(al_key_down(&keystate, ALLEGRO_KEY_LEFT))
			{
				player.x -= player.speed;
				player.dir_row = 1;
			}	
			else if(al_key_down(&keystate, ALLEGRO_KEY_RIGHT))
			{
				player.x += player.speed;
				player.dir_row = 2;
			}			
			else
			{
				active_player = 0;
			}
			
			if(active_player)
				update_sprite(&player);

			redraw = true;
		}

		if(redraw)
		{
			redraw = false;

			draw_sprite(player);		
	
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);

	return 0;
}
