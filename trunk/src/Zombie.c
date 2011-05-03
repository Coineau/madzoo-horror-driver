#include "Zombie.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

void zombieInit(Zombie * pZon ,int cx ,int cy)
{
	pZon->x=cx;
	pZon->y=cy;
}

int zombieGetX(const Zombie* pZon)
{
	return pZon->x;
}

int zombieGetY(const Zombie* pZon)
{
	return pZon->y;
}

void zombieSetX(zombie*,cx)
{
    pZon->x = cx ;
}

void zombieSetY(zombie*,y);
{
    pZon->y = cy;
}


int testDeplacementZombie(terrain* pter ,int Xz,int  Yz,Terrain *Pter)
{
     if((terEstPositionPersoValide(pTer,Xz, Yz) == 1) &&
        (terEstPositionSurvivant(pTer, Xz,Yz) !=1) &&
        (terEstPositionZombie(pTer, Xz, Yz)))
        {
            return 1;
        }
    return 0;
}

void zombieDeplacement(const Zombie * pZon,int Xa,int  Ya,Terrain *Pter)
{
    int Xz=zombieGetX(pZon);
    int Yz=zombieGetY(pZon);
    float d=sqrt(sqr(Xa-Xz)+sqr(Ya-Yz));
    if(d < 4)
    {
        if(Xz<Xa)
        {
            if(testDeplacementZombie(pter , Xz+1 , Yz,pTer)
            {
                zombieSetX(pZon , Xz+1 );
            }
            else{
                if(Yz>Ya)
                {
                    if(testDeplacementZombie(pter , Xz , Yz +1,pTer)
                       {
                           zombieSetY(pZon , Yz+1 );
                       }
                }
    }
}
}




int zombieGetPdv(const Zombie * pZon)
{
	return pZon->pdv;
}

void zombieSetPdv(Zombie * pZon, int pv)
{
	pZon->pdv=pv;
}
