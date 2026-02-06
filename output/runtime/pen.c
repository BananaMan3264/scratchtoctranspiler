#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "scratch.h"

bool inited = false;

PenOperations ops;

bool PenDown;
double PenSize = 1;

int penColour = 0x0000ff;

extern int activeSprite;

extern double scratch_motion_SpriteX[];
extern double scratch_motion_SpriteY[];
extern double scratch_motion_SpriteDirection[];
extern double scratch_motion_SpriteSize[];
extern int scratch_looks_CostumeIndex[];
extern int scratch_motion_SpriteRotStyle[];

extern int scratch_motion_SpriteWidth[];
extern int scratch_motion_SpriteHeight[];

#define SX scratch_motion_SpriteX[activeSprite]
#define SY scratch_motion_SpriteY[activeSprite]
#define SD scratch_motion_SpriteDirection[activeSprite]
#define SS scratch_motion_SpriteSize[activeSprite]
#define SCI scratch_looks_CostumeIndex[activeSprite]
#define SR scratch_motion_SpriteRotStyle[activeSprite]

#define SW scratch_motion_SpriteWidth[activeSprite]
#define SH scratch_motion_SpriteHeight[activeSprite]

void initPen()
{
	if (!inited)
	{
		ops.data = malloc(sizeof(PenOperation) * 8); if (!ops.data) { printf("Malloc error!"); exit(-1); }
		ops.allocated_size = 8;
		ops.length = 0;

		inited = true;
	}
}

void resizeOps(int length)
{
	ops.allocated_size = length;
	void* temp = realloc(ops.data, ops.allocated_size * sizeof(PenOperation));
	if (!temp) { exit(-1); }
	ops.data = temp;
}

void addOpToOps(PenOperation data)
{
	initPen();

	if (ops.length + 1 > ops.allocated_size)
	{
		resizeOps(ops.allocated_size * 2);
	}
	ops.data[ops.length] = data;
	ops.length++;
}

void pen_clear() 
{
	initPen();
	free(ops.data);
	inited = false;
	initPen();
}

void pen_penDown() 
{
	PenDown = true;
}

void pen_penUp() 
{
	PenDown = false;
}

void pen_stamp() 
{
	stampData sd;
	sd.x = SX;
	sd.y = SY;
	sd.size = SS;
	sd.rotation = SD;
	sd.sprite_index = activeSprite;
	sd.costume_index = SCI;
	sd.width = SW;
	sd.height = SH;
	sd.rot_style = SR;

	PenOperation po;
	po.operation_type = Pen_Stamp;
	po.operation_data.stamp_data = sd;

	addOpToOps(po);
}

void penDrawLine(double x1, double y1, double x2, double y2) 
{
	lineData ld;
	ld.x1 = x1;
	ld.y1 = y1;
	ld.x2 = x2;
	ld.y2 = y2;
	ld.thickness = PenSize;
	ld.colour = penColour;

	PenOperation po;
	po.operation_type = Pen_Line;
	po.operation_data.line_data = ld;

	addOpToOps(po);
}

void pen_setPenSizeTo(ScratchValue size) 
{
	PenSize = ScratchVarGetDouble(size);
}

void pen_setPenColorToColor(ScratchValue color)
{
	penColour = ScratchVarGetDouble(color);
}