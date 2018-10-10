
#include "symbolTable.h"
#include "ast.h"

// Starts typechecking the AST  returns 1 on success
//use the global variable program

int typecheck();

// compares two types and returns the resulting type
// from the comparison

Type* type_equiv(Type *, Type *);

// Typechecks a method and returns 1 on success
int typecheck_method(AstNode *);

// Typechecks a statement and returns 1 on success
int typecheck_stmt( AstNode *);

// Type checks a given expression and returns its type
// 

Type *typecheck_expr (AstNode *);




