
#ifndef _CAR_H
#define _CAR_H

#include "Terrain.h"

typedef struct 
{
	int x,y;
	int nbsurvi;
	int pdv;
} Auto;


void autoInit(Auto *);
void autoGauche(Auto *, const Terrain *);
void autoDroite(Auto *, const Terrain *);
void autoHaut(Auto *, const Terrain *);
void autoBas(Auto *, const Terrain *);
int autoGetX(const Auto *);
int autoGetY(const Auto *);


#endif
