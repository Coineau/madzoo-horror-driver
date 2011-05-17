
#include "Jeu.h"


void jeuInit(Jeu *pJeu)
{
	autoInit(&(pJeu->oto));
	terInit(&(pJeu->ter));
	dSurviInit(&(pJeu->dsurvis),&(pJeu->ter));
	dZombieInit(&(pJeu->dzombies),&(pJeu->ter));
}

Terrain *jeuGetTerrainPtr(Jeu *pJeu)
{
	return &(pJeu->ter);
}

Auto *jeuGetAutoPtr(Jeu *pJeu)
{
	return &(pJeu->oto);
}

const Terrain *jeuGetConstTerrainPtr(const Jeu *pJeu)
{
	return &(pJeu->ter);
}

const Auto *jeuGetConstAutoPtr(const Jeu *pJeu)
{
	return &(pJeu->oto);
}

void jeuActionClavier(Jeu *pJeu, const char touche)
{
	switch(touche)
	{
		case 'g' :
				autoGauche(&(pJeu->oto), &(pJeu->ter));
				collisionSurvi(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto));
				break;
		case 'd' :
				autoDroite(&(pJeu->oto), &(pJeu->ter));
				collisionSurvi(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto));
				break;
		case 'h' :
				autoHaut(&(pJeu->oto), &(pJeu->ter));
				collisionSurvi(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto));
				break;
		case 'b' :
				autoBas(&(pJeu->oto), &(pJeu->ter));
				collisionSurvi(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto));
				break;
	}
}


void collisionSurvi(Terrain *pTer, DesSurvivants *pdsurvis, Auto *pauto)
{
	int autoX;
	int autoY;
	autoX=autoGetX(pauto);
	autoY=autoGetY(pauto);

	if((terEstPositionSurvivant(pTer, autoX,autoY)==1)&&(autoGetNbPlaces(pauto)>autoGetnbSurviDansAuto(pauto)))
	{
		terSetXY(pTer, autoX, autoY, ' ');
		surviSetEtat(dGetSurvi(pdsurvis, autoX, autoY), 1);
		autoSetnbSurviDansAuto(pauto,1);
	}
}

void collisionZombie(Terrain *pTer, DesZombies *pdzombies, Auto *pauto)
{
	int autoX;
	int autoY;
	int autoPdV;
	autoX=autoGetX(pauto);
	autoY=autoGetY(pauto);
	autoPdV=autoGetPdv(pauto);

	if(terEstPositionZombie(pTer, autoX,autoY)&&(autoPdV>1))
		{
			pTer->tab[autoX][autoY]=' ';
			autoSetPdv(pauto,autoPdV-1);
		}
}

void collisionHeli(Terrain *pTer, DesSurvivants *pdsurvis, Auto *pauto)
{
	int autoX;
	int autoY;
	autoX=autoGetX(pauto);
	autoY=autoGetY(pauto);

	if((terEstPositionHeli(pTer, autoX,autoY)==1)&&(autoGetnbSurviDansAuto(pauto)==1))
	{
		surviSetEtat(dGetSurvi(pdsurvis, autoX, autoY), 2);
		autoSetnbSurviDansAuto(pauto,-1);
	}
}