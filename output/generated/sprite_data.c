#include <stdbool.h>
#include <stdlib.h>
#include "../runtime/motion.h"
#include "../sprite_data.h"

double scratch_motion_SpriteX[] = { 0.0, 167.000000, -201.000000, 20.000000 };
double scratch_motion_SpriteY[] = { 0.0, 92.000000, -77.000000, 199.000000 };
double scratch_motion_SpriteDirection[] = { 0.0, 0.000000, 0.000000, 0.000000 };
bool scratch_looks_hidden[] = { false, false, false, false };
int scratch_motion_SpriteRotStyle[] = { RotStyle_allaround, RotStyle_allaround, RotStyle_allaround, RotStyle_allaround };
int scratch_looks_CostumeIndex[] = { 0, 0, 0, 0 };
int scratch_looks_CostumeCounts[] = { 1, 1, 1, 3 };
char* scratch_looks_CostumeNames[SPRITES][MAX_COSTUME_LENGTH] = {
	{ "backdrop1", NULL, NULL },
	{ "costume1", NULL, NULL },
	{ "Penguin-b", NULL, NULL },
	{ "balloon1-a", "balloon1-b", "balloon1-c" }
 };
char* scratch_looks_CostumeFiles[SPRITES][MAX_COSTUME_LENGTH] = {
	{ "cd21514d0531fdffb22204e0ec5ed84a.svg", NULL, NULL },
	{ "927d672925e7b99f7813735c484c6922.svg", NULL, NULL },
	{ "e2221bfd35df2eeffe45a37b75161611.svg", NULL, NULL },
	{ "d7974f9e15000c16222f94ee32d8227a.svg", "a2516ac2b8d7a348194908e630387ea9.svg", "63e5aea255610f9fdf0735e1e9a55a5c.svg" }
 };
double scratch_looks_RotationCentreX[SPRITES][MAX_COSTUME_LENGTH] = {
	{ 240.000000, 0.0, 0.0 },
	{ 30.749379, 0.0, 0.0 },
	{ 26.000000, 0.0, 0.0 },
	{ 32.000000, 31.000000, 31.000000 }
 };
double scratch_looks_RotationCentreY[SPRITES][MAX_COSTUME_LENGTH] = {
	{ 180.000000, 0.0, 0.0 },
	{ 58.864768, 0.0, 0.0 },
	{ 46.000000, 0.0, 0.0 },
	{ 94.000000, 94.000000, 94.000000 }
 };
int scratch_sound_SoundEffectCounts[] = { 0, 0, 0, 1 };
char* scratch_sound_SoundEffectNames[SPRITES][MAX_SOUND_LENGTH] = {
	{ NULL, NULL },
	{ NULL, NULL },
	{ NULL, NULL },
	{ "Pop", NULL }
 };
char* scratch_sound_SoundEffectFiles[SPRITES][MAX_SOUND_LENGTH] = {
	{ NULL, NULL },
	{ NULL, NULL },
	{ NULL, NULL },
	{ "83a9787d4cb6f3b7632b4ddfebf74367.wav", NULL }
 };
double scratch_motion_SpriteSize[] = { 100.0, 100.000000, 100.000000, 100.000000 };
double scratch_motion_SpriteWidth[SPRITES][MAX_COSTUME_LENGTH] = { {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0} };
double scratch_motion_SpriteHeight[SPRITES][MAX_COSTUME_LENGTH] = { {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0} };
double scratch_looks_effects_colour[] = { 0.0, 0.0, 0.0, 0.0 };
double scratch_looks_effects_fisheye[] = { 0.0, 0.0, 0.0, 0.0 };
double scratch_looks_effects_whirl[] = { 0.0, 0.0, 0.0, 0.0 };
double scratch_looks_effects_pixelate[] = { 0.0, 0.0, 0.0, 0.0 };
double scratch_looks_effects_mosaic[] = { 0.0, 0.0, 0.0, 0.0 };
double scratch_looks_effects_brightness[] = { 0.0, 0.0, 0.0, 0.0 };
double scratch_looks_effects_ghost[] = { 0.0, 0.0, 0.0, 0.0 };
