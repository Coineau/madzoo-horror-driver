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
void dsurviInit(DesSurvivants*, Terrain *);

/**Libere le tableau de survivants*/
void dsurviLibere(DesSurvivants *);

/**Supprime le survivant passe en parametre*/
void SupprimeSurvi(DesSurvivants *dsurvis, Survivant survi);

/**Test si tous les survivants ont ete sauves*/
int dSurviTestSauve (DesSurvivants *);

/**Renvoie le survivant dont les coordonnees sont passees en parametre*/
Survivant* dGetSurvi(DesSurvivants *, const int x, const int y);

/**Renvoie le nombre total de survivants*/
int GetNbS (DesSurvivants *);

/**Modife le nombre total de survivants*/
void SetNbS (DesSurvivants *, const int);

#endif
