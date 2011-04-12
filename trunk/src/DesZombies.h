#ifndef _DZOMBIE_H
#define _DZOMBIE_H

#include "Zombie.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct
{
	/** tableau conteanant tous le zombie du jeux */
	Zombie *zombies;
	/** le nombre de zombie dans le jeux */
	int nbz;
	/** nombre de zombie restant */
	int zomrest;
}DesZombies;

void dZombieInit(DesZombies *);
void dZombieLibere(DesZombies *);
void AjouterZombie(DesZombies *, Zombie );
void SupprimeZombie(DesZombies *);
//Zombie dGetZombie(DesZombies *, int );
//void dSetZombie(DesZombies *,int);
//void dZombieDeplacer(DesZombies *);

#endif
