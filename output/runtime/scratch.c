#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "scratch.h"
#include "garbagecollector.h"

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
		if (var.data.String[0] == '#' && strlen(var.data.String) > 1) 
		{
			char* num = malloc(strlen(var.data.String) + 3); if (!num) { printf("Malloc error!"); exit(-1); }
			snprintf(num, strlen(var.data.String) + 3, "0x%s", var.data.String + 1);
			double out = strtod(num, &end);
			free(num);
			return out;
		}
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
	char* buf;
	switch (var.ScratchType)
	{
	case ScratchType_Number:
		buf = gc_malloc(20); if (!buf) { printf("Malloc error!"); exit(-1); }
		snprintf(buf, 20, "%g", var.data.Number);
		return buf;
	case ScratchType_Bool:
		return var.data.Bool ? "true" : "false";
	case ScratchType_String:
		return var.data.String;
	default:
		return "";
	}
}

int iclamp(int idx, int min, int max) 
{ 
	if (max < idx)
	{ 
		return max; 
	} 
	if (min > idx)
	{ 
		return min; 
	} 
	return idx; 
}