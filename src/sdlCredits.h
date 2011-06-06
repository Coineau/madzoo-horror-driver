#ifndef _SDLCREDITS_H
#define _SDLCREDITS_H

#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct 
{
	Mix_Music *musiquecredits;
	SDL_Rect positionFond;
	SDL_Surface* surface_ecran;
	SDL_Surface* surface_bg;
	SDL_Surface* surface_icone;
} sdlCredits;

void sdlCreditsInit(sdlCredits *);
void sdlCreditsAff(sdlCredits *);
void sdlCreditsBoucle(sdlCredits *);
void sdlCreditsDetruit(sdlCredits *);

#endif