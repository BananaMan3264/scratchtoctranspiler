#include <math.h>
#include <time.h>
#include "main.h"
#include "scratch.h"
#include "motion.h"
#include "types.h"

#pragma once

extern int activeSprite;

extern double scratch_motion_SpriteX[];
extern double scratch_motion_SpriteY[];
extern double scratch_motion_SpriteDirection[];
extern int scratch_motion_SpriteRotStyle[];

#define SX scratch_motion_SpriteX[activeSprite]
#define SY scratch_motion_SpriteY[activeSprite]
#define SD scratch_motion_SpriteDirection[activeSprite]
#define SR scratch_motion_SpriteRotStyle[activeSprite]

#define DEG_TO_RAD 0.0174532925199
#define RAD_TO_DEG 57.295779513082
#define HALF_PI    1.5707963267948

void motion_movesteps(ScratchValue steps) 
{
	double Steps = ScratchVarGetDouble(steps);
	SX += cos(SD) * Steps;
	SY += sin(SD) * Steps;
}

void motion_turnright(ScratchValue degrees) 
{
	SD += ScratchVarGetDouble(degrees) * DEG_TO_RAD;
}

void motion_turnleft(ScratchValue degrees)
{
	SD += ScratchVarGetDouble(degrees) * DEG_TO_RAD;
}

void motion_goto(ScratchValue x, ScratchValue y) 
{
	SX = ScratchVarGetDouble(x);
	SY = ScratchVarGetDouble(y);
}

void motion_glideto(ScratchValue secs, ScratchValue x, ScratchValue y) 
{
	double startTime = clock() / (double)CLOCKS_PER_SEC;
	double _secs = ScratchVarGetDouble(secs), _x = ScratchVarGetDouble(x), _y = ScratchVarGetDouble(y);
	double startx = SX, starty = SY;
	double time = (clock() / (double)CLOCKS_PER_SEC);
	while (time < startTime + _secs) 
	{
		double t = (time - startTime) / (_secs);

		double sx = _x * t + startx * (1 - t);
		double sy = _y * t + starty * (1 - t);

		SX = sx;
		SY = sy;

		Yield();
		time = (clock() / (double)CLOCKS_PER_SEC);
	}

	SX = _x;
	SY = _y;
}

void motion_pointtowards(ScratchValue dir)
{
	SD = ScratchVarGetDouble(dir) * DEG_TO_RAD;
}

void motion_changexby(ScratchValue x)
{
	SX += ScratchVarGetDouble(x);
}

void motion_changeyby(ScratchValue y)
{
	SY += ScratchVarGetDouble(y);
}

void motion_setx(ScratchValue x)
{
	SX = ScratchVarGetDouble(x);
}

void motion_sety(ScratchValue y)
{
	SY = ScratchVarGetDouble(y);
}

void motion_setrotationstyleYlaeafathbaraiagahat() 
{
	SR = RotStyle_leftright;
}

void motion_setrotationstyleYdaoanybatibaraoataaatae()
{
	SR = RotStyle_dontrotate;
}

void motion_setrotationstyleYaalalibaaaraoauanad()
{
	SR = RotStyle_allaround;
}

void motion_ifonedgebounce()
{
	//TODO: Fix this when real sprite bounds work

	//double distLeft    = max(0, (STAGE_WIDTH  / 2) + bounds.left  );
	//double distTop     = max(0, (STAGE_HEIGHT / 2) - bounds.top   );
	//double distRight   = max(0, (STAGE_WIDTH  / 2) - bounds.right );
	//double distBottom  = max(0, (STAGE_HEIGHT / 2) + bounds.bottom);

	double distLeft    = max(0, (STAGE_WIDTH  / 2)); 
	double distTop     = max(0, (STAGE_HEIGHT / 2));
	double distRight   = max(0, (STAGE_WIDTH  / 2)); 
	double distBottom  = max(0, (STAGE_HEIGHT / 2));

	int nearestEdge = 0;
	double minDist = distLeft + 1;
	if (distLeft < minDist) {
		minDist = distLeft;
		nearestEdge = 0; // left
	}
	if (distTop < minDist) {
		minDist = distTop;
		nearestEdge = 1; // top
	}
	if (distRight < minDist) {
		minDist = distRight;
		nearestEdge = 2; // right
	}
	if (distBottom < minDist) {
		minDist = distBottom;
		nearestEdge = 3; // bottom
	}
	if (minDist > 0) {
		return; // Not touching any edge.
	}
	// Point away from the nearest edge.
	double radians = HALF_PI - SD;
	double dx =  cos(radians);
	double dy = -sin(radians);
	switch (nearestEdge)
	{
	case 0:
			dx = max(0.2, fabs(dx));
			break;
	case 1:
			dy = max(0.2, fabs(dy));
			break;
	case 2:
			dx = 0 - max(0.2, fabs(dx));
			break;
	case 3:
			dy = 0 - max(0.2, fabs(dy));
			break;
	}
	SD = atan2(dy, dx) + HALF_PI;
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