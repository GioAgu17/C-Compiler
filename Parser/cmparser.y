%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define YYERROR_VERBOSE 1
/* external function prototypes */
extern int yylex();
extern int initLex(int ,  char **);
 
    

/* external global variables */

extern int		yydebug;
extern int		yylineno;


/* function prototypes */ 
void	yyerror(const char *);

/* global variables */

%}

/* YYSTYPE */

/* terminals */
/* Adding token names here */
/* The file cmparser.tab.h gets generated here */

%token TOK_ELSE
%token TOK_IF
%token TOK_RETURN
%token TOK_VOID
%token TOK_INT
%token TOK_WHILE
%token TOK_ID
%token TOK_NUM
%token TOK_PLUS
%token TOK_MINUS
%token TOK_MULT
%token TOK_DIV
%token TOK_LT
%token TOK_LE
%token TOK_GT
%token TOK_GE
%token TOK_EQ
%token TOK_NE
%token TOK_ASSIGN
%token TOK_SEMI
%token TOK_COMMA
%token TOK_LPAREN
%token TOK_RPAREN
%token TOK_LSQ
%token TOK_RSQ
%token TOK_LBRACE
%token TOK_RBRACE
%token TOK_ERROR 

/* associativity and precedence */


%left TOK_MULT 
%left TOK_DIV
%left TOK_PLUS
%left TOK_MINUS
%left TOK_EQ
%left TOK_NE

%right TOK_ASSIGN 

%nonassoc TOK_LT
%nonassoc TOK_GT
%nonassoc TOK_LE
%nonassoc TOK_GE
%nonassoc error

/* grammar specification begins here here */
%%


Start	: Declarations ;

Declarations : Var_declarationStar Fun_declaration Fun_declarationStar ;

Fun_declaration : Type_specifier TOK_ID TOK_LPAREN Params TOK_RPAREN Compound_stmt ;

Fun_declarationStar : Fun_declarationStar Fun_declaration 
		    | /* empty */
		    ;
 

Var_declarationStar : Var_declarationStar Var_declaration 
		    | /* empty */
		    ;

Var_declaration :  Type_specifier TOK_ID Array_declaration TOK_SEMI;

Array_declaration :  TOK_LSQ TOK_NUM TOK_RSQ 
		  | /*empty*/
		  ;


Compound_stmt : TOK_LBRACE Local_declarationStar StatementStar TOK_RBRACE ;	


Params : Param_list
       | TOK_VOID
       ;

Param_list : Param_list TOK_COMMA Param
	   | Param
	   ;

Param : Type_specifier TOK_ID Squares ;

Squares : TOK_LSQ TOK_RSQ 
	| /* empty */
	;



Type_specifier : TOK_INT
	       | TOK_VOID
	       ; 


Local_declarationStar : Local_declarationStar Local_declaration
		      | /* empty */
		      ;

Local_declaration : Var_declaration ;

StatementStar : StatementStar Statement
	      | /*empty*/
	      ;


Statement : Expression_stmt
	  | Compound_stmt
	  | /*empty*/
	  | Selection_stmt
	  ;

Statement : Iteration_stmt
	  | Return_stmt
	  ;

Expression_stmt : Expression TOK_SEMI
		| TOK_SEMI
		;

Expression : Var TOK_ASSIGN Expression
	   | Simple_expression
	   ;


Selection_stmt : TOK_IF TOK_LPAREN Expression TOK_RPAREN Statement ;

Selection_stmt : TOK_IF TOK_LPAREN Expression TOK_RPAREN Statement TOK_ELSE Statement ;
 
Iteration_stmt : TOK_WHILE TOK_LPAREN Expression TOK_RPAREN Statement ;

Return_stmt : TOK_RETURN Expression_stmt ;

Simple_expression : Additive_expression Rel_op Additive_expression
		  | Additive_expression
		  ;

Additive_expression : Additive_expression Add_op Term
		    | Term
		    ;

Var : TOK_ID
    | TOK_ID TOK_LSQ Expression TOK_RSQ
    ;

Rel_op : TOK_GT
       | TOK_GE
       | TOK_LT
       | TOK_LE
       | TOK_NE
       | TOK_EQ
       ;

Add_op : TOK_PLUS
       | TOK_MINUS
       ;

Term : Term Mult_op Factor
     | Factor
     ;

Factor : TOK_LPAREN Expression TOK_RPAREN
       | Var
       | Call
       | TOK_NUM
       ;

Call : TOK_ID TOK_LPAREN Args TOK_RPAREN ;

Args : Args_list
     | /* empty */
     ;

Args_list : Args_list TOK_COMMA Expression
	  | Expression
	  ;

Mult_op : TOK_MULT
	| TOK_DIV
	;



//Selection_stmt : TOK_IF

%%
void yyerror (char const *s) {
       fprintf (stderr, "Line %d: %s\n", yylineno, s);
	// printError(s);
}
/* function to generate error messages */
void printError(char *errorstring){
}
int main(int argc, char **argv){

	initLex(argc,argv);

#ifdef YYLLEXER
   while (gettok() !=0) ; //gettok returns 0 on EOF
    return;
#else
    yyparse();
    
#endif
    
} 
