#include "Zombie.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

void zombieInit(Zombie * pZon ,int cx ,int cy)
{
	(pZon*).x=cx;
	(pZon*).y=cy;
}

int zombieGetX(Zombie* pZon)
{
	return (pZon*).x;
}

int zombieGetY(Zombie* pZon);
{
	return pZon.y;
}

//void zombieDeplacement(zombie *,terrain);



int zombieGetPdv(Zombie *)
{
	return (pZon*).y;
}

void zombieSetPdv(Zombie * pZon, int pv)
{
	(pZon*).pdv=pv;
}
