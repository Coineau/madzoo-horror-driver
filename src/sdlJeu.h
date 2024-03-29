
#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "Jeu.h"


typedef struct 
{
	Jeu jeu;
	int autoActuel;
	SDL_Color bgColorBlack;
	SDL_Color textColor;
	Mix_Music *musiquejeu;
	Mix_Chunk *deplace;
	SDL_Surface* surface_icone;
	SDL_Surface* surface_ecran;
	SDL_Surface* surface_autoHaut;
	SDL_Surface* surface_autoBas;
	SDL_Surface* surface_autoGauche;
	SDL_Surface* surface_autoDroite;
	SDL_Surface* surface_mur;
        SDL_Surface* surface_titre;
	SDL_Surface* surface_zombie;
	SDL_Surface* surface_survivant;
	SDL_Surface* surface_heli;
	SDL_Surface* surface_HUD;
	SDL_Surface* surface_sol;
	TTF_Font* surface_police;
} sdlJeu;

/**Initialise le jeu*/
void sdljeuInit(sdlJeu *,int);
/**Affiche le jeu*/
void sdljeuAff(sdlJeu *);
/**Lance la boucle de jeu */
void sdljeuBoucle(sdlJeu *,int);
/**Detruit la structure*/
void sdljeuDetruit(sdlJeu *);

#endif
