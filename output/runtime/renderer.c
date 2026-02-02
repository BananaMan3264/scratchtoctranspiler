#include<SDL2/SDL.h>
#include"types.h"

extern double scratch_motion_SpriteX[];
extern double scratch_motion_SpriteY[];
extern double scratch_motion_SpriteDirection[];
extern int scratch_motion_SpriteRotStyle[];

extern SDL_Renderer* renderer;

/*
According to my research the Scratch VM refreshed the screen:
- At each iteration of all repeat, repeat until, while, and forever loops
- After each 'glide' block
- After each say/think for seconds block
- After each  `play sound <> until done`, but only if an actual sound is provided
- After each `wait <> seconds`
- After each `Wait until`
- After each `ask <> and wait`
*/

void draw()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	SDL_Rect rect;

	int width = 20;
	int height = 20;

	rect.x = scratch_motion_SpriteX[1] + STAGE_WIDTH / 2 - width / 2;
	rect.y = scratch_motion_SpriteY[1] + STAGE_HEIGHT / 2 - height / 2;
	rect.w = width;
	rect.h = height;

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	SDL_RenderDrawRect(renderer, &rect);
}