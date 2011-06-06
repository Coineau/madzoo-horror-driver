#ifndef _SDLFIN_H
#define _SDLFIN_H

#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct 
{

	SDL_Rect positionFond;
	Mix_Music *musiquevictoire;
	Mix_Music *musiquedefaite;
	SDL_Surface* surface_bgdefaite;
	SDL_Surface* surface_bgvictoire;
	SDL_Surface* surface_icone;
	SDL_Surface* surface_ecran;
} sdlFin;

void sdlFinInit(sdlFin *);
void sdlFinAff(sdlFin*, int);
void sdlFinBoucle(sdlFin*,int);
void sdlFinDetruit(sdlFin*);

#endif