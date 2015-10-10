#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>

struct bouncing_name 
{
	int x; 
	int y;
	int speed;
	int traveled_y_down;
	int traveled_y_up;
	char name[255];

	// constants 
	int speed_down;
	int speed_up;
	int speed_right;
	int go_down;
	int go_up; 
	int delay;
	int delay_counter;

	ALLEGRO_FONT *font18;
};

void init_bouncing_name(struct bouncing_name *name)
{
	// constants
	// order reversed because name->speed = name->speed_down which would be uninitialized
	name->speed_down = 100;
	name->speed_up = 4;
	name->speed_right = 7;
	name->go_down = 75;	
	name->go_up = 20;
	name->delay = 5;
	name->delay_counter = 0;

	name->x = 30;
	name->y = 30;
	name->speed = name->speed_down;
	name->traveled_y_down = 0;
	name->traveled_y_up = 0;
	name->name[0] = '\0';

	name->font18 = al_load_font("Arial.ttf", 18, 0);
}

void update_bouncing_name(struct bouncing_name *name)
{
	if(++name->delay_counter >= name->delay)
	{
		name->delay_counter = 0;
		if(name->speed == name->speed_down)
		{
			name->y += name->speed;
			name->traveled_y_down += name->speed;
		
			if(name->traveled_y_down >= name->go_down)
			{
				name->speed = name->speed_up;
				name->traveled_y_down = 0;
			}
		}
		else if(name->speed == name->speed_up)
		{
			name->y -= name->speed;
			name->traveled_y_up += name->speed;

			name->x += name->speed_right;

			if(name->traveled_y_up >= name->go_up)
			{	
				name->speed = name->speed_down;
				name->traveled_y_up = 0;
			}
		}
	}
}

void draw_bouncing_name(struct bouncing_name name)
{
	//al_draw_circle(name.x, name.y, 10, al_map_rgb(255, 255, 255), 3);
	al_draw_textf(name.font18, al_map_rgb(255, 255, 255), name.x, name.y, 0, "%s", name.name);
}

void destroy_bouncing_name(struct bouncing_name *name)
{
	al_destroy_font(name->font18);
}

int main(int argc, char const *argv[])
{
	const int screen_width = 640;	
	const int screen_height = 480;
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

	al_init_font_addon(); // for whatever reason this function is void returning

	if(!al_init_ttf_addon())
	{
		al_show_native_message_box(display, "Error", "Error", 
			"Could not initialize ttf addon.", 0, ALLEGRO_MESSAGEBOX_ERROR);
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_init_primitives_addon();

	struct bouncing_name name;
	init_bouncing_name(&name);
	printf("Please enter your name: ");
	scanf("%s", name.name);

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
			update_bouncing_name(&name);
			
			if(name.y > screen_height)
				done = 1;

			redraw = 1;
		}

		if(redraw)
		{
			redraw = 0;

			draw_bouncing_name(name);
			
			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
	}

	destroy_bouncing_name(&name);	
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);

	return 0;
}
