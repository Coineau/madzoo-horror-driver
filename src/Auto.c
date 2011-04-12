#include "Auto.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void autoInit(Auto *pauto)
{
	pauto->x=pauto->y=0;
}	

void autoGauche(Auto *pauto, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pauto->x-1, pauto->y))
		pauto->x--;
}

void autoDroite(Auto *pauto, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pauto->x+1, pauto->y))
		pauto->x++;
}

void autoHaut(Auto *pauto, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pauto->x, pauto->y-1))
		pauto->y--;
}

void autoBas(Auto *pauto, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pauto->x, pauto->y+1))
		pauto->y++;
}

int autoGetX(const Auto *pauto)
{
	return pauto->x;
}

int autoGetY(const Auto *pauto)
{
	return pauto->y;
}

/*void autoLibere(Auto*)
{
}*/

int autoGetPdv(const Auto *pauto)
{
	return(pauto->pdv);
}

void autoSetPdv(Auto *pauto,int pv)
{
	assert(pv>=0);
	pauto->pdv=pv;
}

int autoGetNbPlaces(const Auto *pauto)
{
	return(pauto->nbPlaces);
}

void autoSetNbPlaces(Auto *pauto,int nbp)
{
	assert(nbp>0);
	pauto->nbPlaces=nbp;
}

int autoGetnbSurviDansAuto(const Auto *pauto)
{
	return(pauto->nbSurviDansAuto);
	
}
void autoSetnbSurviDansAuto(Auto *pauto,int sda)
{
	assert(sda>0);
	assert(sda<=pauto->nbPlaces);
	pauto->nbSurviDansAuto=sda;
}