#include "DesSurvivants.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>


void surviInit(DesSurvivants *dsurvis, const int nbS, Terrain *pTer)
{
    int i, j;
    for(j=0;j<getDimY(&pTer);++)
    {
        for(i=0;i<getDimX(&pTer);i++)
        {
            if (terEstPositionSurvivant(&pTer,i,j)==1)
            {
                surviInit(Survivant*, const int x, const int y);
            }
        }
    }
}
