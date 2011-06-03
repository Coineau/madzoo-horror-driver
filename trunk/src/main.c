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

/*#ifdef JEU_NCURSES
    Menu m;
    menuInit(m);
    menuAjouterLigne(m,"Quitter",Quitter);
    menuAjouterLigne(m,"Jouer",jouer);
    menuAjouterLigne(m,"Credit",credit);
    menuLoop(m);
    menuRun();
#endif*/

#ifdef JEU_SDL
	sdlJeu sj;
	sdlMenu sm;
	
	sdlMenuInit(&sm);
	do
	{
		sdlMenuBoucle(&sm);
		if(sm.changerfenetre==1)
		{
			sdljeuInit( &sj );
			sdljeuBoucle( &sj );
			if(sj.findepartie==2)
			{
				sdljeuDetruit( &sj );
				sm.changerfenetre=0;
			}
		}
	}while(sm.changerfenetre==0);
	sdlMenuDetruit(&sm);
	

#endif

	printf("Fin\n");
	return 0;
}






