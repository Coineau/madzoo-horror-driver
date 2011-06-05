#include <stdio.h>

#ifdef JEU_NCURSES
#include "ncursMenu.h"
#include "ncursJeu.h"
#endif

#ifdef JEU_SDL
#include "sdlJeu.h"
#include "sdlMenu.h"
#endif


int main ( int argc, char** argv )
{

#ifdef JEU_NCURSES
MenuNcurs();


#endif
	

#ifdef JEU_SDL
       sdlMenu sm;
	sdlJeu sj;
	
	
	/**Jeu avec menu*/
        sdlMenuInit(&sm);
	sdlMenuBoucle(&sm, &sj);
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






