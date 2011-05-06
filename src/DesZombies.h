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
	/** nombre de zombie restant */
	/*int zomrest;*/
}DesZombies;

/** initialisation d'un tebleau dinamique et placement des zombies en fonction du terrain */
void dZombieInit(DesZombies *pdzon,Terrain *pTer);

/**supprime tous les allocation de la structure zombie (fin du jeux , supresion de tous)*/
void dZombieLibere(DesZombies *pdzon);

/**suprime un zombie dans le tableau dinamique  */
void SupprimeZombie(DesZombies *pdzon, Zombie* pzon);

/*void dZombieDeplacer(DesZombies *pdzon, int autoX , int autoY,Terrain * pTer);*/

/**Recupere le nombre de zombie*/
int dzombieGetnbz(const desZombie*);

/**Recupere le nombre de zombie restant*/
int dzombieGetzomrest(const Zombie*);


/**Modifie la valeur du nombre de zombie */
void dzombieSetnbz(Zombie*,int x);

/**Modifie la valeur du nombre de zombie restant */
void dzombieSetzomrest(Zombie*,int y);
#endif
