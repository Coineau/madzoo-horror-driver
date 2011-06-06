#ifndef _DZOMBIE_H
#define _DZOMBIE_H

#include "Zombie.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct
{
	/** tableau conteanant tous le zombie du jeux */
	Zombie ** zombies;
	/** le nombre de zombie dans le jeux */
	int nbz;
}DesZombies;

/** Initialisation d'un tebleau dinamique et placement des zombies en fonction du terrain */
void dZombieInit(DesZombies *pdzon,Terrain *pTer);

/** Supprime tous les allocation de la structure zombie (fin du jeux , supresion de tous)*/
void dZombieLibere(DesZombies *pdzon);

/** Suprime un zombie dans le tableau dinamique  */
void SupprimeZombie(DesZombies *pdzon,int autoX,int autoY,Terrain* pTer);

/** Deplace les zombies */
void dZombieDeplacer(DesZombies *pdzon, int autoX , int autoY,Terrain * pTer);

/** Recupere l'indice d'un zombie en fonction de ces coordonnées */
int dzombieGetzomb(const DesZombies *pdzon,int Xz ,int Yz);

/** Recupere le nombre de zombie*/
int dzombieGetnbZ(const DesZombies* pdzon);

/** Modifie la valeur du nombre de zombie */
void dzombieSetnbZ(DesZombies* pdzon,int n);

/** Recupere le nombre de zombie restant */
int dzombieGetzomrest(const Zombie*);


#endif
