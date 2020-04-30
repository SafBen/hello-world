CC=g++
CPPFLAGS=-c -fpic -Wall -I "/home/user/Documents/intellij/idea-IU-193.6911.18/jbr/include" -I "/home/user/Documents/intellij/idea-IU-193.6911.18/jbr/include/linux"
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
