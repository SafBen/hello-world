#only ok for project with no templated classes

#compiler
COMPILER = g++-5
#linker
LINKER =g++-5

#options for linker and compiler
FLAGS =-g -ansi -Wall -Wextra -Wold-style-cast -Woverloaded-virtual -D_DEBUG_ -std=c++11

EXE_NAME= palindrom.exe

#can have several ones separated by spaces, only cpp files
SOURCES = palindrom.cpp


#PATH to extra header used in the project (when using libs not installed in the OS)
INC_PATHS= -I

#extra libs used in the project (for instance -lpthread)
LIBS	= -L 

LINKOBJ	= $(SOURCES:.cpp=.o)
SOURCEHEADERS = $(SOURCES:.cpp=.h)

$(EXE_NAME): $(LINKOBJ)
	$(LINKER) $(LINKOBJ) $(INC_PATHS) $(LIBS) -o $(EXE_NAME) $(FLAGS)

%.o: %.cpp %.h
	$(COMPILER) -g -c $< -o $@ $(INC_PATHS) $(FLAGS)

%.o: %.cpp 
	$(COMPILER) -g -c $< -o $@ $(INC_PATHS) $(FLAGS)
	
# cleanup
clean:
	rm -f $(LINKOBJ)
