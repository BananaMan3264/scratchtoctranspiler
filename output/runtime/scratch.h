#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "types.h"
#include "renderer.h"

#pragma once

#define argument_reporter_string_number(a) a

ScratchValue ScratchSetDouble(double d);
ScratchValue ScratchSetBool(bool b);
ScratchValue ScratchSetString(char* s);
double ScratchVarGetDouble(ScratchValue var);
bool ScratchVarGetBool(ScratchValue var);
char* ScratchVarGetString(ScratchValue var);
ScratchValue sensing_timer();

#define FUNCTION_YIELD gc_enabled = false;  co_switch(scheduler); gc_enabled = true;
#define TRUE_YIELD co_switch(scheduler);
#define END_THREAD delete_thread = true; TRUE_YIELD