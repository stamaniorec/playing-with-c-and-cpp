#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

const int screen_width = 640;	
const int screen_height = 480;

/*void camera_update(float *camera_pos, float x, float y, int width, int height)
{
	camera_pos[0] = -(screen_width/2) + x + width/2; 
	camera_pos[1] = -(screen_height/2) + y + height/2;

	if(camera_pos[0] < 0)
		camera_pos[0] = 0;
	if(camera_pos[1] < 0)
		camera_pos[1] = 0;
}*/

struct background
{
	int x; 
	int y;
	int speed;
	int dir;
	ALLEGRO_BITMAP *image;
	int width;
	int height;
};

void init_bg(struct background *bg)
{
	bg->x = 0;
	bg->y = 0;
	bg->speed = 2;
	bg->dir = -1;
	bg->image = al_load_bitmap("82316_1.png");
	bg->width = 640;	
	bg->height = 480;
}

void update_bg(struct background *bg)
{
	bg->x += bg->speed * bg->dir;
	if(bg->x + bg->width < 0)
		bg->x = 0;
}

void draw_bg(struct background bg)
{
	al_draw_bitmap(bg.image, bg.x, bg.y, 0);
	if(bg.x + bg.width < screen_width)
	{
		al_draw_bitmap(bg.image, bg.x + bg.width, bg.y, 0);
	}
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

	al_init_primitives_addon();
	al_init_image_addon();

	int x = 10, y = 10;
	int width = 100, height = 30;
	int speed = 5;

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	ALLEGRO_KEYBOARD_STATE keystate;

	//ALLEGRO_BITMAP *image = al_load_bitmap("82316_1.png");
	//float camera_position[] = { 0, 0 };
	//ALLEGRO_TRANSFORM camera;

	struct background bg;
	init_bg(&bg);

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
			al_get_keyboard_state(&keystate);
			if(al_key_down(&keystate, ALLEGRO_KEY_UP)) 
			{
				y -= speed;
			}				
			else if(al_key_down(&keystate, ALLEGRO_KEY_DOWN))
			{
				y += speed;
			}
			else if(al_key_down(&keystate, ALLEGRO_KEY_LEFT))
			{
				x -= speed;
			}	
			else if(al_key_down(&keystate, ALLEGRO_KEY_RIGHT))
			{
				x += speed;
			}			


			// updates
			update_bg(&bg);
			//camera_update(camera_position, x, y, width, height);
			//al_identity_transform(&camera);
			//al_translate_transform(&camera, -camera_position[0], -camera_position[1]);
			//al_use_transform(&camera); 

			redraw = true;
		}
		else if(event.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			//prev_x = x;
			//prev_y = y;
			x = event.mouse.x;
			y = event.mouse.y;
		}
		else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if(event.mouse.button & 1)
			{

			}
			else if(event.mouse.button & 2)
			{

			}
		}

		if(redraw)
		{
			redraw = false;

			// drawing 	
			//al_draw_bitmap(image, 0, 0, 0);
			draw_bg(bg);
			al_draw_rectangle(x, y, x+width, y+height, al_map_rgb(255, 0, 0), 2);	
	
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);

	return 0;
}
