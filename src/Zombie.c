#include "Zombie.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <math.h>

void zombieInit(Zombie *pZon ,int cx ,int cy)
{
        pZon->x=cx;
        pZon->y=cy;
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


int zombieGetPdv(const Zombie * pZon)
{
        return pZon->pdv;
}

void zombieSetPdv(Zombie * pZon, int pv)
{
        pZon->pdv=pv;
}

void zombieSupr(Zombie *pZon,Terrain* pTer)
{
    int Xz;
    int Yz;
    Xz=zombieGetX(pZon);
    Yz=zombieGetY(pZon);
    free(pZon);
    terSetXY(pTer, Xz, Yz, ' ');
}


/** DEPLACEMENT DU ZOMBIE !! */

int testDeplacementZombie(Terrain* pTer ,int Xz,int  Yz)
{
     if((terEstPositionPersoValide(pTer,Xz, Yz) == 1) &&
        (terEstPositionSurvivant(pTer, Xz, Yz) !=1 ) &&
        (terEstPositionZombie(pTer, Xz, Yz) != 1 ) &&
        (terEstPositionHeli(pTer, Xz, Yz) != 1))
        {
            return 1;
        }
    return 0;
}

void zombieDeplacementChoix(Zombie* pZon,Terrain *pTer,int Xa,int  Ya)
{
    float d;
    int Xz;
    int Yz;
    Xz=zombieGetX(pZon);
    Yz=zombieGetY(pZon);

    d = sqrt((Xz - Xa )*(Xz - Xa )+ (Yz - Ya)*(Yz - Ya));
    if(d <= 4)
    {
        zombieDeplacementAgro(pZon,pTer,Xa,Ya);
    }
    else
    {
        zombieDeplacementAleat(pZon,pTer);
    }
}

void zombieDeplacementAgro(Zombie * pZon,Terrain *pTer,int Xa,int  Ya)
{
    int Xz;
    int Yz;
    int Xt;
    int Yt;
    Xz=zombieGetX(pZon);
    Yz=zombieGetY(pZon);
    Xt = Xa - Xz;
    Yt = Ya - Yz;
    if(abs(Xt) > abs(Yt ))
    {
        if(Xt > 0)
        {
             if(testDeplacementZombie(pTer ,Xz+1,Yz))
            {
                zombieSetX(pZon,Xz+1);
                                terSetXY(pTer, Xz, Yz, ' ');
                                terSetXY(pTer, Xz+1, Yz, 'z');

            }
            else
            {
                zombieDeplacementAleat(pZon,pTer);
            }
        }
        else
        {
            if(testDeplacementZombie(pTer ,Xz-1,Yz))
            {
                zombieSetX(pZon,Xz-1);
                terSetXY(pTer, Xz, Yz, ' ');
                terSetXY(pTer, Xz-1, Yz, 'z');
            }
            else
            {
                zombieDeplacementAleat(pZon,pTer);
            }
        }
    }
    else
    {
        if(Yt>0)
        {
             if(testDeplacementZombie(pTer ,Xz,Yz+1))
            {
                zombieSetY(pZon,Yz+1);
                terSetXY(pTer, Xz, Yz, ' ');
                terSetXY(pTer, Xz,Yz+1, 'z');
            }
            else
            {
                zombieDeplacementAleat(pZon,pTer);
            }

        }
        else
        {
             if(testDeplacementZombie(pTer ,Xz,Yz-1))
             {
                zombieSetY(pZon,Yz-1);
                terSetXY(pTer, Xz, Yz, ' ');
                terSetXY(pTer, Xz, Yz-1, 'z');
             }
             else
            {
                zombieDeplacementAleat(pZon,pTer);
            }
        }
    }
}

void zombieDeplacementAleat(Zombie * pZon,Terrain *pTer)
{
    int dir;
    int i;
    int sommesol;
    char tabdir[4];
    int r;
    int Xz;
    int Yz;

    r = rand();
    Xz=zombieGetX(pZon);
    Yz=zombieGetY(pZon);

    if(testDeplacementZombie(pTer ,Xz,Yz-1))
    {
        tabdir[0]=1;
    }
    else
    {
         tabdir[0]=0;
    }

    if(testDeplacementZombie(pTer ,Xz-1,Yz))
    {
        tabdir[1]=1;
    }
    else
    {
        tabdir[1]=0;
    }
    if(testDeplacementZombie(pTer ,Xz,Yz+1))
    {
        tabdir[2]=1;
    }
    else
    {
        tabdir[2]=0;
    }
    if(testDeplacementZombie(pTer ,Xz+1,Yz))
    {
        tabdir[3]=1;
    }
    else
    {
        tabdir[3]=0;
    }

    sommesol = 0 ;
    for(i = 0 ; i <4 ; i++)
    {
        sommesol = sommesol + tabdir[i];
    }
    if(sommesol!=0)
    {
    r = rand()%sommesol;

    i=0 ;
    dir = 0;
    while(i != 4)
    {
        if(tabdir[i] == 1)
        {
            if(r == 0)
            {
                dir = i;
                r--;
            }
            else
            {
                r --;
            }

        }
        i++;

    }

        switch(dir)
        {
        case 0 :
                                zombieSetY(pZon,Yz-1);
                                terSetXY(pTer, Xz, Yz, ' ');
                                terSetXY(pTer, Xz, Yz-1, 'z');
                                break;
                case 1 :
                                zombieSetX(pZon,Xz-1);
                                terSetXY(pTer, Xz, Yz, ' ');
                                terSetXY(pTer, Xz-1, Yz, 'z');
                                break;
                case 2 :
                                zombieSetY(pZon,Yz+1);
                                terSetXY(pTer, Xz, Yz, ' ');
                                terSetXY(pTer, Xz,Yz+1, 'z');
                                break;
                case 3 :
                                zombieSetX(pZon,Xz+1);
                                terSetXY(pTer, Xz, Yz, ' ');
                                terSetXY(pTer, Xz+1, Yz, 'z');
                                break;
        default : break;
        }
    }



}
