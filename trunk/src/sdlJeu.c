
#include <assert.h>
#include "sdlJeu.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

const int TAILLE_SPRITE=32;

SDL_Surface *SDL_load_image(const char* filename );
void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y );



void sdljeuInit(sdlJeu *pSdlJeu)
{
	Jeu *pJeu;
	int dimx, dimy, tempsActuel;
	char HUD[20*32]=" ";
	/*dimx = getDimX( jeuGetConstTerrainPtr(pJeu) );
	char* HUD= (char*)malloc( dimx * sizeof(char*));
	int x=0;
	for (x; x<dimx;x++)
	{
		HUD[x]=" ";
	}*/
	
	pJeu = &(pSdlJeu->jeu);
	jeuInit(pJeu);

	assert(   SDL_Init( SDL_INIT_EVERYTHING )!= -1 );

	pSdlJeu->surface_icone = SDL_LoadBMP("data/icone.bmp");
	if (pSdlJeu->surface_icone==NULL)
	pSdlJeu->surface_icone = SDL_LoadBMP("../data/icone.bmp");
	assert( pSdlJeu->surface_icone!=NULL);
	
	SDL_WM_SetIcon(pSdlJeu->surface_icone, NULL);
	
	
	if(Mix_OpenAudio(11025, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("%s", Mix_GetError());
	}
	
	SDL_Color textColor= { 238, 238,0 };
	SDL_Color bgColorBlack= {0,0,0};

	dimx = getDimX( jeuGetConstTerrainPtr(pJeu) );
	dimy = getDimY( jeuGetConstTerrainPtr(pJeu) );
	dimx = dimx * TAILLE_SPRITE;
	dimy = (dimy+2) * TAILLE_SPRITE;
	pSdlJeu->surface_ecran = SDL_SetVideoMode(   dimx, dimy, 32, SDL_SWSURFACE );
	assert( pSdlJeu->surface_ecran!=NULL);
	SDL_WM_SetCaption( "MHD v1.0", NULL );

	/**Chargement des surfaces*/
	
	pSdlJeu->surface_sol = SDL_load_image("data/sol.bmp");
	if (pSdlJeu->surface_sol==NULL)
		pSdlJeu->surface_sol = SDL_load_image("../data/sol.bmp");
	assert( pSdlJeu->surface_sol!=NULL);
	
	pSdlJeu->surface_auto = SDL_load_image("data/auto.bmp");
	if (pSdlJeu->surface_auto==NULL)
		pSdlJeu->surface_auto = SDL_load_image("../data/auto.bmp");
	assert( pSdlJeu->surface_auto!=NULL);
	
	pSdlJeu->surface_zombie = SDL_load_image("data/zombie.bmp");
	if (pSdlJeu->surface_zombie==NULL)
		pSdlJeu->surface_zombie = SDL_load_image("../data/zombie.bmp");
	assert( pSdlJeu->surface_zombie!=NULL);

	pSdlJeu->surface_survivant = SDL_load_image("data/survivant.bmp");
	if (pSdlJeu->surface_survivant==NULL)
		pSdlJeu->surface_survivant = SDL_load_image("../data/survivant.bmp");
	assert( pSdlJeu->surface_survivant!=NULL);
	
	pSdlJeu->surface_heli = SDL_load_image("data/Heliport.bmp");
	if (pSdlJeu->surface_heli==NULL)
		pSdlJeu->surface_heli = SDL_load_image("../data/Heliport.bmp");
	assert( pSdlJeu->surface_heli!=NULL);

	pSdlJeu->surface_mur = SDL_load_image("data/mur.bmp");
	if (pSdlJeu->surface_mur==NULL)
		pSdlJeu->surface_mur = SDL_load_image("../data/mur.bmp");
	assert( pSdlJeu->surface_mur!=NULL);

	/**Initialisation de la police, du titre et du HUD*/
	TTF_Init();
	
	pSdlJeu->surface_police=TTF_OpenFont( "data/jeu/Courier_New.ttf", 28 );
	if (pSdlJeu->surface_police==NULL)
		pSdlJeu->surface_police=TTF_OpenFont( "../data/jeu/Courier_New.ttf", 28 );
	assert(pSdlJeu->surface_police!=NULL);
	
	pSdlJeu->surface_titre = TTF_RenderText_Shaded( pSdlJeu->surface_police, "Madzoo Horror Driver", textColor, bgColorBlack ); 
	
	tempsActuel = SDL_GetTicks()/10;
	
	sprintf(HUD, "PV : %d Passager : %d Temps : %d", autoGetPdv(jeuGetAutoPtr(pJeu)),autoGetnbSurviDansAuto(jeuGetAutoPtr(pJeu)), tempsActuel);

	pSdlJeu->surface_HUD = TTF_RenderText_Shaded( pSdlJeu->surface_police, HUD, textColor, bgColorBlack);
	
	
	/**Chargement des musiques*/
	pSdlJeu->musique=Mix_LoadMUS("data/musique/bgmusic.wav");
	if (pSdlJeu->musique==NULL)
		pSdlJeu->musique=Mix_LoadMUS("../data/musique/bgmusic.wav");
	assert( pSdlJeu->musique!=NULL);
	
	/**Chargement des sons*/
	pSdlJeu->deplace=Mix_LoadWAV("data/musique/move.wav");
	if(pSdlJeu->deplace==NULL)
		pSdlJeu->deplace=Mix_LoadWAV("../data/musique/move.wav");
	assert( pSdlJeu->deplace!=NULL);
}



void sdljeuAff(sdlJeu *pSdlJeu)
{
	Jeu *pJeu;
	int x,y,tempsActuel,dimx;
	const Terrain *pTer ;
	const Auto *pAuto;
	char HUD[20*32]=" ";
	int i,j;
	
	
	i=0;
	j=0;
	pJeu = &(pSdlJeu->jeu);
	dimx = getDimX( jeuGetConstTerrainPtr(pJeu) );
	pTer= jeuGetConstTerrainPtr(&(pSdlJeu->jeu));
	pAuto= jeuGetConstAutoPtr(&(pSdlJeu->jeu));
	/*HUD= (char**)malloc( dimx * sizeof(char*));
	
	
	for (i; i<dimx;i++)
	{
		HUD[i] = (char *)malloc(sizeof(char)*dimx);
	}
	
	for (j; j<dimx;j++)
	{
		HUD[j]=" ";
	}*/
	
	
	SDL_Color textColor= { 238, 238,0 };
	SDL_Color bgColorBlack= {0,0,0};

	
	/** Remplir l'écran */	
	for (x=0;x<getDimX(pTer);++x)
		for (y=0;y<getDimY(pTer);++y)
			if (terGetXY(pTer,x,y)=='#')
			{
				SDL_apply_surface(  pSdlJeu->surface_mur, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, (y+1)*TAILLE_SPRITE);
			}
			else
			{
				if(terGetXY(pTer,x,y)=='z')
				{
					SDL_apply_surface(  pSdlJeu->surface_zombie, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, (y+1)*TAILLE_SPRITE);
				}
				else
				{	
					if(terGetXY(pTer,x,y)=='o')
					{
						SDL_apply_surface(  pSdlJeu->surface_survivant, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, (y+1)*TAILLE_SPRITE);
					}
					else
					{
						if(terGetXY(pTer,x,y)=='H')
						{
						SDL_apply_surface(  pSdlJeu->surface_heli, pSdlJeu->surface_ecran, x*TAILLE_SPRITE, (y+1)*TAILLE_SPRITE);
						}
						else
						{
							SDL_apply_surface( pSdlJeu->surface_sol, pSdlJeu->surface_ecran, x*TAILLE_SPRITE,(y+1)*TAILLE_SPRITE);
						}
					}
				}
			}
	/** Copier le sprite de Auto sur l'écran */
	SDL_apply_surface(  pSdlJeu->surface_auto, pSdlJeu->surface_ecran, autoGetX(pAuto)*TAILLE_SPRITE,  (autoGetY(pAuto)+1)*TAILLE_SPRITE);

	/** Mettre le titre en bas de l'écran */
	SDL_apply_surface( pSdlJeu->surface_titre, pSdlJeu->surface_ecran, ((getDimX(pTer)/2)-5)*TAILLE_SPRITE,(getDimY(pTer)+1)*TAILLE_SPRITE);
	
	/** Gere le HUD */
			
	tempsActuel = SDL_GetTicks()/10;
	
	
	sprintf(HUD,"PV : %d Passager : %d Temps : %d", autoGetPdv(jeuGetAutoPtr(pJeu)),autoGetnbSurviDansAuto(jeuGetAutoPtr(pJeu)), tempsActuel);
	pSdlJeu->surface_HUD = TTF_RenderText_Shaded( pSdlJeu->surface_police, HUD, textColor, bgColorBlack);
	
	SDL_apply_surface( pSdlJeu->surface_HUD, pSdlJeu->surface_ecran, 0,0);
	
	SDL_FreeSurface(pSdlJeu->surface_HUD);
}



void sdljeuBoucle(sdlJeu *pSdlJeu)
{
	SDL_Event event;
	int continue_boucle = 1;
	int tempsActuel=0; 
	int tempsPrecedent=0; 

	sdljeuAff(pSdlJeu);
	assert( SDL_Flip( pSdlJeu->surface_ecran )!=-1 );
	
	
	SDL_EnableKeyRepeat(100, 200);

	Mix_VolumeChunk(pSdlJeu->deplace, MIX_MAX_VOLUME/10);
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
			pSdlJeu->findepartie=JeuTestFinNiveau(&(pSdlJeu->jeu));
			if(pSdlJeu->findepartie!=0)
			{continue_boucle=0;}
		}

		tempsActuel = SDL_GetTicks();
		if (tempsActuel - tempsPrecedent > 350) /** Si 100 ms se sont écoulées depuis le dernier tour de boucle */
				{
				jeuDeplaceZombies(&(pSdlJeu->jeu));
				tempsPrecedent = tempsActuel; /** Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
				}
		
		/** On affiche le jeu sur le buffer caché */
		sdljeuAff(pSdlJeu);

		/** On permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle) */
		SDL_Flip( pSdlJeu->surface_ecran );
	}
}


void sdljeuDetruit( sdlJeu *pSdlJeu)
{
	SDL_FreeSurface( pSdlJeu->surface_zombie);
	SDL_FreeSurface( pSdlJeu->surface_auto );
	SDL_FreeSurface( pSdlJeu->surface_mur );
	SDL_FreeSurface( pSdlJeu->surface_auto);
	SDL_FreeSurface( pSdlJeu->surface_mur);
        SDL_FreeSurface( pSdlJeu->surface_titre);
	SDL_FreeSurface( pSdlJeu->surface_zombie);
	SDL_FreeSurface( pSdlJeu->surface_survivant);
	SDL_FreeSurface( pSdlJeu->surface_heli);
	SDL_FreeSurface( pSdlJeu->surface_HUD);
	SDL_FreeSurface( pSdlJeu->surface_sol);
	Mix_FreeMusic(pSdlJeu->musique);
	Mix_CloseAudio();
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