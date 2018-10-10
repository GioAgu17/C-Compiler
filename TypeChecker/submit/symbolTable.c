

#include "symbolTable.h"

// Top should point to the top of the scope stack,
// which is the most recent scope pushed

SymbolTableStackEntryPtr symbolStackTop;

int scopeDepth;


/* global function prototypes */

//allocate the global scope entry and symbol table --and set scopeDepth to 0
// The global scope remains till the end of the program
void initSymbolTable() 
{
	//initialize a stack 
	int i=0;
	symbolStackTop = (SymbolTableStackEntryPtr) malloc (sizeof(struct symbolTableStackEntry));
	symbolStackTop -> symbolTablePtr = (SymbolTable*) malloc (sizeof(SymbolTable));

	for(i=0; i<MAXHASHSIZE; i++)
		symbolStackTop -> symbolTablePtr->hashTable[i] = NULL;				

	symbolStackTop -> symbolTablePtr->queue = NULL;
	symbolStackTop-> next = NULL;
    symbolStackTop-> prev = NULL;
	scopeDepth = 0;	
	//printf("\n Initialized Stack with Global Hash Table");
}


// Look up a given entry 
ElementPtr symLookup(char *name)
{
	char *a = name;
	SymbolTableStackEntryPtr iter = symbolStackTop;	
	int ascii = 0,depth = scopeDepth ;		
	while(*a!='\0')
	{
		ascii+= (int) *a; 
		a++;
	}
	// bug(?): does not search in all scopes?
	while(iter)
	{
		ElementPtr symelement = iter->symbolTablePtr->hashTable[ascii%16];			
		while(symelement)
		{
			if(strcmp(symelement->id, name) == 0)
			{
				//printf("\n Found symbol %s at scope depth %d",name, depth);
				return symelement;				
			}			
			else
			   symelement = symelement->next; 					
				
		}
		iter = iter->next;	
		//printf("\n Did not find symbol %s at scope depth %d",name, depth);
		depth--;
	}		
	return NULL;
}


// Insert an element with a specified type in a particular line number
// initialize the scope depth of the entry from the global var scopeDepth

//symInsert("counter", typ, 10);
ElementPtr symInsert(char *name, Type *type, int line)
{
	ElementPtr new_element = (ElementPtr) malloc (sizeof(Element));
	char *a = name;
	int ascii = 0 ;		
	while(*a!='\0')
	{
		ascii+= (int) *a; 
		a++;
	}
	new_element->key = ascii%16;
	new_element->id = strdup(name);
	new_element->linenumber = line;
	new_element->scope = scopeDepth;
	new_element->stype = type;
  new_element->snode = NULL;
  new_element->queue_next = NULL;

	if(!symbolStackTop->symbolTablePtr->queue) // if  this is the first element of symbol table
	  {
	    symbolStackTop->symbolTablePtr->queue = new_element;
	  } 
	else
	  {
	    ElementPtr tmp_queue_ptr;
	    for(tmp_queue_ptr = symbolStackTop->symbolTablePtr->queue; tmp_queue_ptr->queue_next != NULL; tmp_queue_ptr = tmp_queue_ptr->queue_next) ;
	    tmp_queue_ptr->queue_next = new_element;
	}
	if(!symbolStackTop->symbolTablePtr->hashTable[new_element->key]) // if the first element of hash table for this ascii is null
	{
		new_element->next = NULL;
		symbolStackTop->symbolTablePtr->hashTable[new_element->key] = new_element;	
	}	
	else
	{
		new_element->next = symbolStackTop->symbolTablePtr->hashTable[new_element->key];
		symbolStackTop->symbolTablePtr->hashTable[new_element->key] = new_element;
	}	
	//printf("\n Inserted %s at scope depth %d with ascii %d ",new_element->id,scopeDepth,new_element->key);
	return symbolStackTop->symbolTablePtr->hashTable[new_element->key];

}



//push a new entry to the symbol stack
// This should modify the variable top and change the scope depth
void enterScope()
{
	int i;
	SymbolTableStackEntryPtr newSymbolStackEntry = (SymbolTableStackEntryPtr) malloc (sizeof(struct symbolTableStackEntry));
	newSymbolStackEntry -> symbolTablePtr = (SymbolTable*) malloc (sizeof(SymbolTable));
	for(i=0; i<MAXHASHSIZE; i++)
		newSymbolStackEntry -> symbolTablePtr->hashTable[i] = NULL;				
	newSymbolStackEntry -> symbolTablePtr->queue = NULL;				
	newSymbolStackEntry->next = symbolStackTop; 
    
    newSymbolStackEntry->prev = NULL;
    symbolStackTop->prev = newSymbolStackEntry;

	symbolStackTop = newSymbolStackEntry;
	scopeDepth++;	
	//printf("\n New Scope");
}


//pop an entry off the symbol stack
// This should modify top and change scope depth
void leaveScope()
{
	if (!symbolStackTop)
		printf("\n Error .. cannot leave global scope");
	else if(!symbolStackTop->next)
		symbolStackTop = NULL;		
	else	
		symbolStackTop = symbolStackTop->next;	
	scopeDepth--;	
}

// Do not modify this function
void printElement(ElementPtr symelement) {
    if (symelement != NULL) {
        printf("Line %d: %s\n", symelement->linenumber,symelement->id);
    }
    else printf("Wrong call! symbol table entry NULL");
}

//should traverse through the entire symbol table and print it
// must use the printElement function given above
void printSymbolTable(int print_flag)
{
	int i;
	SymbolTableStackEntryPtr SymbolStackEntry = symbolStackTop;

    // rewind
    while (SymbolStackEntry->prev)
        SymbolStackEntry = SymbolStackEntry->prev;

	if (print_flag == 0){ // print in hash table order

	while(SymbolStackEntry)
	{
		for(i=0; i<MAXHASHSIZE;i++)
		{	
			ElementPtr symelement = SymbolStackEntry->symbolTablePtr->hashTable[i];
			while(symelement)
			{
				printElement(symelement);
				symelement = symelement->next; 
			}		
		}	
		SymbolStackEntry = SymbolStackEntry->next; 
	}
	}
	else{ // print in order of declaration

	while(SymbolStackEntry)
	  {
	    
	    ElementPtr symelement = SymbolStackEntry->symbolTablePtr->queue;
	    while(symelement)
	      {
		printElement(symelement);
		symelement = symelement->queue_next; 
	      }		

		SymbolStackEntry = SymbolStackEntry->next; 
	}
	}
}





            


    




