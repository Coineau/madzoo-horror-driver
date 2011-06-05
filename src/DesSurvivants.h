#ifndef _DesSurvivants_H
#define _DesSurvivants_H

#include "Survivant.h"

typedef struct
{
    /**Tableau 1D de survivants*/
	Survivant *tabS;
	/**Nombre de survivant*/
	int nbS;

} DesSurvivants;

/**Initialise les survivants en les placant sur le terrain*/
void dSurviInit(DesSurvivants*, Terrain *);

/**Libere le tableau de survivants*/
void dsurviLibere(DesSurvivants *);

/**Passe les survivants de l'etat dans la voiture a l'etat sauve*/
void dSurviSauve (DesSurvivants *);

/**Renvoie 1 si tous les survivants sont sauves 0 sinon*/
int dSurviTestTousSauve (DesSurvivants *);

/**Renvoie le nombre de survivants non sauve*/
int dSurviRestant (DesSurvivants *dsurvis);

/**Renvoie le survivant dont les coordonnees sont passees en parametre*/
Survivant* dGetSurvi(DesSurvivants *, const int x, const int y);

/**Renvoie le nombre total de survivants*/
int GetNbS (DesSurvivants *);

/**Modife le nombre total de survivants*/
void SetNbS (DesSurvivants *, const int);

#endif
