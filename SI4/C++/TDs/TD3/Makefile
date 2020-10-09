# Compilateur et options

CC=g++
CFLAGS=-g -ansi -Wall -Wextra -std=c++14

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
SOURCEHEADERS = $(SRC:.cpp=.h)
EXE=$(SRC:.cpp=.exe)


%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

main.exe: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Nettoyage
clean:
	@rm -f \#* *.o $(EXE)
