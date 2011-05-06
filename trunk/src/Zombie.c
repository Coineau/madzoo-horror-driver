#include "Zombie.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

void zombieInit(Zombie *pZon ,int cx ,int cy)
{
	pZon->x=cx;
	pZon->y=cy;
  pZon->xa=cx;
  pZon->ya=cy;
}

int zombieGetX(const Zombie* pZon)
{
	return pZon->x;
}

int zombieGetY(const Zombie* pZon)
{
	return pZon->y;
}

void zombieSetX(Zombie* pZon,int cx)
{
    pZon->x = cx ;
}

void zombieSetY(Zombie* pZon,int cy)
{
    pZon->y = cy;
}

int zombieGetXA(const Zombie* pZon)
{
	return pZon->xa;
}

int zombieGetYA(const Zombie* pZon)
{
	return pZon->ya;
}

void zombieSetXA(Zombie* pZon,int cx)
{
    pZon->xa = cx ;
}

void zombieSetYA(Zombie* pZon,int cy)
{
    pZon->ya= cy;
}

int testDeplacementZombie(Terrain* pTer ,int Xz,int  Yz)
{
     if((terEstPositionPersoValide(pTer,Xz, Yz) == 1) &&
        (terEstPositionSurvivant(pTer, Xz,Yz) !=1) &&
        (terEstPositionZombie(pTer, Xz, Yz)))
        {
            return 1;
        }
    return 0;
}

/*void zombieDeplacement(const Zombie * pZon,int Xa,int  Ya,Terrain *Pter)
{
    int Xz=zombieGetX(pZon);
    int Yz=zombieGetY(pZon);
    float d=sqrt(sqr(Xa-Xz)+sqr(Ya-Yz));
    if(d < 4)
    {
        
    }
}
}*/




int zombieGetPdv(const Zombie * pZon)
{
	return pZon->pdv;
}

void zombieSetPdv(Zombie * pZon, int pv)
{
	pZon->pdv=pv;
}
