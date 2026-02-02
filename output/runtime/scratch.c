#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "scratch.h"

ScratchValue ScratchSetDouble(double d) 
{
	ScratchValue v;
	v.ScratchType = ScratchType_Number;
	v.data.Number = d;
	return v;
}

ScratchValue ScratchSetBool(bool b)
{
	ScratchValue v;
	v.ScratchType = ScratchType_Bool;
	v.data.Bool = b;
	return v;
}

ScratchValue ScratchSetString(char* s)
{
	ScratchValue v;
	v.ScratchType = ScratchType_String;
	v.data.String = s;
	return v;
}

double ScratchVarGetDouble(ScratchValue var)
{
	char* end;
	switch (var.ScratchType)
	{
	case ScratchType_Number:
		return var.data.Number;
	case ScratchType_Bool:
		return var.data.Bool;
	case ScratchType_String:
		return strtod(var.data.String, &end);
	default:
		return 0;
	}
}

bool ScratchVarGetBool(ScratchValue var) 
{
	switch (var.ScratchType)
	{
	case ScratchType_Number:
		return var.data.Number == 0;
	case ScratchType_Bool:
		return var.data.Bool;
	case ScratchType_String:
		if (var.data.String[0] == '\0' || (var.data.String[0] == '0' && var.data.String[1] == '\0')) 
		{
			return false;
		}
		return true;
	default:
		return false;
	}
}

char* ScratchVarGetString(ScratchValue var) 
{
	switch (var.ScratchType)
	{
	case ScratchType_Number:
		char* buf = malloc(20); if (!buf) { printf("Malloc error!"); exit(-1); }
		snprintf(buf, 20, "%.20f", var.data.Number);
		return buf;
	case ScratchType_Bool:
		return var.data.Bool ? "true" : "false";
	case ScratchType_String:
		return var.data.String;
	default:
		return "";
	}
}