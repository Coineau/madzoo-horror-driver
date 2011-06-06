#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ncursMenu.h"

void jouer()
{ 
    Jeu jeu;
    ncursBoucle(&jeu,1);
    
}

void Quitter()
{
    printf("fin\n");
    exit(0);
}



void MenuNcurs()
{
    char ch ;
    int av = 0 ;
    printf(" MADZOO HORROR DRIVER \n");
    while(av != 1)
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
							av =1;
							
							break;
				case 'b' :		
							Instruction();
							break;
                case 'c' :
							Credit();
							break;
			}
        }
        while( ((ch = getchar()) != '\n') && ch != EOF); 
    }
    Quitter();
}

void Instruction()
{
	printf("\nBienvenue dans Madzoo Horror Driver\n\n");
	printf("A l'aide des fleches directionnelles recuperer\n ");
	printf("le panda et rammener le le plus vite possible\n "); 
	printf("a l'heliport en evitant les zombies.\n");
}

void Credit()
{
}


void AfficherChoixMenu()
{
	printf("\n");
	printf("a: -JOUER- \n");
	printf("b: -INSTRUCTIONS- \n");
	printf("c: -CREDIT- \n");
}
