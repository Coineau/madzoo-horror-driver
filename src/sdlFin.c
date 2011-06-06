#include <assert.h>
#include "sdlFin.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


void sdlFinInit(sdlFin *pSdlFin)
{
	assert(   SDL_Init( SDL_INIT_EVERYTHING )!= -1 );
	
	
	pSdlFin->surface_icone = SDL_LoadBMP("data/icone.bmp");
	if (pSdlFin->surface_icone==NULL)
		pSdlFin->surface_icone = SDL_LoadBMP("../data/icone.bmp");
	assert( pSdlFin->surface_icone!=NULL);
	
	SDL_WM_SetIcon(pSdlFin->surface_icone, NULL);
	

	pSdlFin->surface_ecran = SDL_SetVideoMode( 640, 640, 32, SDL_SWSURFACE );
	assert( pSdlFin->surface_ecran!=NULL);
	SDL_WM_SetCaption( "MHD v1.0", NULL );

	/*Chargement des surfaces*/
	
	pSdlFin->surface_bgdefaite = SDL_LoadBMP("data/jeu/img/bgdefaite.bmp");
	if (pSdlFin->surface_bgdefaite==NULL)
		pSdlFin->surface_bgdefaite = SDL_LoadBMP("../data/jeu/img/bgdefaite.bmp");
	assert( pSdlFin->surface_bgdefaite!=NULL);
	
	pSdlFin->surface_bgvictoire = SDL_LoadBMP("data/jeu/img/bgvictoire.bmp");
	if (pSdlFin->surface_bgvictoire==NULL)
		pSdlFin->surface_bgvictoire = SDL_LoadBMP("../data/jeu/img/bgvictoire.bmp");
	assert( pSdlFin->surface_bgvictoire!=NULL);
	
	pSdlFin->surface_bgfindejeu = SDL_LoadBMP("data/jeu/img/bgfindejeu.bmp");
	if (pSdlFin->surface_bgfindejeu==NULL)
		pSdlFin->surface_bgfindejeu = SDL_LoadBMP("../data/jeu/img/bgfindejeu.bmp");
	assert( pSdlFin->surface_bgfindejeu!=NULL);	
	
	
	/*Chargement des musiques*/
	/*pSdlFin->musiquedefaite=Mix_LoadMUS("data/jeu/musique/musiquedefaite.wav");
	if (pSdlFin->musiquedefaite==NULL)
		pSdlFin->musiquedefaite=Mix_LoadMUS("../data/jeu/musique/musiquedefaite.wav");
	assert( pSdlFin->musiquedefaite!=NULL);
	
	pSdlFin->musiquevictoire=Mix_LoadMUS("data/jeu/musique/musiquevictoire.wav");
	if (pSdlFin->musiquevictoire==NULL)
		pSdlFin->musiquevictoire=Mix_LoadMUS("../data/jeu/musique/musiquevictoire.wav");
	assert( pSdlFin->musiquevictoire!=NULL);*/
	
	
	/**Determination de la position de l'image*/
	pSdlFin->positionFond.x = 0;
	pSdlFin->positionFond.y = 0;
	
}
void sdlFinAff(sdlFin* pSdlFin, int typefin, int niveau)
{
	if(typefin==2)
	/* Remplir avec l'écran de defaite */	
	{SDL_BlitSurface(pSdlFin->surface_bgdefaite, NULL, pSdlFin->surface_ecran, &(pSdlFin->positionFond));}
	
	else 
	{
		if((typefin==1)&&(niveau>5))
		/*Remplir avec l'écran de fin du jeu*/
		{SDL_BlitSurface(pSdlFin->surface_bgfindejeu, NULL, pSdlFin->surface_ecran, &(pSdlFin->positionFond));}
		else
		/*Remplir avec l'ecran de victoire*/
		{SDL_BlitSurface(pSdlFin->surface_bgvictoire, NULL, pSdlFin->surface_ecran, &(pSdlFin->positionFond));}
	}
}
	
	
	
	
void sdlFinBoucle(sdlFin* pSdlFin,int typefin, int niveau)
{
	SDL_Event event;
	int continue_boucle = 1;
	
	sdlFinAff(pSdlFin, typefin, niveau);
	assert( SDL_Flip( pSdlFin->surface_ecran )!=-1 );
	/*if (typefin==1)
	{
		Mix_PlayMusic(pSdlFin->musiquevictoire, -1);
	}
	else
	{
		Mix_PlayMusic(pSdlFin->musiquedefaite, -1);
	}*/
	
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
	sdlFinAff(pSdlFin, typefin, niveau);

	/** On permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle) */
	SDL_Flip( pSdlFin->surface_ecran );
}


void sdlFinDetruit(sdlFin *pSdlFin)
{
	SDL_FreeSurface (pSdlFin->surface_bgdefaite);
	SDL_FreeSurface (pSdlFin->surface_bgvictoire);
	SDL_FreeSurface (pSdlFin->surface_bgfindejeu);
	SDL_FreeSurface (pSdlFin->surface_ecran);
	SDL_FreeSurface (pSdlFin->surface_icone);
	/*Mix_FreeMusic (pSdlFin->musiquevictoire);
	Mix_FreeMusic (pSdlFin->musiquedefaite);*/
}