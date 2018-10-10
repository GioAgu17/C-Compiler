%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"
#include "symbolTable.h"
#include "util.h"


/* other external function prototypes */
extern int yylex();
extern int initLex(int ,  char **);
extern AstNodePtr new_Node(NodeKind kind); 
    
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

%type <nodePtr> Declarations Functions Fun_Declaration Compound_Stmt_Function
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
                            if ($1->kind != INT){	//C-- deals only with integers
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
                            if ($1->kind != INT){ //C-- should have only integer types
                   			    yyerror("non-int variable declared\n");
	     					    yyerror($2);
					   		}	
							ElementPtr symElement = symLookup($2); //look up identifier in symbol table
							if(!symElement || scopeDepth != symElement->scope) {	/* reuse Type for storing dimension */
								$1->kind = ARRAY; 
      							$1->dimension = $4; 
      							$1->function = NULL; 
 								symInsert($2,$1,yylineno); //insert it in symbol table
      						}
      						else {
      							yyerror("Redeclaration of variable");
	     						yyerror($2);
      							free($1);
      						} 	
      			}
;

Fun_Declaration : Type_Specifier TOK_ID TOK_LPAREN {	
						$<nodePtr>$ =  new_Node(METHOD); 	 //Mid-rule action. It counts as a component of the rule. It has not
						$<nodePtr>$->nLinenumber = yylineno; //been defined in the token and non-terminal declarations, so its type is set using 
															 //the $<...>$ syntax. $<nodePtr>$ means that the datatype of the value
						$<nodePtr>$->nType = $1;	     	 //represented by this component is nodePtr 
						ElementPtr symElement = symLookup($2); //the identifier is looked up to see if it exists. If it does not exist,
						if(!symElement || scopeDepth != symElement->scope) { 
								 //or if it has been declared in a previous scope 
							$<nodePtr>$->nSymbolPtr = symInsert($2,$1,yylineno);//insert it in the symbol table, set the nSymbolPtr
	 						$<nodePtr>$->nSymbolPtr->stype->function = (Type*) malloc(sizeof(Type)); //allocate the type for the function
	 						$<nodePtr>$->nSymbolPtr->stype->function->kind = $1->kind; 	//set the kind of the function, i.e. its return type
	 						$<nodePtr>$->nSymbolPtr->snode = $<nodePtr>$; 			 //nSymbolPtr->snode must point to the AST node itself
							$1->kind = FUNCTION; 								//$1->kind is a function.
	 						enterScope(); 										//create a new scope for the function 
						}	
						else {	
   	  						yyerror("Redeclaration of function");
							yyerror($2);
   	  						free($1);
   						}  
				}
				Params TOK_RPAREN     {
					$<nodePtr>4->children[0] = $5; 	//refer to the previous semantic action node with $<nodePtr>4, 
					$<nodePtr>4->children[0] = $5; //refer to the previous semantic action node with $<nodePtr>4, 
					
													//since it is the fourth component of the rule
				} 					//we also need to specify its type. children[0] is represented by Params. 
				Compound_Stmt     {
							
				       			$<nodePtr>4->children[1] = $8; 	//Compound Statement. According to the handout, the children[1] should be set to Compund_Stmt.
				       			$$ = $<nodePtr>4; //this is the last action, $$, i.e. Fun_Declaration is set to the node created in the first semantic action, which represents
							leaveScope();
				 		   } 	 	  		       	     
											 
;

Params : Param_List {$$ = $1;}
       | TOK_VOID {$$=NULL;}
;

Param_List : Param_List TOK_COMMA Param { 
						$<nodePtr>$ = $1; //this is a paramter list appearing in a function declaration. Mid-rule action. Set its value to $1. 
						while($<nodePtr>$->sibling){	//go to the end of the list of siblings
							$<nodePtr>$ = $<nodePtr>$->sibling; 
						}
						$<nodePtr>$->sibling = $3; //set the sibling to $3, that is to the next Param in input. This whole list (current $3 included) will represent Param_List
						$3->sibling = NULL;	   //so far if there are even more params in input, ie. as long as this rule keeps matching.
						$$ = $1;
					}
	   | Param {
	   		$1->sibling = NULL;	//single parameter. It has no siblings   		
	   		$$ = $1;	   		
	   	   }
;

Param : Type_Specifier TOK_ID  { 	
					ElementPtr symElement = symLookup($2); //lookup if it has been declared before
					if(!symElement || scopeDepth != symElement->scope)// if not declared before, or declared in a different scope, it must be inserted in the current (i.e. function) 												  //scope
					{
						$$ =  new_Node(FORMALVAR);	//this is a formal variable
						$$->nLinenumber = yylineno;	//set the line number
						if ($1->kind != INT){		//if it is not INT, C-- error
						  yyerror("non-int variable declared\n");
						}
						else{
						  $$->nSymbolPtr = symInsert($2,$1,yylineno); //otherwise insert in symbol table, set nSymbolPtr to the entry in the symbol table
						  $$->nType = $1;	//set the type of the whole Param to $1 (i.e. Type_Specifier)
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
			   $$ = (Type*) new_type(INT); //creates a new Type INT struct, it is used elsewhere whenever Type_Specifier appears (?)
			 }
	       | TOK_VOID { 
	       		   $$ = (Type*) new_type(VOID); //creates a new Type VOID struct
	       		  }
;

Compound_Stmt : TOK_LBRACE {  
				enterScope(); //a compound statement has a different scope from that of the function declaration, as per handout instructions
				$<nodePtr>$ =  new_StmtNode(COMPOUND_STMT);//mid-rule action. Create a new StmtNode of kind Compund_Stmt. 
				$<nodePtr>$->nSymbolTabPtr = symbolStackTop->symbolTablePtr; //the hashtable with the Symbol Entries
			   	$<nodePtr>$->nLinenumber = yylineno;			   	//set the line number
			   }
		Statements { $<nodePtr>2->children[0] = $3; } // should point to first statement. The others will be its siblings
		TOK_RBRACE { 
				leaveScope(); //Statements will be parsed and the actions executed, then the scope ends.
				$$ = $<nodePtr>2; //set $$ to the second node.
			   }
						 
              | TOK_LBRACE {  
				enterScope(); //same as the previous, only we have Local_Declarations also this time. Local_Declarations will be parsed and its actions executed. 
				$<nodePtr>$ =  new_StmtNode(COMPOUND_STMT); //This seems like a bottom-up parser (?)
				$<nodePtr>$->nSymbolTabPtr = symbolStackTop->symbolTablePtr;
			   	$<nodePtr>$->nLinenumber = yylineno;			   	
			   }
                Local_Declarations Statements { $<nodePtr>2->children[0] = $4;} // should point to first statement
                TOK_RBRACE { 
                		leaveScope();
                		$$ = $<nodePtr>2;
                	   }
;

Compound_Stmt_Function : TOK_LBRACE {  
				$<nodePtr>$ =  new_StmtNode(COMPOUND_STMT);//mid-rule action. Create a new StmtNode of kind Compund_Stmt. 
				$<nodePtr>$->nSymbolTabPtr = symbolStackTop->symbolTablePtr; //the hashtable with the Symbol Entries
			   	$<nodePtr>$->nLinenumber = yylineno;			   	//set the line number
			   }
		Statements { $<nodePtr>2->children[0] = $3; } // should point to first statement. The others will be its siblings
		TOK_RBRACE { 
				leaveScope(); //Statements will be parsed and the actions executed, then the scope ends.
				$$ = $<nodePtr>2; //set $$ to the second node.
			   }
						 
              | TOK_LBRACE {  
				$<nodePtr>$ =  new_StmtNode(COMPOUND_STMT); 
				$<nodePtr>$->nSymbolTabPtr = symbolStackTop->symbolTablePtr;
			   	$<nodePtr>$->nLinenumber = yylineno;			   	
			   }
                Local_Declarations Statements { $<nodePtr>2->children[0] = $4;} // should point to first statement
                TOK_RBRACE { 
                		leaveScope();
                		$$ = $<nodePtr>2;
                	   }
;

Local_Declarations : Var_Declaration Local_Declarations {} //Var_Declaration takes care of inserting in symbol table, nothing to do here
		   | Var_Declaration {}
;

Statements : Statement Statements {
				     $1->sibling = $2; //for every statement, set its sibling to the rest of the statements
				     $$ = $1;				    
				  } | TOK_SEMI {$$=NULL;}
	   | {$$=NULL;}		//when no more statements this is null
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
		$$ =  new_ExprNode(VAR_EXP); //create a new ExprNode to represent the variable
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
       | Var { $$ = $1; }
       | Call { $$ = $1; }
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
 					 	$$->fname = strdup($1);
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
    print_Ast();
#endif
    
} 

