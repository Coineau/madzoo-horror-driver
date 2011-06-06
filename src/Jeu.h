
#ifndef _JEU_H
#define _JEU_H

#include "Auto.h"
#include "Terrain.h"
#include "DesSurvivants.h"
#include "DesZombies.h"

typedef struct
{
	/**Structure Terrain*/
	Terrain ter;
	/**Structure Auto*/
	Auto oto;
	/**Structure DesSurvivants*/
	DesSurvivants dsurvis;
	/**Structure DesZombies*/
	DesZombies dzombies;
	/**Numero du niveau*/
	int niv;
} Jeu;

/** Initialise une structure Jeu*/
void jeuInit(Jeu *,int niveau);

/**Libere la structure Jeu*/
void JeuLibere(Jeu *pJeu);

/** Renvoie la structure Terrain contenue dans Jeu*/
Terrain *jeuGetTerrainPtr(Jeu *);

/** Renvoie la structure Auto contenue dans Jeu*/
Auto *jeuGetAutoPtr(Jeu *);

/** Renvoie la structure DesZombies contenue dans Jeu*/
DesZombies *jeuGetdZombPtr(Jeu *);

/** Renvoie la structure Terrain contenue dans Jeu en constante*/
const Terrain *jeuGetConstTerrainPtr(const Jeu *);

/** Renvoie la structure Auto contenue dans Jeu en constante*/
const Auto *jeuGetConstAutoPtr(const Jeu *);

/**Renvoie la structuere DesZombies contenue dans Jeu en constante*/
const DesZombies *jeuGetConstdZombPtr(const Jeu *);

/** Renvoie une lettre en fonction de la touche pressee par l'utilisateur*/
void jeuActionClavier(Jeu *j, const char);

/**Gere le déplacement des zombies*/
void jeuDeplaceZombies(Jeu *j);

/** Gère les collisions entre un Survivant ou un Zombie ou l'Heliport et l'Auto*/
void collision(Terrain *pTer, DesSurvivants *pdsurvis, Auto *pauto, DesZombies *pdzombies);

/**Renvoie 2 si la voiture n'a plus de Pdv, 1 si tous les survivants sont sauves et 0 sinon*/
int JeuTestFinNiveau (Jeu *pJeu);

/*
//Ecrie le fichier de sauvegarde de la partie en cours
void JeuSauvegardePartie (Jeu *pJeu);


//Compare le score courant au 3 meilleurs scores et l'enregistre au besoin
void JeuSauvegardeScores (Jeu *pJeu);
*/


#endif
