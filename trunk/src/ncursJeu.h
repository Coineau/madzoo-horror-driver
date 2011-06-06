
#ifndef _NCURSJEU_H
#define _NCURSJEU_H

#include "Jeu.h"

/** boucle du jeux */
void ncursBoucle(Jeu *pJeu , int niveau);

/** deux choix( le joueur perd et sa quite sinon il change de lvl )*/
void ncursFinJeu(Jeu *pJeu , int niveau);

#endif
