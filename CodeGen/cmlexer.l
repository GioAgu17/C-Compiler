
/**********************/
/* C header files */
/**********************/

%{
#include "globals.h"
#include "ast.h"
#include "cmparser.tab.h"
char tokenString[TOKENMAX];
int printoutScan = 0;

%}

%option yylineno

/**********************/
/* start your regular definitions  here */
/**********************/

NUMBER		[0-9]+
IDENTIFIER	[a-zA-Z_$][a-zA-Z_$0-9]*
WHITESPACE	[ \t\r\n]+


/* start your token specifications here */
/* Token names must come from cmparser.tab.h */

%%

auto { return TOK_ERROR; }
continue { return TOK_ERROR; }
goto { return TOK_ERROR; }
break { return TOK_ERROR; }
default { return TOK_ERROR; }
long { return TOK_ERROR; }
case { return TOK_ERROR; }
do { return TOK_ERROR; }
short { return TOK_ERROR; }
char { return TOK_ERROR; }
double { return TOK_ERROR; }
register { return TOK_ERROR; }
const { return TOK_ERROR; }
for { return TOK_ERROR; }
switch { return TOK_ERROR; }
byte { return TOK_ERROR; }
float { return TOK_ERROR; }
"~" { return TOK_ERROR; }
"&" { return TOK_ERROR; }
"+=" { return TOK_ERROR; }
"^=" { return TOK_ERROR; }
"?" { return TOK_ERROR; }
"|" { return TOK_ERROR; }
"-=" { return TOK_ERROR; }
"%=" { return TOK_ERROR; }
":" { return TOK_ERROR; }
"^" { return TOK_ERROR; }
"*=" { return TOK_ERROR; }
"<<=" { return TOK_ERROR; }
"++" { return TOK_ERROR; }
"<<" { return TOK_ERROR; }
"/=" { return TOK_ERROR; }
">>=" { return TOK_ERROR; }
"--" { return TOK_ERROR; }
">>" { return TOK_ERROR; }
"&=" { return TOK_ERROR; }
">>>=" { return TOK_ERROR; }
"!" { return TOK_ERROR; }
">>>" { return TOK_ERROR; }
"|=" { return TOK_ERROR; }
else { return TOK_ELSE; }
if { return TOK_IF; }
return { return TOK_RETURN; }
void { return TOK_VOID; }
int { return TOK_INT; }
while { return TOK_WHILE; }
"+" { return TOK_PLUS; }
"-" { return TOK_MINUS; }
"*" { return TOK_MULT; }
"/" { return TOK_DIV; }
"<" { return TOK_LT; }
"<=" { return TOK_LE; }
">" { return TOK_GT; }
">=" { return TOK_GE; }
"==" { return TOK_EQ; }
"!=" { return TOK_NE; }
"=" { return TOK_ASSIGN; }
";" { return TOK_SEMI; }
"," { return TOK_COMMA; }
"(" { return TOK_LPAREN; }
")" { return TOK_RPAREN; }
"[" { return TOK_LSQ; }
"]" { return TOK_RSQ; }
"{" { return TOK_LBRACE; }
"}" { return TOK_RBRACE; }
{NUMBER} {  yylval.iVal = atoi(yytext); return TOK_NUM; }
{IDENTIFIER} {yylval.cVal = strdup(yytext); return TOK_ID; }
{WHITESPACE} {  }
"//".* { }
"/*"([^*]|\*+[^*/])*("*"+)("/") {}
. { return TOK_ERROR; }


%%
/**********************/
/* C support functions */
/**********************/

void printToken(int token, char *str)
{
/* Print the line number, token name and matched lexeme
   -- one per line without any additional characters exactly as below */ 
/* Example  13:TOK_INT: 37*/

    switch(token)
        {
            case TOK_ELSE:
                fprintf(yyout,"%d : TOK_ELSE : %s\n",yylineno,str);
                break;
            case TOK_IF:
                fprintf(yyout,"%d : TOK_IF : %s\n",yylineno,str);
                break;
       	    case TOK_RETURN:
                fprintf(yyout,"%d : TOK_RETURN : %s\n",yylineno,str);
                break;
            case TOK_VOID:
	        fprintf(yyout,"%d : TOK_VOID : %s\n",yylineno,str);
                break;
            case TOK_INT:
                fprintf(yyout,"%d : TOK_INT : %s\n",yylineno,str);
                break;
            case TOK_WHILE:
		fprintf(yyout,"%d : TOK_WHILE : %s\n",yylineno,str);
                break;
            case TOK_ID:
		fprintf(yyout,"%d : TOK_ID : %s\n",yylineno,str);
                break;
            case TOK_NUM:
		fprintf(yyout,"%d : TOK_NUM : %s\n",yylineno,str);
                break;
            case TOK_PLUS:
		fprintf(yyout,"%d : TOK_PLUS : %s\n",yylineno,str);
                break;
            case TOK_MINUS:
		fprintf(yyout,"%d : TOK_MINUS : %s\n",yylineno,str);
                break;
            case TOK_MULT:
		fprintf(yyout,"%d : TOK_MULT : %s\n",yylineno,str);
                break;
            case TOK_DIV:
		fprintf(yyout,"%d : TOK_DIV : %s\n",yylineno,str);
                break;
            case TOK_LT:
		fprintf(yyout,"%d : TOK_LT : %s\n",yylineno,str);
                break;
            case TOK_LE:
		fprintf(yyout,"%d : TOK_LE : %s\n",yylineno,str);
                break;
            case TOK_GT:
		fprintf(yyout,"%d : TOK_GT : %s\n",yylineno,str);
                break;
            case TOK_GE:
		fprintf(yyout,"%d : TOK_GE : %s\n",yylineno,str);
                break;
            case TOK_EQ:
		fprintf(yyout,"%d : TOK_EQ : %s\n",yylineno,str);
                break;
            case TOK_NE:
	        fprintf(yyout,"%d : TOK_NE : %s\n",yylineno,str);
                break;
            case TOK_ASSIGN:
	        fprintf(yyout,"%d : TOK_ASSIGN : %s\n",yylineno,str);
                break;
            case TOK_SEMI:
	        fprintf(yyout,"%d : TOK_SEMI : %s\n",yylineno,str);
                break;
            case TOK_COMMA:
	        fprintf(yyout,"%d : TOK_COMMA : %s\n",yylineno,str);
                break;
            case TOK_LPAREN:
	        fprintf(yyout,"%d : TOK_LPAREN : %s\n",yylineno,str);
                break;
            case TOK_RPAREN:
	        fprintf(yyout,"%d : TOK_RPAREN : %s\n",yylineno,str);
                break;
            case TOK_LSQ:
	        fprintf(yyout,"%d : TOK_LSQ : %s\n",yylineno,str);
                break;
            case TOK_RSQ:
	        fprintf(yyout,"%d : TOK_RSQ : %s\n",yylineno,str);
                break;
            case TOK_LBRACE:
	        fprintf(yyout,"%d : TOK_LBRACE : %s\n",yylineno,str);
                break;
            case TOK_RBRACE:
	    	fprintf(yyout,"%d : TOK_RBRACE : %s\n",yylineno,str);
                break;
            case TOK_ERROR:
                fprintf(yyout,"%d : TOK_ERROR : %s\n",yylineno,str);
                break;
        }
}


int gettok(void){
    int currentToken;
    
    currentToken=yylex();
    if (currentToken == 0) { // means EOF}
            return 0;
    }
    strncpy(tokenString, yytext, TOKENMAX);
    if (printoutScan) {
        printToken(currentToken,tokenString);
    }
    return currentToken;
}


int initLex(int argc, char **argv){

    
   if ( argc > 1 )
       yyin = fopen( argv[1], "r" );
   else
    yyin = stdin;

    return 1;
} 
