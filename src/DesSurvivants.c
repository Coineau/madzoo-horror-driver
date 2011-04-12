#include "DesSurvivants.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>


void dSurviInit(DesSurvivants *dsurvis, Terrain *pTer)
{
    int i, j;
    int k = 0;
    dsurvis->tabS = (Survivant*)malloc(terGetnbS(&pTer)*sizeof(Survivant));
    for(j=0;j<getDimY(&pTer);j++)
    {
        for(i=0;i<getDimX(&pTer);i++)
        {
            if (terEstPositionSurvivant(&pTer,i,j)==1)
            {
                surviInit(tabS[k], i,j);
                k=k+1;
            }
        }
    }
}

