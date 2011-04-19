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
    for(j=0;j<getDimY(pTer);j++)
    {
        for(i=0;i<getDimX(pTer);i++)
        {
            if (terEstPositionSurvivant(pTer,i,j)==1)
            {
                surviInit(&(dsurvis->tabS[k]), i,j);
                k=k+1;
            }
        }
    }
}

void dsurviLibere(DesSurvivants *dsurvis)
{
    free(dsurvis->tabS);
}

int dSurviTestSauve (DesSurvivants *dsurvis)
{
    int i;
    for (i=0;i<(GetNbS(dsurvis));i++)
    {
        if (surviGetEtat(&(dsurvis->tabS[i]))==0)
        {
            return 0;
        }
    }
    return 1;
}

Survivant dGetSurvi(DesSurvivants *dsurvis, const int x, const int y)
{
    int i;
    for (i=0;i<(GetNbS(dsurvis));i++)
    {
        if (surviGetX(&(dsurvis->tabS[i]))==x && surviGetY(&(dsurvis->tabS[i]))==y)
        {
            return dsurvis->tabS[i];
        }
    }
}

void SetNbS (DesSurvivants *dsurvis, const int n)
{
    dsurvis->nbS=n;
}

int GetNbS (DesSurvivants *dsurvis)
{
    return dsurvis->nbS;
}