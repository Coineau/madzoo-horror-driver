#include "Survivant.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void surviInit(Survivant *psurvi, const int x, const int y)
{
	psurvi->x = x;
	psurvi->y = y;
	psurvi.etat=0;
}

int surviGetX(const Survivant *psurvi)
{
	return psurvi->x;
}

int surviGetY(const Survivant *psurvi)
{
	return psurvi->y;
}

int surviGetEtat(const Survivant *psurvi)
{
    return psurvi->etat;
}

int surviSetEtat(Survivant *psurvi, const int e)
{
    psurvi->etat = e;
}
