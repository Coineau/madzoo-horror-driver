#include "Auto.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void autoInit(Auto *pauto)
{
	pauto->x=pauto->y=0;
	pauto->pdv=2;
	pauto->pdvmax=2;
	pauto->nbSurviDansAuto=0;
	pauto->nbPlaces=1;
}


void autoGauche(Auto *pauto, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, (autoGetX(pauto)-1), autoGetY(pauto)))
		autoSetX(pauto,(autoGetX(pauto)-1));
}


void autoDroite(Auto *pauto, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, autoGetX(pauto)+1, autoGetY(pauto)))
		autoSetX(pauto,(autoGetX(pauto)+1));
}


void autoHaut(Auto *pauto, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, autoGetX(pauto), autoGetY(pauto)-1))
		autoSetY(pauto,(autoGetY(pauto)-1));
}


void autoBas(Auto *pauto, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, autoGetX(pauto), autoGetY(pauto)+1))
		autoSetY(pauto,(autoGetY(pauto)+1));
}


int autoGetX(const Auto *pauto)
{
	return pauto->x;
}


int autoGetY(const Auto *pauto)
{
	return pauto->y;
}


void autoSetX(Auto *pauto, const int x)
{
	assert( x>=0) ;
	pauto->x= x;
}



void autoSetY(Auto *pauto, const int y)
{
	assert( y>=0) ;
	pauto->y= y;
}



int autoGetPdv(const Auto *pauto)
{
	return(pauto->pdv);
}

void autoSetPdv(Auto *pauto,int pv)
{
	assert(pv>=0);
	pauto->pdv=pv;
}



int autoGetPdvMax(const Auto *pauto)
{
	return(pauto->pdvmax);
}


void autoSetPdvMax(Auto *pauto, int pdvm)
{
	assert(pdvm>0);
	assert(pdvm>pauto->pdvmax);
	pauto->pdvmax=pdvm;
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

void autoSetnbSurviDansAuto(Auto *pauto,int x)
{
	pauto->nbSurviDansAuto=pauto->nbSurviDansAuto+x;
}



