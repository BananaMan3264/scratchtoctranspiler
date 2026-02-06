#include <stdbool.h>
#include <stdio.h>

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

typedef struct ScratchList 
{
	ScratchValue* data;
	size_t allocated_size;
	size_t length;
} ScratchList;

typedef struct lineData 
{
	double x1;
	double y1;
	double x2;
	double y2;
	double thickness;
	int colour;
} lineData;

typedef struct stampData 
{
	int sprite_index;
	int costume_index;
	double size;
	double rotation;
	double x;
	double y;
	double width;
	double height;
	int rot_style;
} stampData;

typedef union penOperationData
{
	stampData stamp_data;
	lineData line_data;
} penOperationData;

typedef struct PenOperation
{
	int operation_type;
	penOperationData operation_data;
} PenOperation;

typedef struct PenOperations
{
	PenOperation* data;
	size_t allocated_size;
	size_t length;
} PenOperations;

enum PenOperationType 
{
	Pen_Line,
	Pen_Stamp
};

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

#define FPS_CAP 30