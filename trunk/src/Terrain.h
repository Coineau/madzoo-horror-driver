#ifndef _TERRAIN_H
#define _TERRAIN_H

typedef struct
{
        /**Largeur du terrain*/
        int dimx;        
        /**Hauteur du terrain*/
        int dimy;        
        /**Tableau 2D referant les elements du terrain*/
        char **tab;        
        /**Nombre de survivants*/
        int nbS;        
        /**Nombre de zombies*/
        int nbZ;
} Terrain;

/**Initialise le terrain en important la structure terrain d'un fichier texte*/
void terInit(Terrain *);

/**Libere le terrain*/
void terLibere(Terrain *);

/**Verifie que la case n'est pas un mur*/
int terEstPositionPersoValide(const Terrain *, const int x, const int y);

/**Verifie que la case est un survivant*/
int terEstPositionSurvivant(const Terrain*, const int x, const int y);

/**Verifie que la case est un zombie*/
int terEstPositionZombie(const Terrain*, const int x, const int y);

/**Renvoie le caractere dont les coordonnees sont passees en parametre*/
const char terGetXY(const Terrain *, const int x, const int y);

/**Modife le caractere dont les coordonnees sont passees en parametre*/
void terSetXY(const Terrain *, const int x, const int y, const char);

/**Renvoie la largeur du terrain*/
const int getDimX(const Terrain *);

/**Renvoie la hauteur du terrain*/
const int getDimY(const Terrain *);

/**Renvoie le nombre total de survivants*/
const int terGetnbS(const Terrain *);

/**Modife le nombre total de survivants*/
void terSetnbS(Terrain *, const int);

/**Renvoie le nombre total de zombies*/
const int terGetnbZ(const Terrain *);

/**Modife le nombre total de zombies*/
void terSetnbZ(Terrain *, const int);


#endif
