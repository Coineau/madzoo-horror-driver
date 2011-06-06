#ifndef _SDLMENU_H
#define _SDLMENU_H
#include "sdlFin.h"
#include "sdlJeu.h"
#include "sdlCredits.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


typedef struct
{
	int niveau;
	Mix_Music *musiquemenu;
	SDL_Rect positionFond;
	SDL_Rect positionJouer;
	SDL_Rect positionCredits;
	SDL_Rect positionQuitter;
	SDL_Surface* surface_icone;
	SDL_Surface* surface_ecran;
	SDL_Surface* surface_titre;
	SDL_Surface* surface_bg;
	SDL_Surface* surface_jouer;
	SDL_Surface* surface_credits;
        SDL_Surface* surface_quitter;
} sdlMenu;

/**Initialise le menu*/
void sdlMenuInit(sdlMenu *);
/**Affiche le menu*/
void sdlMenuAff(sdlMenu *);
/**Lance la boucle du menu qui appelle ensuite les credit et le jeu selon le choix de l'utilisateur*/
void sdlMenuBoucle(sdlMenu *, sdlJeu *, sdlCredits *, sdlFin *);
/**Detruit la structure*/
void sdlMenuDetruit(sdlMenu *, sdlJeu *);

#endif
