
#ifndef _JEU_H
#define _JEU_H

#include "Auto.h"
#include "Terrain.h"

typedef struct 
{
	Terrain ter;
	Auto oto;
} Jeu;

void jeuInit(Jeu *);
Terrain *jeuGetTerrainPtr(Jeu *);
Auto *jeuGetAutoPtr(Jeu *);
const Terrain *jeuGetConstTerrainPtr(const Jeu *);
const Auto *jeuGetConstAutoPtr(const Jeu *);

void jeuActionClavier(Jeu *j, const char);


#endif
