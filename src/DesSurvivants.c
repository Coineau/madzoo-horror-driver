#include "DesSurvivants.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>


void surviInit(DesSurvivants* dessurvis, int nbs)
{
	dessurvis.tabsurvis= (char *)malloc(sizeof(char)*nbs);
	for (int x=0; x<nbs ; x++)
	{
		Survivant * surv;
		survInit(surv);
		dessurvis.tabsurvis[x]=surv;
		for(y=0;y<pTer->dimy;++y)
			for(x=0;x<pTer->dimx;++x)
			{
				if(pTer.tab[y][x] == 'o')
				{
					surviPlace(tab[i],x,y);
					i++;
				}
			}		
	}
}