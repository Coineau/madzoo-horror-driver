
#include <assert.h>
#include "sdlCredits.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


SDL_Surface *SDL_load_image(const char* filename );
void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y );



void sdlCreditsInit(sdlCredits *pSdlCredits)
{
	assert(   SDL_Init( SDL_INIT_EVERYTHING )!= -1 );
	
	
	pSdlCredits->surface_icone = SDL_LoadBMP("data/icone.bmp");
	if (pSdlCredits->surface_icone==NULL)
		pSdlCredits->surface_icone = SDL_LoadBMP("../data/icone.bmp");
	assert( pSdlCredits->surface_icone!=NULL);
	
	SDL_WM_SetIcon(pSdlCredits->surface_icone, NULL);
	

	pSdlCredits->surface_ecran = SDL_SetVideoMode( 640, 640, 32, SDL_SWSURFACE );
	assert( pSdlCredits->surface_ecran!=NULL);
	SDL_WM_SetCaption( "MHD v1.0", NULL );

	/**Chargement des surfaces*/
	
	pSdlCredits->surface_bg = SDL_LoadBMP("data/credits/bgcredits.bmp");
	if (pSdlCredits->surface_bg==NULL)
		pSdlCredits->surface_bg = SDL_LoadBMP("../data/credits/bgcredits.bmp");
	assert( pSdlCredits->surface_bg!=NULL);
	
	
	
	/**Chargement des musiques*/
	pSdlCredits->musiquecredits=Mix_LoadMUS("data/credits/musiquecredits.wav");
	if (pSdlCredits->musiquecredits==NULL)
		pSdlCredits->musiquecredits=Mix_LoadMUS("../data/credits/musiquecredits.wav");
	assert( pSdlCredits->musiquecredits!=NULL);
	
	
	/**Determination de la position de l'image*/
	pSdlCredits->positionFond.x = 0;
	pSdlCredits->positionFond.y = 0;
}



void sdlCreditsAff(sdlCredits *pSdlCredits)
{
	/** Remplir l'écran */	
	SDL_BlitSurface(pSdlCredits->surface_bg, NULL, pSdlCredits->surface_ecran, &(pSdlCredits->positionFond));
}
	
	
	



void sdlCreditsBoucle(sdlCredits *pSdlCredits)
{
	SDL_Event event;
	int continue_boucle = 1;
	
	sdlCreditsAff(pSdlCredits);
	assert( SDL_Flip( pSdlCredits->surface_ecran )!=-1 );
	
	Mix_PlayMusic(pSdlCredits->musiquecredits, -1);
	
	while ( continue_boucle == 1 )
	{
		SDL_WaitEvent(&event);

		switch(event.type)
		{
			case SDL_QUIT :
				continue_boucle = 0;
				break;
			
			case SDL_MOUSEBUTTONUP:
				continue_boucle=0;				
				break;
			
		}
	}

	
	/** On affiche le jeu sur le buffer caché */
	sdlCreditsAff(pSdlCredits);

	/** On permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle) */
	SDL_Flip( pSdlCredits->surface_ecran );

	
}


void sdlCreditsDetruit( sdlCredits *pSdlCredits)
{
	SDL_FreeSurface( pSdlCredits->surface_bg);
	Mix_FreeMusic(pSdlCredits->musiquecredits);

}