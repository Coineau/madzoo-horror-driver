#include "Survivant.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void surviInit(Survivant * survi, int posx, int posy)
{
	survi	.x=posx;
	survi.y=posy;
	survi.etat=0;
}

int surviGetX(const Survivant *psurvi)
{
	return psurvi->x;
}

int surviGetY(const Survivant *psurvi)
{
	return psurvi->y;
}

int surviChangeEtat(Survivant * survi)
{
	
	
	
}