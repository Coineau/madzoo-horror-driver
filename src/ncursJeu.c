#include <stdio.h>
#include <stdlib.h>
#ifdef WIN32
#include <curses.h>
#else
#include <ncurses.h>
#endif

#include "Jeu.h"
#include "ncursJeu.h"

void ncursAff( WINDOW* win, const Jeu *pJeu,int niv)
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

    mvwprintw(win,row,(col/2)-10,"PV %d|Passengers %d/%d ", autoGetPdv(pAuto),autoGetnbSurviDansAuto(pAuto),autoGetNbPlaces(pAuto));
	mvwprintw(win,row+1,(col/2)-6,"MHD-niveau %d", niv);

}


void ncursBoucle(Jeu *pJeu , int niveau)
{
	WINDOW *win ;
	int niv = niveau ;
	int c;
	int continue_boucle;
	jeuInit(pJeu , niv);

	initscr();		/* passe l'écran texte en mode NCurses */
	clear();		/* efface l'écran */
	noecho();  	/* Lorsqu'une touche est pressée au clavier, elle n'apparait pas à l'écran */
	cbreak();		/* un autoactère est directement affiché, il ne passe pas dans un buffer */

	/* Creation d'une nouvelle fenetre en mode texte */
	/* => fenetre de dimension et position ( WIDTH, HEIGHT, STARTX,STARTY) */
	win = newwin( getDimY(jeuGetConstTerrainPtr(pJeu))+2, getDimX(jeuGetConstTerrainPtr(pJeu)), 10, 5 );
	keypad(win, TRUE);		/* pour que les flèches soient traitées (il faut le faire après création de la fenêtre) */

	halfdelay(10 );
	/* notimeout(win,true); */
	/* wtimeout( win, 500 ); */
	/* nodelay(win,true); */




	continue_boucle = 1;
	do
	{
		ncursAff( win, pJeu , niv);

		c = wgetch(win);
		switch(c)
		{
			case KEY_LEFT:
				jeuActionClavier( pJeu, 'g');
				jeuDeplaceZombies(pJeu);
				ncursFinJeu(pJeu , niv);
				if(JeuTestFinNiveau(pJeu) == 2)
					{
						continue_boucle=0;
					}
				break;
			case KEY_RIGHT:
				jeuActionClavier( pJeu, 'd');
				jeuDeplaceZombies(pJeu);
				ncursFinJeu(pJeu , niv);
				if(JeuTestFinNiveau(pJeu) == 2)
					{
						continue_boucle=0;
					}
				break;
			case KEY_UP:
				jeuActionClavier( pJeu, 'h');
				jeuDeplaceZombies(pJeu);
				ncursFinJeu(pJeu , niv);
				if(JeuTestFinNiveau(pJeu) == 2)
					{
						continue_boucle=0;
					}
				break;
			case KEY_DOWN:
				jeuActionClavier( pJeu, 'b');
				jeuDeplaceZombies(pJeu);
				ncursFinJeu(pJeu , niv);
				if(JeuTestFinNiveau(pJeu) == 2)
					{
						continue_boucle=0;
					}
				break;
			case 'q' :
				JeuLibere(pJeu);
				endwin();
				continue_boucle=0;
				break;

		}
	} while(continue_boucle==1);
}

void ncursFinJeu(Jeu *pJeu , int niveau)
{
	if(JeuTestFinNiveau(pJeu) == 2)
					{
						JeuLibere(pJeu);
						endwin();
						printf("Perdu \n");
					}
	if(JeuTestFinNiveau(pJeu) == 1)
					{
						JeuLibere(pJeu);
						endwin();
						printf("niveau %d \n", niveau);
						ncursBoucle(pJeu , niveau + 1);
					}
}


