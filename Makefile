IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR) -Wall -Wextra -Wpedantic -g

SRC=./src

ODIR=./src/obj
LDIR=../lib

LIBS=-lm

_DEPS=generic.h string_functions.h program_operation.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o string_functions.o program_operation.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

setup:
	mkdir -p $(ODIR)

$(ODIR)/%.o: $(SRC)/%.c $(DEPS) setup
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -rf $(ODIR) *~ core $(INCDIR)/*~ ./main.exe