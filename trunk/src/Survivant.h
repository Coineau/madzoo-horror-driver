#ifndef _Survivant_H
#define _Survivant_H

#include "Terrain.h"

typedef struct 
{
	int x,y,etat;
} Survivant;

void surviInit(Survivant);
const int surviGetX(Survivant);
const int intsurviGetY(Survivant);
const int surviChangeEtat(Survivant);

#endif