#ifndef _Survivant_H
#define _Survivant_H

#include "Terrain.h"

typedef struct
{
	int x,y; /*Coordonnees (x,y) du survivant sur la carte"*/
	int etat; /*0 si n'est pas dans la voiture, 1 sinon"*/

} Survivant;

void surviInit(Survivant*, const int x, const int y);
void surviLibere(Survivant*);
int surviGetX(Survivant *);
int surviGetY(Survivant *);
int surviGetEtat(Survivant *);
int surviSetEtat(Survivant *, const int);

#endif
