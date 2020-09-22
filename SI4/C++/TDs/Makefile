# Auteur : Programmation système
# Modifié par : Safwane

#---------------------------------------------------------------------------------
# Variables
#---------------------------------------------------------------------------------

# Compilateur et options
# ----------------------
CC=g++
CFLAGS=-g -ansi -Wall -Wextra -std=c++11

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
EXE=$(SRC:.cpp=.exe)

#---------------------------------------------------------------------------------
# Cibles principales
#---------------------------------------------------------------------------------

# Exécutables
# -----------

all: $(OBJ) $(EXE)

# Règle par défaut pour construire foo.exe à partir d'un seul fichier foo.o
# -------------------------------------------------------------------------

%.exe: %.o
	$(CC) $(CFLAGS) -o $@ $<

# Règle existant par défaut pour générer un .o à partir d'un .c (donc pas la peine de la réécrire)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

# Nettoyages
# ----------

# Nettoyage léger
clean:
	@rm -f \#* *.o $(EXE)

# Nettoyage en profondeur
mrproper: clean
	@rm -rf *~ $(FIFO)

test:
