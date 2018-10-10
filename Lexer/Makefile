# Makefile for cminus

CC=gcc
LEX=flex
YACC=bison
MV=/bin/mv
RM=/bin/rm
CP=/bin/cp

#COMMON_DIR = /mnt_nfs/home4/instruct/i473/scan
#INCL_DIR = /mnt_nfs/home4/instruct/i473/scan

LIBRARIES=-ll 

CFLAGS=-g

PROGRAM=cmlexer

OBJECTS=cmlexer.o 

SOURCES=cmlexer.l 


$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJECTS) $(LIBRARIES)

cmlexer.o: cmlexer.c cmparser.tab.h globals.h
	$(CC) $(CFLAGS) -c cmlexer.c

cmlexer.c: cmlexer.l 
	$(LEX)  -ocmlexer.c cmlexer.l 

clean:
	$(RM) $(PROGRAM) $(OBJECTS) 

submit:
	mkdir submit
	cp $(SOURCES) submit
	turnin -ccs473 -plexer submit
