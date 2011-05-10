
#ifndef _JEU_H
#define _JEU_H

#include "Auto.h"
#include "Terrain.h"
#include "DesSurvivants.h"
#include "DesZombies.h"

typedef struct 
{
	Terrain ter;
	Auto oto;
	DesSurvivants dsurvis;
	DesZombies dzombies;
} Jeu;

/** Initialise une structure Jeu*/
void jeuInit(Jeu *);
/** Renvoie la structure Terrain contenue dans Jeu*/
Terrain *jeuGetTerrainPtr(Jeu *);
/** Renvoie la structure Auto contenue dans Jeu*/
Auto *jeuGetAutoPtr(Jeu *);
/** Renvoie la structure Terrain contenue dans Jeu en constante*/
const Terrain *jeuGetConstTerrainPtr(const Jeu *);
/** Renvoie la structure Auto contenue dans Jeu en constante*/
const Auto *jeuGetConstAutoPtr(const Jeu *);
/** Renvoie une lettre en fonction de la touche pressee par l'utilisateur*/
void jeuActionClavier(Jeu *j, const char);
/** Gère les collisions entre un Survivant et l'Auto*/
void collisionSurvi(Terrain *pter, DesSurvivants *pdsurvis, Auto *pauto);
/** Gère les collisions entre un Zombie et l'Auto*/
void collisionZombie(Terrain *pter, DesZombies *pdzombies, Auto *pauto);

#endif
