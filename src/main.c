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
                       if(sj.findepartie!=0)
                        {
				sm.changerfenetre=0;
                                sdljeuDetruit( &sj );
                        }
                }
        }while(sm.changerfenetre==0);
        sdlMenuDetruit(&sm);


#endif

	printf("Fin\n");
	return 0;
}






