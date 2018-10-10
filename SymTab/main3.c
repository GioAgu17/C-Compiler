
#include "symbolTable.h"
extern SymbolTableStackEntryPtr top;

int main()
{
    initSymbolTable();
    // create a new type structure for a integer variable
    Type *typ_int = (Type *)malloc(sizeof(Type));
    typ_int->kind = INT;
    
    // create a new type structure for a integer variable
    Type *typ_void = (Type *)malloc(sizeof(Type));
    typ_void->kind = VOID;

    // create a new type structure for a integer variable
    Type *typ_func = (Type *)malloc(sizeof(Type));
    typ_func->kind = FUNCTION;
    
    // create a new type structure for a integer variable
    Type *typ_array = (Type *)malloc(sizeof(Type));
    typ_array->kind = ARRAY;
    typ_array->dimension = 10;
    
    ElementPtr s;
        
    symInsert("x", typ_int, 2);
    symInsert("main", typ_func, 3);
    enterScope();
    enterScope();
    symInsert("y", typ_array, 5);
    symInsert("x", typ_int, 6);
    
    s = symLookup("x");
    printElement(s);
    leaveScope();
    
   s = symLookup("x");
printElement(s);
 
   leaveScope();
//This must return symbol table entry for counter on line  10
   s = symLookup("x");
printElement(s);

    
}

