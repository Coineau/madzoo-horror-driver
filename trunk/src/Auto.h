
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

/** Initialise une structure Auto*/
void autoInit(Auto *);

/** Les quatres fonctions suivantes d�placent le joueur*/
void autoGauche(Auto *, const Terrain *);
void autoDroite(Auto *, const Terrain *);
void autoHaut(Auto *, const Terrain *);
void autoBas(Auto *, const Terrain *);

/**Les deux fonctions suivantes r�cuperent la position du joueur*/
int autoGetX(const Auto *);
int autoGetY(const Auto *);

/**R�cup�re les PV du joueur*/
int autoGetPdv(const Auto*);

/**Change les PV*/
void autoSetPdv(Auto*,int);

/** R�cup�re le nombre de places total*/
int autoGetNbPlaces(const Auto*);

/** Change le nombre de places total*/
void autoSetNbPlaces(Auto*,int);

/** R�cup�re le nombre de places occup�es*/
int autoGetnbSurviDansAuto(const Auto*);

/**Change le nombre de places occup�es*/
void autoSetnbSurviDansAuto(Auto*,int);


//void autoLibere(Auto*);
#endif
