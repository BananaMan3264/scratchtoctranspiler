#include<SDL2/SDL.h>
#include<SDL2/SDL_mixer.h>
#include<SDL2/SDL_image.h>
#include<stdbool.h>
#include"renderer.h"
#include"../generated/schedule.h"
#include"types.h"
#include"sound.h"
#include"scratch.h"
#include"garbagecollector.h"

SDL_Renderer* renderer;

bool keysdown[SDL_NUM_SCANCODES];
int keysdownheld[SDL_NUM_SCANCODES];

ScratchValue mouseDown;

Uint32 lastTime = 0;
int frames = 0;
float fps = 0.0f;

long long wait_duration = (1 / (double)FPS_CAP) * 1000;
long long last_time = 0;

int gc_count = 0;

bool gc_enabled = true;

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

void Render()
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
			keysdownheld[e.key.keysym.scancode] = 0;
			break;
		case SDL_MOUSEBUTTONDOWN:
			mouseDown = ScratchSetBool(true);
			break;
		case SDL_MOUSEBUTTONUP:
			mouseDown = ScratchSetBool(false);
			break;
		}
	}

	for (int i = 0; i < SDL_NUM_SCANCODES; i++)
	{
		if (keysdown[i])
		{
			keysdownheld[i]++;
		}
	}

	draw();

	gc_count++;

	if (gc_count == 30)
	{
		gc_count = 0;
		if (gc_enabled)
		{
			gc_tick();
		}
	}

	SDL_RenderPresent(renderer);
}

int main()
{
	mouseDown = ScratchSetBool(false);

	gc_init();

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
	{
		printf("Unable to initialise SDL: %s", SDL_GetError());
		exit(-1);
	}

	IMG_Init(IMG_INIT_PNG);

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 8, 2048)) 
	{
		printf("Unable to initialise audio.");
		exit(-1);
	}

	InitSounds();

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
	RunScheduler();
}