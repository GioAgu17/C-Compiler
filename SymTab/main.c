
#include "symbolTable.h"
extern SymbolTableStackEntryPtr symbolStacktop;

int main()
{
    initSymbolTable();
     // the following call adds a symbol hello in line 10 with unknown type
    symInsert("hello", NULL, 9);
// create a new type structure for a integer variable
    TypePtr typ = (TypePtr) malloc(sizeof(Type));
    typ->kind = INT;
// the following call adds a symbol counter in line 10 with type int
    symInsert("counter", typ, 10);

// the following code must return the entry created above
   ElementPtr s;
   s = symLookup("counter");

    
// Entering a new scope
    enterScope();

// create a new type structure for an array variable of array size 20
    TypePtr typ1 = (TypePtr )malloc(sizeof(Type));
    typ1->kind = ARRAY;
    typ1->dimension = 20;

    symInsert("carray", typ1, 13);
// the following code must return the entry created above
    TypePtr typ2 = (TypePtr)malloc(sizeof(Type));
    typ2->kind = ARRAY;
    typ2->dimension = 20;

    symInsert("counter", typ2, 14);
    printSymbolTable();	

//The following code must return the symbol table entry for counter on line 14xo
   s = symLookup("counter");
   leaveScope();
//This must return symbol table entry for counter on line  10
   s = symLookup("counter");

    
}


