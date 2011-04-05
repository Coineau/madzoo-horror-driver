
#include "Jeu.h"


void jeuInit(Jeu *pJeu)
{
	carInit(&(pJeu->car));
	terInit(&(pJeu->ter));
}

Terrain *jeuGetTerrainPtr(Jeu *pJeu)
{
	return &(pJeu->ter);
}

Car *jeuGetCarPtr(Jeu *pJeu)
{
	return &(pJeu->car);
}

const Terrain *jeuGetConstTerrainPtr(const Jeu *pJeu)
{ 
	return &(pJeu->ter);
}

const Car *jeuGetConstCarPtr(const Jeu *pJeu)
{
	return &(pJeu->car);
}


void jeuActionClavier(Jeu *pJeu, const char touche)
{
	switch(touche)
	{
		case 'g' : 
				carGauche(&(pJeu->car), &(pJeu->ter));
				break;
		case 'd' :
				carDroite(&(pJeu->car), &(pJeu->ter));
				break;
		case 'h' :
				carHaut(&(pJeu->car), &(pJeu->ter));
				break;
		case 'b' : 
				carBas(&(pJeu->car), &(pJeu->ter));
				break;
	}
}
