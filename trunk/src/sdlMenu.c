
#include <assert.h>
#include "sdlMenu.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


SDL_Surface *SDL_load_image(const char* filename );
void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y );



void sdlMenuInit(sdlMenu *pSdlMenu)
{
	assert(   SDL_Init( SDL_INIT_EVERYTHING )!= -1 );
	
	/*if(Mix_OpenAudio(11025, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("%s", Mix_GetError());
	}*/
	
	pSdlMenu->surface_icone = SDL_LoadBMP("data/icone.bmp");
	if (pSdlMenu->surface_icone==NULL)
		pSdlMenu->surface_icone = SDL_LoadBMP("../data/icone.bmp");
	assert( pSdlMenu->surface_icone!=NULL);
	
	SDL_WM_SetIcon(pSdlMenu->surface_icone, NULL);
	

	pSdlMenu->surface_ecran = SDL_SetVideoMode( 640, 640, 32, SDL_SWSURFACE );
	assert( pSdlMenu->surface_ecran!=NULL);
	SDL_WM_SetCaption( "MHD v1.0", NULL );

	/**Chargement des surfaces*/
	
	pSdlMenu->surface_bg = SDL_LoadBMP("data/menu/img/bg.bmp");
	if (pSdlMenu->surface_bg==NULL)
		pSdlMenu->surface_bg = SDL_LoadBMP("../data/menu/img/bg.bmp");
	assert( pSdlMenu->surface_bg!=NULL);
	
	/*pSdlMenu->surface_titre = SDL_load_image("data/menu/img/titre.bmp");
	if (pSdlMenu->surface_titre==NULL)
		pSdlMenu->surface_titre = SDL_load_image("../data/menu/img/titre.bmp");
	assert( pSdlMenu->surface_titre!=NULL);*/
	
	pSdlMenu->surface_jouer = SDL_LoadBMP("data/menu/img/jouer.bmp");
	if (pSdlMenu->surface_jouer==NULL)
		pSdlMenu->surface_jouer = SDL_LoadBMP("../data/menu/img/jouer.bmp");
	assert( pSdlMenu->surface_jouer!=NULL);
	
	/*pSdlMenu->surface_credits = SDL_load_image("data/menu/img/credits.bmp");
	if (pSdlMenu->surface_credits==NULL)
		pSdlMenu->surface_credits = SDL_load_image("../data/menu/img/credits.bmp");
	assert( pSdlMenu->surface_credits!=NULL);*/
	
	pSdlMenu->surface_quitter = SDL_LoadBMP("data/menu/img/quitter.bmp");
	if (pSdlMenu->surface_quitter==NULL)
		pSdlMenu->surface_quitter = SDL_LoadBMP("../data/menu/img/quitter.bmp");
	assert( pSdlMenu->surface_quitter!=NULL);
	
	
	/**Chargement des musiques*/
	/*pSdlMenu->musiquemenu=Mix_LoadMUS("data/menu/musique/musiquemenu.wav");
	if (pSdlMenu->musiquemenu==NULL)
		pSdlMenu->musiquemenu=Mix_LoadMUS("../data/menu/musique/musiquemenu.wav");
	assert( pSdlMenu->musiquemenu!=NULL);*/
	
	/**Chargement des sons*/
	/*pSdlMenu->deplace=Mix_LoadWAV("data/menu/musique/deplace.wav");
	if(pSdlMenu->deplace==NULL)
		pSdlMenu->deplace=Mix_LoadWAV("../data/menu/musique/deplace.wav");
	assert( pSdlMenu->deplace!=NULL);*/
}



void sdlMenuAff(sdlMenu *pSdlMenu)
{
	SDL_Rect positionFond;
	SDL_Rect positionJouer;
	SDL_Rect positionQuitter;
	positionFond.x = 0;
	positionFond.y = 0;
	positionJouer.x = 96;
	positionJouer.y = 128;
	positionQuitter.x = 96;
	positionQuitter.y = 384;

	/** Remplir l'écran */	
	SDL_BlitSurface(pSdlMenu->surface_bg, NULL, pSdlMenu->surface_ecran, &positionFond);
	
	/** Placer  les bouttons*/
	SDL_BlitSurface(pSdlMenu->surface_jouer, NULL, pSdlMenu->surface_ecran, &positionJouer);
	SDL_BlitSurface(pSdlMenu->surface_quitter, NULL, pSdlMenu->surface_ecran, &positionQuitter);

	
}
	
	
	



void sdlMenuBoucle(sdlMenu *pSdlMenu)
{
	SDL_Event event;
	int continue_boucle = 1;
	
	sdlMenuAff(pSdlMenu);
	assert( SDL_Flip( pSdlMenu->surface_ecran )!=-1 );
	
	SDL_EnableKeyRepeat(100, 200);
	
	while ( continue_boucle == 1 )
	{
		while ( SDL_PollEvent( &event) ) 
		{
			if ( event.type == SDL_QUIT )
				continue_boucle = 0;
		}	
	}
	
	
	
	/*Mix_VolumeChunk(pSdlMenu->deplace, MIX_MAX_VOLUME/3);
	Mix_PlayMusic(pSdlMenu->musiquemenu, -1);*/
	
	
		
		/* on affiche le jeu sur le buffer caché */
		sdlMenuAff(pSdlMenu);

		/* on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle) */
		SDL_Flip( pSdlMenu->surface_ecran );
}


void sdlMenuDetruit( sdlMenu *pSdlMenu)
{
	SDL_FreeSurface( pSdlMenu->surface_bg);
	/*SDL_FreeSurface( pSdlMenu->surface_titre);*/
	SDL_FreeSurface( pSdlMenu->surface_jouer);
	/*SDL_FreeSurface( pSdlMenu->surface_credits);*/
        SDL_FreeSurface( pSdlMenu->surface_quitter);
	/*Mix_FreeMusic(pSdlMenu->musiquemenu);*/
	SDL_Quit();
}