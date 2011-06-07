Madzoo Horror Driver - version 1.0
=========================================
contacts : sir.mc.ogan@gmail.com
	dedieu.simon@gmail.com
	fumeur51@gmail.com
=========================================


1 - Presentation
2 - Contenu
3 - Librairies
4 - Compilation et ex�cution
5 - Documention


=========================================

1 - Presentation
=========================================


Le but du jeu est de r�cup�rer des survivants (en l'occurrence des pandas plac�s sur la carte) 
� l'aide d'une voiture conduite par un singe.
Le joueur devra faire avec des meutes de zombies qui vont chercher � endommager son v�hicule.


=========================================

2 - Contenu
=========================================

- makefile : compilation du projet

- dossier src : contient les sources et les headers

- dossier data :
	- credits : contient l'image (au format bmp) et la musique (au format wav) n�cessaire
		� la mise en place des cr�dits
	- jeu : contient les diff�rents sprites et images (au format bmp), les musiques et 			
		bruitages (au format wav) et la police d'�criture (au format ttf)
	- menu : contient les images(au format bmp) et la musique (au format wav) n�cessaire
		� la mise en place du menu
	- niveau : contient les diff�rents niveaux du jeu (au format txt)
	- icone.bmp : icone s'affichant dans la barre de taches lors de l'ex�cution du programme

- dossier doc : contient les fichiers n�cessaire a la documentation et sa mise en page sur le navigateur

- dossier bin : emplacement o� seront stock�s les fichiers executables et les fichiers objets


=========================================

3 - Librairies
=========================================
Madzoo Horror Driver peut �tre jou� avec les librairies ncurses et SDL.

- ncurses :
Il s'agit d'une version simple du jeu. Celui-ci est lanc� dans le terminal. Les diff�rents �l�ments du terrain
sont des caract�res. Le d�placement des zombies est synchronis� sur celui du joueur. Dans cette version le d�placement
des zombies ne d�pend volontairement pas du temps. Cela permet une difficult� et un gameplay diff�rent par rapport � la version SDL.


- SDL :
Grace � la librairie SDL le jeu est visiblement plus esth�tique. Cette librairie permet aussi l'ajout de sons qui vont
rythmer vos parties. Le d�placement de l'IA est call� sur une horloge.

****/!\Attention/!\*****
Vous avez besoin des libraires SDL, SDL_ttf, SDL_mixer et de Timidity.
Ces librairies n'�tant pas toujours toutes pr�sentes voici comment les obtenir :
SDL:
sudo apt-get install libsdl1.2-dev

SDL_ttf:
sudo apt-get install libsdl-ttf2.0-0 libsdl-ttf2.0-dev

SDL_mixer:
sudo apt-get install libsdl-mixer1.2 libsdl-mixer1.2-dev

Timidity:
sudo apt-get install timidity


=========================================

4 - Compilation et ex�cution
=========================================

Par d�faut le makefile est �crit pour jouer en mode graphique c'est-�-dire avec les librairies SDL.
Pour jouer � MHD en mode texte vous devrez �diter le makefile.
Mettez un caract�re '#' devant "JEU = graphique" � la ligne 5 et enlevez celui devant "JEU = texte"
� la ligne 4.
La compilation s'effectue manuellement.
Il suffit d'entrer "make" dans un terminal.
Si vous avez choisi de jouer � MHD en mode graphique entrer "bin/mhd_gfx" dans votre terminal ou 
"bin/mhd_txt" si vous avez choisi le mode texte.


=========================================

5 - Documention
=========================================

Pour consulter la documentation du module entrer directement "firefox doc/html/index.html"
dans le terminal.

