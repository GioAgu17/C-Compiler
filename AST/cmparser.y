%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"
#include "symbolTable.h"
#include "util.h"


#define YYERROR_VERBOSE 1

/* other external function prototypes */
extern int yylex();
extern int initLex(int ,  char **);

    
/* external global variables */

extern int		yydebug;
extern int		yylineno;
extern SymbolTableStackEntryPtr symbolStackTop;
extern int scopeDepth;

/* function prototypes */ 
void	yyerror(const char *);

/* global variables */

AstNodePtr  program;
 

%}



/* YYSTYPE */
%union
{
    AstNodePtr nodePtr;
    int        iVal;
    char      *cVal;
    Type      *type;
}

    

/* terminals */

%token TOK_ELSE TOK_IF TOK_RETURN TOK_VOID TOK_INT TOK_WHILE 
%token TOK_PLUS TOK_MINUS TOK_MULT TOK_DIV TOK_LT TOK_LE TOK_GT TOK_GE TOK_EQ TOK_NE TOK_ASSIGN TOK_SEMI TOK_COMMA
%token TOK_LPAREN TOK_RPAREN TOK_LSQ TOK_RSQ TOK_LBRACE TOK_RBRACE TOK_ERROR
%token <cVal> TOK_ID 
%token <iVal> TOK_NUM

%type <nodePtr> Declarations Functions Fun_Declaration
%type <type> Type_Specifier 
%type <nodePtr> Compound_Stmt Statements Statement
%type <nodePtr> Expr_Statement If_Else_Statement Selection_Stmt Iteration_Stmt Return_Stmt
%type <nodePtr> Expression Simple_Expression Additive_Expression Factor Var Call
%type <nodePtr> Args Args_List Params Param_List Param Term
/* associativity and precedence */

%nonassoc TOK_IF
%nonassoc TOK_ELSE
%right TOK_ASSIGN
%left TOK_EQ TOK_NE
%nonassoc TOK_LT TOK_GT	TOK_LE TOK_GE
%left TOK_PLUS TOK_SUB
%left TOK_MULT TOK_DIV 
%nonassoc error

%%


Start	: Declarations {
		
                        }
;

Declarations : Functions { 
                         program = $1;
						
			 }
	     | Var_Declaration Declarations {
			$$ = $2;
			
	     }
;

Functions    : Fun_Declaration {
	                   $$ = $1;
			   }
	     | Fun_Declaration Functions {
	     			//$$ = $1;
				$1->sibling = $2;
					
		   	   }
;

Var_Declaration : Type_Specifier TOK_ID TOK_SEMI {
			if(symLookupInScope($2) != NULL){
				yyerror($2);			
			}
			else{
				symInsert($2,$1,yylineno);
			}			   
		}
		| Type_Specifier TOK_ID TOK_LSQ TOK_NUM TOK_RSQ TOK_SEMI {
			$1->kind = ARRAY;
			$1->dimension = $4;
			if(symLookupInScope($2) != NULL){
				yyerror($2);
			}
			else
				symInsert($2,$1,yylineno);		        
   }
			
;

Fun_Declaration : Type_Specifier TOK_ID TOK_LPAREN {enterScope();}Params TOK_RPAREN {enterScope();} Compound_Stmt {leaveScope();} {leaveScope();}  {
			


			if(symLookupInScope($2) != NULL){
				yyerror($2);
			}
			else{
				$$ = new_GenNode(METHOD);
				TypePtr newType = new_type($1->kind);
				$1->kind = FUNCTION;
				$1->function = newType;
				$$->nType = $1;
				$$->nSymbolPtr = symInsert($2,$1,yylineno);
				$$->children[0] = $5;
				$$->children[1] = $8;
				$$->nSymbolTabPtr = symbolStackTop->symbolTablePtr;
				$$->nLinenumber = yylineno;
				
				
			}
                           }
;

Params : Param_List {
		$$ = $1;
			   
			   }
       | TOK_VOID {
       			   }
;

Param_List : Param_List TOK_COMMA Param {
		AstNodePtr temp = $1;
		while(temp->sibling!=NULL){
			temp = temp->sibling;
		}
		temp->sibling = $3;
		$$ = $1;
	
}
	   | Param {
		$$= $1;
	   			
			}
;

Param : Type_Specifier TOK_ID  {
		
		if(symLookupInScope($2)!=NULL){
			yyerror($2);
		}
		else{
			$$ = new_GenNode(FORMALVAR);
			$$->nType = $1;
			$$->nSymbolPtr = symInsert($2,$1,yylineno);
			$$->nLinenumber = yylineno;
		}	
		 	}
      | Type_Specifier TOK_ID TOK_LSQ TOK_RSQ  {
      		if(symLookupInScope($2)!=NULL){
			yyerror($2);
		}
		else{
			$$ = new_GenNode(FORMALVAR);
			$1->kind = ARRAY;
			$$->nType = $1;
			$$->nSymbolPtr = symInsert($2,$1,yylineno);
			$$->nLinenumber = yylineno;
		}
			
      			}
;
Type_Specifier : TOK_INT {
		$$ = new_type(INT);	
			}
	       | TOK_VOID {
	       	$$ = new_type(VOID);
	       		}
;

Compound_Stmt : TOK_LBRACE Statements TOK_RBRACE  {
		
			$$ = new_StmtNode(COMPOUND_STMT);
			$$->nSymbolTabPtr = symbolStackTop->symbolTablePtr;
			$$->children[0] = $2;
			
			}
              | TOK_LBRACE Local_Declarations Statements TOK_RBRACE {
	      	
			$$ = new_StmtNode(COMPOUND_STMT);
			$$->nSymbolTabPtr = symbolStackTop->symbolTablePtr;
			$$->children[0] = $3;
	      		}
;

Local_Declarations : Var_Declaration Local_Declarations {
		
		
			}
		   | Var_Declaration {
		   	
		   	}
;

Statements : Statement Statements {
			$$ = $1;
			$$->sibling = $2;
			}
	   | {
			$$ = NULL;
	   		
			}
;

Statement : Expr_Statement  {
			$$ = $1;
			}
	  | {enterScope();}Compound_Stmt {leaveScope();} {
	  		$$ = $2;
			}
	  | Selection_Stmt {
	  		$$ = $1;
	  		}
	  | Iteration_Stmt {
	  		$$ = $1;
	  		}
	  | Return_Stmt {
	  		$$ = $1;
			}
;

Expr_Statement : Expression TOK_SEMI {
			$$ = new_StmtNode(EXPRESSION_STMT);
			$$->children[0] = $1;
			$$->nLinenumber = yylineno;
			}
	       | TOK_SEMI {
	       
	       		}
;

Selection_Stmt : If_Else_Statement %prec TOK_IF {
			$$ = $1;
			}
	       | If_Else_Statement TOK_ELSE Statement {
	       		$$ = $1;
			$$->children[2] = $3;
	       		}
;

If_Else_Statement : TOK_IF TOK_LPAREN Expression TOK_RPAREN Statement {
			$$ = new_StmtNode(IF_THEN_ELSE_STMT);
			$$->children[0] = $3;
			$$->children[1] = $5;
			$$->nLinenumber = yylineno;
			}
;

Iteration_Stmt : TOK_WHILE TOK_LPAREN Expression TOK_RPAREN Statement {
			$$ = new_StmtNode(WHILE_STMT);
			$$->children[0] = $3;
			$$->children[1] = $5;
			$$->nLinenumber = yylineno;
			}
;

Return_Stmt : TOK_RETURN Expression TOK_SEMI {
		$$ = new_StmtNode(RETURN_STMT);
		$$->children[0] = $2;

			}
	    | TOK_RETURN TOK_SEMI {
	    	$$ = new_StmtNode(RETURN_STMT);
		$$->children[0] = NULL;
	    		}
;

Expression : Var TOK_ASSIGN Expression  {
			$$ = new_ExprNode(ASSI_EXP);
			$$->children[0] = $1;
			$$->children[1] = $3;
			$$->nLinenumber = yylineno;
			
			}
            | Simple_Expression {
	    		$$ = $1;
	    		}
;

Var : TOK_ID {
	if(symLookup($1)==NULL){
		yyerror($1);
	}
	else{
		$$ = new_ExprNode(VAR_EXP);
		$$->nSymbolPtr = symLookup($1);
		$$->nLinenumber = yylineno;
	}
	
			}
    | TOK_ID TOK_LSQ Expression TOK_RSQ {
	if(symLookup($1)==NULL){
		yyerror($1);
	}
	else{
		$$ = new_ExprNode(ARRAY_EXP);
		$$->nSymbolPtr = symLookup($1);
		$$->nLinenumber = yylineno;
		$$->children[0] = $3;
	}
	
    
    			}
;

Simple_Expression : Additive_Expression TOK_GT Additive_Expression {
				$$ = new_ExprNode(GT_EXP);
				$$->nLinenumber = yylineno;
				$$->children[0] = $1;
				$$->children[1] = $3;	
			}
                  | Additive_Expression TOK_LT Additive_Expression {
				$$ = new_ExprNode(LT_EXP);
				$$->nLinenumber = yylineno;
				$$->children[0] = $1;
				$$->children[1] = $3;		  
		
		  	}
                  | Additive_Expression TOK_GE Additive_Expression {
		  		$$ = new_ExprNode(GE_EXP);
				$$->nLinenumber = yylineno;
				$$->children[0] = $1;
				$$->children[1] = $3;
		  	}
                  | Additive_Expression TOK_LE Additive_Expression {
		  		$$ = new_ExprNode(LE_EXP);
				$$->nLinenumber = yylineno;
				$$->children[0] = $1;
				$$->children[1] = $3;
			}
                  | Additive_Expression TOK_EQ Additive_Expression {
		  		$$ = new_ExprNode(EQ_EXP);
				$$->nLinenumber = yylineno;
				$$->children[0] = $1;
				$$->children[1] = $3;
		  	}
                  | Additive_Expression TOK_NE Additive_Expression {
		  		$$ = new_ExprNode(NE_EXP);
				$$->nLinenumber = yylineno;
				$$->children[0] = $1;
				$$->children[1] = $3;
		  	}
		  | Additive_Expression {
		  		$$ = $1;
		  	}
;

Additive_Expression : Additive_Expression TOK_PLUS Term {
				$$ = new_ExprNode(ADD_EXP);
				$$->nLinenumber = yylineno;
				$$->children[0] = $1;
				$$->children[1] = $3;
			}
                    | Additive_Expression TOK_MINUS Term {
		    		$$ = new_ExprNode(SUB_EXP);
				$$->nLinenumber = yylineno;
				$$->children[0] = $1;
				$$->children[1] = $3;
		    	}
		    | Term {
		    		$$ = $1;
		    	}
;

Term : Term TOK_MULT Factor  {
				$$ = new_ExprNode(MULT_EXP);
				$$->nLinenumber = yylineno;
				$$->children[0] = $1;
				$$->children[1] = $3;
			}
     |  Term TOK_DIV Factor {
				$$ = new_ExprNode(DIV_EXP);
				$$->nLinenumber = yylineno;
				$$->children[0] = $1;
				$$->children[1] = $3;
     
     			}
     | Factor {
			$$ = $1;
     			
			}
;

Factor : TOK_LPAREN Expression TOK_RPAREN {
			$$ = $2;
			}
       | Var {
 			$$ = $1;
       			
			}
       | Call {
			$$ = $1;
       
       			}
       | TOK_NUM {
			$$ = new_ExprNode(CONST_EXP);
			$$->nValue = $1;
			$$->nLinenumber = yylineno;
       
       			}
;

Call : TOK_ID TOK_LPAREN Args TOK_RPAREN {
			$$ = new_ExprNode(CALL_EXP);
			$$->children[0] = $3;
			$$->nLinenumber = yylineno;
			$$->fname = $1;

			}
;

Args : Args_List {
		$$ = $1;
			
			}
     | {
     		$$ = NULL;
     			}
;

Args_List : Args_List TOK_COMMA Expression {
			AstNodePtr temp = $1;
			while(temp->sibling!=NULL){
				temp = temp->sibling;
			}
			temp->sibling = $3;
			$$ = $1;
			}
	  | Expression {
	  		$$ = $1;
	  		}
;

%%
void yyerror (char const *s) {
       fprintf (stderr, "Error in line %d: %s\n", yylineno, s);
}

int main(int argc, char **argv){

	initLex(argc,argv);
	initSymbolTable();
#ifdef YYLLEXER
   while (gettok() !=0) ; //gettok returns 0 on EOF
    return;
#else
    yyparse();

  print_Ast();
    
#endif
    
} 
