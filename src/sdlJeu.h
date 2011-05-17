
#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL/SDL.h>
#include "Jeu.h"


typedef struct 
{
	Jeu jeu;
	SDL_Surface* surface_ecran;
	SDL_Surface* surface_auto;
	SDL_Surface* surface_mur;
        SDL_Surface* surface_titre;
	SDL_Surface* surface_zombie;
	SDL_Surface* surface_survivant;
	SDL_Surface* surface_heli;
} sdlJeu;

void sdljeuInit(sdlJeu *);
void sdljeuBoucle(sdlJeu *);
void sdljeuLibere(sdlJeu *);
void sdljeuDetruit(sdlJeu *);

#endif
