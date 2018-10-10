
#ifndef _SYMBOL_TABLE
#define _SYMBOL_TABLE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "globals.h"

/* data structure of one element in the symbol table */

typedef enum  {VOID, INT, ARRAY, FUNCTION} TypeKind;

typedef struct type{
	TypeKind kind;   /* one from the enum above */
	int  dimension; /* for arrays */
	struct type *function; /*function argument and return types */
}Type;

typedef Type *TypePtr;
        
typedef struct element {
	int key;
  char * id;	       
	int             linenumber;
	int             scope;   /* scope depth at declaration */
	Type     	*stype;	      /* pointer to the type infomation */
	struct element	*next;		/* pointer to the next symbol with the				          same hash table index */
  struct node     *snode;   /* (New) AST Node for method declaration */
	struct element *queue_next; /* (New) Pointer to next element in  queue of  declarared elements  */
	int FPOffset; // frame pointer offset stored in Element <---------------- this is what it should be added
	int global; // 0 if the variable is global, 1 otherwise
} Element;

typedef Element	* ElementPtr;

typedef ElementPtr HashTableEntry;

/* data structure of the symbol table */

typedef struct symbolTable {
	HashTableEntry	hashTable[MAXHASHSIZE];		/* hash table  */
	struct element *queue; /* (New) points to first inserted (or first declared) symbol */
} SymbolTable;

typedef SymbolTable	*SymbolTablePtr;

typedef struct symbolTableStackEntry {
	SymbolTablePtr			symbolTablePtr;
	struct symbolTableStackEntry	*next;
    struct symbolTableStackEntry    *prev;
} SymbolTableStackEntry;

typedef SymbolTableStackEntry	*SymbolTableStackEntryPtr;


void		initSymbolTable() ;
ElementPtr		symLookup(char *);
ElementPtr		symInsert(char *, Type *, int );
void			enterScope();
void			leaveScope();


#endif

