#ifndef _ZOMBIE_H
#define _ZOMBIE_H

#include "Terrain.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef struct
{
	/** Coordonées du zombie au temps T */
	int x,y;
  /**Coordonnées du zombie au temps T-1*/
 int xa,ya;
	/** Points de vie du zombie */
	int pdv;
}Zombie;

/**Initialise une stucture zombie*/
void zombieInit(Zombie *,int x,int y);

/**Recupere la coordonnée x d'un zombie*/
int zombieGetX(const Zombie*);

/**Recupere la coordonnée y d'un zombie*/
int zombieGetY(const Zombie*);

/**Modifie la coordonée x du zombie*/
void zombieSetX(Zombie*,int x);

/**Modifie la coordonée y du zombie*/
void zombieSetY(Zombie*,int y);

/**Recupere la valeur de xa*/
int zombieGetXA(const Zombie*);

/**Recupere la valeur de ya*/
int zombieGetYA(const Zombie*);

/**Modifie la valeur de xa */
void zombieSetXA(Zombie*,int x);

/**Modifie la valeur de ya*/
void zombieSetYA(Zombie*,int y);

/**Recupere les points de vie du zombie */
int zombieGetPdv(const Zombie*);

/** Modifie les points de vie du zombie */
void zombieSetPdv(Zombie *, int);


/** DEPLACEMENT DU ZOMBIE !! **/


/** teste si la position du futur deplacement du zombie est valide ( sans mur ,ni de survivant ,ni de zombie )*/
int testDeplacementZombie(Zombie * ,Terrain* pTer ,int Xz,int  Yz);

/**Deplacement du zombie en fonction de l'auto*/
void zombieDeplacement(Zombie *,Terrain*,int autoX, int autoY);



#endif
