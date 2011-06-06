
#ifndef _NCURSJEU_H
#define _NCURSJEU_H

#include "Jeu.h"

void ncursBoucle(Jeu *pJeu , int niveau);

void ncursAff( WINDOW* win, const Jeu *pJeu,int niv);

void ncursFinJeu(Jeu *pJeu , int niveau);

#endif
