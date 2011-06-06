
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
void autoInit(Auto *, Terrain *);

/** Deplace le joueur à gauche*/
void autoGauche(Auto *, const Terrain *);
/** Deplace le joueur à droite*/
void autoDroite(Auto *, const Terrain *);
/** Deplace le joueuren haut*/
void autoHaut(Auto *, const Terrain *);
/** Deplace le joueur en bas*/
void autoBas(Auto *, const Terrain *);

/**Recupere la coordonnee X du joueur*/
int autoGetX(const Auto *);
/**Recupere la coordonnee Y du joueur*/
int autoGetY(const Auto *);

/**Modifie la coordonne X du joueur*/
void autoSetX(Auto *, const int x);
/**Modifie la coordonne Y du joueur*/
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
