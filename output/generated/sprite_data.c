#include <stdbool.h>
#include <stdlib.h>
#include "../runtime/motion.h"
#include "../sprite_data.h"

double scratch_motion_SpriteX[] = { 0.0, -28.539297 };
double scratch_motion_SpriteY[] = { 0.0, 56.305655 };
double scratch_motion_SpriteDirection[] = { 0.0, 0.000000 };
bool scratch_looks_hidden[] = { false, true };
int scratch_motion_SpriteRotStyle[] = { RotStyle_allaround, RotStyle_allaround };
int scratch_looks_CostumeIndex[] = { 0, 0 };
int scratch_looks_CostumeCounts[] = { 1, 1 };
char* scratch_looks_CostumeNames[SPRITES][MAX_COSTUME_LENGTH] = {
	{ "backdrop1" },
	{ "Ball-a" }
 };
char* scratch_looks_CostumeFiles[SPRITES][MAX_COSTUME_LENGTH] = {
	{ "87ec29ad216c0074c731d581c7f40c39.svg" },
	{ "911dacd97f29220a6ec52c8af2c254e8.svg" }
 };
double scratch_looks_RotationCentreX[SPRITES][MAX_COSTUME_LENGTH] = {
	{ 240.000000 },
	{ 22.000000 }
 };
double scratch_looks_RotationCentreY[SPRITES][MAX_COSTUME_LENGTH] = {
	{ 180.000000 },
	{ 22.000000 }
 };
int scratch_sound_SoundEffectCounts[] = { 1, 1 };
char* scratch_sound_SoundEffectNames[SPRITES][MAX_SOUND_LENGTH] = {
	{ "pop", NULL },
	{ "Meow", NULL }
 };
char* scratch_sound_SoundEffectFiles[SPRITES][MAX_SOUND_LENGTH] = {
	{ "83a9787d4cb6f3b7632b4ddfebf74367.wav", NULL },
	{ "83c36d806dc92327b9e7049a565c6bff.wav", NULL }
 };
double scratch_motion_SpriteSize[] = { 100.0, 225.222621 };
double scratch_motion_SpriteWidth[SPRITES][MAX_COSTUME_LENGTH] = { {0.0}, {0.0} };
double scratch_motion_SpriteHeight[SPRITES][MAX_COSTUME_LENGTH] = { {0.0}, {0.0} };
double scratch_looks_effects_colour[] = { 0.0, 0.0 };
double scratch_looks_effects_fisheye[] = { 0.0, 0.0 };
double scratch_looks_effects_whirl[] = { 0.0, 0.0 };
double scratch_looks_effects_pixelate[] = { 0.0, 0.0 };
double scratch_looks_effects_mosaic[] = { 0.0, 0.0 };
double scratch_looks_effects_brightness[] = { 0.0, 0.0 };
double scratch_looks_effects_ghost[] = { 0.0, 0.0 };
