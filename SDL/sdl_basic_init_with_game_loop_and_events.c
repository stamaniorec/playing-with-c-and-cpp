#include <SDL2/SDL.h>

const int WIDTH = 500;
const int HEIGHT = 500;

SDL_Window *window = NULL;
SDL_Surface *screen_surface = NULL;

int running = 1;

// returns the image on SUCCESS and NULL on FAIL
SDL_Surface* load_image(const char* file_name)
{
	SDL_Surface *image = SDL_LoadBMP(file_name);

	if(image == NULL)
	{
		printf("Error loading image %s: %s\n", file_name, SDL_GetError());
		return NULL;
	}

	return image;	
}

// returns 1 on SUCCESS and 0 on FAIL
int init(const char* title, int screen_width, int screen_height)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		printf("Error loading SDL: %s\n", SDL_GetError());
		return 0;
	}

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		printf("Error creating window: %s\n", SDL_GetError());
		return 0;
	}

	screen_surface = SDL_GetWindowSurface(window);
	if(screen_surface == NULL)
	{
		printf("Error getting window surface: %s\n", SDL_GetError());
		return 0;
	}

	SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window);

	return 1; // sucess
}

void cleanup()
{
	SDL_DestroyWindow(window); // takes care of screen_surface too
	window = screen_surface = NULL;
	SDL_Quit();
}

void game_loop()
{
	SDL_Event event;

	while(running)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				running = 0;
			}
		}
	}
}

int main (int argc, char *argv[])
{
	if(!init("SDLProject", WIDTH, HEIGHT))
		return -1;
	
	game_loop();

	cleanup();

	return 0;
}
