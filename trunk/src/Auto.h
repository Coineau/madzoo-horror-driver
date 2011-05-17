
#ifndef _AUTO_H
#define _AUTO_H

#include "Terrain.h"

typedef struct 
{
	/**Coordonnées du joueur*/
	int x,y;
		
	/** PV restants*/
	int pdv;
	
	/** PV initiaux*/
	int pdvmax;
	
	/** Nombre de places occupées dans l'auto*/
	int nbSurviDansAuto;
	
	/** Nombre de places total*/
	int nbPlaces;

} Auto;

/** Initialise une structure Auto*/
void autoInit(Auto *);

/** Les quatres fonctions suivantes déplacent le joueur*/
void autoGauche(Auto *, const Terrain *);
void autoDroite(Auto *, const Terrain *);
void autoHaut(Auto *, const Terrain *);
void autoBas(Auto *, const Terrain *);

/**Les deux fonctions suivantes récuperent la position du joueur*/
int autoGetX(const Auto *);
int autoGetY(const Auto *);

/**Les deux fonctions suivantes modifient la position du joueur*/
void autoSetX(Auto *, const int x);
void autoSetY(Auto *, const int y);

/**Récupère les PV du joueur*/
int autoGetPdv(const Auto*);

/**Change les PV*/
void autoSetPdv(Auto*,int);

/**Récupère les PV totaux du joueur*/
int autoGetPdvMax(const Auto*);

/**Change les PV totaux*/
void autoSetPdvMax(Auto*,int);

/** Récupère le nombre de places total*/
int autoGetNbPlaces(const Auto*);

/** Change le nombre de places total*/
void autoSetNbPlaces(Auto*,int);

/** Récupère le nombre de places occupées*/
int autoGetnbSurviDansAuto(const Auto*);

/**Change le nombre de survivants dans l'auto*/
void autoSetnbSurviDansAuto(Auto*,int);

#endif
