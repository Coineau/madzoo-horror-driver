#ifndef _DesSurvivants_H
#define _DesSurvivants_H

#include "Survivant.h"

typedef struct
{
	Survivant* tabS[];

} DesSurvivants;

void dsurviInit(DesSurvivants*, Terrain *);
void dsurviLibere(DesSurvivants *);
void AjouterSurvi(DesSurvivants *);
void SupprimerSurvi(DesSurvivants *);
Survivant dGetSurvi(DesSurvivants *, const int);
void dSetSurvi(DesSurvivants *, const int);

#endif
