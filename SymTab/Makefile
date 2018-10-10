# Makefile for cminus

CC=gcc
LEX=flex
YACC=bison
MV=/bin/mv
RM=/bin/rm
CP=/bin/cp

LIBRARIES=  

CFLAGS=-g -Wall
YFLAGS=-d

PROGRAM=symboltable

OBJECTS=main3.o symbolTable.o

SOURCES=main3.c symbolTable.c


$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJECTS) $(LIBRARIES)

clean:
	$(RM) $(PROGRAM) $(OBJECTS) 

submit:
	mkdir submit
	cp symbolTable.c submit
	turnin -ccs473 -psymtab submit
