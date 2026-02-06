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