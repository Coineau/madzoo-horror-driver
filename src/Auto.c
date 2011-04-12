#include "Auto.h"


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
