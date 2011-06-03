#include <stdio.h>
#include "menu.h"

void menuAff()
{
    printf("\n MENU \n");
    printf("1 : Jouer \n");
    printf("2 : Credit \n");
    printf("3 : QUITTER \n");

}

void menuRun()
{
char ch;
do
{
menuAff();
scanf("%c", &ch);
switch(ch)
{
case 1 : Jeu jeu;
         jeuInit(&jeu);
         ncursBoucle(&jeu); break;
case 2 : printf("credit\n"); break;
case 3 : printf("quit a faire\n"); break;
default: printf("Erreur\n"); break;
}
} while(ch<1 || ch>3);
}




