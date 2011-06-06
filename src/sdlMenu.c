
#include <assert.h>
#include "sdlMenu.h"
#include "sdlJeu.h"
#include "sdlCredits.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


SDL_Surface *SDL_load_image(const char* filename );
void SDL_apply_surface( SDL_Surface* source, SDL_Surface* destination, int x, int y );



void sdlMenuInit(sdlMenu *pSdlMenu)
{
	assert(   SDL_Init( SDL_INIT_EVERYTHING )!= -1 );

	pSdlMenu->niveau=1;
	
	if(Mix_OpenAudio(11025, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
	{
		printf("%s", Mix_GetError());
	}

	pSdlMenu->surface_icone = SDL_LoadBMP("data/icone.bmp");
	if (pSdlMenu->surface_icone==NULL)
		pSdlMenu->surface_icone = SDL_LoadBMP("../data/icone.bmp");
	assert( pSdlMenu->surface_icone!=NULL);

	SDL_WM_SetIcon(pSdlMenu->surface_icone, NULL);


	pSdlMenu->surface_ecran = SDL_SetVideoMode( 704, 704, 32, SDL_SWSURFACE );
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

	pSdlMenu->surface_credits = SDL_load_image("data/menu/img/credits.bmp");
	if (pSdlMenu->surface_credits==NULL)
		pSdlMenu->surface_credits = SDL_load_image("../data/menu/img/credits.bmp");
	assert( pSdlMenu->surface_credits!=NULL);

	pSdlMenu->surface_quitter = SDL_LoadBMP("data/menu/img/quitter.bmp");
	if (pSdlMenu->surface_quitter==NULL)
		pSdlMenu->surface_quitter = SDL_LoadBMP("../data/menu/img/quitter.bmp");
	assert( pSdlMenu->surface_quitter!=NULL);


	/**Chargement des musiques*/
	pSdlMenu->musiquemenu=Mix_LoadMUS("data/menu/musique/musiquemenu.wav");
	if (pSdlMenu->musiquemenu==NULL)
		pSdlMenu->musiquemenu=Mix_LoadMUS("../data/menu/musique/musiquemenu.wav");
	assert( pSdlMenu->musiquemenu!=NULL);


	/**Determination de la position des bouttons*/
	pSdlMenu->positionFond.x = 0;
	pSdlMenu->positionFond.y = 0;
	pSdlMenu->positionJouer.x = 96;
	pSdlMenu->positionJouer.y = 128;
	pSdlMenu->positionCredits.x=96;
	pSdlMenu->positionCredits.y=256;
	pSdlMenu->positionQuitter.x = 96;
	pSdlMenu->positionQuitter.y = 384;
}



void sdlMenuAff(sdlMenu *pSdlMenu)
{


	/** Remplir l'écran */
	SDL_BlitSurface(pSdlMenu->surface_bg, NULL, pSdlMenu->surface_ecran, &(pSdlMenu->positionFond));

	/** Placer  les bouttons*/
	SDL_BlitSurface(pSdlMenu->surface_jouer, NULL, pSdlMenu->surface_ecran, &(pSdlMenu->positionJouer));
	SDL_BlitSurface(pSdlMenu->surface_quitter, NULL, pSdlMenu->surface_ecran, &(pSdlMenu->positionQuitter));
	SDL_BlitSurface(pSdlMenu->surface_credits, NULL, pSdlMenu->surface_ecran, &(pSdlMenu->positionCredits));


}






void sdlMenuBoucle(sdlMenu *pSdlMenu, sdlJeu *pSdlJeu, sdlCredits *pSdlCredits, sdlFin *pSdlFin)
{
	SDL_Event event;
	int continue_boucle = 1;
	int ptypefin;
	

	sdlMenuAff(pSdlMenu);
	assert( SDL_Flip( pSdlMenu->surface_ecran )!=-1 );

	Mix_PlayMusic(pSdlMenu->musiquemenu, -1);

	while ( continue_boucle == 1 )
	{
		SDL_WaitEvent(&event);

		switch(event.type)
		{
			case SDL_QUIT :
				continue_boucle = 0;
				break;
			
			case SDL_MOUSEBUTTONUP:


				if((event.button.x>pSdlMenu->positionCredits.x)&&(event.button.x<(pSdlMenu->positionCredits.x)+127)&&(event.button.y<(pSdlMenu->positionCredits.y)+63)&&(event.button.y>pSdlMenu->positionCredits.y))
				{
					sdlCreditsInit(pSdlCredits);
					sdlCreditsBoucle(pSdlCredits);
					sdlMenuAff(pSdlMenu);
					SDL_Flip (pSdlMenu->surface_ecran);
					Mix_PlayMusic(pSdlMenu->musiquemenu,-1);
					sdlCreditsDetruit(pSdlCredits);
				}

				if((event.button.x>pSdlMenu->positionJouer.x)&&(event.button.x<(pSdlMenu->positionJouer.x)+127)&&(event.button.y<(pSdlMenu->positionJouer.y)+63)&&(event.button.y>pSdlMenu->positionJouer.y))
				{
					do{
					sdljeuInit( pSdlJeu,pSdlMenu->niveau );
					sdljeuBoucle( pSdlJeu, pSdlMenu->niveau);
					ptypefin=JeuTestFinNiveau(&(pSdlJeu->jeu));
					sdljeuDetruit(pSdlJeu);
					if(ptypefin!=0)
					{
						(pSdlMenu->niveau)++;
						sdlFinInit(pSdlFin);
						sdlFinBoucle(pSdlFin,ptypefin);
						sdlFinDetruit(pSdlFin);
					}
					}while(ptypefin==1);
					sdlMenuAff(pSdlMenu);
					SDL_Flip (pSdlMenu->surface_ecran);
					Mix_PlayMusic(pSdlMenu->musiquemenu,-1);
				}
				
				if((event.button.x>pSdlMenu->positionQuitter.x)&&(event.button.x<(pSdlMenu->positionQuitter.x)+127)&&(event.button.y<(pSdlMenu->positionQuitter.y)+63)&&(event.button.y>pSdlMenu->positionQuitter.y))
				{
						continue_boucle=0;
				}
				break;

		}
	}


	/** On affiche le jeu sur le buffer caché */
	sdlMenuAff(pSdlMenu);

	/** On permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans a boucle) */
	SDL_Flip( pSdlMenu->surface_ecran );


}


void sdlMenuDetruit( sdlMenu *pSdlMenu, sdlJeu *pSdlJeu)
{
	SDL_FreeSurface( pSdlMenu->surface_bg);
	/*SDL_FreeSurface( pSdlMenu->surface_titre);*/
	SDL_FreeSurface( pSdlMenu->surface_jouer);
	SDL_FreeSurface( pSdlMenu->surface_credits);
        SDL_FreeSurface( pSdlMenu->surface_quitter);
	Mix_FreeMusic(pSdlMenu->musiquemenu);
	Mix_CloseAudio();
	SDL_Quit();
}
