
#include "Jeu.h"


void jeuInit(Jeu *pJeu)
{
	autoInit(&(pJeu->oto));
	terInit(&(pJeu->ter));
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


void recupSurvi(Terrain *pter, DesSurvivants *pdsurvis, Auto *pauto)
{
	int autoX;
	int autoY;
	autoX=autoGetX(pauto);
	autoY=autoGetY(pauto);

	if((terEstPositionSurvivant(pTer, autoX,autoY)&&(autoGetNbPlaces(pauto)>autoGetnbSurviDansAuto(const Auto *pauto))
	{
		pter->tab[autoX][autoY]=' ';
		surviSetEtat(dGetSurvi(pdsurvis, autoX, autoY), 1);
		autonbSurviDansAutoPlusUn(pauto);
	}
}


void jeuActionClavier(Jeu *pJeu, const char touche)
{
	switch(touche)
	{
		case 'g' : 
				autoGauche(&(pJeu->oto), &(pJeu->ter));					
				break;
		case 'd' :
				autoDroite(&(pJeu->oto), &(pJeu->ter));
				break;
		case 'h' :
				autoHaut(&(pJeu->oto), &(pJeu->ter));
				break;
		case 'b' : 
				autoBas(&(pJeu->oto), &(pJeu->ter));
				break;
	}
}
