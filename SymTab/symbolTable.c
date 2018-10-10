

#include "symbolTable.h"

// Top should point to the top of the scope stack,
// which is the most recent scope pushed

SymbolTableStackEntryPtr symbolStackTop;

int scopeDepth;


/* global function prototypes */

//allocate the global scope entry and symbol table --and set scopeDepth to 0
// The global scope remains till the end of the program
// return 1 on success, 0 on failure (such as a failed malloc)
int		initSymbolTable() 
{
	scopeDepth = 0;
	symbolStackTop = malloc(sizeof(struct symbolTableStackEntry));

	if(symbolStackTop == NULL)
		return 0;
	
	symbolStackTop -> symbolTablePtr = malloc(sizeof(struct symbolTable));
	
	if(symbolStackTop -> symbolTablePtr == NULL)
		return 0;

	symbolStackTop -> prevScope = NULL;
	return 1;
	
}


// Look up a given entry 
ElementPtr		symLookup(char* name)
{
	int index = hashIndex(name);
	SymbolTableStackEntryPtr supportStack = symbolStackTop;

	while(supportStack!=NULL){

		SymbolTablePtr symbolTable = supportStack -> symbolTablePtr;
		ElementPtr elem = symbolTable -> hashTable[index];

		while(elem != NULL){
			if(strcmp(elem -> id,name)==0)
				return elem;
			else
				elem = elem -> next;
		}
		supportStack = supportStack -> prevScope;
	}
	return NULL;
		
		
}


// Insert an element with a specified type in a particular line number
// initialize the scope depth of the entry from the global var scopeDepth
ElementPtr		symInsert(char *name, struct type *type, int line)
{
	int index = hashIndex(name);
	ElementPtr newElement = malloc(sizeof(struct element));

	if(newElement == NULL){
		printf("problem with malloc in symInsert");
		return NULL;
	}

	newElement -> key = index;
	newElement -> id = name;
	newElement -> linenumber = line;
	newElement -> stype = type;
	newElement -> scope = scopeDepth;
	newElement -> next = NULL;
	
	if(symbolStackTop -> symbolTablePtr -> hashTable[index] == NULL)
		symbolStackTop -> symbolTablePtr -> hashTable[index] = newElement;
	else{	
		ElementPtr elem = symbolStackTop -> symbolTablePtr -> hashTable[index];
		while(elem -> next!=NULL)
			elem = elem -> next;
		elem -> next = newElement;	
	}
	return newElement;
}


//push a new entry to the symbol stack
// This should modify the variable top and change the scope depth
// return 1 on success, 0 on failure (such as a failed malloc)
int			enterScope()
{
	SymbolTableStackEntryPtr newStackEntry = malloc(sizeof(struct symbolTableStackEntry));

	if(newStackEntry == NULL)
		return 0;

	SymbolTableStackEntryPtr temp = symbolStackTop;
	symbolStackTop = newStackEntry;
	symbolStackTop -> prevScope = temp;
	symbolStackTop -> symbolTablePtr = malloc(sizeof(struct symbolTable));
		
	if(symbolStackTop -> symbolTablePtr == NULL)
		return 0;
	scopeDepth++;
	return 1;
}


//pop an entry off the symbol stack
// This should modify top and change scope depth
void			leaveScope()
{
	SymbolTableStackEntryPtr temp = symbolStackTop;
	for(int i=0; i< MAXHASHSIZE; i++){
		ElementPtr ptr = temp -> symbolTablePtr -> hashTable[i];
		while(ptr != NULL){
			ElementPtr ptr1 = ptr;
			ptr = ptr -> next;
			free(ptr1);
		}
	}
	
	free(temp -> symbolTablePtr);
	symbolStackTop = temp -> prevScope;
	free(temp);
	scopeDepth--;
	
}




// Do not modify this function
void printElement(ElementPtr symelement) {
    if (symelement != NULL) {
        printf("Line %d: %s", symelement->linenumber,symelement->id);
    }
    else printf("Wrong call! symbol table entry NULL");
}

//should traverse through the entire symbol table and print it
// must use the printElement function given above
void printSymbolTable()
{	
	
	
	SymbolTableStackEntryPtr temp = symbolStackTop;
	
	while(temp!=NULL){
		 
		for(int i =0; i< MAXHASHSIZE; i++){
			ElementPtr elem = temp -> symbolTablePtr -> hashTable[i];
			if(elem != NULL){
				printElement(elem);
				while(elem -> next !=NULL){
					printElement(elem -> next);
					elem = elem -> next;
				}
			}
		}
		if(temp -> prevScope != NULL)
			temp = temp -> prevScope;
		else
			break;
	}

	
}


int hashIndex(char* name){
	// hashing the string to an index
	int index = 0;
	for(int i = 0; name[i]!= '\0'; i++){
		index = index + name[i];
	}
	index = index%MAXHASHSIZE;
	return index;
}


            


    





