
#ifndef _AUTO_H
#define _AUTO_H

#include "Terrain.h"

typedef struct 
{
	int x,y;
	int nbSurviDansAuto;
	int pdv;
	int nbPlaces;
} Auto;


void autoInit(Auto *);
void autoGauche(Auto *, const Terrain *);
void autoDroite(Auto *, const Terrain *);
void autoHaut(Auto *, const Terrain *);
void autoBas(Auto *, const Terrain *);
int autoGetX(const Auto *);
int autoGetY(const Auto *);
int autoGetPdv(const Auto*);
void autoSetPdv(Auto*,int);
int autoGetNbPlaces(const Auto*);
void autoSetNbPlaces(Auto*,int);
int autoGetnbSurviDansAuto(const Auto*);
void autoSetnbSurviDansAuto(Auto*,int);


//void autoLibere(Auto*);
#endif
