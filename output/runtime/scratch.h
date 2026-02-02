#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "renderer.h"

#pragma once

#define argument_reporter_string_number(a) a

#define data_setvariableto(a,b) b = a
#define data_changevariableby(a,b) b = operator_add(a,b)

ScratchValue ScratchSetDouble(double d);
ScratchValue ScratchSetBool(bool b);
ScratchValue ScratchSetString(char* s);
double ScratchVarGetDouble(ScratchValue var);
bool ScratchVarGetBool(ScratchValue var);
char* ScratchVarGetString(ScratchValue var);