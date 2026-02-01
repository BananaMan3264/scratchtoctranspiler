#pragma once

enum ScratchType
{
	ScratchType_Number,
	ScratchType_Bool,
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
	RotStyle_allaround,
};

#define STAGE_WIDTH 480
#define STAGE_HEIGHT 360