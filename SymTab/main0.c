
#include "symbolTable.h"
extern SymbolTableStackEntryPtr top;

int main()
{
    initSymbolTable();
     // the following call adds a symbol hello in line 10 with unknown type
enterScope();
    symInsert("hello", NULL, 9);
// create a new type structure for a integer variable
    Type *typ = (Type *)malloc(sizeof(Type));
    typ->kind = INT;
// the following call adds a symbol counter in line 10 with type int
    symInsert("counter", typ, 10);

// the following code must return the entry created above
   ElementPtr s;
   s = symLookup("counter");
printElement(s);

    
// Entering a new scope
    enterScope();

// create a new type structure for an array variable of array size 20
    Type *typ1 = (Type *)malloc(sizeof(Type));
    typ1->kind = ARRAY;
    typ1->dimension = 20;

    symInsert("carray", typ1, 13);
// the following code must return the entry created above
    Type *typ2 = (Type *)malloc(sizeof(Type));
    typ2->kind = ARRAY;
    typ2->dimension = 20;

    symInsert("counter", typ2, 14);
//The following code must return the symbol table entry for counter on line 14xo
   s = symLookup("counter");
printElement(s);
   leaveScope();
//This must return symbol table entry for counter on line  10
   s = symLookup("counter");
printElement(s);
   leaveScope();
    
}

