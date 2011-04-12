#include "DesZombies.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


void dZombieInit(DesZombies * pdzon)
{
	pdzon->nbz=0;
	pdzon->zomrest=0;
}

void dZombieLibere(DesZombies * pdzon)
{
	int i = 0;
	while(i < pdzon->nbz)
	{
		if(pdzon->zombies[i] == NULL );
		{
			free(pdzon->zombies[i]);
			pdzon->zombies[i] = NULL;
		}
		i++;
	}
	pdzon->nbz=0;
	pdzon->zomrest=0;
}
void AjouterZombie(DesZombies * pdzon, int x , int y , int i)
{
	pdzon->zombies[i] = (Zombie*)malloc(sizeof(Zombie));
	ZombieInit(&pdzon->zombies[i] , x, y);
	pdzon->nbz=pdzon.nbz + 1;
	pdzon->zomrest=pdzonzomrest + 1;
}

void SupprimeZombie((DesZombies *pdzon,  int i)
{
		free((pdzon->zombies[i]);
		pdzon->zombies[i] = NULL;
		pdzon->nbz=pdzon.nbz - 1;
		pdzon->zomrest=pdzon.zomrest - 1;
}
	
Zombie dGetZombie(DesZombies *, int )
{
	return pdzon.zombies[i];
}

//void dSetZombie(DesZombies *,int, int);
//void dZombieDeplacer(DesZombies *);
