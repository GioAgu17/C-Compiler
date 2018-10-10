# Makefile for cminus

CC=gcc
LEX=flex
YACC=bison
MV=/bin/mv
RM=/bin/rm
CP=/bin/cp

LIBRARIES=  -ll

CFLAGS=-g 
YFLAGS=-d

PROGRAM=cmparser

OBJECTS=cmparser.o cmlexer.o symbolTable.o ast.o util.o

SOURCES=cmlexer.l cmparser.y symbolTable.c ast.c util.c

CTEMPS=cmlexer.c cmparser.c cmparser.tab.h cmparser.tab.c cmparser.output


$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJECTS) $(LIBRARIES)

util.o: util.c
	$(CC) $(CFLAGS) -c util.c
ast.o:  ast.c
	$(CC) $(CFLAGS) -c ast.c

symbolTable.o: symbolTable.c
	$(CC) $(CFLAGS) -c symbolTable.c

cmparser.o: cmparser.c 
	$(CC) $(CFLAGS) -c cmparser.c

cmparser.c: cmparser.y
	$(YACC)  cmparser.y -o cmparser.c

cmlexer.o: cmlexer.c cmparser.tab.h globals.h
	$(CC) $(CFLAGS) -c cmlexer.c

cmparser.tab.h: cmparser.y
	$(YACC) -d  cmparser.y 

cmlexer.c: cmlexer.l 
	$(LEX)  -ocmlexer.c cmlexer.l 

clean:
	$(RM) $(PROGRAM) $(OBJECTS) $(CTEMPS) 

submit:
	mkdir submit
	cp $(SOURCES) submit
	turnin -ccs473 -past submit
