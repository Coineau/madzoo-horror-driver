
#include "Jeu.h"


void jeuInit(Jeu *pJeu)
{
	autoInit(&(pJeu->oto));
	terInit(&(pJeu->ter));
	dSurviInit(&(pJeu->dsurvis),&(pJeu->ter));
	/*dZombiesInit(&(pjeu->dzombies));*/
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
				collisionSurvi(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto));
				autoGauche(&(pJeu->oto), &(pJeu->ter));
				/*collisionSurvi(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto));*/
				break;
		case 'd' :
								collisionSurvi(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto));
				autoDroite(&(pJeu->oto), &(pJeu->ter));
				/*collisionSurvi(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto));*/
				break;
		case 'h' :
							collisionSurvi(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto));
				autoHaut(&(pJeu->oto), &(pJeu->ter));
				/*collisionSurvi(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto));*/
				break;
		case 'b' : 
							collisionSurvi(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto));
				autoBas(&(pJeu->oto), &(pJeu->ter));
				/*collisionSurvi(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto));*/
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
		terSetXY(pTer, autoY, autoX, ' ');
		surviSetEtat(dGetSurvi(pdsurvis, autoX, autoY), 1);
		autonbSurviDansAutoPlusUn(pauto);
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