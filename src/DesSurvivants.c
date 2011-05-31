#include "DesSurvivants.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>


void dSurviInit(DesSurvivants *dsurvis, Terrain *pTer)
{
    int i, j;
    int k = 0;
    SetNbS (dsurvis, terGetnbS(pTer));
    dsurvis->tabS = (Survivant*)malloc(GetNbS(dsurvis)*sizeof(Survivant));
    for(i=0;i<getDimX(pTer);i++)
    {
        for(j=0;j<getDimY(pTer);j++)
        {
            if (terEstPositionSurvivant(pTer,i,j)==1)
            {
                surviInit(&(dsurvis->tabS[k]), i,j);
                k=k+1;
            }
        }
    }
    void SetNbSurviSauv(dsurvis,0);
}

void dsurviLibere(DesSurvivants *dsurvis)
{
    free(dsurvis->tabS);
}

void dSurviSauve (DesSurvivants *dsurvis)
{
    int i;
    for (i=0;i<(GetNbS(dsurvis));i++)
    {
        if (surviGetEtat(&(dsurvis->tabS[i]))==1)
        {
            surviSetEtat(&(dsurvis->tabS[i]),2);
        }
    }
}

Survivant* dGetSurvi(DesSurvivants *dsurvis, const int x, const int y)
{
    int i;
    for (i=0;i<(GetNbS(dsurvis));i++)
    {
        if (surviGetX(&(dsurvis->tabS[i]))==x && surviGetY(&(dsurvis->tabS[i]))==y)
        {
            return &(dsurvis->tabS[i]);
        }
    }
    return NULL;
}

void SetNbS (DesSurvivants *dsurvis, const int n)
{
    dsurvis->nbS=n;
}

int GetNbS (DesSurvivants *dsurvis)
{
    return dsurvis->nbS;
}


int GetNbSurviSauv(DesSurvivants *dsurvis)
{
    return dsurvis->nbSurviSauv;
}

void SetNbSurviSauv(DesSurvivants *dsurvis, const int n)
{
    dsurvis->nbSurviSauv=n;
}
