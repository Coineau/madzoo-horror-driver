#ifndef _Survivant_H
#define _Survivant_H

#include "Terrain.h"

typedef struct
{
	/**Coordonnees (x,y) du survivant sur la carte"*/
	int x,y;
	/**0 si n'est pas dans la voiture, 1 sinon"*/
	int etat;

} Survivant;

/**Place le survivant a sa position initiale*/
void surviInit(Survivant*, const int x, const int y);

/***/
void surviLibere(Survivant*);

/**Renvoi la coordonnee x du survivant*/
int surviGetX(const Survivant *);

/**Renvoi la coordonnee y du survivant*/
int surviGetY(const Survivant *);

/**Renvoi l etat du survivant*/
int surviGetEtat(const Survivant *);

/**Modifie l etat du survivant*/
int surviSetEtat(Survivant *, const int);

#endif
