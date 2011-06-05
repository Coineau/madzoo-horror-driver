#include <stdio.h>

#ifdef JEU_NCURSES
#include "ncursMenu.h"
#include "ncursJeu.h"
#endif

#ifdef JEU_SDL
#include "sdlJeu.h"
#include "sdlMenu.h"
#include "sdlCredits.h"
#endif


int main ( int argc, char** argv )
{

#ifdef JEU_NCURSES
MenuNcurs();


#endif
	

#ifdef JEU_SDL
	sdlMenu sm;
	sdlJeu sj;
	sdlCredits sc;
	
	
	/**Jeu avec menu*/
        sdlMenuInit(&sm);
	sdlMenuBoucle(&sm, &sj, &sc);
        sdlMenuDetruit(&sm, &sj);
	
	
	
	/**Jeu sans menu*/
	/*sdlJeu sj;
	sdljeuInit( &sj);
	sdljeuBoucle( &sj );
	sdljeuDetruit( &sj);*/


#endif

	printf("Fin\n");
	return 0;
}






