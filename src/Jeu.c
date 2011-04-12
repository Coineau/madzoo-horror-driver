
#include "Jeu.h"


void jeuInit(Jeu *pJeu)
{
	autoInit(&(pJeu->oto));
	terInit(&(pJeu->ter));
	/*int nsurvi=1;
	dessurvisInit(pjeu->DesSurvivants,nsurvi);*/
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
