#include "globals.h"
#include "symbolTable.h"

typedef enum {STMT, EXPRESSION, FORMALVAR, METHOD} NodeKind;

typedef enum {IF_THEN_ELSE_STMT, WHILE_STMT,
              RETURN_STMT, COMPOUND_STMT, EXPRESSION_STMT } StmtKind;

typedef enum {VAR_EXP, ARRAY_EXP, ASSI_EXP, ADD_EXP, SUB_EXP, MULT_EXP, DIV_EXP,
              GT_EXP, LT_EXP, GE_EXP, LE_EXP, EQ_EXP, NE_EXP, CALL_EXP, CONST_EXP
}ExpKind;

typedef struct node {
    NodeKind    nKind;
    StmtKind sKind; 
    ExpKind  eKind;
    struct node *children[MAXCHILDREN]; // max needed for if_then_else
    struct node *sibling; //List of statements, formal argument
    Type *nType; //node's type for typechecking expressions for HW5
    ElementPtr nSymbolPtr; // for variable and array expressions
    int nValue;  // for integer constants 
    SymbolTablePtr nSymbolTabPtr; //For a block, its symbol table
    char *fname;  // for a call expr, the name of the called function
    int nLinenumber;
}AstNode;

typedef AstNode *AstNodePtr;

AstNodePtr  new_ExprNode(ExpKind kind) ;

AstNodePtr new_StmtNode(StmtKind kind);

Type* new_type(TypeKind kind);

AstNodePtr new_Node(NodeKind kind);








