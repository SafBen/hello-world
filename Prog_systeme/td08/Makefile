#---------------------------------------------------------------------------------
# Primitives de POSIX.1 : Manipulations de processus
#---------------------------------------------------------------------------------

#---------------------------------------------------------------------------------
# Variables
#---------------------------------------------------------------------------------

# Compilateur et options
# ----------------------
CC      = gcc
CFLAGS  = -g -Wall -Wextra -Wno-unused-variable -std=gnu99 -fpic #-DMALLOC_DBG

DYN_LIB = libmalloc.so libmymalloc.so
EXE     = test-simple-malloc.exe test-simple-mymalloc.exe test-malloc.exe test-mymalloc.exe

HTML    = $(EXE:.exe=.html)

#---------------------------------------------------------------------------------
# Cibles principales
#---------------------------------------------------------------------------------

all: $(DYN_LIB) $(EXE)

lib%.so: %.o
	$(CC) $(CFLAGS) -shared -Wl,-soname,$@ $^ -o $@

test-mymalloc.c: test-malloc.c
	cp test-malloc.c test-mymalloc.c

test-simple-mymalloc.c: test-simple-malloc.c
	cp test-simple-malloc.c test-simple-mymalloc.c

test-%.exe: test-%.o lib%.so
	$(CC) $(CFLAGS) -o $@ $^

test-simple-%.exe: test-simple-%.o lib%.so
	$(CC) $(CFLAGS) -o $@ $^

%.exe: %.o
	$(CC) $(CFLAGS) -o $@ $^

# Nettoyages
# ----------

# Nettoyage léger
clean:
	@rm -f \#* *.o $(HTML) $(DYN_LIB) $(EXE)

# Nettoyage en profondeur
mrproper: clean
	@rm -rf *~ *.html test-mymalloc.c test-simple-mymalloc.c

# Tests
# ----------

test: SHELL:=/bin/bash
test: $(EXE) $(HTML)

villoc/villoc.py:
	@chmod 755 villoc/villoc.py

%.html: %.exe villoc/villoc.py
	@LD_LIBRARY_PATH=. ltrace -S ./$< |& villoc/villoc.py --raw - $@