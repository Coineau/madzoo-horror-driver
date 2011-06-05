
#include "Jeu.h"


void jeuInit(Jeu *pJeu)
{
	pJeu->niv=1;
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

/*void JeuSauvegardePartie (Jeu *pJeu)
{
    int i,j;
    FILE* fichier = NULL;
    fichier = fopen("sauvegarde.txt", "w+");
    if (fichier != NULL)
    {
        fprintf(fichier, "%d ", getDimX(&(pJeu->ter)));
        fprintf(fichier, "%d ", getDimY(&(pJeu->ter)));
        fprintf(fichier, "%d ", dSurviRestant(&(pJeu->dsurvis)));
        fprintf(fichier, "%d\n", dzombieGetnbZ(&(pJeu->dzombies)));
        for (i=0; i<getDimY(&(pJeu->ter));i++)
        {
            for (j=0; j<getDimY(&(pJeu->ter));j++)
            {
                fprintf(fichier, "%c ", terGetXY(&(pJeu->ter),i,j));
            }
            fputs("\n", fichier);
        }
    fclose(fichier);
    }
}

void JeuSauvegardeScores (Jeu *pJeu)
{
    int S,s1,s2,s3;
    FILE* fichier = NULL;
    fichier = fopen("scores.txt", "r+");
    if (fichier != NULL)
    {
        fscanf(fichier, "%d %d %d", &s1, &s2, &s3);
        if (S>=s1)
        {
            fprintf(fichier, "%d %d %d", S, s1, s2);
        }
        else if (S>=s2 && S<s1)
            {
                fprintf(fichier, "%d %d %d", s1, S, s2);
            }
            else if (S>=s3 && S<s2)
                {
                    fprintf(fichier, "%d %d %d", s1, s2, S);
                }

        fclose(fichier);
    }

}*/
