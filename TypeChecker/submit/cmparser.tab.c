/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "cmparser.y" /* yacc.c:339  */


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


#line 98 "cmparser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "cmparser.tab.h".  */
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
#line 35 "cmparser.y" /* yacc.c:355  */

    AstNodePtr nodePtr;
    int        iVal;
    char      *cVal;
    Type      *type;

#line 177 "cmparser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CMPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 194 "cmparser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    77,    78,    81,    82,    88,   103,   123,
     144,   123,   159,   160,   163,   172,   178,   199,   223,   226,
     231,   237,   231,   243,   249,   243,   279,   280,   283,   286,
     287,   290,   293,   296,   297,   300,   303,   308,   315,   318,
     324,   324,   335,   335,   347,   352,   359,   359,   370,   375,
     386,   401,   401,   410,   410,   419,   419,   429,   429,   439,
     439,   449,   449,   458,   461,   461,   471,   471,   481,   486,
     486,   496,   496,   505,   510,   511,   512,   513,   520,   535,
     536,   539,   548
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_ELSE", "TOK_IF", "TOK_RETURN",
  "TOK_VOID", "TOK_INT", "TOK_WHILE", "TOK_PLUS", "TOK_MINUS", "TOK_MULT",
  "TOK_DIV", "TOK_LT", "TOK_LE", "TOK_GT", "TOK_GE", "TOK_EQ", "TOK_NE",
  "TOK_ASSIGN", "TOK_SEMI", "TOK_COMMA", "TOK_LPAREN", "TOK_RPAREN",
  "TOK_LSQ", "TOK_RSQ", "TOK_LBRACE", "TOK_RBRACE", "TOK_ERROR", "TOK_ID",
  "TOK_NUM", "TOK_SUB", "$accept", "Start", "Declarations", "Functions",
  "Var_Declaration", "Fun_Declaration", "@1", "$@2", "Params",
  "Param_List", "Param", "Type_Specifier", "Compound_Stmt", "@3", "$@4",
  "@5", "$@6", "Local_Declarations", "Statements", "Statement",
  "Expr_Statement", "Selection_Stmt", "If_Else_Statement", "@11",
  "Iteration_Stmt", "@12", "Return_Stmt", "Expression", "@13", "Var",
  "Simple_Expression", "@14", "@15", "@16", "@17", "@18", "@19",
  "Additive_Expression", "@20", "@21", "Term", "@22", "@23", "Factor",
  "Call", "Args", "Args_List", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

#define YYPACT_NINF -72

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-72)))

#define YYTABLE_NINF -30

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      19,   -72,   -72,    20,   -72,   -72,    19,    19,    23,   -72,
     -72,   -72,    33,    14,    -8,   -72,   -72,    -7,    36,    39,
      40,    21,    47,   -72,    43,    53,   -72,    19,    50,   -72,
      62,   -72,    64,    44,   -72,   -72,    11,    19,    80,   -12,
      81,    78,   -18,   -15,   -72,   -72,   -72,    11,   -72,   -72,
     101,   -72,   -72,    86,    88,   -72,    77,    42,   -72,   -72,
      19,    79,    11,   -18,   -72,    89,   -18,    87,   -18,   -18,
      84,   -72,    41,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,    15,   -72,   -72,   -72,
     -72,   -72,   -72,    90,    91,    92,   -72,   -72,   -72,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
      93,    95,    96,   -72,   -18,   -72,   -72,   -72,    42,    42,
      38,    38,    38,    38,    38,    38,   -72,   -72,   -72,    41,
      41,   -72,   -72,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    19,    18,     0,     2,     3,     0,     5,     0,     1,
       4,     6,     0,     0,     0,     7,     9,     0,     0,     0,
      13,     0,    12,    15,     0,     0,    10,     0,    16,     8,
       0,    14,     0,    20,    11,    17,    30,     0,     0,     0,
       0,    37,     0,    49,    77,    32,    21,    30,    31,    33,
      38,    34,    35,     0,    75,    48,    63,    68,    73,    76,
      27,     0,    30,     0,    45,     0,     0,     0,    80,     0,
       0,    28,     0,    36,    46,    64,    66,    53,    57,    51,
      55,    59,    61,    69,    71,    26,     0,    24,    40,    44,
      42,    74,    82,     0,    79,     0,    22,    37,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,    50,    47,    75,    65,    67,
      54,    58,    52,    56,    60,    62,    70,    72,    25,     0,
       0,    81,    41,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,   108,   109,   -32,   -72,   -72,   -72,   -72,   -72,
      94,    -5,    85,   -72,   -72,   -72,   -72,    63,   -41,   -71,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -39,   -72,   -24,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,    -6,   -72,   -72,
     -44,   -72,   -72,   -43,   -72,   -72,   -72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,    18,    30,    21,    22,
      23,     8,    45,    36,    70,    37,   110,    62,    46,    47,
      48,    49,    50,   111,    51,   112,    52,    53,    99,    54,
      55,   104,   102,   105,   103,   106,   107,    56,   100,   101,
      57,   108,   109,    58,    59,    93,    94
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    98,    12,    67,    42,    60,    71,    68,    64,    69,
      42,    43,    44,    24,    16,    38,    39,    43,    44,    40,
       9,    87,    24,    19,    88,     1,     2,    90,    60,    92,
      95,    41,    61,    42,    15,    15,    16,    33,    17,    17,
      43,    44,    20,     2,    26,    38,    39,    75,    76,    40,
     -23,   -23,    13,    83,    84,    61,   118,   119,   132,   133,
     116,    97,    14,    42,    25,   126,   127,    33,    27,   -19,
      43,    44,    28,    29,    32,   131,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,    75,    76,    33,    35,
      77,    78,    79,    80,    81,    82,   120,   121,   122,   123,
     124,   125,    63,    66,    72,   -29,    73,    74,    86,    89,
      91,    96,   114,   113,    10,    34,    11,   115,   129,   130,
     128,    31,     0,    85
};

static const yytype_int16 yycheck[] =
{
      39,    72,     7,    42,    22,    37,    47,    22,    20,    24,
      22,    29,    30,    18,    22,     4,     5,    29,    30,     8,
       0,    62,    27,    30,    63,     6,     7,    66,    60,    68,
      69,    20,    37,    22,    20,    20,    22,    26,    24,    24,
      29,    30,     6,     7,    23,     4,     5,     9,    10,     8,
       6,     7,    29,    11,    12,    60,   100,   101,   129,   130,
      99,    20,    29,    22,    25,   108,   109,    26,    21,    29,
      29,    30,    29,    20,    24,   114,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     9,    10,    26,    25,
      13,    14,    15,    16,    17,    18,   102,   103,   104,   105,
     106,   107,    22,    22,     3,    27,    20,    19,    29,    20,
      23,    27,    21,    23,     6,    30,     7,    25,    23,    23,
      27,    27,    -1,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    33,    34,    35,    36,    37,    43,     0,
      34,    35,    43,    29,    29,    20,    22,    24,    38,    30,
       6,    40,    41,    42,    43,    25,    23,    21,    29,    20,
      39,    42,    24,    26,    44,    25,    45,    47,     4,     5,
       8,    20,    22,    29,    30,    44,    50,    51,    52,    53,
      54,    56,    58,    59,    61,    62,    69,    72,    75,    76,
      36,    43,    49,    22,    20,    59,    22,    59,    22,    24,
      46,    50,     3,    20,    19,     9,    10,    13,    14,    15,
      16,    17,    18,    11,    12,    49,    29,    50,    59,    20,
      59,    23,    59,    77,    78,    59,    27,    20,    51,    60,
      70,    71,    64,    66,    63,    65,    67,    68,    73,    74,
      48,    55,    57,    23,    21,    25,    59,    61,    72,    72,
      69,    69,    69,    69,    69,    69,    75,    75,    27,    23,
      23,    59,    51,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    38,
      39,    37,    40,    40,    41,    41,    42,    42,    43,    43,
      45,    46,    44,    47,    48,    44,    49,    49,    50,    50,
      50,    51,    51,    51,    51,    51,    52,    52,    53,    53,
      55,    54,    57,    56,    58,    58,    60,    59,    59,    61,
      61,    63,    62,    64,    62,    65,    62,    66,    62,    67,
      62,    68,    62,    62,    70,    69,    71,    69,    69,    73,
      72,    74,    72,    72,    75,    75,    75,    75,    76,    77,
      77,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     3,     6,     0,
       0,     8,     1,     1,     3,     1,     2,     4,     1,     1,
       0,     0,     5,     0,     0,     6,     2,     1,     2,     1,
       0,     1,     1,     1,     1,     1,     2,     1,     1,     3,
       0,     6,     0,     6,     3,     2,     0,     4,     1,     1,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     1,     0,     4,     0,     4,     1,     0,
       4,     0,     4,     1,     3,     1,     1,     1,     4,     1,
       0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 74 "cmparser.y" /* yacc.c:1646  */
    {}
#line 1372 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 77 "cmparser.y" /* yacc.c:1646  */
    { program = (yyvsp[0].nodePtr);}
#line 1378 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 78 "cmparser.y" /* yacc.c:1646  */
    { }
#line 1384 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 81 "cmparser.y" /* yacc.c:1646  */
    { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1390 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 82 "cmparser.y" /* yacc.c:1646  */
    { 
	     				   (yyvsp[-1].nodePtr)->sibling = (yyvsp[0].nodePtr);
	     				   (yyval.nodePtr) = (yyvsp[-1].nodePtr) ;	
           				}
#line 1399 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 88 "cmparser.y" /* yacc.c:1646  */
    {	
                            if ((yyvsp[-2].type)->kind != INT){	//C-- deals only with integers
							    yyerror("non-int variable declared\n");
	     					    yyerror((yyvsp[-1].cVal));	
						    }	
							ElementPtr symElement = symLookup((yyvsp[-1].cVal)); 
							if(!symElement || scopeDepth != symElement->scope) 
								symInsert((yyvsp[-1].cVal),(yyvsp[-2].type),yylineno);		
							else 
	     						{
	     							yyerror("Redeclaration of variable"); 
	     							yyerror((yyvsp[-1].cVal));
	     							free((yyvsp[-2].type));	
	     						}
	     					}
#line 1419 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 103 "cmparser.y" /* yacc.c:1646  */
    { 
                            if ((yyvsp[-5].type)->kind != INT){ //C-- should have only integer types
                   			    yyerror("non-int variable declared\n");
	     					    yyerror((yyvsp[-4].cVal));
					   		}	
							ElementPtr symElement = symLookup((yyvsp[-4].cVal)); //look up identifier in symbol table
							if(!symElement || scopeDepth != symElement->scope) {	/* reuse Type for storing dimension */
								(yyvsp[-5].type)->kind = ARRAY; 
      							(yyvsp[-5].type)->dimension = (yyvsp[-2].iVal); 
      							(yyvsp[-5].type)->function = NULL; 
 								symInsert((yyvsp[-4].cVal),(yyvsp[-5].type),yylineno); //insert it in symbol table
      						}
      						else {
      							yyerror("Redeclaration of variable");
	     						yyerror((yyvsp[-4].cVal));
      							free((yyvsp[-5].type));
      						} 	
      			}
#line 1442 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 123 "cmparser.y" /* yacc.c:1646  */
    {	
						(yyval.nodePtr) =  new_Node(METHOD); 	 //Mid-rule action. It counts as a component of the rule. It has not
						(yyval.nodePtr)->nLinenumber = yylineno; //been defined in the token and non-terminal declarations, so its type is set using 
															 //the $<...>$ syntax. $<nodePtr>$ means that the datatype of the value
						(yyval.nodePtr)->nType = (yyvsp[-2].type);	     	 //represented by this component is nodePtr 
						ElementPtr symElement = symLookup((yyvsp[-1].cVal)); //the identifier is looked up to see if it exists. If it does not exist,
						if(!symElement || scopeDepth != symElement->scope) { 
								 //or if it has been declared in a previous scope 
							(yyval.nodePtr)->nSymbolPtr = symInsert((yyvsp[-1].cVal),(yyvsp[-2].type),yylineno);//insert it in the symbol table, set the nSymbolPtr
	 						(yyval.nodePtr)->nSymbolPtr->stype->function = (Type*) malloc(sizeof(Type)); //allocate the type for the function
	 						(yyval.nodePtr)->nSymbolPtr->stype->function->kind = (yyvsp[-2].type)->kind; 	//set the kind of the function, i.e. its return type
	 						(yyval.nodePtr)->nSymbolPtr->snode = (yyval.nodePtr); 			 //nSymbolPtr->snode must point to the AST node itself
							(yyvsp[-2].type)->kind = FUNCTION; 								//$1->kind is a function.
	 						enterScope(); 										//create a new scope for the function 
						}	
						else {	
   	  						yyerror("Redeclaration of function");
							yyerror((yyvsp[-1].cVal));
   	  						free((yyvsp[-2].type));
   						}  
				}
#line 1468 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "cmparser.y" /* yacc.c:1646  */
    {
					(yyvsp[-2].nodePtr)->children[0] = (yyvsp[-1].nodePtr); 	//refer to the previous semantic action node with $<nodePtr>4, 
					(yyvsp[-2].nodePtr)->children[0] = (yyvsp[-1].nodePtr); //refer to the previous semantic action node with $<nodePtr>4, 
					
													//since it is the fourth component of the rule
				}
#line 1479 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 150 "cmparser.y" /* yacc.c:1646  */
    {
							
				       			(yyvsp[-4].nodePtr)->children[1] = (yyvsp[0].nodePtr); 	//Compound Statement. According to the handout, the children[1] should be set to Compund_Stmt.
				       			(yyval.nodePtr) = (yyvsp[-4].nodePtr); //this is the last action, $$, i.e. Fun_Declaration is set to the node created in the first semantic action, which represents
							leaveScope();
				 		   }
#line 1490 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 159 "cmparser.y" /* yacc.c:1646  */
    {(yyval.nodePtr) = (yyvsp[0].nodePtr);}
#line 1496 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 160 "cmparser.y" /* yacc.c:1646  */
    {(yyval.nodePtr)=NULL;}
#line 1502 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 163 "cmparser.y" /* yacc.c:1646  */
    { 
						(yyval.nodePtr) = (yyvsp[-2].nodePtr); //this is a paramter list appearing in a function declaration. Mid-rule action. Set its value to $1. 
						while((yyval.nodePtr)->sibling){	//go to the end of the list of siblings
							(yyval.nodePtr) = (yyval.nodePtr)->sibling; 
						}
						(yyval.nodePtr)->sibling = (yyvsp[0].nodePtr); //set the sibling to $3, that is to the next Param in input. This whole list (current $3 included) will represent Param_List
						(yyvsp[0].nodePtr)->sibling = NULL;	   //so far if there are even more params in input, ie. as long as this rule keeps matching.
						(yyval.nodePtr) = (yyvsp[-2].nodePtr);
					}
#line 1516 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 172 "cmparser.y" /* yacc.c:1646  */
    {
	   		(yyvsp[0].nodePtr)->sibling = NULL;	//single parameter. It has no siblings   		
	   		(yyval.nodePtr) = (yyvsp[0].nodePtr);	   		
	   	   }
#line 1525 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 178 "cmparser.y" /* yacc.c:1646  */
    { 	
					ElementPtr symElement = symLookup((yyvsp[0].cVal)); //lookup if it has been declared before
					if(!symElement || scopeDepth != symElement->scope)// if not declared before, or declared in a different scope, it must be inserted in the current (i.e. function) 												  //scope
					{
						(yyval.nodePtr) =  new_Node(FORMALVAR);	//this is a formal variable
						(yyval.nodePtr)->nLinenumber = yylineno;	//set the line number
						if ((yyvsp[-1].type)->kind != INT){		//if it is not INT, C-- error
						  yyerror("non-int variable declared\n");
						}
						else{
						  (yyval.nodePtr)->nSymbolPtr = symInsert((yyvsp[0].cVal),(yyvsp[-1].type),yylineno); //otherwise insert in symbol table, set nSymbolPtr to the entry in the symbol table
						  (yyval.nodePtr)->nType = (yyvsp[-1].type);	//set the type of the whole Param to $1 (i.e. Type_Specifier)
						}
					}	
					else 
	     				{
	     					yyerror("Redeclaration of variable");
	     					yyerror((yyvsp[0].cVal));
	     					free((yyvsp[-1].type));
   					}
	     			}
#line 1551 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 199 "cmparser.y" /* yacc.c:1646  */
    {
      							ElementPtr symElement = symLookup((yyvsp[-2].cVal));
							if(!symElement || scopeDepth != symElement->scope)
							{
							        Type *typ;	
								if ((yyvsp[-3].type)->kind != INT){
									yyerror("non-int array declared\n");
								}
							        typ = new_type(ARRAY);
							        (yyval.nodePtr) =  new_Node(FORMALVAR);
							        (yyval.nodePtr)->nLinenumber = yylineno;
								(yyval.nodePtr)->nSymbolPtr = symInsert((yyvsp[-2].cVal),typ,yylineno);
								(yyval.nodePtr)->nType = typ;
								free((yyvsp[-3].type));
							}	
							else 
			     				{
			     					yyerror("Redeclaration of variable\n");
	     							yyerror((yyvsp[-2].cVal));
			     					free((yyvsp[-3].type));
		   					}
       					        }
#line 1578 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 223 "cmparser.y" /* yacc.c:1646  */
    {
			   (yyval.type) = (Type*) new_type(INT); //creates a new Type INT struct, it is used elsewhere whenever Type_Specifier appears (?)
			 }
#line 1586 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 226 "cmparser.y" /* yacc.c:1646  */
    { 
	       		   (yyval.type) = (Type*) new_type(VOID); //creates a new Type VOID struct
	       		  }
#line 1594 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 231 "cmparser.y" /* yacc.c:1646  */
    {  
				enterScope(); //a compound statement has a different scope from that of the function declaration, as per handout instructions
				(yyval.nodePtr) =  new_StmtNode(COMPOUND_STMT);//mid-rule action. Create a new StmtNode of kind Compund_Stmt. 
				(yyval.nodePtr)->nSymbolTabPtr = symbolStackTop->symbolTablePtr; //the hashtable with the Symbol Entries
			   	(yyval.nodePtr)->nLinenumber = yylineno;			   	//set the line number
			   }
#line 1605 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 237 "cmparser.y" /* yacc.c:1646  */
    { (yyvsp[-1].nodePtr)->children[0] = (yyvsp[0].nodePtr); }
#line 1611 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 238 "cmparser.y" /* yacc.c:1646  */
    { 
				leaveScope(); //Statements will be parsed and the actions executed, then the scope ends.
				(yyval.nodePtr) = (yyvsp[-3].nodePtr); //set $$ to the second node.
			   }
#line 1620 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 243 "cmparser.y" /* yacc.c:1646  */
    {  
				enterScope(); //same as the previous, only we have Local_Declarations also this time. Local_Declarations will be parsed and its actions executed. 
				(yyval.nodePtr) =  new_StmtNode(COMPOUND_STMT); //This seems like a bottom-up parser (?)
				(yyval.nodePtr)->nSymbolTabPtr = symbolStackTop->symbolTablePtr;
			   	(yyval.nodePtr)->nLinenumber = yylineno;			   	
			   }
#line 1631 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 249 "cmparser.y" /* yacc.c:1646  */
    { (yyvsp[-2].nodePtr)->children[0] = (yyvsp[0].nodePtr);}
#line 1637 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 250 "cmparser.y" /* yacc.c:1646  */
    { 
                		leaveScope();
                		(yyval.nodePtr) = (yyvsp[-4].nodePtr);
                	   }
#line 1646 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 279 "cmparser.y" /* yacc.c:1646  */
    {}
#line 1652 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 280 "cmparser.y" /* yacc.c:1646  */
    {}
#line 1658 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 283 "cmparser.y" /* yacc.c:1646  */
    {
				     (yyvsp[-1].nodePtr)->sibling = (yyvsp[0].nodePtr); //for every statement, set its sibling to the rest of the statements
				     (yyval.nodePtr) = (yyvsp[-1].nodePtr);				    
				  }
#line 1667 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 286 "cmparser.y" /* yacc.c:1646  */
    {(yyval.nodePtr)=NULL;}
#line 1673 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 287 "cmparser.y" /* yacc.c:1646  */
    {(yyval.nodePtr)=NULL;}
#line 1679 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 290 "cmparser.y" /* yacc.c:1646  */
    { 
				(yyval.nodePtr) = (yyvsp[0].nodePtr);
			    }
#line 1687 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 293 "cmparser.y" /* yacc.c:1646  */
    {
	  			(yyval.nodePtr) = (yyvsp[0].nodePtr);
	  		  }
#line 1695 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 296 "cmparser.y" /* yacc.c:1646  */
    { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1701 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 297 "cmparser.y" /* yacc.c:1646  */
    {
	  			(yyval.nodePtr) = (yyvsp[0].nodePtr);
	  		   }
#line 1709 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 300 "cmparser.y" /* yacc.c:1646  */
    { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 1715 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 303 "cmparser.y" /* yacc.c:1646  */
    {	
					(yyval.nodePtr) =  new_StmtNode(EXPRESSION_STMT);
					(yyval.nodePtr)->nLinenumber = yylineno;
					(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);  
				     }
#line 1725 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 308 "cmparser.y" /* yacc.c:1646  */
    {
	       			(yyval.nodePtr) =  new_StmtNode(EXPRESSION_STMT) ;
	       			(yyval.nodePtr)->nLinenumber = yylineno;
	       			(yyval.nodePtr)->children[0] = NULL;
	       		  }
#line 1735 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 315 "cmparser.y" /* yacc.c:1646  */
    { 
							(yyval.nodePtr) = (yyvsp[0].nodePtr); 
						}
#line 1743 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 318 "cmparser.y" /* yacc.c:1646  */
    { 
	       						(yyval.nodePtr) = (yyvsp[-2].nodePtr);
	       						(yyval.nodePtr)->children[2]= (yyvsp[0].nodePtr);
	       			   		      }
#line 1752 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 324 "cmparser.y" /* yacc.c:1646  */
    {
							(yyval.nodePtr) =  new_StmtNode(IF_THEN_ELSE_STMT);
							(yyval.nodePtr)->nLinenumber = yylineno;
							(yyval.nodePtr)->children[0] = (yyvsp[0].nodePtr);
						 }
#line 1762 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 329 "cmparser.y" /* yacc.c:1646  */
    { 
				 			(yyvsp[-2].nodePtr)->children[1] = (yyvsp[0].nodePtr);
							(yyval.nodePtr) = (yyvsp[-2].nodePtr);
						      }
#line 1771 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 335 "cmparser.y" /* yacc.c:1646  */
    {
							(yyval.nodePtr) =  new_StmtNode(WHILE_STMT);
							(yyval.nodePtr)->nLinenumber = yylineno;
							(yyval.nodePtr)->children[0] = (yyvsp[0].nodePtr); 							
						 }
#line 1781 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 340 "cmparser.y" /* yacc.c:1646  */
    {
							(yyvsp[-2].nodePtr)->children[1] = (yyvsp[0].nodePtr); 
							(yyval.nodePtr) = (yyvsp[-2].nodePtr);			
							(yyval.nodePtr)->nLinenumber = yylineno;		
				 	       }
#line 1791 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 347 "cmparser.y" /* yacc.c:1646  */
    { 	
						(yyval.nodePtr) =  new_StmtNode(RETURN_STMT);
						(yyval.nodePtr)->nLinenumber = yylineno;
						(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr); 
					     }
#line 1801 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 352 "cmparser.y" /* yacc.c:1646  */
    {
	    				(yyval.nodePtr) =  new_StmtNode(RETURN_STMT);
	    				(yyval.nodePtr)->nLinenumber = yylineno;
					(yyval.nodePtr)->children[0] = NULL; 
	    			  }
#line 1811 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 359 "cmparser.y" /* yacc.c:1646  */
    {
	     			(yyval.nodePtr) =  new_ExprNode(ASSI_EXP);
	     			(yyval.nodePtr)->nLinenumber = yylineno;
	     			(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);	     			
	     		    }
#line 1821 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 364 "cmparser.y" /* yacc.c:1646  */
    {
				
				(yyvsp[-1].nodePtr)->children[1] = (yyvsp[0].nodePtr);
				(yyval.nodePtr) = (yyvsp[-1].nodePtr);						
			}
#line 1831 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 370 "cmparser.y" /* yacc.c:1646  */
    {
            				(yyval.nodePtr) = (yyvsp[0].nodePtr);	
            			}
#line 1839 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 375 "cmparser.y" /* yacc.c:1646  */
    { 
		(yyval.nodePtr) =  new_ExprNode(VAR_EXP); //create a new ExprNode to represent the variable
		(yyval.nodePtr)->nLinenumber = yylineno;  
		(yyval.nodePtr)->nSymbolPtr =  symLookup((yyvsp[0].cVal)); 
		if(!(yyval.nodePtr)->nSymbolPtr)		
		{
			yyerror("Variable must be declared before use");
			yyerror((yyvsp[0].cVal));
			free((yyval.nodePtr));
		}	
	     }
#line 1855 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 386 "cmparser.y" /* yacc.c:1646  */
    {
    					 (yyval.nodePtr) =  new_ExprNode(ARRAY_EXP);
    					 (yyval.nodePtr)->nLinenumber = yylineno;
				  		 (yyval.nodePtr)->nSymbolPtr = symLookup((yyvsp[-3].cVal));
						 if(!(yyval.nodePtr)->nSymbolPtr)
 						 {  	
 						 	yyerror("Variable must be declared before use");
							yyerror((yyvsp[-3].cVal));
	 					 	free((yyval.nodePtr));
 						 }
						 else
						 	(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);			  	
    					 }
#line 1873 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 401 "cmparser.y" /* yacc.c:1646  */
    {
							(yyval.nodePtr) =  new_ExprNode(GT_EXP);
							(yyval.nodePtr)->nLinenumber = yylineno;
	     					(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);	 			
					       }
#line 1883 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 406 "cmparser.y" /* yacc.c:1646  */
    {
							(yyvsp[-1].nodePtr)->children[1] = (yyvsp[0].nodePtr);
							(yyval.nodePtr) = (yyvsp[-1].nodePtr);		
					    }
#line 1892 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 410 "cmparser.y" /* yacc.c:1646  */
    {
                  					(yyval.nodePtr) =  new_ExprNode(LT_EXP);
                  					(yyval.nodePtr)->nLinenumber = yylineno;
	     							(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);	 			
                  			       }
#line 1902 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 415 "cmparser.y" /* yacc.c:1646  */
    {
                  				(yyvsp[-1].nodePtr)->children[1] = (yyvsp[0].nodePtr);
								(yyval.nodePtr) = (yyvsp[-1].nodePtr);		
                  			    }
#line 1911 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 419 "cmparser.y" /* yacc.c:1646  */
    {
                  					(yyval.nodePtr) =  new_ExprNode(GE_EXP);
                  					(yyval.nodePtr)->nLinenumber = yylineno;
	     							(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);	 			
                  			       }
#line 1921 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 424 "cmparser.y" /* yacc.c:1646  */
    {
                  					(yyvsp[-1].nodePtr)->children[1] = (yyvsp[0].nodePtr);
									(yyval.nodePtr) = (yyvsp[-1].nodePtr);	
                  			    }
#line 1930 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 429 "cmparser.y" /* yacc.c:1646  */
    {
                  					(yyval.nodePtr) =  new_ExprNode(LE_EXP);
                  					(yyval.nodePtr)->nLinenumber = yylineno;
	     							(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);	 			
                  			       }
#line 1940 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 434 "cmparser.y" /* yacc.c:1646  */
    {
                  				(yyvsp[-1].nodePtr)->children[1] = (yyvsp[0].nodePtr);
								(yyval.nodePtr) = (yyvsp[-1].nodePtr);	
                  			    }
#line 1949 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 439 "cmparser.y" /* yacc.c:1646  */
    {
                  					(yyval.nodePtr) =  new_ExprNode(EQ_EXP);
                  					(yyval.nodePtr)->nLinenumber = yylineno;
	     							(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);	 			
                  			       }
#line 1959 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 444 "cmparser.y" /* yacc.c:1646  */
    {
                  				(yyvsp[-1].nodePtr)->children[1] = (yyvsp[0].nodePtr);
								(yyval.nodePtr) = (yyvsp[-1].nodePtr);	
                  			    }
#line 1968 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 449 "cmparser.y" /* yacc.c:1646  */
    {	
                  					(yyval.nodePtr) =  new_ExprNode(NE_EXP);
                  					(yyval.nodePtr)->nLinenumber = yylineno;
	     							(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);	 			
                  			       }
#line 1978 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 454 "cmparser.y" /* yacc.c:1646  */
    {
                  	 			(yyvsp[-1].nodePtr)->children[1] = (yyvsp[0].nodePtr);
								(yyval.nodePtr) = (yyvsp[-1].nodePtr);	
                  	   		     }
#line 1987 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 458 "cmparser.y" /* yacc.c:1646  */
    { (yyval.nodePtr) = (yyvsp[0].nodePtr) ;}
#line 1993 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 461 "cmparser.y" /* yacc.c:1646  */
    {
							(yyval.nodePtr) =  new_ExprNode(ADD_EXP);
							(yyval.nodePtr)->nLinenumber = yylineno;
	     						(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);	 			
					 	   }
#line 2003 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 466 "cmparser.y" /* yacc.c:1646  */
    {
				(yyvsp[-1].nodePtr)->children[1] = (yyvsp[0].nodePtr);
				(yyval.nodePtr) = (yyvsp[-1].nodePtr);
			     }
#line 2012 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 471 "cmparser.y" /* yacc.c:1646  */
    {
            						(yyval.nodePtr) =  new_ExprNode(SUB_EXP);
            						(yyval.nodePtr)->nLinenumber = yylineno;
     							(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);	 		
            					     }
#line 2022 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 476 "cmparser.y" /* yacc.c:1646  */
    {
            	        	(yyvsp[-1].nodePtr)->children[1] = (yyvsp[0].nodePtr);
				(yyval.nodePtr) = (yyvsp[-1].nodePtr);	            	        
            	             }
#line 2031 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 481 "cmparser.y" /* yacc.c:1646  */
    {
		    		(yyval.nodePtr) = (yyvsp[0].nodePtr);	
		    	   }
#line 2039 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 486 "cmparser.y" /* yacc.c:1646  */
    {
			(yyval.nodePtr) = new_ExprNode(MULT_EXP);
			(yyval.nodePtr)->nLinenumber = yylineno;
			(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);	 		
		     }
#line 2049 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 491 "cmparser.y" /* yacc.c:1646  */
    {
	     		(yyvsp[-1].nodePtr)->children[1] = (yyvsp[0].nodePtr);
			(yyval.nodePtr) = (yyvsp[-1].nodePtr);	      
		     }
#line 2058 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 496 "cmparser.y" /* yacc.c:1646  */
    {
     			(yyval.nodePtr) =  new_ExprNode(DIV_EXP);
     			(yyval.nodePtr)->nLinenumber = yylineno;
			(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);	 			
     		     }
#line 2068 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 501 "cmparser.y" /* yacc.c:1646  */
    {
     	      		(yyvsp[-1].nodePtr)->children[1] = (yyvsp[0].nodePtr);
			(yyval.nodePtr) = (yyvsp[-1].nodePtr);	      
     	      	     }
#line 2077 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 505 "cmparser.y" /* yacc.c:1646  */
    {
     		(yyval.nodePtr) = (yyvsp[0].nodePtr);		 	
     	      }
#line 2085 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 510 "cmparser.y" /* yacc.c:1646  */
    { (yyval.nodePtr) = (yyvsp[-1].nodePtr); }
#line 2091 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 511 "cmparser.y" /* yacc.c:1646  */
    { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 2097 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 512 "cmparser.y" /* yacc.c:1646  */
    { (yyval.nodePtr) = (yyvsp[0].nodePtr); }
#line 2103 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 513 "cmparser.y" /* yacc.c:1646  */
    { 
       			(yyval.nodePtr) =  new_ExprNode(CONST_EXP);
       			(yyval.nodePtr)->nLinenumber = yylineno;
       			(yyval.nodePtr)->nValue = (yyvsp[0].iVal); 
       		 }
#line 2113 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 520 "cmparser.y" /* yacc.c:1646  */
    {
						(yyval.nodePtr)= new_ExprNode(CALL_EXP);
						(yyval.nodePtr)->nLinenumber = yylineno;
						(yyval.nodePtr)->nSymbolPtr = symLookup((yyvsp[-3].cVal));

					 	if(!(yyval.nodePtr)->nSymbolPtr)
 					 	{  	
						  printf("function %s not found, forward reference\n", (yyvsp[-3].cVal));
						  (yyval.nodePtr)->fname = strdup((yyvsp[-3].cVal));
 					 	}
 					 	(yyval.nodePtr)->fname = strdup((yyvsp[-3].cVal));
					 	(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);	
					 }
#line 2131 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 535 "cmparser.y" /* yacc.c:1646  */
    {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 2137 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 536 "cmparser.y" /* yacc.c:1646  */
    { (yyval.nodePtr) = NULL; }
#line 2143 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 540 "cmparser.y" /* yacc.c:1646  */
    { 
						(yyval.nodePtr) = (yyvsp[-2].nodePtr);
						while((yyval.nodePtr)->sibling)
							(yyval.nodePtr) = (yyval.nodePtr)->sibling;
						(yyval.nodePtr)->sibling = (yyvsp[0].nodePtr);
						(yyvsp[0].nodePtr)->sibling = NULL;
						(yyval.nodePtr) = (yyvsp[-2].nodePtr);
					   }
#line 2156 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 548 "cmparser.y" /* yacc.c:1646  */
    {
	 			(yyvsp[0].nodePtr)->sibling = NULL;	   		
	   			(yyval.nodePtr) = (yyvsp[0].nodePtr);				
	  	       }
#line 2165 "cmparser.tab.c" /* yacc.c:1646  */
    break;


#line 2169 "cmparser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 554 "cmparser.y" /* yacc.c:1906  */

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

