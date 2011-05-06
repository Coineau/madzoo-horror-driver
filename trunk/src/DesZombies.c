#include "DesZombies.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


void dZombieInit(DesZombies * pdzon , Terrain *pTer )
{
	int i,j;
	int k =0;
	zombieSetnbz(pdzon,terGetnbz(pTer));
	int nbz = dzombieGetnbz(pdzon);
	int DimX = getDimX(pTer);
	int DimY = getDimy(pTer);
	*pdzon = (*Zombie)malloc(nbz * sizeof(Zombie));
	for(i=0; i < DimX ; i++)
	{
		for(j=0; j <DimY; j++)
		{
			if(terEstPositionZombie(pTer , i ,j) == 1)
			{
				int  =0;
				pdzon->zombies[k] = (Zombie*)malloc(sizeof(Zombie));
				zombieInit(pdzon->zombies[k] , i, j);
				k++;
			}
		}
	}
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
	free(pdzon);
}

/*void AjouterZombie(DesZombies * pdzon, terrain *pTer)
{
	int  =0;
	pdzon->zombies[i] = (Zombie*)malloc(sizeof(Zombie));
	zombieInit(pdzon->zombies[i] , x, y);
	pdzon->nbz=pdzon->nbz + 1;
	pdzon->zomrest=pdzon->zomrest + 1;
}*/

void SupprimeZombie(DesZombies *pdzon , Zombie pzon)
{
	
	int i = dzombieGetnbz(pdzon);
	Zombie e = pzon;
	pzon= pdzon->zombies[i-1];
	pdzon->zombies[i-1] = e;
	free(pdzon->zombies[i-1]);
	dzombieSetnbz(pdzon*, i-1);
}

/*void dZombieDeplacer(DesZombies pdzon* ,int autoX ,int autoY ,Terrrain pTer*)
{
    int i = 0;
	while(i < pdzon->nbz)
	{
		if(pdzon->zombies[i] != NULL );
		{
			zombieDeplacement(pdzon->zombies[i] ,autoX,autoY,pTer);
		}
		i++;
	}
}*/



int dzombieGetnbz(DesZombies pdzon* )
{
	return pdzon->nbz;
}

/*int dzombieGet(DesZombies pdzon* )
{
	return pdzon->zomrest;
}*/

void dzombieSetnbz(DesZombies pdzon*, int nbzi)
{
	pdzon->nbz=nbzi;
}
/*
void dzombieSetPdv(DesZombies pdzon* , int zomresti)
{
	pdzon->zomrest=zomresti;
}*/
