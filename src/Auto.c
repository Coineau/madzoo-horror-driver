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
	if (terEstPositionPersoValide( pTer, autoGetX(pauto)-1, autoGetY(pauto))
		autoSetX(pauto,autoGetX(pauto)-1);
}


void autoDroite(Auto *pauto, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, autoGetX(pauto)+1, autoGetY(pauto)))
		autoSetX(pauto->x++;
}


void autoHaut(Auto *pauto, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pauto->x, pauto-1))
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


void autoSetX(const Auto *pauto, const int X)
{
	assert( x>=0) ;
	assert( x<pTer->dimx ) ;
	pauto->x= X;
}



void autoSetY(const Auto *pauto, const int Y)
{
	assert( y>=0) ;
	assert( y<pTer->dimy ) ;
	pauto->y= Y;
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

void autonbSurviDansAutoPlusUn(Auto *pauto)
{
	assert(pauto->nbSurviDansAuto+1<=pauto->nbPlaces);
	pauto->nbSurviDansAuto++;
}



