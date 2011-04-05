
#ifndef _JEU_H
#define _JEU_H

#include "Car.h"
#include "Terrain.h"

typedef struct 
{
	Terrain ter;
	Car car;
} Jeu;

void jeuInit(Jeu *);
Terrain *jeuGetTerrainPtr(Jeu *);
Car *jeuGetCarPtr(Jeu *);
const Terrain *jeuGetConstTerrainPtr(const Jeu *);
const Car *jeuGetConstCarPtr(const Jeu *);

void jeuActionClavier(Jeu *j, const char);


#endif
