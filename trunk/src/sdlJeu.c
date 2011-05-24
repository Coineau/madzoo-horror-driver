
#include <assert.h>
#include "sdlJeu.h"
#include <SDL/SDL_ttf.h>

const int TAILLE_SPRITE=32;

SDL_Surface *SDL_load_image(const char* filename );
void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y );



void sdljeuInit(sdlJeu *pSdlJeu)
{
	Jeu *pJeu;
	int dimx, dimy, tempsActuel;
	char HUD[50]=" ";
	SDL_Color textColor= { 238, 238,0 };
	SDL_Color bgColorBlack= {0,0,0};
	
	pJeu = &(pSdlJeu->jeu);
	jeuInit(pJeu);

	assert(   SDL_Init( SDL_INIT_EVERYTHING )!= -1 );

	dimx = getDimX( jeuGetConstTerrainPtr(pJeu) );
	dimy = getDimY( jeuGetConstTerrainPtr(pJeu) );
	dimx = dimx * TAILLE_SPRITE;
	dimy = (dimy+2) * TAILLE_SPRITE;
	pSdlJeu->surface_ecran = SDL_SetVideoMode(   dimx, dimy, 32, SDL_SWSURFACE );
	assert( pSdlJeu->surface_ecran!=NULL);
	SDL_WM_SetCaption( "MHD v0.5", NULL );

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

	TTF_Init();
	pSdlJeu->surface_police=TTF_OpenFont( "/usr/share/fonts/truetype/msttcorefonts/Courier_New.ttf", 28 );
	
	
	pSdlJeu->surface_titre = TTF_RenderText_Shaded( pSdlJeu->surface_police, "Madzoo Horror Driver", textColor, bgColorBlack ); 
	tempsActuel = SDL_GetTicks()/10;
	
	sprintf(HUD, "PV : %d Passager : %d Temps : %d", autoGetPdv(jeuGetAutoPtr(pJeu)),autoGetnbSurviDansAuto(jeuGetAutoPtr(pJeu)), tempsActuel);

	pSdlJeu->surface_HUD = TTF_RenderText_Shaded( pSdlJeu->surface_police, HUD, textColor, bgColorBlack);

}



void sdljeuAff(sdlJeu *pSdlJeu)
{
	Jeu *pJeu;
	int x,y,tempsActuel;
	char HUD[50]=" ";
	const Terrain *pTer = jeuGetConstTerrainPtr(&(pSdlJeu->jeu));
	const Auto *pAuto = jeuGetConstAutoPtr(&(pSdlJeu->jeu));
	SDL_Color textColor= { 238, 238,0 };
	SDL_Color bgColorBlack= {0,0,0};
	
	pJeu = &(pSdlJeu->jeu);

	/** Remplir l'�cran */
	SDL_FillRect( pSdlJeu->surface_ecran, &pSdlJeu->surface_ecran->clip_rect, SDL_MapRGB( pSdlJeu->surface_ecran->format, 0x00, 0x00, 0xFF ) );
	
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
					}
				}
			}
	/** Copier le sprite de Auto sur l'�cran */
	SDL_apply_surface(  pSdlJeu->surface_auto, pSdlJeu->surface_ecran, autoGetX(pAuto)*TAILLE_SPRITE,  (autoGetY(pAuto)+1)*TAILLE_SPRITE);

	/** Mettre le titre en bas de l'�cran */
	SDL_apply_surface( pSdlJeu->surface_titre, pSdlJeu->surface_ecran, ((getDimX(pTer)/2)-5)*TAILLE_SPRITE,(getDimY(pTer)+1)*TAILLE_SPRITE);
	
	/** Gere le HUD */
			
	tempsActuel = SDL_GetTicks()/10;
	
	sprintf(HUD, "PV : %d Passager : %d Temps : %d", autoGetPdv(jeuGetAutoPtr(pJeu)),autoGetnbSurviDansAuto(jeuGetAutoPtr(pJeu)), tempsActuel);
	pSdlJeu->surface_HUD = TTF_RenderText_Shaded( pSdlJeu->surface_police, HUD, textColor, bgColorBlack);
	
	SDL_apply_surface( pSdlJeu->surface_HUD, pSdlJeu->surface_ecran, 0,0);
	
	SDL_FreeSurface(pSdlJeu->surface_HUD);
}



void sdljeuBoucle(sdlJeu *pSdlJeu)
{
	/*SDL_TimerID timer;*/
	SDL_Event event;
	int continue_boucle = 1;
	int tempsActuel=0; 
	int tempsPrecedent=0; 
	tempsActuel = SDL_GetTicks();
	sdljeuAff(pSdlJeu);
	assert( SDL_Flip( pSdlJeu->surface_ecran )!=-1 );
	
	SDL_EnableKeyRepeat(100, 200);
	/* timer = SDL_AddTimer(150, sdljeudZDeplaceAuto,pSdlJeu ); *//* D�marrage du Timer */
	
	
	/* tant que ce n'est pas la fin ... */
	while ( continue_boucle == 1 )
	{
		/* tant qu'il y a des evenements � traiter : cette boucle n'est pas bloquante */
		while ( SDL_PollEvent( &event ) )
		{
			/* Si l'utilisateur a cliqu� sur la croix de fermeture */
			if ( event.type == SDL_QUIT )
				continue_boucle = 0;

			/* Si l'utilisateur a appuy� sur une touche */
			if ( event.type == SDL_KEYDOWN )
			{
				switch ( event.key.keysym.sym )
				{
				case SDLK_UP:
					jeuActionClavier( &(pSdlJeu->jeu), 'h');
					break;
				case SDLK_DOWN:
					jeuActionClavier( &(pSdlJeu->jeu), 'b');
					break;
				case SDLK_LEFT:
					jeuActionClavier( &(pSdlJeu->jeu), 'g');
					break;
				case SDLK_RIGHT:
					jeuActionClavier( &(pSdlJeu->jeu), 'd');
					break;
				default: 	
						break;
				}
			}
			if (tempsActuel - tempsPrecedent > 100) /* Si 100 ms se sont �coul�es depuis le dernier tour de boucle */
			{
				jeuActionClavier( &(pSdlJeu->jeu), 'O');
				tempsPrecedent = tempsActuel; /* Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
			}
		}

		/* on affiche le jeu sur le buffer cach� */
		sdljeuAff(pSdlJeu);

		/* on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle) */
		SDL_Flip( pSdlJeu->surface_ecran );
	}
}


void sdljeuDetruit( sdlJeu *pSdlJeu)
{
	SDL_FreeSurface( pSdlJeu->surface_auto );
	SDL_FreeSurface( pSdlJeu->surface_mur );
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


Uint32 sdljeudZDeplaceAuto(Uint32 intervalle,void *parametre,sdlJeu *pSdlJeu)
{	
	dZombieDeplacer(jeuGetdZombPtr(&(pSdlJeu->jeu)),autoGetX(jeuGetConstAutoPtr(&(pSdlJeu->jeu))),autoGetY(jeuGetConstAutoPtr(&(pSdlJeu->jeu))), jeuGetTerrainPtr(&(pSdlJeu->jeu)));
	return intervalle;
}
	
