
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
				collision(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto), &(pJeu->dzombies));
				break;
		case 'd' :
				autoDroite(&(pJeu->oto), &(pJeu->ter));
				collision(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto), &(pJeu->dzombies));
				break;
		case 'h' :
				autoHaut(&(pJeu->oto), &(pJeu->ter));
				collision(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto), &(pJeu->dzombies));
				break;
		case 'b' :
				autoBas(&(pJeu->oto), &(pJeu->ter));
				collision(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto), &(pJeu->dzombies));
				break;
	}
}




void collision(Terrain *pTer, DesSurvivants *pdsurvis, Auto *pauto, DesZombies *pdzombies)
{
	int autoX;
	int autoY;
	int autoPdV;
	char Pos;
	autoX=autoGetX(pauto);
	autoY=autoGetY(pauto);
	autoPdV=autoGetPdv(pauto);
	Pos=terGetXY(pTer, autoX, autoY);
	switch(Pos)
	{
		case 'o' :
				if(autoGetNbPlaces(pauto)>autoGetnbSurviDansAuto(pauto))
				{
					terSetXY(pTer, autoX, autoY, ' ');
					surviSetEtat(dGetSurvi(pdsurvis, autoX, autoY), 1);
					autoSetnbSurviDansAuto(pauto,1);
				}
				break;
		case 'z' :
				if(autoPdV>0)
				{
					terSetXY(pTer, autoX, autoY, ' ');
					autoSetPdv(pauto,autoPdV-1);
				}
				break;
				
		case 'H' :
				if(autoGetnbSurviDansAuto(pauto)==1)
				{
					surviSetEtat(dGetSurvi(pdsurvis, autoX, autoY), 2);
					autoSetnbSurviDansAuto(pauto,-1);
				}
				break;
	}
}