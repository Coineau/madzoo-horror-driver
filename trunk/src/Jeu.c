
#include "Jeu.h"


void jeuInit(Jeu *pJeu)
{
	autoInit(&(pJeu->auto));
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
	return &(pJeu->auto);
}

const Terrain *jeuGetConstTerrainPtr(const Jeu *pJeu)
{ 
	return &(pJeu->ter);
}

const Auto *jeuGetConstAutoPtr(const Jeu *pJeu)
{
	return &(pJeu->auto);
}


void jeuActionClavier(Jeu *pJeu, const char touche)
{
	switch(touche)
	{
		case 'g' : 
				autoGauche(&(pJeu->auto), &(pJeu->ter));
				break;
		case 'd' :
				autoDroite(&(pJeu->auto), &(pJeu->ter));
				break;
		case 'h' :
				autoHaut(&(pJeu->auto), &(pJeu->ter));
				break;
		case 'b' : 
				autoBas(&(pJeu->auto), &(pJeu->ter));
				break;
	}
}
