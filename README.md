# C--Compiler
A compiler for a subset of C using Yacc/Bison for compiling C-- code. 
## Introduction
This compiler is divided into six folders. There is the lexer, which
tokenizes some values of the input code. Then there is a symbol table, which
has been implemented with C pointers in order to model the encapsulation of
scopes. Thirdly the parser, in which there are the grammar rules to be checked.
After the parser there is the AST, i.e. Abstract Syntax Tree, which creates 
a useful data structure for other types of check. Then there is a simple
type checker for providing type safety to the compiler. Finally, we have the
code generation part which takes as input the source code and translates it
into assembly. 
## Installation and test
Every folder of the project has its own tests that can be used on the given 
part of the compiler. As you go further you will find repeated files, this 
is done in order for you to test each part separately using the previous part. 
I recommend using the order provided in the introduction, as it is the
natural order of a compiler. Each folder has also a Makefile in order to 
compile the given code. I do recommend doing this on Linux environment as it
is not checked on Mac or Windows systems. 
## C-- Grammar
In this section I will briefly explain the C-- grammar. Please report any
bugs, ambiguities, or other problems with this document to me. 
### Notation
The terminal symbols used in this description of the C- grammar are: 

| Category                 | Symbols         |
|--------------------------|-----------------|
| Identifiers              | identifier      |
| Literals                 | integer-literal |
| Keywords                 | if while else   |
| Primitive Types          | int void        |
| Punctuation              | ( ) { } [ ] ; , |
| Relational Operators     | <= >= == ...    |
| Additive Operators       | + ,  -          |
| Multiplicative Operators | * ,  -          |

All other symbols appearing in typewriter font are terminal symbols and 
the corresponding TOKEN DEFINITION from Lexer must be used. 
(E.g., for the symbol ";", TOK SEMI must be used). Consult your 
cmparser.tab.h from Lexer project for Token deﬁnitions.

In addition to these nonterminals, the following notation is used:  
"Start" is a non-terminal symbol (the first letter is capitalized)  
"ε" represents the empty string  
"X*" represents zero or more occurences of "X"  
"X+" represents one or more occurences of "X"  
"X?" represents one or zero occurences of "X"  
"X -> Y" represents a production  
"X -> Y | Z" is shorthand for "X -> Y" or "X -> Z"  
### C-Grammar production
1. Start -> Declarations
2. Declarations -> Var-declaration* Fun-declaration+
3. Var-declaration -> Type-specifier identifier ;
4. Arr-declaration -> Type-specifier identifier [ integer-literal ] ;
5. Type-specifier -> int | void
6. Fun-declaration -> Type-specifier identifier ( Params ) Compound-stmt
7. Params -> Param-list | void
8. Param-list -> Param-list, Param | Param
9. Param -> Type-specifier identifier | Type-specifier identifier []
10. Compount-stmt -> { Local-declaration* Statement* }
11. Local-declaration -> Var-declaration
12. Statement -> Expression-stmt | Compound-stmt | | Selection-stmt
13. Statement -> Iteration-stmt | Return-stmt
14. Expression-stmt -> Expression ; | ;
15. Selection-stmt -> if ( Expression ) Statement 
16. Selection-stmt -> if ( Expression ) Statement else Statement
17. Iteration-stmt -> while ( Expression ) Statement
18. Return-stmt -> return Expression-stmt ;
19. Expression -> Var = Expression | Simple-expression
21. Simple-expression -> Additive-expression Rel-op Additive-expression | Additive-expression
22. Rel-op -> relational-operator
23. Additive-expression -> Additive-expression Add-op Term | Term
24. Add-op -> additive-operator
25. Term -> Term Mult-op Factor | Factor
26. Mult-op -> multiplicative operator
27. Factor -> ( Expression ) | Var | Call | integer-literal
28. Call -> identifier ( Args )
29. Args -> Args-list | ε
30. Args-list -> Args-list, Expression | Expression
### Dangling else
In C-, the else keyword always binds to the most recent if. Hence, 
"if C1 if C2 S1 else S2" is equivalent to "if C1 { if C2 S1 else S2 }".
### Operator Precedence
The C-operators precedence is given by the following table (1 is the 
highest precedence, 7 lowest):

| Operator | Precedence | Associativity   |
|----------|------------|-----------------|
| *        | 1          | Left            |
| /        | 1          | Left            |
| +        | 2          | Left            |
| -        | 2          | Left            |
| <        | 3          | Not Associative |
| >        | 3          | Not Associative |
| <=       | 3          | Not Associative |
| >=       | 3          | Not Associative |
| ==       | 4          | Left            |
| !=       | 4          | Left            |
| =        | 7          | Right           |

If you notice, precedence has already been taken care of by the grammar rules (look
at rules for the nonterminal Factor and Term). Associativity can be easily speciﬁed 
in yacc using the commands %left, %right and %nonassoc.


