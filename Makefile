IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR) -Wall -Wextra -Wpedantic -std=c17 -g

SRC=./src

ODIR=./obj
LDIR=../lib

LIBS=-lm

_DEPS=generic.h string_functions.h program_operation.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o string_functions.o program_operation.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRC)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ ./main.exe