#ifndef _MENU_H
#define _MENU_H

#include "ncurses.h"
#include "Jeu.h"

typedef void (*MenuFonction)();

typedef struct
{
    char texte[64];
    MenuFonction fonction_commande;
} MenuLigne;

typedef struct
{
    MenuLigne lignes[32];
    int nb_lignes;
}Menu;

void jouer();
void Quitter();
void menuInit(Menu m);
void menuAjouterLigne(Menu m, char txt[64],MenuFonction fonct);
void menuLoop(Menu m);
void menuLibere();

#endif
