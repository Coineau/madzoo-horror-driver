CC 			= gcc
LD 			= gcc

JEU	= texte
#JEU	= graphique
#OS	= WIN32
OS	= LINUX

ifeq ($(JEU),texte)
	SRCS = Auto.c Terrain.c DesSurvivants.c Survivant.c Jeu.c ncursJeu.c main.c
	FINAL_TARGET = mhd_txt
	DEFINE = -D$(OS) -DJEU_NCURSES
else
	SRCS = Auto.c Terrain.c DesSurvivants.c Survivant.c Jeu.c sdlJeu.c main.c
	FINAL_TARGET = mhd_gfx
	DEFINE = -D$(OS) -DJEU_SDL
endif

ifeq ($(JEU)$(OS),texteWIN32)
	LIBS = "C:\Program Files (x86)\PDCurses-SO\win32\pdcurses.a"
endif
ifeq ($(JEU)$(OS),texteLINUX)
	LIBS = -lncurses
endif
ifeq ($(JEU)$(OS),graphiqueWIN32)
	LIBS = -L"G:\alex\A_CLASSER\LIF7-DeveloppementApp\SDL-1.2.14\lib" -lmingw32 -lSDLmain -lSDL.dll
endif
ifeq ($(JEU)$(OS),graphiqueLINUX)
	LIBS = -lSDL -lSDL_ttf
endif


LDFLAGS  			=
CFLAGS 			= $(DEFINE)  -Wall -pedantic -ansi -ggdb   #-O2   # pour optimiser
INCLUDE_DIR 		= -I/usr/include -Isrc -I"C:\Program Files (x86)\PDCurses-SO" -I/usr/include/SDL -I"G:\alex\A_CLASSER\LIF7-DeveloppementApp\SDL-1.2.14\include\SDL"

OBJ_DIR 		= bin
SRC_DIR 		= src
BIN_DIR 		= bin



default: $(BIN_DIR)/$(FINAL_TARGET)


$(BIN_DIR)/$(FINAL_TARGET): $(SRCS:%.c=$(OBJ_DIR)/%.o)
	$(LD) $+ -o $@ $(LDFLAGS) $(LIB_DIR) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $(INCLUDE_DIR) $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/$(FINAL_TARGET)
