#include <math.h>
#include <time.h>
#include "scratch.h"
#include "motion.h"
#include "types.h"
#include "pen.h"

#pragma once

extern bool PenDown;

extern int activeSprite;

extern double scratch_motion_SpriteX[];
extern double scratch_motion_SpriteY[];
extern double scratch_motion_SpriteWidth[];
extern double scratch_motion_SpriteHeight[];
extern double scratch_motion_SpriteDirection[];
extern int scratch_motion_SpriteRotStyle[];

#define SX scratch_motion_SpriteX[activeSprite]
#define SY scratch_motion_SpriteY[activeSprite]
#define SW scratch_motion_SpriteWidth[activeSprite]
#define SH scratch_motion_SpriteHeight[activeSprite]
#define SD scratch_motion_SpriteDirection[activeSprite]
#define SR scratch_motion_SpriteRotStyle[activeSprite]

#define DEG_TO_RAD 0.0174532925199
#define RAD_TO_DEG 57.295779513082
#define HALF_PI    1.5707963267948

void motion_movesteps(ScratchValue steps) 
{
	double Steps = ScratchVarGetDouble(steps);
	double nx = SX + cos(SD) * Steps, ny = SY + sin(SD) * Steps;
	if (PenDown)
	{
		penDrawLine(nx, ny, SX, SY);
	}
	SX = nx;
	SY = ny;
}

void motion_turnright(ScratchValue degrees) 
{
	SD += ScratchVarGetDouble(degrees) * DEG_TO_RAD;
}

void motion_turnleft(ScratchValue degrees)
{
	SD -= ScratchVarGetDouble(degrees) * DEG_TO_RAD;
}

void motion_goto(ScratchValue x, ScratchValue y) 
{
	double nx = ScratchVarGetDouble(x), ny = ScratchVarGetDouble(y);
	if (PenDown) 
	{
		penDrawLine(nx, ny, SX, SY);
	}
	SX = nx;
	SY = ny;
}

void motion_pointtowards(ScratchValue dir)
{
	SD = ScratchVarGetDouble(dir) * DEG_TO_RAD;
}

void motion_changexby(ScratchValue x)
{
	double nx = SX + ScratchVarGetDouble(x);
	if (PenDown)
	{
		penDrawLine(nx, SY, SX, SY);
	}
	SX = nx;
}

void motion_changeyby(ScratchValue y)
{
	double ny = SY + ScratchVarGetDouble(y);
	if (PenDown)
	{
		penDrawLine(SX, ny, SX, SY);
	}
	SY = ny;
}

void motion_setx(ScratchValue x)
{
	double nx = ScratchVarGetDouble(x);
	if (PenDown)
	{
		penDrawLine(nx, SY, SX, SY);
	}
	SX = nx;
}

void motion_sety(ScratchValue y)
{
	double ny = ScratchVarGetDouble(y);
	if (PenDown)
	{
		penDrawLine(SX, ny, SX, SY);
	}
	SY = ny;
}

void motion_setrotationstyleYalaeafathbaraiagahat() 
{
	SR = RotStyle_leftright;
}

void motion_setrotationstyleYadaoanybatibaraoataaatae()
{
	SR = RotStyle_dontrotate;
}

void motion_setrotationstyleYaaalalibaaaraoauanad()
{
	SR = RotStyle_allaround;
}

void motion_ifonedgebounce()
{
	//TODO: Fix this when real sprite bounds work
	//TODO: This doesn't work at all. Fix it completely

	float w = SW;
	float h = SH;

	double distLeft = max(0, (STAGE_WIDTH / 2) + (SX - w / 2));
	double distTop = max(0, (STAGE_HEIGHT / 2) - (SY + h / 2));
	double distRight = max(0, (STAGE_WIDTH / 2) - (SX + w / 2));
	double distBottom = max(0, (STAGE_HEIGHT / 2) + (SY - h / 2));
	// Find the nearest edge.
	char nearestEdge = ' ';
	double minDist = distBottom + 1;
	if (distLeft < minDist) {
		minDist = distLeft;
		nearestEdge = 'l';
	}
	if (distTop < minDist) {
		minDist = distTop;
		nearestEdge = 't';
	}
	if (distRight < minDist) {
		minDist = distRight;
		nearestEdge = 'r';
	}
	if (distBottom < minDist) {
		minDist = distBottom;
		nearestEdge = 'b';
	}
	if (minDist > 0) {
		return; // Not touching any edge.
	}
	// Point away from the nearest edge.
	double radians = HALF_PI - SD;
	double dx = cos(radians);
	double dy = sin(radians);
	if (nearestEdge == 'l') {
		dx = max(0.2, fabs(dx));
	}
	else if (nearestEdge == 't') {
		dy = max(0.2, fabs(dy));
	}
	else if (nearestEdge == 'r') {
		dx = 0 - max(0.2, fabs(dx));
	}
	else if (nearestEdge == 'b') {
		dy = 0 - max(0.2, fabs(dy));
	}
	double newDirection = atan2(dy, dx) + HALF_PI;
	SD = newDirection;
}

ScratchValue motion_xposition() 
{
	return ScratchSetDouble(SX);
}
ScratchValue motion_yposition()
{
	return ScratchSetDouble(SY);
}
ScratchValue motion_direction()
{
	return ScratchSetDouble(SD * RAD_TO_DEG);
}

ScratchValue motion_pointtowards_menuY_amaoauasaea_() 
{
	int mx, my;
	SDL_GetMouseState(&mx, &my);

	double m_x = (mx / (double)(WINDOW_WIDTH)-0.5) * (double)(STAGE_WIDTH), m_y = (-my / (double)(WINDOW_HEIGHT)+0.5) * (double)(STAGE_HEIGHT);

	return ScratchSetDouble(-atan2(m_y-SY,m_x-SX) * RAD_TO_DEG);
}