#include <stdio.h>
#ifdef WIN32
#include <curses.h>
#else
#include <ncurses.h>
#endif

#include "Jeu.h"

void ncursAff( WINDOW* win, const Jeu *pJeu)
{
	int x,y;
 
	int row = getDimY(jeuGetConstTerrainPtr(pJeu));
        int col = getDimX(jeuGetConstTerrainPtr(pJeu));

	const Terrain *pTer = jeuGetConstTerrainPtr(pJeu);
	const Auto *pAuto = jeuGetConstAutoPtr(pJeu);
	
	wclear(win);

	for(x=0;x<getDimX(pTer);++x)
		for(y=0;y<getDimY(pTer);++y)
			mvwprintw( win, y, x, "%c", terGetXY(pTer,x,y) );

	mvwprintw( win, autoGetY(pAuto), autoGetX(pAuto), "*");

	wmove( win, autoGetY(pAuto), autoGetX(pAuto));

	mvwprintw(win,row,(col/2)-3,"PACMAN");
       
}


void ncursBoucle(Jeu *pJeu)
{
	WINDOW *win;
	int c;
	int continue_boucle;

	initscr();		/* passe l'écran texte en mode NCurses */
	clear();		/* efface l'écran */
	noecho();  	/* Lorsqu'une touche est préssée au clavier, elle n'apparait pasa à l'écran */
	cbreak();		/* un autoactère est directement affiché, il ne passe pas dans un buffer */
		
	/* Creation d'une nouvelle fenetre en mode texte */
	/* => fenetre de dimension et position ( WIDTH, HEIGHT, STARTX,STARTY) */
	win = newwin( getDimY(jeuGetConstTerrainPtr(pJeu))+1, getDimX(jeuGetConstTerrainPtr(pJeu)), 10, 5 );	
	keypad(win, TRUE);		/* pour que les flèches soient traitées (il faut le faire après création de la fenêtre) */

	halfdelay( 10 );
	/* notimeout(win,true); */
	/* wtimeout( win, 500 ); */
	/* nodelay(win,true); */

	
			      

	continue_boucle = 1;
	do
	{	
		ncursAff( win, pJeu);
	
		c = wgetch(win);
		/* jeuActionClavier( jeu, 'd'); */
		switch(c)
		{	
			case KEY_LEFT:
				jeuActionClavier( pJeu, 'g');
				break;
			case KEY_RIGHT:
				jeuActionClavier( pJeu, 'd');
				break;
			case KEY_UP:
				jeuActionClavier( pJeu, 'h');
				break;
			case KEY_DOWN:
				jeuActionClavier( pJeu, 'b');
				break;
			case 27: /* ECHAP */
				continue_boucle = 0;
				break;
		}
	} while (continue_boucle==1);
	
	endwin();
}
