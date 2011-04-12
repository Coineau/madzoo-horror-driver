#include "Zombie.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

void zombieInit(Zombie * pZon ,int cx ,int cy)
{
	pZon->x=cx;
	pZon->y=cy;
}

int zombieGetX(const Zombie* pZon)
{
	return pZon->x;
}

int zombieGetY(const Zombie* pZon)
{
	return pZon->y;
}

//void zombieDeplacement(zombie *,terrain);



int zombieGetPdv(const Zombie * pZon)
{
	return pZon->pdv;
}

void zombieSetPdv(Zombie * pZon, int pv)
{
	pZon->pdv=pv;
}
