#include<stdbool.h>

#define max(a, b) (( (a) > (b) ) ? (a) : (b))
#define min(a, b) (( (a) < (b) ) ? (a) : (b))

#pragma once

enum ScratchType
{
	ScratchType_Bool,
	ScratchType_Number,
	ScratchType_String
};

typedef struct ScratchValue
{
	int ScratchType;
	union data
	{
		bool Bool;
		double Number;
		char* String;
	} data;
} ScratchValue;

enum RotationStyle
{
	RotStyle_leftright,
	RotStyle_dontrotate,
	RotStyle_allaround
};

#define WINDOW_WIDTH (480*2)
#define WINDOW_HEIGHT (360*2)

#define STAGE_WIDTH 480
#define STAGE_HEIGHT 360