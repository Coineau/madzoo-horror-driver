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

typedef struct Menu
{
    MenuLigne ligne[32];
    int nb_lignes;
}Menu;

void menuInit(Menu* m);
void menuAjouterLigne(Menu* m)


#endif
