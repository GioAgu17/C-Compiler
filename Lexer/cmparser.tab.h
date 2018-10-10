#ifndef BISON_CMPARSER_TAB_H
# define BISON_CMPARSER_TAB_H

# ifndef YYSTYPE
#  define YYSTYPE int
#  define YYSTYPE_IS_TRIVIAL 1
# endif
# define	TOK_ELSE	257
# define	TOK_IF	258
# define	TOK_RETURN	259
# define	TOK_VOID	260
# define	TOK_INT	261
# define	TOK_WHILE	262
# define	TOK_ID	263
# define	TOK_NUM	264
# define	TOK_PLUS	265
# define	TOK_MINUS	266
# define	TOK_MULT	267
# define	TOK_DIV	268
# define	TOK_LT	269
# define	TOK_LE	270
# define	TOK_GT	271
# define	TOK_GE	272
# define	TOK_EQ	273
# define	TOK_NE	274
# define	TOK_ASSIGN	275
# define	TOK_SEMI	276
# define	TOK_COMMA	277
# define	TOK_LPAREN	278
# define	TOK_RPAREN	279
# define	TOK_LSQ	280
# define	TOK_RSQ	281
# define	TOK_LBRACE	282
# define	TOK_RBRACE	283
# define	TOK_ERROR	284


extern YYSTYPE yylval;

#endif /* not BISON_CMPARSER_TAB_H */
