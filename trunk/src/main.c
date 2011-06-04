#include <stdio.h>

#ifdef JEU_NCURSES
#include "ncursMenu.h"
#endif

#ifdef JEU_SDL
#include "sdlJeu.h"
#include "sdlMenu.h"
#endif


int main ( int argc, char** argv )
{

#ifdef JEU_NCURSES
    Menu m;
    menuInit(m);
    menuAjouterLigne(m,"Quitter",Quitter);
    menuAjouterLigne(m,"Jouer",jouer);
    /*menuAjouterLigne(m,"Credit",credit);*/
    menuLoop(m);
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






