#include <stdio.h>

#ifdef JEU_NCURSES
#include "ncursJeu.h"
#endif

#ifdef JEU_SDL
#include "sdlJeu.h"
#endif


int main ( int argc, char** argv )
{



#ifdef JEU_SDL
	sdlJeu sj;
	sdljeuInit( &sj );
	sdljeuBoucle( &sj );
	sdljeuDetruit( &sj );
#endif

	printf("Fin\n");
	return 0;
}



/*
  #ifdef JEU_NCURSES
 	Jeu jeu;
 	jeuInit(&jeu);
	ncursBoucle(&jeu);
  #endif
*/
