#ifndef _DesSurvivants_H
#define _DesSurvivants_H

#include "Survivant.h"

typedef struct
{
	Survivant* tabsurvis[nbS];
	int nbS;

} DesSurvivants;

void dsurviInit(DesSurvivants* , const int, Terrain *);
void dsurviLibere(DesSurvivants *);
void AjouterSurvi(DesSurvivants *);
void SupprimerSurvi(DesSurvivants *);
Survivant dGetSurvi(DesSurvivants *, const int);
void dSetSurvi(DesSurvivants *, const int);

#endif
