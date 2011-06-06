#ifndef _SDLFIN_H
#define _SDLFIN_H

#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct 
{

	SDL_Rect positionFond;
	Mix_Music *musiquevictoire;
	Mix_Music *musiquedefaite;
	Mix_Music *musiquefindejeu;
	SDL_Surface* surface_bgdefaite;
	SDL_Surface* surface_bgvictoire;
	SDL_Surface* surface_bgfindejeu;
	SDL_Surface* surface_icone;
	SDL_Surface* surface_ecran;
} sdlFin;

/**Initialise un ecran de fin*/
void sdlFinInit(sdlFin *);
/**Affiche l'ecran de fin*/
void sdlFinAff(sdlFin*, int, int);
/**Lance une boucle affichant un ecran de fin selectionne selon la victoire ou la défaite au cours du jeu*/
void sdlFinBoucle(sdlFin*,int,int);
/**Detruit la structure*/
void sdlFinDetruit(sdlFin*);

#endif