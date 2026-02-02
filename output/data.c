#include <stdbool.h>
#include "runtime/motion.h"
#include "data.h"

double scratch_motion_SpriteX[] = { 0.0, 0.0, 0.0 };
double scratch_motion_SpriteY[] = { 0.0, 0.0, 0.0 };
double scratch_motion_SpriteSize[] = { 100.0, 100.0, 100.0 };
// These are stored in radians
double scratch_motion_SpriteDirection[] = { 0.0, 0.0, 0.0 };

int scratch_motion_SpriteRotStyle[] = { RotStyle_allaround, RotStyle_allaround, RotStyle_allaround };

int scratch_looks_CostumeIndex[]  = { 0, 0, 0 };
int scratch_looks_CostumeCounts[] = { 3, 3, 3 };

char* scratch_looks_CostumeNames[SPRITES][MAX_COSTUME_LENGTH] =
{
	{ "abc", "abc1", "abc2"},
	{ "abc", "abc1", "abc2"},
	{ "abc", "abc1", "abc2"}
};

double scratch_looks_effects_colour[]     = { 0.0, 0.0, 0.0 };
double scratch_looks_effects_fisheye[]    = { 0.0, 0.0, 0.0 };
double scratch_looks_effects_whirl[]      = { 0.0, 0.0, 0.0 };
double scratch_looks_effects_pixelate[]   = { 0.0, 0.0, 0.0 };
double scratch_looks_effects_mosaic[]     = { 0.0, 0.0, 0.0 };
double scratch_looks_effects_brightness[] = { 0.0, 0.0, 0.0 };
double scratch_looks_effects_ghost[]      = { 0.0, 0.0, 0.0 };

bool scratch_looks_hidden[] = {true, false, true};

int activeSprite = 1;