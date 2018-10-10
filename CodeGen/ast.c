#include "symbolTable.h"
#include "ast.h"


extern SymbolTableStackEntryPtr symbolStackTop;

extern int scopeDepth;

//creates a new expression node
AstNodePtr  new_ExprNode(ExpKind kind) 
{
	AstNodePtr node = (AstNodePtr) malloc(sizeof(AstNode));
	node->nKind = EXPRESSION;
	node->eKind = kind;
	return node;
}

//creates a new statement node
AstNodePtr new_StmtNode(StmtKind kind)
{
	AstNodePtr node = (AstNodePtr) malloc(sizeof(AstNode));
	node->nKind = STMT; 
	node->sKind = kind;
	return node;		   	
}

AstNodePtr new_Node(NodeKind kind)
{
 	AstNodePtr node = (AstNodePtr) malloc(sizeof(AstNode));
 	node->nKind = kind; 
 	return node;
}
//creates a new type node for entry into symbol table
Type* new_type(TypeKind kind)
{
    Type *typ1 = (Type *)malloc(sizeof(Type));
    typ1->kind = kind; 	
    return typ1;
}







