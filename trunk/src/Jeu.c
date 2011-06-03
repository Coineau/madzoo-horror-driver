
#include "Jeu.h"


void jeuInit(Jeu *pJeu)
{
	pJeu->niv=2;
	terInit(&(pJeu->ter),pJeu->niv);
	autoInit(&(pJeu->oto),&(pJeu->ter));
	dSurviInit(&(pJeu->dsurvis),&(pJeu->ter));
	dZombieInit(&(pJeu->dzombies),&(pJeu->ter));
}

void JeuLibere(Jeu *pJeu)
{
    terLibere(&(pJeu->ter));
    dsurviLibere(&(pJeu->dsurvis));
    dZombieLibere(&(pJeu->dzombies));
}

Terrain *jeuGetTerrainPtr(Jeu *pJeu)
{
	return &(pJeu->ter);
}

Auto *jeuGetAutoPtr(Jeu *pJeu)
{
	return &(pJeu->oto);
}

DesZombies *jeuGetdZombPtr(Jeu * pJeu)
{
	return &(pJeu->dzombies);
}

const Terrain *jeuGetConstTerrainPtr(const Jeu *pJeu)
{
	return &(pJeu->ter);
}

const Auto *jeuGetConstAutoPtr(const Jeu *pJeu)
{
	return &(pJeu->oto);
}

const DesZombies *jeuGetConstdZombPtr(const Jeu * pJeu)
{
	return &(pJeu->dzombies);
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
		default:
				break;
	}
	collision(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto), &(pJeu->dzombies));

}

void jeuDeplaceZombies(Jeu *pJeu)
{
	int autoX;
	int autoY;
	autoX=autoGetX(&(pJeu->oto));
	autoY=autoGetY(&(pJeu->oto));

	dZombieDeplacer(&(pJeu->dzombies) ,autoX,autoY,&(pJeu->ter));
	collision(&(pJeu->ter), &(pJeu->dsurvis), &(pJeu->oto), &(pJeu->dzombies));
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
					SupprimeZombie(pdzombies,autoX,autoY,pTer);
					autoSetPdv(pauto,autoPdV-1);
				}
				break;

		case 'H' :
				if(autoGetnbSurviDansAuto(pauto)>=1)
				{
					dSurviSauve (pdsurvis);
					autoSetnbSurviDansAuto(pauto,-1);
				}
				break;
	}
}

int JeuTestFinNiveau (Jeu *pJeu)
{
    if (autoGetPdv(&(pJeu->oto))==0)
    {
        return 2;
    }
    if (dSurviTestTousSauve(&(pJeu->dsurvis))==1)
    {
        return 1;
    }
    return 0;
}
