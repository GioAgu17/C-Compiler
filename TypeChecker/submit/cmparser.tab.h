/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_CMPARSER_TAB_H_INCLUDED
# define YY_YY_CMPARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_ELSE = 258,
    TOK_IF = 259,
    TOK_RETURN = 260,
    TOK_VOID = 261,
    TOK_INT = 262,
    TOK_WHILE = 263,
    TOK_PLUS = 264,
    TOK_MINUS = 265,
    TOK_MULT = 266,
    TOK_DIV = 267,
    TOK_LT = 268,
    TOK_LE = 269,
    TOK_GT = 270,
    TOK_GE = 271,
    TOK_EQ = 272,
    TOK_NE = 273,
    TOK_ASSIGN = 274,
    TOK_SEMI = 275,
    TOK_COMMA = 276,
    TOK_LPAREN = 277,
    TOK_RPAREN = 278,
    TOK_LSQ = 279,
    TOK_RSQ = 280,
    TOK_LBRACE = 281,
    TOK_RBRACE = 282,
    TOK_ERROR = 283,
    TOK_ID = 284,
    TOK_NUM = 285,
    TOK_SUB = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 35 "cmparser.y" /* yacc.c:1909  */

    AstNodePtr nodePtr;
    int        iVal;
    char      *cVal;
    Type      *type;

#line 93 "cmparser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CMPARSER_TAB_H_INCLUDED  */
