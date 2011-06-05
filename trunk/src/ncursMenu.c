#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ncursMenu.h"

void jouer()
{
    printf("YOU WILL SUFFER");
    Jeu jeu;
    jeuInit(&jeu);
    ncursBoucle(&jeu);
    JeuLibere(&*pJeu)
    
}

void Quitter()
{
    printf("fin\n");
    exit(0);
}



void MenuNcurs()
{
    char ch ;
    printf(" MADZOO HORROR DRIVER \n");
    do
    {
		printf("\n\nMenu");
		AfficherChoixMenu();
		scanf("%c",&ch);
        if(ch <'a' || ch> 'c')
        {
            printf ("Erreur choix menu\n");
        }
        else
        {
            switch(ch)
			{
				case 'a' :		
							jouer();
							break;
                case 'b' :		
							printf("2: -CREDIT- \n");
							break;
				case 'c' :		
							Quitter();
							break;
				default : break;
			}
        }
        while( ((ch = getchar()) != '\n') && ch != EOF)
        {}
    }while(ch!=3);
}


void AfficherChoixMenu()
{
	printf("\n");
	printf("a: -JOUER- \n");
	printf("b: -CREDIT- \n");
	printf("c: -QUITTER- \n");
}
