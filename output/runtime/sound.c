#include <math.h>
#include <SDL2/SDL_mixer.h>
#include <time.h>
#include "scratch.h"
#include "motion.h"
#include "types.h"
#include "pen.h"
#include "../sprite_data.h"

Mix_Chunk* sound[SPRITES][MAX_SOUND_LENGTH];

extern int   scratch_sound_SoundEffectCounts[];
extern char* scratch_sound_SoundEffectNames[SPRITES][MAX_SOUND_LENGTH];
extern char* scratch_sound_SoundEffectFiles[SPRITES][MAX_SOUND_LENGTH];

extern int activeSprite;

#define SSC scratch_sound_SoundEffectCounts[activeSprite]
#define SSN scratch_sound_SoundEffectNames[activeSprite]

void InitSounds() 
{
	for (int i = 0; i < SPRITES; i++) 
	{
		for (int j = 0; j < MAX_SOUND_LENGTH; j++) 
		{
			char* this = scratch_sound_SoundEffectFiles[i][j];

			if (!this)
			{
				continue;
			}

			char* path = "../../../../scratch/Project/";

			int length = strlen(this) + strlen(path) + 1;

			char* srtc = malloc(length);
			if (!srtc) { printf("Malloc error!"); exit(-1); }

			snprintf(srtc, length, "%s%s", path, this);

			sound[i][j] = Mix_LoadWAV(srtc);


			if (!sound[i][j])
			{
				printf("Error loading sound: %s, reason: %s\n", srtc, Mix_GetError());
				exit(-1);
			}

			free(srtc);
		}
	}

	//sound = Mix_LoadWAV("../../../../scratch/Project/c4e9e84fd9244ca43986c2bdb6669ae8.wav");
}

Mix_Chunk* getSound(ScratchValue id) 
{
	return sound[activeSprite][(int)ScratchVarGetDouble(id) - 1];
}

void sound_play(ScratchValue id)
{
	Mix_PlayChannel(-1, getSound(id), 0);
}

ScratchValue sound_sounds_menu(ScratchValue value)
{
	char* str = ScratchVarGetString(value);
	for (int i = 0; i < SSC; i++)
	{
		if (strcmp(SSN[i], str) == 0)
		{
			return ScratchSetDouble(i + 1);
		}
	}
	return ScratchSetDouble(1);
}

void sound_stopallsounds() 
{
	Mix_HaltChannel(-1);
}