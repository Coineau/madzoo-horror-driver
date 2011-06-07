Madzoo Horror Driver - version 1.0
=========================================
contacts : sir.mc.ogan@gmail.com
	dedieu.simon@gmail.com
	fumeur51@gmail.com
=========================================


1 - Presentation
2 - Contenu
3 - Librairies
4 - Compilation et exécution
5 - Documention


=========================================

1 - Presentation
=========================================


Le but du jeu est de récupérer des survivants (en l'occurrence des pandas placés sur la carte) 
à l'aide d'une voiture conduite par un singe.
Le joueur devra faire avec des meutes de zombies qui vont chercher à endommager son véhicule.


=========================================

2 - Contenu
=========================================

- makefile : compilation du projet

- dossier src : contient les sources et les headers

- dossier data :
	- credits : contient l'image (au format bmp) et la musique (au format wav) nécessaire
		à la mise en place des crédits
	- jeu : contient les différents sprites et images (au format bmp), les musiques et 			
		bruitages (au format wav) et la police d'écriture (au format ttf)
	- menu : contient les images(au format bmp) et la musique (au format wav) nécessaire
		à la mise en place du menu
	- niveau : contient les différents niveaux du jeu (au format txt)
	- icone.bmp : icone s'affichant dans la barre de taches lors de l'exécution du programme

- dossier doc : contient les fichiers nécessaire a la documentation et sa mise en page sur le navigateur

- dossier bin : emplacement où seront stockés les fichiers executables et les fichiers objets


=========================================

3 - Librairies
=========================================
Madzoo Horror Driver peut être joué avec les librairies ncurses et SDL.

- ncurses :
Il s'agit d'une version simple du jeu. Celui-ci est lancé dans le terminal. Les différents éléments du terrain
sont des caractères. Le déplacement des zombies est synchronisé sur celui du joueur. Dans cette version le déplacement
des zombies ne dépend volontairement pas du temps. Cela permet une difficulté et un gameplay différent par rapport à la version SDL.


- SDL :
Grace à la librairie SDL le jeu est visiblement plus esthétique. Cette librairie permet aussi l'ajout de sons qui vont
rythmer vos parties. Le déplacement de l'IA est callé sur une horloge.

****/!\Attention/!\*****
Vous avez besoin des libraires SDL, SDL_ttf, SDL_mixer et de Timidity.
Ces librairies n'étant pas toujours toutes présentes voici comment les obtenir :
SDL:
sudo apt-get install libsdl1.2-dev

SDL_ttf:
sudo apt-get install libsdl-ttf2.0-0 libsdl-ttf2.0-dev

SDL_mixer:
sudo apt-get install libsdl-mixer1.2 libsdl-mixer1.2-dev

Timidity:
sudo apt-get install timidity


=========================================

4 - Compilation et exécution
=========================================

Par défaut le makefile est écrit pour jouer en mode graphique c'est-à-dire avec les librairies SDL.
Pour jouer à MHD en mode texte vous devrez éditer le makefile.
Mettez un caractère '#' devant "JEU = graphique" à la ligne 5 et enlevez celui devant "JEU = texte"
à la ligne 4.
La compilation s'effectue manuellement.
Il suffit d'entrer "make" dans un terminal.
Si vous avez choisi de jouer à MHD en mode graphique entrer "bin/mhd_gfx" dans votre terminal ou 
"bin/mhd_txt" si vous avez choisi le mode texte.


=========================================

5 - Documention
=========================================

Pour consulter la documentation du module entrer directement "firefox doc/html/index.html"
dans le terminal.

