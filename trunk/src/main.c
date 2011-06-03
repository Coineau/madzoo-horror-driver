#include <stdio.h>

#ifdef JEU_NCURSES
#include "menu.h"
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
    //menuAjouterLigne(m,"Credit",credit);
    menuLoop(m);
    menuRun();
#endif

#ifdef JEU_SDL
	sdlJeu sj;
	/*sdlMenu sm;
	sdlMenuInit(&sm);
	sdlMenuBoucle(&sm);
	sdlMenuDetruit(&sm);*/
	sdljeuInit( &sj );
	sdljeuBoucle( &sj );
	sdljeuDetruit( &sj );
#endif

	printf("Fin\n");
	return 0;
}






