
#ifndef _JEU_H
#define _JEU_H

#include "Pacman.h"
#include "Terrain.h"

typedef struct 
{
	Terrain ter;
	Pacman pac;
} Jeu;

void jeuInit(Jeu *);
Terrain *jeuGetTerrainPtr(Jeu *);
Pacman *jeuGetPacmanPtr(Jeu *);
const Terrain *jeuGetConstTerrainPtr(const Jeu *);
const Pacman *jeuGetConstPacmanPtr(const Jeu *);

void jeuActionClavier(Jeu *j, const char);


#endif
