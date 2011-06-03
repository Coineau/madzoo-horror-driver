
#include <assert.h>
#include "sdlMenu.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


SDL_Surface *SDL_load_image(const char* filename );
void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y );



void sdlMenuInit(sdlMenu *pSdlMenu)
{
	assert(   SDL_Init( SDL_INIT_EVERYTHING )!= -1 );
	
	if(Mix_OpenAudio(11025, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("%s", Mix_GetError());
	}
	
	SDL_Color textColor= { 238, 238,0 };
	SDL_Color bgColorBlack= {0,0,0};

	pSdlJeu->surface_ecran = SDL_SetVideoMode( 20, 20, 32, SDL_SWSURFACE );
	assert( pSdlMenu->surface_ecran!=NULL);
	SDL_WM_SetCaption( "MHD v1.0", NULL );

	/**Chargement des surfaces*/
	
	pSdleu->surface_bg = SDL_load_image("data/menu/img/bg.bmp");
	if (pSdlMenu->surface_bg==NULL)
		pSdlMenu->surface_bg = SDL_load_image("../data/menu/img/bg.bmp");
	assert( pSdlMenu->surface_bg!=NULL);
	
	pSdleu->surface_jouer = SDL_load_image("data/jmenu/img/ouer.bmp");
	if (pSdlMenu->surface_jouer==NULL)
		pSdlMenu->surface_jouer = SDL_load_image("../data/menu/img/jouer.bmp");
	assert( pSdlMenu->surface_jouer!=NULL);
	
	pSdleu->surface_credits = SDL_load_image("data/menu/img/credits.bmp");
	if (pSdlMenu->surface_credits==NULL)
		pSdlMenu->surface_credits = SDL_load_image("../data/menu/img/credits.bmp");
	assert( pSdlMenu->surface_credits!=NULL);
	
	pSdlMenu->surface_quitter = SDL_load_image("data/menu/img/quitter.bmp");
	if (pSdlMenu->surface_quitter==NULL)
		pSdlMenu->surface_quitter = SDL_load_image("../data/menu/img/quitter.bmp");
	assert( pSdlMenu->surface_quitter!=NULL);
	
	
	/**Chargement des musiques*/
	pSdlMenu->musique=Mix_LoadMUS("data/menu/musique/bgmusic.wav");
	if (pSdlMenu->musique==NULL)
		pSdlMenu->musique=Mix_LoadMUS("../data/menu/musique/bgmusic.wav");
	assert( pSdlMenu->musique!=NULL);
	
	/**Chargement des sons*/
	pSdlMenu->deplace=Mix_LoadWAV("data/menu/musique/move.wav");
	if(pSdlMenu->deplace==NULL)
		pSdlMenu->deplace=Mix_LoadWAV("../data/menu/musique/move.wav");
	assert( pSdlMenu->deplace!=NULL);
}



void sdlMenuAff(sdlMenu *pSdlMenu)
{
	
	/** Remplir l'écran */	
	SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
	
	



void sdlMenuBoucle(sdlMenu *pSdlMenu)
{
	SDL_Event event;
	int continue_boucle = 1;
	int tempsActuel=0; 
	int tempsPrecedent=0; 

	sdljeuAff(pSdlJeu);
	assert( SDL_Flip( pSdlJeu->surface_ecran )!=-1 );
	
	
	SDL_EnableKeyRepeat(100, 200);

	Mix_VolumeChunk(pSdlJeu->deplace, MIX_MAX_VOLUME/3);
	Mix_PlayMusic(pSdlJeu->musique, -1);
	
	/** tant que ce n'est pas la fin ... */
	while ( continue_boucle == 1 )
	{	/** tant qu'il y a des evenements à traiter : cette boucle n'est pas bloquante */
		while ( SDL_PollEvent( &event) ) 
		{
			/** Si l'utilisateur a cliqué sur la croix de fermeture */
			if ( event.type == SDL_QUIT )
				continue_boucle = 0;

			/** Si l'utilisateur a appuyé sur une touche */
			if ( event.type == SDL_KEYDOWN )
			{
				switch ( event.key.keysym.sym )
				{
				case SDLK_UP:
					jeuActionClavier( &(pSdlJeu->jeu), 'h');
					Mix_PlayChannel(1, pSdlJeu->deplace,0);
					break;
				case SDLK_DOWN:
					jeuActionClavier( &(pSdlJeu->jeu), 'b');
					Mix_PlayChannel(1, pSdlJeu->deplace,0);
					break;
				case SDLK_LEFT:
					jeuActionClavier( &(pSdlJeu->jeu), 'g');
					Mix_PlayChannel(1, pSdlJeu->deplace,0);
					break;
				case SDLK_RIGHT:
					jeuActionClavier( &(pSdlJeu->jeu), 'd');
					Mix_PlayChannel(1, pSdlJeu->deplace,0);
					break;
				default: 	
						break;
				}
			}
			
		}
		

		tempsActuel = SDL_GetTicks();
		if (tempsActuel - tempsPrecedent > 350) /** Si 100 ms se sont écoulées depuis le dernier tour de boucle */
				{
				jeuDeplaceZombies(&(pSdlJeu->jeu));
				tempsPrecedent = tempsActuel; /** Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
				}
		
		/* on affiche le jeu sur le buffer caché */
		sdlMenuAff(pSdlMenu);

		/* on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle) */
		SDL_Flip( pSdlMenu->surface_ecran );
	}
}


void sdlMenuDetruit( sdlMenu *pSdlMenu)
{
	SDL_FreeSurface( pSdlJeu->surface_auto );
	SDL_FreeSurface( pSdlJeu->surface_mur );
	Mix_FreeMusic(pSdlJeu->musique);
	SDL_Quit();
}



SDL_Surface *SDL_load_image(const char* filename )
{
	/* Temporary storage for the image that's loaded */
	SDL_Surface* loadedImage = NULL;

	/* The optimized image that will be used */
	SDL_Surface* optimizedImage = NULL;

	/* Load the image */
	loadedImage = SDL_LoadBMP( filename );

	/* If nothing went wrong in loading the image */
	if ( loadedImage != NULL )
	{
		/* Create an optimized image */
		optimizedImage = SDL_DisplayFormat( loadedImage );

		/* Free the old image */
		SDL_FreeSurface( loadedImage );
	}

	/* Return the optimized image */
	return optimizedImage;
}


void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y )
{
	/* Make a temporary rectangle to hold the offsets */
	SDL_Rect offset;

	/* Give the offsets to the rectangle */
	offset.x = x;
	offset.y = y;

	/* Blit the surface */
	SDL_BlitSurface( source, NULL, destination, &offset );
}