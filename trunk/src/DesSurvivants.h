#ifndef _DesSurvivants_H
#define _DesSurvivants_H

#include "Survivant.h"

typedef struct 
{
	Survivant* tabsurvis[nbs];
	int nbs;
	
} DesSurvivants;

void surviInit(DesSurvivant);

#endif