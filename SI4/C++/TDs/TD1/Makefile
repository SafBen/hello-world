# Compilateur et options

CC=g++
CFLAGS=-g -ansi -Wall -Wextra -std=c++11

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
SOURCEHEADERS = $(SRC:.cpp=.h)
EXE=$(SRC:.cpp=.exe)

# Exécutables
all: $(OBJ) $(EXE)

# Règle pour construire un fichier .exe à partir d'un fichier .o
%.exe: %.o %.cpp
	$(CC) $(CFLAGS) -o $@ $^

# Nettoyage
clean:
	@rm -f \#* *.o $(EXE)
