#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ncursMenu.h"

void jouer()
{
    printf("fonction jouer\n");
    fflush(stdout);
}

void Quitter()
{
    printf("fin\n");
    exit(0);
}

void menuInit(Menu m)
{
    m.nb_lignes=0;
}

void menuAjouterLigne(Menu m, char txt[64], MenuFonction fonct)
{
    strcpy(m.lignes[m.nb_lignes].texte, txt);
    m.lignes[m.nb_lignes].fonction_commande = fonct;
    m.nb_lignes++;
}

void menuLibere(Menu m)
{
    m.nb_lignes=0;
}

void menuAff(const Menu m)
{
    int i;
    printf("\n\nMenu");
    for(i=0;i<m.nb_lignes;i++)
    {
        printf("%d : %s\n",i,m.lignes[i].texte);
    }
    printf("Votre choix?\n");
    fflush(stdout);
}

int menuQuestion(const Menu m)
{
    int cm;
    char dum[32];
    bool ok = false;
    do
    {
        if(scanf("%d",&cm)!=1)
        {
            scanf("%s",dum);
        }
        if((cm<0)||(cm>=m.nb_lignes))
        {
            printf ("Erreur choix menu\n");
        }
        else
        {
            ok=true;
        }
        fflush(stdout);
    }while(!ok);
    printf("\n");
    fflush(stdout);
    return cm;
}

void menuLoop(Menu m)
{
    int cm;
    while(1)
    {
        menuAff(m);
        cm = menuQuestion(m);
        m.lignes[cm].fonction_commande();
    }
}
