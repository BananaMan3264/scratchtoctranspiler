#include<SDL2/SDL.h>
#include<stdbool.h>
#include"renderer.h"
#include"output.h"
#include"types.h"

SDL_Renderer* renderer;

bool keysdown[SDL_NUM_SCANCODES];

Uint32 lastTime = 0;
int frames = 0;
float fps = 0.0f;

long long wait_duration = (1 / (double)FPS_CAP) * 1000;
long long last_time = 0;

void update_fps() {
	Uint32 current = SDL_GetTicks();
	frames++;

	if (current > lastTime + 1000) {  // 1 second passed
		fps = frames * 1000.0f / (current - lastTime);
		printf("FPS: %f\n", fps);
		lastTime = current;
		frames = 0;
	}
}

void Yield()
{
	if (FPS_CAP != -1)
	{
		while (SDL_GetTicks() < last_time + wait_duration)
		{

		}
	}

	last_time += wait_duration;

	update_fps();

	SDL_Event e;

	while (SDL_PollEvent(&e)) {
		switch (e.type)
		{
		case SDL_QUIT:
			exit(-1);
		case SDL_KEYDOWN:
			keysdown[e.key.keysym.scancode] = true;
			break;
		case SDL_KEYUP:
			keysdown[e.key.keysym.scancode] = false;
			break;
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

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");

	SDL_Window* window = SDL_CreateWindow(
		"Scratch",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
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
		SDL_RENDERER_ACCELERATED
	);

	if (!renderer)
	{
		printf("Unable to initialise SDL renderer: %s", SDL_GetError());
		exit(-1);
	}

	initRenderer();
	Init();
	Start();

	while (1) 
	{
		Yield();
	}
}