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
	zombieInit(pdzon->zombies[i] , x, y);
	pdzon->nbz=pdzon->nbz + 1;
	pdzon->zomrest=pdzon->zomrest + 1;
}

void SupprimeZombie(DesZombies *pdzon,  int i)
{
		free(pdzon->zombies[i]);
		pdzon->zombies[i] = NULL;
		pdzon->zomrest=pdzon->zomrest - 1;
}

//void dZombieDeplacer(DesZombies *);
