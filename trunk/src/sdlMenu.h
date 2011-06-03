#ifndef _SDLMENU_H
#define _SDLMENU_H

#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct 
{
	Mix_Music *musiquemenu;
	Mix_Chunk *deplace;
	SDL_Surface* surface_icone;
	SDL_Surface* surface_ecran;
	SDL_Surface* surface_titre;
	SDL_Surface* surface_bg;
	SDL_Surface* surface_jouer;
	SDL_Surface* surface_credits;
        SDL_Surface* surface_quitter;
} sdlMenu;

void sdlMenuInit(sdlMenu *);
void sdlMenuAff(sdlMenu *);
void sdlMenuBoucle(sdlMenu *);
void sdlMenuLibere(sdlMenu *);
void sdlMenuDetruit(sdlMenu *);

#endif