#include "DesZombies.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


void dZombieInit(DesZombies * pdzon , Terrain *pTer )
{
	int i,j,nbz;
	int k = 0;
	int DimX = getDimX(pTer);
	int DimY = getDimY(pTer);
	dzombieSetnbZ(pdzon,terGetnbZ(pTer));
	nbz = dzombieGetnbZ(pdzon);
	pdzon->zombies = (Zombie**)malloc(nbz * sizeof(Zombie*));
	for(i=0; i < DimX ; i++)
	{
		for(j=0; j <DimY; j++)
		{
			if(terEstPositionZombie(pTer , i ,j) == 1)
			{
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

void SupprimeZombie(DesZombies *pdzon ,int autoX ,int autoY , Terrain * pTer)
{

	int i,y;
	Zombie* p;
	Zombie* e;
	y = 0;
	i = dzombieGetnbZ(pdzon);
	y = dzombieGetzomb(pdzon , autoX , autoY);
	e = pdzon->zombies[y];
	p= pdzon->zombies[i-1];
	pdzon->zombies[i-1] = e;
	pdzon->zombies[y] = p ;
	zombieSupr(e,pTer);
	dzombieSetnbZ(pdzon, i-1);

}

void dZombieDeplacer(DesZombies *pdzon ,int autoX ,int autoY ,Terrain *pTer)
{
    int i = 0;
	while(i < pdzon->nbz)
	{
		zombieDeplacementChoix(pdzon->zombies[i],pTer ,autoX,autoY);
		i++;
	}
}

int dzombieGetzomb(const DesZombies *pdzon,int Xz ,int Yz)
{
    int i,y;
    int Xe;
    int Ye;
    Zombie* e ;
    i = dzombieGetnbZ(pdzon);
    for(y =0 ; y <i ; y++)
    {
        e = pdzon->zombies[y];
        Xe=zombieGetX(e);
        Ye=zombieGetY(e);
        if(Xe == Xz && Ye == Yz )
        {
            return y;
        }
    }
    return 0;
}

int dzombieGetnbZ(const DesZombies *pdzon )
{
	return pdzon->nbz;
}



void dzombieSetnbZ(DesZombies *pdzon, int nbzi)
{
	pdzon->nbz=nbzi;
}

