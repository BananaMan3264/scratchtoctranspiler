#include <SDL2/SDL_mixer.h>
#define sound_playuntildone(id) {int sound_id = Mix_PlayChannel(-1, getSound(id), 0); while(Mix_Playing(sound_id)) {TRUE_YIELD;}}
ScratchValue sound_sounds_menu(ScratchValue value);
Mix_Chunk* getSound(ScratchValue id);
void sound_play(ScratchValue id);
void sound_stopallsounds();
void InitSounds();