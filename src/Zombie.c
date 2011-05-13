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
	pZon->pdv=1; 
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


int zombieGetPdv(const Zombie * pZon)
{
	return pZon->pdv;
}

void zombieSetPdv(Zombie * pZon, int pv)
{
	pZon->pdv=pv;
}


/** DEPLACEMENT DU ZOMBIE !! */


int testDeplacementZombie(Terrain* pTer ,int Xz,int  Yz)
{
     if((terEstPositionPersoValide(pTer,Xz, Yz) == 1) &&
        (terEstPositionSurvivant(pTer, Xz, Yz) !=1 ) &&
        (terEstPositionZombie(pTer, Xz, Yz) != 1 ))
        {
            return 1;
        }
    return 0;
}

void zombieDeplacement(Zombie * pZon,Terrain *pTer,int Xa,int  Ya)
{
    int z;
    int y;
    int s;
    char i[4];
    int r;
    int Xz;
    int Yz;

    r = rand();
    Xz=zombieGetX(pZon);
    Yz=zombieGetY(pZon);

    if(testDeplacementZombie(pTer ,Xz,Yz-1))
    {
        i[0]=1;
    }
    else
    {
         i[0]=0;
    }

    if(testDeplacementZombie(pTer ,Xz-1,Yz))
    {
        i[1]=1;
    }
    else
    {
        i[1]=0;
    }
    if(testDeplacementZombie(pTer ,Xz,Yz+1))
    {
        i[2]=1;
    }
    else
    {
        i[2]=0;
    }
    if(testDeplacementZombie(pTer ,Xz+1,Yz))
    {
        i[3]=1;
    }
    else
    {
        i[3]=0;
    }

    s = 0 ;
    for(y = 0 ; y <4 ; y++)
    {
        s = s + i[y];
    }

    r = rand()%s;

    y =0 ;
    while(y != 4)
    {
        if(i[y] == 1)
        {
            if(r == 0)
            {
                z = y;
                r--;
            }
            else
            {
                r --;
            }

        }
        y++;

    }

	switch(z)
	{
        case 0 :
				zombieSetY(pZon,Yz-1);
				break;
		case 1 :
				zombieSetX(pZon,Xz-1);
				break;
		case 2 :
				zombieSetY(pZon,Yz+1);
				break;
		case 3 :
				zombieSetX(pZon,Xz+1);
				break;
	}


}



