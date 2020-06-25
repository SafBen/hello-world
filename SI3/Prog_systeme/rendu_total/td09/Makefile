CC=g++
CPPFLAGS=-c -fpic -Wall -I "/snap/intellij-idea-ultimate/217/jbr/include" -I "/snap/intellij-idea-ultimate/217/jbr/include/linux"
LIBFLAGS=-Wl,-soname,lib$*.so -shared -o 
JAVA=$(wildcard *.java)
H=$(JAVA:.java=.h)
CPP=$(wildcard *.cpp)
OBJ=$(CPP:.cpp=.o)
LIB=$(OBJ:.o=.so)

%.h: %.java
	javac -h . $*.java

%.o: %.h %.cpp
	$(CC) $(CPPFLAGS) $*.cpp

%.so: %.o
	$(CC) $(LIBFLAGS) lib$*.so *.o

all: $(H) $(OBJ) $(LIB)

clean:
	rm -f *.class *.so *.h *.o
