
#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "Jeu.h"


typedef struct 
{
	int findepartie;
	Jeu jeu;
	Mix_Music *musique;
	Mix_Chunk *deplace;
	SDL_Surface* surface_icone;
	SDL_Surface* surface_ecran;
	SDL_Surface* surface_auto;
	SDL_Surface* surface_mur;
        SDL_Surface* surface_titre;
	SDL_Surface* surface_zombie;
	SDL_Surface* surface_survivant;
	SDL_Surface* surface_heli;
	SDL_Surface* surface_HUD;
	SDL_Surface* surface_sol;
	TTF_Font* surface_police;
} sdlJeu;

void sdljeuInit(sdlJeu *);
void sdljeuAff(sdlJeu *);
void sdljeuBoucle(sdlJeu *);
void sdljeuLibere(sdlJeu *);
void sdljeuDetruit(sdlJeu *);

#endif
