CC = gcc
CFLAGS = -ansi -Wall
LDFLAGS = -lsx
SRC = conv.c callbacks.c data.c
PROG = conv
OBJS = $(SRC:.c=.o)
.SUFFIXES: .c .o

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

callbacks.o: callbacks.h data.h
data.o: data.h
conv.o: data.h callbacks.h
%.o: %.c
	$(CC) $(CFLAGS) -c $<


.PHONY: clean
clean:
	rm -f *.o*~ core $(PROG)
