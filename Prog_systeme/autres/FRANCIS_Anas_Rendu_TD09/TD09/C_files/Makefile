#
#  Makefile 	-- Makefile pour le TD système sur JNI
#

#
#           Author: FRANCIS Anas
#    Creation date:  29-Apr-2020 09:23

#

CC=g++

CFLAGS=-Wall -Wextra -std=gnu99 -g -Wno-unused-variable 

LIB_PATH = -I /usr/lib/jvm/java-11-openjdk-amd64/include/ -I /usr/lib/jvm/java-11-openjdk-amd64/include/linux

OBJ=HelloWorld.o

DEPS=HelloWorld.h

all: libHelloWorld.so

HelloWorld.o: HelloWorld.cpp $(DEPS)
	$(CC) $(CFLAGS) -fpic -c $< $(LIB_PATH)

libHelloWorld.so: $(OBJ)
	$(CC) -Wl,-soname,$@ -shared -o $@ HelloWorld.o

clean:
	rm -f *.so *.exe *.o *~ \#*
