#include<SDL2/SDL.h>
#include<stdbool.h>
#include"renderer.h"
#include"output.h"

SDL_Renderer* renderer;

void Yield()
{
	SDL_Event e;

	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			exit(-1);
		}
	}

	draw();

	SDL_RenderPresent(renderer);
}

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		printf("Unable to initialise SDL: %s", SDL_GetError());
		exit(-1);
	}

	SDL_Window* window = SDL_CreateWindow(
		"Scratch",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		480,
		360,
		SDL_WINDOW_SHOWN
	);

	if (!window) 
	{
		printf("Unable to initialise SDL window: %s", SDL_GetError());
		exit(-1);
	}

	renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (!renderer)
	{
		printf("Unable to initialise SDL renderer: %s", SDL_GetError());
		exit(-1);
	}

	Init();
	Start();

	while (1) 
	{
		Yield();
	}
}