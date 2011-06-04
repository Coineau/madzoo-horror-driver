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

        sdlMenuInit(&sm);
	while (sm.changerfenetre==0)
	{
		sdlMenuBoucle(&sm, &sj);
        }
        sdlMenuDetruit(&sm);


#endif

	printf("Fin\n");
	return 0;
}






