#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "scratch.h"
#include "operators.h"

extern bool keysdown[512];

ScratchValue sensing_keypressed(int key)
{
	if (key == -1000)
	{
		for (int i = 0; i < 512; i++) 
		{
			if (keysdown[i]) 
			{
				return ScratchSetBool(true);
			}
		}
		return ScratchSetBool(false);
	}
	else
	{
		return ScratchSetBool(keysdown[key]);
	}
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

ScratchValue sensing_timer()
{
	return ScratchSetDouble(clock() / (double)CLOCKS_PER_SEC);
}