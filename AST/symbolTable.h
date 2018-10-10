
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
	                       /* Ignore this field until HW5 */
}Type;

typedef Type *TypePtr;
        
typedef struct element {
	int		key;
        char *		id;	       
	int             linenumber;
	int             scope;   /* scope depth at declaration */
	Type     	*stype;	      /* pointer to the type infomation */
	struct element	*next;		/* pointer to the next symbol with the
				          same hash table index */
        struct node     *snode;   /* (New) AST Node for method declartion */
} Element;

typedef Element	*ElementPtr;

typedef ElementPtr HashTableEntry;

/* data structure of the symbol table */

typedef struct symbolTable {
	HashTableEntry	hashTable[MAXHASHSIZE];		/* hash table  */
} SymbolTable;

typedef SymbolTable	*SymbolTablePtr;

typedef struct symbolTableStackEntry {
	SymbolTablePtr			symbolTablePtr;
	struct symbolTableStackEntry	*prevScope;
} SymbolTableStackEntry;

typedef SymbolTableStackEntry	*SymbolTableStackEntryPtr;


int		initSymbolTable() ;
ElementPtr		symLookup(char *);
ElementPtr		symInsert(char *, Type *, int );
int			enterScope();
void			leaveScope();



#endif
