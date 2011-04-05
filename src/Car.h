
#ifndef _CAR_H
#define _CAR_H

#include "Terrain.h"

typedef struct 
{
	int x,y;
	int nbsurvi;
	int pdv;
} Car;


void carInit(Car *);
void carGauche(Car *, const Terrain *);
void carDroite(Car *, const Terrain *);
void carHaut(Car *, const Terrain *);
void carBas(Car *, const Terrain *);
int carGetX(const Car *);
int carGetY(const Car *);


#endif
