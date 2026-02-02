#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "scratch.h"
#include "operators.h"

// Note: in the actual Scratch implementation Max and Min can be flipped.
ScratchValue operator_random(ScratchValue min, ScratchValue max)
{ 
	double a = ScratchVarGetDouble(max);
	double b = ScratchVarGetDouble(min);

	if (a == (int)a && b == (int)b) // If both values are ints
	{
		int range = max(a, b) - min(a, b);

		return ScratchSetDouble(rand() % range + min(a, b));
	}
	else 
	{
		double range = max(a, b) - min(a, b);
		double val = (double)rand() / RAND_MAX;
		return ScratchSetDouble(val * range + min(a, b));
	}
}

ScratchValue operator_equals(ScratchValue a, ScratchValue b)
{
	switch (max(a.ScratchType,b.ScratchType)) 
	{
	ScratchType_Bool:
		return ScratchSetBool(strcmp(ScratchVarGetString(a), ScratchVarGetString(b)) == 0);
	ScratchType_Number:
		return ScratchSetBool(strcmp(ScratchVarGetString(a), ScratchVarGetString(b)) == 0);
	ScratchType_String:
		return ScratchSetBool(strcmp(ScratchVarGetString(a), ScratchVarGetString(b)) == 0);
	default:
		return ScratchSetBool(false);
	}
}

ScratchValue operator_join(ScratchValue a, ScratchValue b)
{
	char* A = ScratchVarGetString(a);
	char* B = ScratchVarGetString(b);

	char* join = malloc(strlen(A) + strlen(B) + 1); if (!join) { printf("Malloc error!"); exit(-1); }

	strcpy(join, A);
	strcat(join, B);

	return ScratchSetString(join);
}

ScratchValue operator_letter_of(ScratchValue index, ScratchValue string)
{
	char* str = ScratchVarGetString(string);
	int idx = floor(ScratchVarGetDouble(index)) - 1;
	if (idx < 0 || strlen(str) < idx) 
	{
		return ScratchSetString("");
	}
	char* out = malloc(2); if (!out) { printf("Malloc error!"); exit(-1); }
	out[1] = '\0';
	out[0] = str[idx];
	return ScratchSetString(out);
}