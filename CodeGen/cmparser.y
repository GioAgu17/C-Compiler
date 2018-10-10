%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"
#include "symbolTable.h"
#include "util.h"
#include "codegen.h"
/* other external function prototypes */
extern int yylex();
extern int initLex(int ,  char **);
extern AstNodePtr new_Node(NodeKind kind); 
extern int typecheck(void);
extern void codegen();
    
/* external global variables */

extern int		yydebug;
extern int		yylineno;
extern SymbolTableStackEntryPtr symbolStackTop;
extern int scopeDepth;

/* function prototypes */ 
void	yyerror(const char *);

/* global variables */

AstNodePtr  program;
FILE *outfile; 

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
%type <nodePtr> Expression Simple_Expression Additive_Expression Factor Var Call Term
%type <nodePtr> Args Args_List
%type <nodePtr> Params Param_List Param

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


Start	: Declarations {}
;

Declarations : Functions { program = $1;}
	     | Var_Declaration Declarations { }
;

Functions    : Fun_Declaration { $$ = $1; }
	     | Fun_Declaration Functions { 
	     				   $1->sibling = $2;
	     				   $$ = $1 ;	
           				}
;

Var_Declaration : Type_Specifier TOK_ID TOK_SEMI {	
                                                       if ($1->kind != INT){
							    yyerror("non-int variable declared\n");
	     						    yyerror($2);
						       }	
							ElementPtr symElement = symLookup($2);
							if(!symElement || scopeDepth != symElement->scope)
								symInsert($2,$1,yylineno);
							else 
	     						{
	     							yyerror("Redeclaration of variable");
	     							yyerror($2);
	     							free($1);
	     						}
	     					}	
		| Type_Specifier TOK_ID TOK_LSQ TOK_NUM TOK_RSQ TOK_SEMI { 
                                                                             if ($1->kind != INT){
                   							    yyerror("non-int variable declared\n");
	     								    yyerror($2);
					   			            }	
									   ElementPtr symElement = symLookup($2);
									   if(!symElement || scopeDepth != symElement->scope)
									   {	/* reuse Type for storing dimension */
									   	$1->kind = ARRAY; 
      									   	$1->dimension = $4;
      									   	$1->function = NULL; 
      									      	symInsert($2,$1,yylineno);	
      									   }
      									   else 
      									   {
      									   	yyerror("Redeclaration of variable");
	     									yyerror($2);
      									   	free($1);
      									   } 	
      									  }
;

Fun_Declaration : Type_Specifier TOK_ID TOK_LPAREN {
							$<nodePtr>$ =  new_Node(METHOD);
							$<nodePtr>$->nLinenumber = yylineno; 
							$<nodePtr>$->nType = $1;
							ElementPtr symElement = symLookup($2);
							if(!symElement || scopeDepth != symElement->scope)
							{
							 	$<nodePtr>$->nSymbolPtr = symInsert($2,$1,yylineno);
							 	$<nodePtr>$->nSymbolPtr->stype->function = (Type*) malloc(sizeof(Type));
							 	$<nodePtr>$->nSymbolPtr->stype->function->kind = $1->kind;
							 	$<nodePtr>$->nSymbolPtr->snode = $<nodePtr>$;
							 	$1->kind = FUNCTION;
							 	enterScope();
							}	
							else 
   		   					{
   		   					  	yyerror("Redeclaration of function");
	     							yyerror($2);
   		   					  	free($1);
   		   					}  
						   }

			     Params TOK_RPAREN     {

							$<nodePtr>4->children[0] = $5; 	
					           } 
				 Compound_Stmt     {
				       			$<nodePtr>4->children[1] = $8; 	
				       			$$ = $<nodePtr>4;
				       			leaveScope();
				 		   } 	 	  		       	     
											 
;

Params : Param_List {$$ = $1;}
       | TOK_VOID {$$=NULL;}
;

Param_List : Param_List TOK_COMMA Param { 
						$<nodePtr>$ = $1;
						while($<nodePtr>$->sibling)
							$<nodePtr>$ = $<nodePtr>$->sibling;
						$<nodePtr>$->sibling = $3;
						$3->sibling = NULL;
						$$ = $1;
					}
	   | Param {
	   		$1->sibling = NULL;	   		
	   		$$ = $1;	   		
	   	   }
;

Param : Type_Specifier TOK_ID  { 	
					ElementPtr symElement = symLookup($2);
					if(!symElement || scopeDepth != symElement->scope)
					{
						$$ =  new_Node(FORMALVAR);
						$$->nLinenumber = yylineno;
						if ($1->kind != INT){
						  yyerror("non-int variable declared\n");
						}
						else{
						  $$->nSymbolPtr = symInsert($2,$1,yylineno);
						  $$->nType = $1;
						}
					}	
					else 
	     				{
	     					yyerror("Redeclaration of variable");
	     					yyerror($2);
	     					free($1);
   					}
	     			}			
      | Type_Specifier TOK_ID TOK_LSQ TOK_RSQ  {
      							ElementPtr symElement = symLookup($2);
							if(!symElement || scopeDepth != symElement->scope)
							{
							        Type *typ;	
								if ($1->kind != INT){
									yyerror("non-int array declared\n");
								}
							        typ = new_type(ARRAY);
							        $$ =  new_Node(FORMALVAR);
							        $$->nLinenumber = yylineno;
								$$->nSymbolPtr = symInsert($2,typ,yylineno);
								$$->nType = typ;
								free($1);
							}	
							else 
			     				{
			     					yyerror("Redeclaration of variable\n");
	     							yyerror($2);
			     					free($1);
		   					}
       					        }
;

Type_Specifier : TOK_INT {
			   $$ = (Type*) new_type(INT); 
			 }
	       | TOK_VOID { 
	       		   $$ = (Type*) new_type(VOID);
	       		  }
;

Compound_Stmt : TOK_LBRACE {  
				enterScope(); 
				$<nodePtr>$ =  new_StmtNode(COMPOUND_STMT);
				$<nodePtr>$->nSymbolTabPtr = symbolStackTop->symbolTablePtr;
			   	$<nodePtr>$->nLinenumber = yylineno;			   	
			   }
		Statements { $<nodePtr>2->children[0] = $3; } // shud point to first statement
		TOK_RBRACE { 
				leaveScope();
				$$ = $<nodePtr>2;
			   }
						 
              | TOK_LBRACE {  
				enterScope(); 
				$<nodePtr>$ =  new_StmtNode(COMPOUND_STMT);
				$<nodePtr>$->nSymbolTabPtr = symbolStackTop->symbolTablePtr;
			   	$<nodePtr>$->nLinenumber = yylineno;			   	
			   }
                Local_Declarations Statements { $<nodePtr>2->children[0] = $4;} // shud point to first statement
                TOK_RBRACE { 
                		leaveScope();
                		$$ = $<nodePtr>2;
                	   }
;

Local_Declarations : Var_Declaration Local_Declarations {}
		   | Var_Declaration {}
;

Statements : Statement Statements {
				     $1->sibling = $2;
				     $$ = $1;				    
				  }
	   | {$$=NULL;}
;

Statement : Expr_Statement  { 
				$$ = $1;
			    }
	  | Compound_Stmt {
	  			$$ = $1;
	  		  }
	  | Selection_Stmt { $$ = $1; }
	  | Iteration_Stmt {
	  			$$ = $1;
	  		   }
	  | Return_Stmt { $$ = $1; }
;

Expr_Statement : Expression TOK_SEMI {	
					$$ =  new_StmtNode(EXPRESSION_STMT);
					$$->nLinenumber = yylineno;
					$$->children[0] = $1;  
				     }
	       | TOK_SEMI {
	       			$$ =  new_StmtNode(EXPRESSION_STMT) ;
	       			$$->nLinenumber = yylineno;
	       			$$->children[0] = NULL;
	       		  }
;

Selection_Stmt : If_Else_Statement %prec TOK_IF { 
							$$ = $1; 
						}
	       | If_Else_Statement TOK_ELSE Statement { 
	       						$$ = $1;
	       						$$->children[2]= $3;
	       			   		      }
;

If_Else_Statement : TOK_IF TOK_LPAREN Expression {
							$<nodePtr>$ =  new_StmtNode(IF_THEN_ELSE_STMT);
							$<nodePtr>$->nLinenumber = yylineno;
							$<nodePtr>$->children[0] = $3;
						 }
				 TOK_RPAREN Statement { 
				 			$<nodePtr>4->children[1] = $6;
							$$ = $<nodePtr>4;
						      }
;

Iteration_Stmt : TOK_WHILE TOK_LPAREN Expression {
							$<nodePtr>$ =  new_StmtNode(WHILE_STMT);
							$<nodePtr>$->nLinenumber = yylineno;
							$<nodePtr>$->children[0] = $3; 							
						 }
			  TOK_RPAREN Statement {
							$<nodePtr>4->children[1] = $6; 
							$$ = $<nodePtr>4;			
							$<nodePtr>$->nLinenumber = yylineno;		
				 	       }
;

Return_Stmt : TOK_RETURN Expression TOK_SEMI { 	
						$$ =  new_StmtNode(RETURN_STMT);
						$$->nLinenumber = yylineno;
						$$->children[0] = $2; 
					     }
	    | TOK_RETURN TOK_SEMI {
	    				$$ =  new_StmtNode(RETURN_STMT);
	    				$$->nLinenumber = yylineno;
					$$->children[0] = NULL; 
	    			  }
;

Expression : Var TOK_ASSIGN {
	     			$<nodePtr>$ =  new_ExprNode(ASSI_EXP);
	     			$<nodePtr>$->nLinenumber = yylineno;
	     			$<nodePtr>$->children[0] = $1;	     			
	     		    }
	     Expression {
				
				$<nodePtr>3->children[1] = $4;
				$$ = $<nodePtr>3;						
			}
			
            | Simple_Expression {
            				$$ = $1;	
            			}
;

Var : TOK_ID { 
		$$ =  new_ExprNode(VAR_EXP);
		$$->nLinenumber = yylineno;
		$$->nSymbolPtr =  symLookup($1);
		if(!$$->nSymbolPtr)
		{
			yyerror("Variable must be declared before use");
			yyerror($1);
			free($$);
		}	
	     }
    | TOK_ID TOK_LSQ Expression TOK_RSQ {
    					 $$ =  new_ExprNode(ARRAY_EXP);
    					 $$->nLinenumber = yylineno;
			  		 $$->nSymbolPtr = symLookup($1);
					 if(!$$->nSymbolPtr)
 					 {  	
 					 	yyerror("Variable must be declared before use");
						yyerror($1);
 					 	free($$);
 					 }
					 else
					 	$$->children[0] = $3;			  	
    					 }
;

Simple_Expression : Additive_Expression TOK_GT {
							$<nodePtr>$ =  new_ExprNode(GT_EXP);
							$<nodePtr>$->nLinenumber = yylineno;
	     						$<nodePtr>$->children[0] = $1;	 			
					       }
			Additive_Expression {
						$<nodePtr>3->children[1] = $4;
						$$ = $<nodePtr>3;		
					    }
                  | Additive_Expression TOK_LT {
                  					$<nodePtr>$ =  new_ExprNode(LT_EXP);
                  					$<nodePtr>$->nLinenumber = yylineno;
	     						$<nodePtr>$->children[0] = $1;	 			
                  			       }
                  	Additive_Expression {
                  				$<nodePtr>3->children[1] = $4;
						$$ = $<nodePtr>3;		
                  			    }
                  | Additive_Expression TOK_GE {
                  					$<nodePtr>$ =  new_ExprNode(GE_EXP);
                  					$<nodePtr>$->nLinenumber = yylineno;
	     						$<nodePtr>$->children[0] = $1;	 			
                  			       } 
                  	Additive_Expression {
                  				$<nodePtr>3->children[1] = $4;
						$$ = $<nodePtr>3;	
                  			    }
                  	
                  | Additive_Expression TOK_LE {
                  					$<nodePtr>$ =  new_ExprNode(LE_EXP);
                  					$<nodePtr>$->nLinenumber = yylineno;
	     						$<nodePtr>$->children[0] = $1;	 			
                  			       } 	 
                  	Additive_Expression {
                  				$<nodePtr>3->children[1] = $4;
						$$ = $<nodePtr>3;	
                  			    }
                  	
                  | Additive_Expression TOK_EQ {
                  					$<nodePtr>$ =  new_ExprNode(EQ_EXP);
                  					$<nodePtr>$->nLinenumber = yylineno;
	     						$<nodePtr>$->children[0] = $1;	 			
                  			       }
                  	Additive_Expression {
                  				$<nodePtr>3->children[1] = $4;
						$$ = $<nodePtr>3;	
                  			    }
                  	
                  | Additive_Expression TOK_NE {	
                  					$<nodePtr>$ =  new_ExprNode(NE_EXP);
                  					$<nodePtr>$->nLinenumber = yylineno;
	     						$<nodePtr>$->children[0] = $1;	 			
                  			       } 	  
                  	 Additive_Expression {
                  	 			$<nodePtr>3->children[1] = $4;
						$$ = $<nodePtr>3;	
                  	   		     }
		  | Additive_Expression { $$ = $1 ;}
;

Additive_Expression : Additive_Expression TOK_PLUS {
							$<nodePtr>$ =  new_ExprNode(ADD_EXP);
							$<nodePtr>$->nLinenumber = yylineno;
	     						$<nodePtr>$->children[0] = $1;	 			
					 	   }
			Term {
				$<nodePtr>3->children[1] = $4;
				$$ = $<nodePtr>3;
			     }
			     
                    | Additive_Expression TOK_MINUS  {
            						$<nodePtr>$ =  new_ExprNode(SUB_EXP);
            						$<nodePtr>$->nLinenumber = yylineno;
     							$<nodePtr>$->children[0] = $1;	 		
            					     }
            	        Term {
            	        	$<nodePtr>3->children[1] = $4;
				$$ = $<nodePtr>3;	            	        
            	             }			
            	             		     
		    | Term {
		    		$$ = $1;	
		    	   }
;

Term : Term TOK_MULT {
			$<nodePtr>$ = new_ExprNode(MULT_EXP);
			$<nodePtr>$->nLinenumber = yylineno;
			$<nodePtr>$->children[0] = $1;	 		
		     } 	
	     Factor  {
	     		$<nodePtr>3->children[1] = $4;
			$$ = $<nodePtr>3;	      
		     }
			     
     |  Term TOK_DIV {
     			$<nodePtr>$ =  new_ExprNode(DIV_EXP);
     			$<nodePtr>$->nLinenumber = yylineno;
			$<nodePtr>$->children[0] = $1;	 			
     		     } 	 
     	      Factor {
     	      		$<nodePtr>3->children[1] = $4;
			$$ = $<nodePtr>3;	      
     	      	     }
     | Factor {
     		$$ = $1;		 	
     	      }
;

Factor : TOK_LPAREN Expression TOK_RPAREN { $$ = $2; }
       | Var { $$ = $1 ;}
       | Call { $$ = $1 ;}
       | TOK_NUM { 
       			$$ =  new_ExprNode(CONST_EXP);
       			$$->nLinenumber = yylineno;
       			$$->nValue = $1; 
       		 }
;

Call : TOK_ID TOK_LPAREN Args TOK_RPAREN {
						$$= new_ExprNode(CALL_EXP);
						$$->nLinenumber = yylineno;
						$$->nSymbolPtr = symLookup($1);
					 	if(!$$->nSymbolPtr)
 					 	{  	
						  printf("function %s not found, forward reference\n", $1);
						  $$->fname = strdup($1);
 					 	}
					 	$$->children[0] = $3;			  	    					 
					 }
;

Args : Args_List {$$=$1;}
     | { $$ = NULL; }
;

Args_List : Args_List TOK_COMMA Expression 
		  			   { 
						$<nodePtr>$ = $1;
						while($<nodePtr>$->sibling)
							$<nodePtr>$ = $<nodePtr>$->sibling;
						$<nodePtr>$->sibling = $3;
						$3->sibling = NULL;
						$$ = $1;
					   }
	  | Expression {
	 			$1->sibling = NULL;	   		
	   			$$ = $1;				
	  	       }
;

%%
void yyerror (char const *s) {
       fprintf (stderr, "Error at line %d: %s\n", yylineno, s);
	exit(1);
}


int main(int argc, char **argv){

	initLex(argc,argv);
	
	
#ifdef YYLLEXER
   while (gettok() !=0) ; //gettok returns 0 on EOF
    return;
#else
    initSymbolTable(); 	
    yyparse();
    typecheck();
    outfile = fopen(argv[2], "w+");
    codegen();
    fclose(outfile);
	
   
    
#endif
    
} 

