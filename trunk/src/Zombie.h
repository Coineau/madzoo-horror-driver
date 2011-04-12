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
void zombieInit(Zombie *,int,int);

/**Recupere la coordonner X d'un zombie*/
int zombieGetX(Zombie);
/recupere la coordonner Y d'un Zombie*/
int zombieGetY(Zombie*);
/**Deplacement du zombie sur le terrain 
 * il prend en compte le train*/
//void zombieDeplacement(zombie *,terrain);
/**recupere les point de vie du zombie */
int zombieGetPdv(Zombie);
/** modifie les point de vie du zombie */
void zombieSetPdv(Zombie *, int);

#endif
