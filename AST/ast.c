#include "symbolTable.h"
#include "ast.h"


extern SymbolTableStackEntryPtr symbolStackTop;

extern int scopeDepth;
//creates a new general node (either STMT, EXPRESSION, FORMALVAR, METHOD)

AstNodePtr new_GenNode(NodeKind kind){
	AstNodePtr newGenNode = (AstNodePtr) malloc(sizeof(struct node));
	newGenNode->nKind = kind;
	return newGenNode;
}
//creates a new expression node
AstNodePtr  new_ExprNode(ExpKind kind) 
{
	AstNodePtr newExprNode = (AstNodePtr) malloc(sizeof(struct node));
	newExprNode->nKind = EXPRESSION;
	newExprNode->sKind = EXPRESSION_STMT;
	newExprNode->eKind = kind;
	return newExprNode;
	
}

//creates a new statement node
AstNodePtr new_StmtNode(StmtKind kind)
{
	AstNodePtr newStmtNode = (AstNodePtr) malloc(sizeof(struct node));
	newStmtNode->nKind = STMT;	
	newStmtNode->sKind = kind;

	return newStmtNode;
	
}

//creates a new type node for entry into symbol table
Type* new_type(TypeKind kind)
{
	TypePtr typeNew = (TypePtr) malloc(sizeof(struct type));
	typeNew->kind = kind;
	typeNew->dimension = 0;
	typeNew->function = NULL;
	return typeNew;	
}

//lookups in the symbol table only in the current scope

ElementPtr symLookupInScope(char *name)
{
	ElementPtr ep = symLookup(name);
	if(ep!=NULL && (ep->scope == scopeDepth))
		return ep;
	else
		return NULL;
}









