#include "Car.h"


void carInit(Car *pcar)
{
	pcar->x=pcar->y=0;
}	

void carGauche(Car *pcar, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pcar->x-1, pcar->y))
		pcar->x--;
}

void carDroite(Car *pcar, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pcar->x+1, pcar->y))
		pcar->x++;
}

void carHaut(Car *pcar, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pcar->x, pcar->y-1))
		pcar->y--;
}

void carBas(Car *pcar, const Terrain *pTer)
{
	if (terEstPositionPersoValide( pTer, pcar->x, pcar->y+1))
		pcar->y++;
}

int carGetX(const Car *pcar)
{
	return pcar->x;
}

int carGetY(const Car *pcar)
{
	return pcar->y;
}
