#ifndef _ZOMBIE_H
#define _ZOMBIE_H

#include "Terrain.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <math.h>

typedef struct
{
	/** Coordonées du zombie au temps T */
	int x,y;
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

/**Recupere les points de vie du zombie */
int zombieGetPdv(const Zombie*);

/** Modifie les points de vie du zombie */
void zombieSetPdv(Zombie *, int);

/** Suprimer Zombie x, y */
void zombieSupr(Zombie *, Terrain* pTer);


/** DEPLACEMENT DU ZOMBIE !! **/


/** Teste si la position du futur deplacement du zombie est valide ( sans mur ,ni de survivant ,ni de zombie , ni heliport )*/
int testDeplacementZombie(Terrain* pTer ,int Xz,int  Yz);

/** Test la distance entre le zombie et la voiture pour choisire si il va sur la voiture ou se deplace alleatoirement */
void zombieDeplacementChoix(Zombie * pZon,Terrain *pTer,int Xa,int  Ya);

/** Deplace le zombie vers la voiture si il est a un distance d < 4 de la voiture .
    Si il est bloquer renvoi sur  zombieDeplacementAleat . */
void zombieDeplacementAgro(Zombie * pZon,Terrain *pTer,int Xa,int  Ya);

/**Deplacement aleatoire du zombie */
void zombieDeplacementAleat(Zombie *,Terrain*);



#endif
