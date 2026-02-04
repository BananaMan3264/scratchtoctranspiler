#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "scratch.h"
#include "operators.h"

extern bool keysdown[512];

ScratchValue sensing_keypressed(int key) 
{
	return ScratchSetBool(keysdown[key]);
}

ScratchValue sensing_mousex() 
{
	int mx, my;
	SDL_GetMouseState(&mx, &my);

	return ScratchSetDouble((mx / (double)(WINDOW_WIDTH) - 0.5) * (double)(STAGE_WIDTH));
}

ScratchValue sensing_mousey()
{
	int mx, my;
	SDL_GetMouseState(&mx, &my);

	return ScratchSetDouble(( - my / (double)(WINDOW_HEIGHT) + 0.5)  * (double)(STAGE_HEIGHT));
}