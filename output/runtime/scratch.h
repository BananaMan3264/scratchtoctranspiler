#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "runtime/motion.h"
#include "runtime/types.h"

#pragma once

#define operator_add(a,b)		 ScratchSetDouble(ScratchVarGetDouble(a)+ScratchVarGetDouble(b))
#define operator_subtract(a,b)	 ScratchSetDouble(ScratchVarGetDouble(a)-ScratchVarGetDouble(b))
#define operator_multiply(a,b)	 ScratchSetDouble(ScratchVarGetDouble(a)*ScratchVarGetDouble(b))
#define operator_divide(a,b)	 ScratchSetDouble(ScratchVarGetDouble(a)/ScratchVarGetDouble(b))
#define operator_mod(a,b)		 ScratchSetDouble(fmod(ScratchVarGetDouble(a)%ScratchVarGetDouble(b))) // fmod
#define operator_round(a)		 ScratchSetDouble(round(ScratchVarGetDouble(a)))
#define operator_equals(a,b)	 a==b

int operator_random(int min, int max)
{
	return rand() % (max - min) + min;
}

#define argument_reporter_string_number(a) a

#define data_setvariableto(a,b) b = a
#define data_changevariableby(a,b) b = operator_add(a,b)

ScratchValue ScratchSetDouble(double d);
ScratchValue ScratchSetBool(bool b);
ScratchValue ScratchSetString(char* s);
double ScratchVarGetDouble(ScratchValue var);
bool ScratchVarGetBool(ScratchValue var);
char* ScratchVarGetString(ScratchValue var);