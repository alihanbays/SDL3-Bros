#ifndef AUDIO_H
#define AUDIO_H
#include <SDL3_mixer/SDL_mixer.h>

// Audio system
static MIX_Mixer* mixer;
static MIX_Track* track;
static MIX_Audio* audio[4]; // TODO: Remove hardcoding
bool audioInit();
void audioPlay(int trackNum);
void audioCleanup();

#endif
