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

/**Test si tous les survivants sont dans la voiture et les met dans l'etat sauvé*/
void dSurviSauve (DesSurvivants *);

/**Renvoie le survivant dont les coordonnees sont passees en parametre*/
Survivant* dGetSurvi(DesSurvivants *, const int x, const int y);

/**Renvoie le nombre total de survivants*/
int GetNbS (DesSurvivants *);

/**Modife le nombre total de survivants*/
void SetNbS (DesSurvivants *, const int);

#endif
