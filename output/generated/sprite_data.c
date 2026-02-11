#include <stdbool.h>
#include <stdlib.h>
#include "../runtime/motion.h"
#include "../sprite_data.h"

double scratch_motion_SpriteX[] = { 0.0, 0.000000 };
double scratch_motion_SpriteY[] = { 0.0, 0.000000 };
double scratch_motion_SpriteDirection[] = { 0.0, 0.000000 };
bool scratch_looks_hidden[] = { false, false };
int scratch_motion_SpriteRotStyle[] = { RotStyle_allaround, RotStyle_allaround };
int scratch_looks_CostumeIndex[] = { 0, 0 };
int scratch_looks_CostumeCounts[] = { 1, 1 };
char* scratch_looks_CostumeNames[SPRITES][MAX_COSTUME_LENGTH] = {
	{ "backdrop1" },
	{ "costume1" }
 };
char* scratch_looks_CostumeFiles[SPRITES][MAX_COSTUME_LENGTH] = {
	{ "cd21514d0531fdffb22204e0ec5ed84a.svg" },
	{ "927d672925e7b99f7813735c484c6922.svg" }
 };
double scratch_looks_RotationCentreX[SPRITES][MAX_COSTUME_LENGTH] = {
	{ 240.000000 },
	{ 30.749379 }
 };
double scratch_looks_RotationCentreY[SPRITES][MAX_COSTUME_LENGTH] = {
	{ 180.000000 },
	{ 58.864768 }
 };
int scratch_sound_SoundEffectCounts[] = { 0, 0 };
char* scratch_sound_SoundEffectNames[SPRITES][MAX_SOUND_LENGTH] = {
	{ NULL },
	{ NULL }
 };
char* scratch_sound_SoundEffectFiles[SPRITES][MAX_SOUND_LENGTH] = {
	{ NULL },
	{ NULL }
 };
double scratch_motion_SpriteSize[] = { 100.0, 100.000000 };
double scratch_motion_SpriteWidth[SPRITES][MAX_COSTUME_LENGTH] = { {0.0}, {0.0} };
double scratch_motion_SpriteHeight[SPRITES][MAX_COSTUME_LENGTH] = { {0.0}, {0.0} };
double scratch_looks_effects_colour[] = { 0.0, 0.0 };
double scratch_looks_effects_fisheye[] = { 0.0, 0.0 };
double scratch_looks_effects_whirl[] = { 0.0, 0.0 };
double scratch_looks_effects_pixelate[] = { 0.0, 0.0 };
double scratch_looks_effects_mosaic[] = { 0.0, 0.0 };
double scratch_looks_effects_brightness[] = { 0.0, 0.0 };
double scratch_looks_effects_ghost[] = { 0.0, 0.0 };
