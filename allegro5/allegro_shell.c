#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

const int screen_width = 640;	
const int screen_height = 480;

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

			}				
			else if(al_key_down(&keystate, ALLEGRO_KEY_DOWN))
			{

			}
			else if(al_key_down(&keystate, ALLEGRO_KEY_LEFT))
			{

			}	
			else if(al_key_down(&keystate, ALLEGRO_KEY_RIGHT))
			{

			}			

			// updates

			redraw = true;
		}
		else if(event.type == ALLEGRO_EVENT_MOUSE_AXES)
		{

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
	
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);

	return 0;
}
