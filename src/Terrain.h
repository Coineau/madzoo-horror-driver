#ifndef _TERRAIN_H
#define _TERRAIN_H

typedef struct
{
	int dimx;
	int dimy;
	char **tab;
	int nbS;
} Terrain;

void terInit(Terrain *);
void terLibere(Terrain *);
int terEstPositionPersoValide(const Terrain *, const int x, const int y);
const char terGetXY(const Terrain *, const int x, const int y);
void terSetXY(const Terrain *, const int x, const int y, const char);
int terEstPositionSurvivant(const Terrain*, const int x, const int y);
const int getDimX(const Terrain *);
const int getDimY(const Terrain *);
const int terGetnbS(const Terrain *);
void terSetnbS(const Terrain *, const int);


#endif
