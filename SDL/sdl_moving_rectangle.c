#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const int FPS = 60;
	const int TIMER = 1000 / FPS;
	enum KEYS { UP, DOWN, LEFT, RIGHT };
	int keys[] = { 0, 0, 0, 0 };

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Coudln't initialize SDL. Error: %s", SDL_GetError());
		return -1;
	}

	SDL_Window *window = SDL_CreateWindow("key movement", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	int start_time = 0;
	int x = 0, y = 0;
	int done = 0;
	int render = 1;

	while(!done)
	{
		SDL_Event event;

		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				done = 1;
			}
			else if(event.type == SDL_KEYDOWN)
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_RIGHT: 
						keys[RIGHT] = 1;
						break;
					case SDLK_LEFT: 
						keys[LEFT] = 1;
						break;
					case SDLK_UP: 
						keys[UP] = 1;
						break;
					case SDLK_DOWN:
						keys[DOWN] = 1;
						break;
				}
			}
			else if(event.type == SDL_KEYUP)
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_RIGHT: 
						keys[RIGHT] = 0;
						break;
					case SDLK_LEFT: 
						keys[LEFT] = 0;
						break;
					case SDLK_UP: 
						keys[UP] = 0;
						break;
					case SDLK_DOWN:
						keys[DOWN] = 0;
						break;
				}
			}

		}

		if(SDL_GetTicks() - start_time >= TIMER)
		{
			if(keys[RIGHT])
				x += 5;
			if(keys[LEFT])
				x -= 5;
			if(keys[UP])
				y -= 5;
			if(keys[DOWN])
				y += 5;

			start_time = SDL_GetTicks();

			render = 1;
		}


		if(render)
		{
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(renderer);
		
			SDL_Rect fill_rect = { x, y, 50, 50 };
			SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);		
			SDL_RenderFillRect(renderer, &fill_rect);
			
			SDL_RenderPresent(renderer);		
			render = 0;
		}		
		
	}

	return 0;
}
