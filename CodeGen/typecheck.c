
//#include "symbolTable.h"
//#include "ast.h"
#include "typecheck.h"
#include "util.h"
// Starts typechecking the AST  returns 1 on success
//use the global variable program
// 
extern AstNodePtr program;
extern int scopeDepth;
extern void yyerror(const char *);
int typesafeexp;
int typeequi;
AstNodePtr currentFun;
int typecheck(){
	
	// adding the functions input and output
	
	AstNodePtr input = (AstNodePtr) malloc(sizeof(AstNode));
	AstNodePtr output = (AstNodePtr) malloc(sizeof(AstNode));
		
	input->nKind = METHOD;
	AstNodePtr param1 = new_Node(FORMALVAR);
	param1->nType=(Type *) new_type(VOID);
	input->children[0] = NULL;
	input->children[1] = NULL;
	input->nType = (Type *) new_type(FUNCTION);
	
	int err = 0;
	ElementPtr symElement = symLookup("input");
	if (symElement == NULL || scopeDepth != symElement->scope)
	{
		input->nSymbolPtr = symInsert("input",input->nType,1);
		input->nSymbolPtr->stype->function = (Type *) malloc(sizeof(Type));
		input->nSymbolPtr->stype->function->kind = INT;
		input->nSymbolPtr->snode = input;
		//printf("\nAdded Input Fn");	
	}
	else
	{
	  format_err(0,"Cannot define global variable/function named", "input");
	  yyerror(err_msg);
	  err = 1;
	}
		

	output->nKind = METHOD;
	AstNodePtr param = new_Node(FORMALVAR);
	param->nType=(Type *) new_type(INT);
	output->children[0] = param;
	output->children[1] = NULL;
	output->nType = (Type *) new_type(FUNCTION);

	ElementPtr symElement1 = symLookup("output");
	if (symElement1 == NULL || scopeDepth != symElement1->scope)
	{
		output->nSymbolPtr = symInsert("output",output->nType,1);
		output->nSymbolPtr->stype->function = (Type *) malloc(sizeof(Type));
		output->nSymbolPtr->stype->function->kind = VOID;
		output->nSymbolPtr->stype->function->function = (Type *) malloc(sizeof(Type));
		output->nSymbolPtr->stype->function->function->kind = INT;
		output->nSymbolPtr->stype->function->function->function = NULL;
		output->nSymbolPtr->snode = output;
		//printf("\nAdded Output Fn");	
	}
	else
	{
		format_err(0,"Cannot define global variable/function named", "output");
		yyerror(err_msg);
		err = 1;
	}
	

	if (!err)
	{
		AstNodePtr currentFn=program;
		while (currentFn->sibling != NULL)
		{
			currentFn = currentFn->sibling;	
		}
		currentFn->sibling = input;
		input->sibling = output;	
	
	}
	// Filling in the type of the methods in their symboltable

	AstNodePtr currentF = program;
	while (currentF != NULL)
	{
		Type* currentType = currentF->nSymbolPtr->stype->function; 
		//printf("\nFn : %s  return type %d ",currentF->nSymbolPtr->id,currentF->nSymbolPtr->stype->function->kind);
		AstNodePtr formalvars = currentF->children[0];
	//	printf("Adding parameters ");
		while (formalvars != NULL)
		{
			currentType->function = formalvars->nType;
		//	printf(" %d,",formalvars->nType->kind);
			currentType = currentType->function;
			formalvars = formalvars->sibling;
		}
		currentF = currentF->sibling;
	}

	
	// Starting type check

	currentFun = program;
	while (currentFun != NULL)
	{
		typecheck_method(currentFun);
		currentFun = currentFun->sibling;
	}
	return 0;
};

// compares two types and returns the resulting type
// from the comparison

Type* type_equiv(Type *t1, Type *t2){
	if (t1->kind == INT && t2->kind == INT)
	{
		return t1;
	}
	
	if (t1->kind == ARRAY && t2->kind == ARRAY)
	{
		return t1;
	}
	typeequi = 0;
	printf ("\nType mismtach %d %d\n",t1->kind,t2->kind);
	yyerror("Type mimsatch");
	return NULL;

}

// Typechecks a method and returns 1 on success
int typecheck_method(AstNode *node_){
	int typesafe = 1;
	AstNodePtr stmt = node_->children[1];
	/* ========= new code block ============*/
	AstNodePtr ret = NULL;
	if (node_->children[1] != NULL)
		ret = node_->children[1]->children[0];
	/* ========= new code block ============*/
	while (stmt != NULL)
	{
		if (stmt->nKind != STMT) yyerror("Ast error tree in function block");
		typesafe = typesafe & typecheck_stmt(stmt);
		stmt = stmt->sibling;

		/* ========== everything from here ============ */
		if (ret == NULL)
			continue;

		while (ret->sibling != NULL)
			ret = ret->sibling;

		if (ret->sKind != RETURN_STMT && currentFun->nSymbolPtr->stype->function->kind != VOID)
		{
			format_err(ret->nLinenumber, "Last statement in method is not a return statement\n", "");
			yyerror(err_msg);
			return 0;
		}
		/* ========== to here is new ============ */
	} 
	return typesafe;
}

// Typechecks a statement and returns 1 on success
int typecheck_stmt( AstNode *node_){
	int typesafe = 1;
	AstNodePtr stmt;
	Type * net;
	switch(node_->sKind)
	{
		case IF_THEN_ELSE_STMT:
			typesafeexp = 1;
			net = typecheck_expr(node_->children[0]);
			if (net->kind != INT) {
				  format_err(node_->nLinenumber,"Error in if then expression", "Must be of type INT");
				  yyerror(err_msg);
				  //	yyerror("Error in if then expression");
				typesafe = 0;
			}
			typesafe = typesafeexp & typesafe;
			typesafe = typesafe & typecheck_stmt(node_->children[1]);
			if (node_->children[2] != NULL) typesafe = typesafe & typecheck_stmt(node_->children[2]);
			break;
		case WHILE_STMT:
			typesafeexp = 1;
			net = typecheck_expr(node_->children[0]);
			if (net->kind != INT) {
				  format_err(node_->nLinenumber,"Error in if while expression", "Must be of type INT");
				  yyerror(err_msg);
				  //yyerror("Error in while expression");
				typesafe = 0;
			}
			typesafe = typesafeexp & typesafe;
			typesafe = typesafe & typecheck_stmt(node_->children[1]);
			break;
		case RETURN_STMT:
			typesafeexp = 1;
			if (node_->children[0] == NULL)
			{
			  if (currentFun->nSymbolPtr->stype->function != NULL && currentFun->nSymbolPtr->stype->function->kind != VOID){
				    format_err(node_->nLinenumber,"Return type mismatch", "expected non-void got void");
					  yyerror(err_msg);
					  //yyerror("Return type mismatch");	
			  }
			}
			else
			{
				typesafeexp = 1;
				net = typecheck_expr(node_->children[0]);
				typesafe = typesafe & typesafeexp;
				if (currentFun->nSymbolPtr->stype->function->kind != net->kind){
				       format_err(node_->nLinenumber,"Return type mismatch", "");
				       yyerror(err_msg);
				      //yyerror("Return type mismatch");	
				}
			}	
			break;
		case COMPOUND_STMT:
			stmt = node_->children[0];
			while (stmt != NULL)
			{
				if (stmt->nKind != STMT) yyerror("Ast error tree in function block");
				typesafe = typesafe & typecheck_stmt(stmt);
				stmt = stmt->sibling;
			} 
			break;
		case EXPRESSION_STMT:
			typesafeexp = 1;
			if (node_-> children[0] != NULL)
			  typecheck_expr(node_->children[0]);		
			typesafe = typesafe & typesafeexp;
			break;
		default:
			yyerror("Incorrect statement kind");
	}
	return typesafe;
}

// Type checks a given expression and returns its type
// 
Type *typecheck_expr (AstNode *node_){
	Type *type1,*type2;
	AstNodePtr params;
	ElementPtr elem;
	switch(node_->eKind)
	{
		case CONST_EXP:
			return new_type(INT);
			break;
		case VAR_EXP:
			if (node_->nSymbolPtr == NULL)
			{
				format_err(node_->nLinenumber,"Variable/Function used before declaration", "");
				yyerror(err_msg);
				//yyerror("Variable/Function used before declaration");
			}
			else
			{
				return node_->nSymbolPtr->stype;
			}
			break;
		case ADD_EXP:
			type1 = typecheck_expr(node_->children[0]);
			type2 = typecheck_expr(node_->children[1]);
			if (type1->kind != INT || type2->kind != INT)
			{
				format_err(node_->nLinenumber," Type mismatch in addition", "");
				yyerror(err_msg);
				//yyerror("Type mismatch in addition");
				typesafeexp = 0;
			}
			return type1;
			break;
		case SUB_EXP:
			type1 = typecheck_expr(node_->children[0]);
			type2 = typecheck_expr(node_->children[1]);
			if (type1->kind != INT || type2->kind != INT)
			{
				format_err(node_->nLinenumber," Type mismatch in subtraction", "");
				yyerror(err_msg);
				//yyerror("Type mismatch in subtraction");
				typesafeexp = 0;
			}
			return type1;
			break;
		case MULT_EXP:
			type1 = typecheck_expr(node_->children[0]);
			type2 = typecheck_expr(node_->children[1]);
			if (type1->kind != INT || type2->kind != INT)
			{
				format_err(node_->nLinenumber," Type mismatch in multiplication", "");
				yyerror(err_msg);
				//	yyerror("Type mismatch in multiplication");
				typesafeexp = 0;
			}
			return type1;
			break;
		case DIV_EXP:
			type1 = typecheck_expr(node_->children[0]);
			type2 = typecheck_expr(node_->children[1]);
			if (type1->kind != INT || type2->kind != INT)
			{			
				format_err(node_->nLinenumber," Type mismatch in division", "");
				yyerror(err_msg);
				//				yyerror("Type mismatch in division");
				typesafeexp = 0;
			}
			return type1;
			break;
		case EQ_EXP:
			type1 = typecheck_expr(node_->children[0]);
			type2 = typecheck_expr(node_->children[1]);
			if (type1->kind != type2->kind)
			{
				format_err(node_->nLinenumber," Type mismatch in equality check", "");
				yyerror(err_msg);
				//				yyerror("Type mismatch in equality check");
				typesafeexp = 0;
			}
			return (new_type(INT));
			break;
		case NE_EXP:
			type1 = typecheck_expr(node_->children[0]);
			type2 = typecheck_expr(node_->children[1]);
			if (type1->kind != type2->kind)
			{
				format_err(node_->nLinenumber," Type mismatch in inequality check", "");
				yyerror(err_msg);
				//		yyerror("Type mismatch in inequality check");
				typesafeexp = 0;
			}
			return (new_type(INT));
			break;
		case GT_EXP:
			type1 = typecheck_expr(node_->children[0]);
			type2 = typecheck_expr(node_->children[1]);
			if (type1->kind != INT || type2->kind != INT)
			{
				format_err(node_->nLinenumber," Type mismatch in greater than check", "");
				yyerror(err_msg);
				//				yyerror("Type mismatch in greater than check");
				typesafeexp = 0;
			}
			return (new_type(INT));
			break;
		case GE_EXP:
			type1 = typecheck_expr(node_->children[0]);
			type2 = typecheck_expr(node_->children[1]);
			if (type1->kind != INT || type2->kind != INT)
			{
				format_err(node_->nLinenumber," Type mismatch in greater than equals check", "");
				yyerror(err_msg);
				//			yyerror("Type mismatch in greater or equal than check");
				typesafeexp = 0;
			}
			return (new_type(INT));
			break;
		case LT_EXP:
			type1 = typecheck_expr(node_->children[0]);
			type2 = typecheck_expr(node_->children[1]);
			if (type1->kind != INT || type2->kind != INT)
			{
				format_err(node_->nLinenumber," Type mismatch in less than check", "");
				yyerror(err_msg);
				//yyerror("Type mismatch in less than check");
				typesafeexp = 0;
			}
			return (new_type(INT));
			break;
		case LE_EXP:
			type1 = typecheck_expr(node_->children[0]);
			type2 = typecheck_expr(node_->children[1]);
			if (type1->kind != INT || type2->kind != INT)
			{
				format_err(node_->nLinenumber," Type mismatch in less than equal check", "");
				yyerror(err_msg);
				//				yyerror("Type mismatch in less or equal than check");
				typesafeexp = 0;
			}
			return (new_type(INT));
			break;
		case ASSI_EXP:
			if (!(node_->children[0]->eKind == VAR_EXP && node_->children[0]->nSymbolPtr->stype->kind == INT) && node_->children[0]->eKind != ARRAY_EXP)
			{
				yyerror("Incorrect Lvalue");
				typesafeexp = 0;
			}
			type2 = typecheck_expr(node_->children[1]);
			if (type2->kind != INT)
			{
				format_err(node_->nLinenumber," Type mismatch in assignment expression ", "");
				yyerror(err_msg);
				//yyerror("Type mismatch in less or equal than check");
				typesafeexp = 0;
			}
			return (type2);
			break;
		case CALL_EXP:
			params = node_->children[0];
			if (node_->nSymbolPtr == NULL)
			{
				elem = symLookup(node_->fname);
				if (elem == NULL){
					format_err(node_->nLinenumber," No function defnition found",node_->fname);
					yyerror(err_msg);
				}
			}
			else
			{
				elem = node_->nSymbolPtr;
			}
			if (elem != NULL)
			{
				type1 = elem->stype->function;
				type2 = type1->function;
			}
			if (params == NULL  && type2 != NULL) {
				format_err(node_->nLinenumber," Type mismatch here in function args", elem->id);
				yyerror(err_msg);
				//	  yyerror("Type mismatch in function parameters");
			}
			if (type2 == NULL && params != NULL){
			       format_err(node_->nLinenumber," Type mismatch in function args", elem->id);
			       yyerror(err_msg);
				typesafeexp = 0;
			}
			while (params != NULL)
			{
				type1 = typecheck_expr(params);
				if (type2->kind != type1->kind)
				{
				       format_err(node_->nLinenumber," Type mismatch in function args", elem->id);
				       yyerror(err_msg);
				       //yyerror("Type mismatch in function parameters");
					typesafeexp = 0;
				}	
				params = params->sibling;
				type2 = type2->function;
				if (type2 == NULL && params != NULL)
				{
				       format_err(node_->nLinenumber," Type mismatch in function args", elem->id);
				       yyerror(err_msg);
				       //yyerror("Type mismatch in function parameters");
					typesafeexp = 0;
					break;
				}
			}
			if (type2 != NULL){
				       format_err(node_->nLinenumber," Type mismatch in function args", elem->id);
				       yyerror(err_msg);
				       //  yyerror("Type mismatch in function parameters");
			}
			type1 = elem->stype->function;
			return type1;
			break;
		case ARRAY_EXP:
			type1 = typecheck_expr(node_->children[0]);
			if (type1->kind != INT){
				 format_err(node_->nLinenumber," Integer expected in array index", "");
				 yyerror(err_msg);
				 //  yyerror("Array index should be an integer");
			}
			if (node_->nSymbolPtr->stype->kind != ARRAY) {
				 format_err(node_->nLinenumber," Array operand expected in array expr", "");
				 yyerror(err_msg);
				 //			  yyerror("Operand is not of array type");
			}
			return new_type(INT);
			break;
	}	
	return NULL;
}




