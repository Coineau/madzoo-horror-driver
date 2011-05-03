#ifndef _ZOMBIE_H
#define _ZOMBIE_H

#include "Terrain.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

typedef struct
{
	/** coordoner du zombie */
	int x,y;
	/** point de vie du zombie */
	int pdv;
}Zombie;

/**Initialise une stucture zombie*/
void zombieInit(Zombie *,int x,int y);

/**Recupere la coordonner X d'un zombie*/
int zombieGetX(const Zombie*);

/**recupere la coordonner Y d'un Zombie*/
int zombieGetY(const Zombie*);

/**modifie la coordoner x du zombieù*/
void zombieSetX(zombie*;int x);

/**modifie la coordoner y du zombieù*/
void zombieSetY(zombie*,int y);

/**test si sur le chemain il y est un mur , un zombie ou un survivant*/
int testDeplacementZombie(terrain* pter ,int Xz,int  Yz,Terrain *Pter)

/**deplacement du zombie en fonction de l'auto*/
void zombieDeplacement(zombie *,int autoX, int autoY,Terrain*);

/**recupere les point de vie du zombie */
int zombieGetPdv(const Zombie*);

/** modifie les point de vie du zombie */
void zombieSetPdv(Zombie *, int);

#endif
