#include "DesZombies.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>


void dZombieInit(DesZombies * pdzom)
{
	(pdzon*).nbz=0;
	(pdzon*).zomrest=0;
}

void dZombieLibere(DesZombies * pdzon)
{
	int i = 0;
	while(i < pdzon.nbz)
	{
		if((pdzom*).zombies[i] == NULL );
		{
			free((pdzom*).zombies[i]);
			(pdzom*).zombies[i] = NULL;
		}
		i++;
	}
	(pdzon*).nbz=0;
	(pdzon*).zomrest=0;
}
void AjouterZombie(DesZombies * pdzom, int x , int y , int i)
{
	(pdzom*).zombies[i] = (Zombie*)malloc(sizeof(Zombie));
	ZombieInit(&(pdzon*).zombies[i] , x, y);
	(pdzon*).nbz=pdzon.nbz + 1;
	(pdzon*).zomrest=pdzonzomrest + 1;
}

void SupprimeZombie((DesZombies *pdzon,  int i)
{
		free((pdzom*).zombies[i]);
		(pdzom*).zombies[i] = NULL;
		(pdzon*).nbz=pdzon.nbz - 1;
		(pdzon*).zomrest=pdzon.zomrest - 1;
}
	
Zombie dGetZombie(DesZombies *, int )
{
	return pdzon.zombies[i];
}

//void dSetZombie(DesZombies *,int, int);
//void dZombieDeplacer(DesZombies *);
