
#ifndef _SYMBOL_TABLE
#define _SYMBOL_TABLE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "globals.h"


/* data structure of one element in the symbol table */

enum TypeKind {VOID, INT, ARRAY, FUNCTION};

struct type{
	enum TypeKind kind;   /* one from the enum above */
	int  dimension; /* for arrays */
	struct type *function; /*function argument and return types */
};

typedef struct type Type;

typedef struct type *TypePtr;
        
struct element {
	int		key;
    char *		id;	       
	int             linenumber;
	int             scope;   /* scope depth at declaration */
	TypePtr	stype;	      /* pointer to the type infomation */
	void *ast;           // AST information
	struct element	*next;		/* pointer to the next symbol with the same hash table index */
};

typedef struct element Element;

typedef struct element	*ElementPtr;

typedef ElementPtr HashTableEntry;

/* data structure of the symbol table */

struct symbolTable {
	HashTableEntry	hashTable[MAXHASHSIZE];		/* hash table  */
};

typedef struct symbolTable *SymbolTablePtr;

struct symbolTableStackEntry {
	SymbolTablePtr			symbolTablePtr;
	struct symbolTableStackEntry	*prevScope; //previous scope
} SymbolTableStackEntry;

typedef struct symbolTableStackEntry *SymbolTableStackEntryPtr;


int		    initSymbolTable() ;
ElementPtr		symLookup(char *);
ElementPtr		symInsert(char *, struct type * , int );
int			enterScope();
void			leaveScope();
void 			printSymbolTable();
int 			hashIndex(char *);

#endif
