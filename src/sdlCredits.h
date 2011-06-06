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

/**Initialise les credits*/
void sdlCreditsInit(sdlCredits *);
/**Affiche l'ecran des credits*/
void sdlCreditsAff(sdlCredits *);
/**Lance une boucle affichant les credits jusqu'au clic de l'utilisateur*/
void sdlCreditsBoucle(sdlCredits *);
/**Detruit la structure*/
void sdlCreditsDetruit(sdlCredits *);

#endif