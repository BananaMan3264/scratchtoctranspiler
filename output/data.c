#include "runtime/motion.h"

double scratch_motion_SpriteX[] = { 0.0, 0.0, 0.0 };
double scratch_motion_SpriteY[] = { 0.0, 0.0, 0.0 };
double scratch_motion_SpriteSize[] = { 100.0, 100.0, 100.0 };
// These are stored in radians
double scratch_motion_SpriteDirection[] = { 0.0, 0.0, 0.0 };

int scratch_motion_SpriteRotStyle[] = { RotStyle_allaround, RotStyle_allaround, RotStyle_allaround };

int activeSprite = 0;