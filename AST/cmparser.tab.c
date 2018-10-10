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
 


#line 100 "cmparser.tab.c" /* yacc.c:339  */

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
#line 39 "cmparser.y" /* yacc.c:355  */

    AstNodePtr nodePtr;
    int        iVal;
    char      *cVal;
    Type      *type;

#line 179 "cmparser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CMPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 196 "cmparser.tab.c" /* yacc.c:358  */

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
#define YYLAST   136

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

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
       0,    76,    76,    81,    85,    91,    94,   101,   109,   121,
     121,   121,   121,   121,   145,   149,   153,   162,   168,   180,
     194,   197,   202,   209,   217,   221,   226,   230,   236,   239,
     239,   239,   242,   245,   248,   253,   258,   263,   266,   272,
     280,   288,   293,   299,   306,   311,   322,   337,   343,   350,
     356,   362,   368,   374,   379,   385,   391,   396,   402,   409,
     415,   418,   422,   426,   434,   443,   447,   452,   460
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
  "Var_Declaration", "Fun_Declaration", "$@1", "$@2", "$@3", "$@4",
  "Params", "Param_List", "Param", "Type_Specifier", "Compound_Stmt",
  "Local_Declarations", "Statements", "Statement", "$@5", "$@6",
  "Expr_Statement", "Selection_Stmt", "If_Else_Statement",
  "Iteration_Stmt", "Return_Stmt", "Expression", "Var",
  "Simple_Expression", "Additive_Expression", "Term", "Factor", "Call",
  "Args", "Args_List", YY_NULLPTR
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

#define YYPACT_NINF -75

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-75)))

#define YYTABLE_NINF -30

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      28,   -75,   -75,     4,   -75,   -75,    28,    28,   -13,   -75,
     -75,   -75,    17,    34,    35,   -75,   -75,    30,    69,    42,
      48,    81,    50,   -75,    74,    85,   -75,    28,    82,   -75,
      83,   -75,    86,     7,   -75,   -75,    90,    33,    91,   -75,
     -20,   -17,   -75,    28,    78,    39,    87,    39,    83,   -75,
     -75,   105,   -75,   -75,    95,    97,   -75,    80,    88,   -75,
     -75,   -75,   -20,   -75,    98,   -20,    94,   -20,   -20,   -75,
      21,    92,   -75,   -75,   -75,    44,   -75,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -75,    99,
     -75,   100,   -75,   -75,   101,    89,    96,   -75,   -75,   -75,
     -75,   -75,    88,    88,    41,    41,    41,    41,    41,    41,
     -75,   -75,    44,    44,   -75,   -20,   -75,   -75,   -75,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    21,    20,     0,     2,     3,     0,     5,     0,     1,
       4,     6,     0,     0,     0,     7,     9,     0,     0,     0,
      15,     0,    14,    17,     0,     0,    10,     0,    18,     8,
       0,    16,     0,    27,    11,    19,     0,     0,     0,    36,
       0,    45,    63,    25,     0,    27,     0,    27,     0,    28,
      32,    37,    33,    34,     0,    61,    44,    53,    56,    59,
      62,    12,     0,    42,     0,     0,     0,    66,     0,    24,
       0,     0,    22,    26,    30,    29,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
      41,     0,    60,    68,     0,    65,     0,    23,    31,    38,
      43,    61,    54,    55,    48,    50,    47,    49,    51,    52,
      57,    58,    29,    29,    64,     0,    46,    39,    40,    67
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -75,   -75,   114,   118,   -25,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   102,    -1,    79,    93,    25,   -74,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -37,     1,   -75,   -61,    13,
      15,   -75,   -75,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,    18,    30,    61,    88,
      21,    22,    23,     8,    34,    45,    46,    47,    48,    98,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    94,    95
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      64,    99,    40,    66,     9,    67,    12,    68,    43,    41,
      42,    36,    37,     1,     2,    38,    13,    24,    43,   104,
     105,   106,   107,   108,   109,    89,    24,    39,    91,    40,
      93,    96,    44,   -29,     1,     2,    41,    42,   117,   118,
     100,    15,    44,    36,    37,    17,    14,    38,    36,    37,
      78,    79,    38,    63,    15,    40,    16,    16,    17,    39,
      19,    40,    41,    42,    39,   -29,    40,    25,    41,    42,
      71,    27,    73,    41,    42,    20,     2,   -21,   119,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,    78,
      79,   102,   103,    80,    81,    82,    83,    84,    85,    86,
      87,   110,   111,    28,    26,    29,    32,    70,    75,    33,
     115,    35,    62,    65,    72,    76,    77,    92,    90,    97,
      10,   116,   112,   113,   114,    11,     0,    74,     0,    31,
       0,     0,     0,     0,     0,     0,    69
};

static const yytype_int8 yycheck[] =
{
      37,    75,    22,    40,     0,    22,     7,    24,    33,    29,
      30,     4,     5,     6,     7,     8,    29,    18,    43,    80,
      81,    82,    83,    84,    85,    62,    27,    20,    65,    22,
      67,    68,    33,    26,     6,     7,    29,    30,   112,   113,
      77,    20,    43,     4,     5,    24,    29,     8,     4,     5,
       9,    10,     8,    20,    20,    22,    22,    22,    24,    20,
      30,    22,    29,    30,    20,    26,    22,    25,    29,    30,
      45,    21,    47,    29,    30,     6,     7,    29,   115,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     9,
      10,    78,    79,    13,    14,    15,    16,    17,    18,    11,
      12,    86,    87,    29,    23,    20,    24,    29,     3,    26,
      21,    25,    22,    22,    27,    20,    19,    23,    20,    27,
       6,    25,    23,    23,    23,     7,    -1,    48,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    33,    34,    35,    36,    37,    45,     0,
      34,    35,    45,    29,    29,    20,    22,    24,    38,    30,
       6,    42,    43,    44,    45,    25,    23,    21,    29,    20,
      39,    44,    24,    26,    46,    25,     4,     5,     8,    20,
      22,    29,    30,    36,    45,    47,    48,    49,    50,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    40,    22,    20,    57,    22,    57,    22,    24,    47,
      29,    48,    27,    48,    46,     3,    20,    19,     9,    10,
      13,    14,    15,    16,    17,    18,    11,    12,    41,    57,
      20,    57,    23,    57,    64,    65,    57,    27,    51,    49,
      57,    58,    61,    61,    60,    60,    60,    60,    60,    60,
      62,    62,    23,    23,    23,    21,    25,    49,    49,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    36,    36,    38,
      39,    40,    41,    37,    42,    42,    43,    43,    44,    44,
      45,    45,    46,    46,    47,    47,    48,    48,    49,    50,
      51,    49,    49,    49,    49,    52,    52,    53,    53,    54,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    60,    61,    61,    61,
      62,    62,    62,    62,    63,    64,    64,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     3,     6,     0,
       0,     0,     0,    10,     1,     1,     3,     1,     2,     4,
       1,     1,     3,     4,     2,     1,     2,     0,     1,     0,
       0,     3,     1,     1,     1,     2,     1,     1,     3,     5,
       5,     3,     2,     3,     1,     1,     4,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     1,     1,     1,     4,     1,     0,     3,     1
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
#line 76 "cmparser.y" /* yacc.c:1646  */
    {
		
                        }
#line 1363 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 81 "cmparser.y" /* yacc.c:1646  */
    { 
                         program = (yyvsp[0].nodePtr);
						
			 }
#line 1372 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 85 "cmparser.y" /* yacc.c:1646  */
    {
			(yyval.nodePtr) = (yyvsp[0].nodePtr);
			
	     }
#line 1381 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "cmparser.y" /* yacc.c:1646  */
    {
	                   (yyval.nodePtr) = (yyvsp[0].nodePtr);
			   }
#line 1389 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 94 "cmparser.y" /* yacc.c:1646  */
    {
	     			//$$ = $1;
				(yyvsp[-1].nodePtr)->sibling = (yyvsp[0].nodePtr);
					
		   	   }
#line 1399 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 101 "cmparser.y" /* yacc.c:1646  */
    {
			if(symLookupInScope((yyvsp[-1].cVal)) != NULL){
				yyerror((yyvsp[-1].cVal));			
			}
			else{
				symInsert((yyvsp[-1].cVal),(yyvsp[-2].type),yylineno);
			}			   
		}
#line 1412 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 109 "cmparser.y" /* yacc.c:1646  */
    {
			(yyvsp[-5].type)->kind = ARRAY;
			(yyvsp[-5].type)->dimension = (yyvsp[-2].iVal);
			if(symLookupInScope((yyvsp[-4].cVal)) != NULL){
				yyerror((yyvsp[-4].cVal));
			}
			else
				symInsert((yyvsp[-4].cVal),(yyvsp[-5].type),yylineno);		        
   }
#line 1426 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 121 "cmparser.y" /* yacc.c:1646  */
    {enterScope();}
#line 1432 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 121 "cmparser.y" /* yacc.c:1646  */
    {enterScope();}
#line 1438 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 121 "cmparser.y" /* yacc.c:1646  */
    {leaveScope();}
#line 1444 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 121 "cmparser.y" /* yacc.c:1646  */
    {leaveScope();}
#line 1450 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 121 "cmparser.y" /* yacc.c:1646  */
    {
			


			if(symLookupInScope((yyvsp[-8].cVal)) != NULL){
				yyerror((yyvsp[-8].cVal));
			}
			else{
				(yyval.nodePtr) = new_GenNode(METHOD);
				TypePtr newType = new_type((yyvsp[-9].type)->kind);
				(yyvsp[-9].type)->kind = FUNCTION;
				(yyvsp[-9].type)->function = newType;
				(yyval.nodePtr)->nType = (yyvsp[-9].type);
				(yyval.nodePtr)->nSymbolPtr = symInsert((yyvsp[-8].cVal),(yyvsp[-9].type),yylineno);
				(yyval.nodePtr)->children[0] = (yyvsp[-5].nodePtr);
				(yyval.nodePtr)->children[1] = (yyvsp[-2].nodePtr);
				(yyval.nodePtr)->nSymbolTabPtr = symbolStackTop->symbolTablePtr;
				(yyval.nodePtr)->nLinenumber = yylineno;
				
				
			}
                           }
#line 1477 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 145 "cmparser.y" /* yacc.c:1646  */
    {
		(yyval.nodePtr) = (yyvsp[0].nodePtr);
			   
			   }
#line 1486 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 149 "cmparser.y" /* yacc.c:1646  */
    {
       			   }
#line 1493 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 153 "cmparser.y" /* yacc.c:1646  */
    {
		AstNodePtr temp = (yyvsp[-2].nodePtr);
		while(temp->sibling!=NULL){
			temp = temp->sibling;
		}
		temp->sibling = (yyvsp[0].nodePtr);
		(yyval.nodePtr) = (yyvsp[-2].nodePtr);
	
}
#line 1507 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 162 "cmparser.y" /* yacc.c:1646  */
    {
		(yyval.nodePtr)= (yyvsp[0].nodePtr);
	   			
			}
#line 1516 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 168 "cmparser.y" /* yacc.c:1646  */
    {
		
		if(symLookupInScope((yyvsp[0].cVal))!=NULL){
			yyerror((yyvsp[0].cVal));
		}
		else{
			(yyval.nodePtr) = new_GenNode(FORMALVAR);
			(yyval.nodePtr)->nType = (yyvsp[-1].type);
			(yyval.nodePtr)->nSymbolPtr = symInsert((yyvsp[0].cVal),(yyvsp[-1].type),yylineno);
			(yyval.nodePtr)->nLinenumber = yylineno;
		}	
		 	}
#line 1533 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 180 "cmparser.y" /* yacc.c:1646  */
    {
      		if(symLookupInScope((yyvsp[-2].cVal))!=NULL){
			yyerror((yyvsp[-2].cVal));
		}
		else{
			(yyval.nodePtr) = new_GenNode(FORMALVAR);
			(yyvsp[-3].type)->kind = ARRAY;
			(yyval.nodePtr)->nType = (yyvsp[-3].type);
			(yyval.nodePtr)->nSymbolPtr = symInsert((yyvsp[-2].cVal),(yyvsp[-3].type),yylineno);
			(yyval.nodePtr)->nLinenumber = yylineno;
		}
			
      			}
#line 1551 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 194 "cmparser.y" /* yacc.c:1646  */
    {
		(yyval.type) = new_type(INT);	
			}
#line 1559 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 197 "cmparser.y" /* yacc.c:1646  */
    {
	       	(yyval.type) = new_type(VOID);
	       		}
#line 1567 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 202 "cmparser.y" /* yacc.c:1646  */
    {
		
			(yyval.nodePtr) = new_StmtNode(COMPOUND_STMT);
			(yyval.nodePtr)->nSymbolTabPtr = symbolStackTop->symbolTablePtr;
			(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);
			
			}
#line 1579 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 209 "cmparser.y" /* yacc.c:1646  */
    {
	      	
			(yyval.nodePtr) = new_StmtNode(COMPOUND_STMT);
			(yyval.nodePtr)->nSymbolTabPtr = symbolStackTop->symbolTablePtr;
			(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);
	      		}
#line 1590 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 217 "cmparser.y" /* yacc.c:1646  */
    {
		
		
			}
#line 1599 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 221 "cmparser.y" /* yacc.c:1646  */
    {
		   	
		   	}
#line 1607 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 226 "cmparser.y" /* yacc.c:1646  */
    {
			(yyval.nodePtr) = (yyvsp[-1].nodePtr);
			(yyval.nodePtr)->sibling = (yyvsp[0].nodePtr);
			}
#line 1616 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 230 "cmparser.y" /* yacc.c:1646  */
    {
			(yyval.nodePtr) = NULL;
	   		
			}
#line 1625 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 236 "cmparser.y" /* yacc.c:1646  */
    {
			(yyval.nodePtr) = (yyvsp[0].nodePtr);
			}
#line 1633 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 239 "cmparser.y" /* yacc.c:1646  */
    {enterScope();}
#line 1639 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 239 "cmparser.y" /* yacc.c:1646  */
    {leaveScope();}
#line 1645 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 239 "cmparser.y" /* yacc.c:1646  */
    {
	  		(yyval.nodePtr) = (yyvsp[-1].nodePtr);
			}
#line 1653 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 242 "cmparser.y" /* yacc.c:1646  */
    {
	  		(yyval.nodePtr) = (yyvsp[0].nodePtr);
	  		}
#line 1661 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 245 "cmparser.y" /* yacc.c:1646  */
    {
	  		(yyval.nodePtr) = (yyvsp[0].nodePtr);
	  		}
#line 1669 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 248 "cmparser.y" /* yacc.c:1646  */
    {
	  		(yyval.nodePtr) = (yyvsp[0].nodePtr);
			}
#line 1677 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 253 "cmparser.y" /* yacc.c:1646  */
    {
			(yyval.nodePtr) = new_StmtNode(EXPRESSION_STMT);
			(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);
			(yyval.nodePtr)->nLinenumber = yylineno;
			}
#line 1687 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 258 "cmparser.y" /* yacc.c:1646  */
    {
	       
	       		}
#line 1695 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 263 "cmparser.y" /* yacc.c:1646  */
    {
			(yyval.nodePtr) = (yyvsp[0].nodePtr);
			}
#line 1703 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 266 "cmparser.y" /* yacc.c:1646  */
    {
	       		(yyval.nodePtr) = (yyvsp[-2].nodePtr);
			(yyval.nodePtr)->children[2] = (yyvsp[0].nodePtr);
	       		}
#line 1712 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 272 "cmparser.y" /* yacc.c:1646  */
    {
			(yyval.nodePtr) = new_StmtNode(IF_THEN_ELSE_STMT);
			(yyval.nodePtr)->children[0] = (yyvsp[-2].nodePtr);
			(yyval.nodePtr)->children[1] = (yyvsp[0].nodePtr);
			(yyval.nodePtr)->nLinenumber = yylineno;
			}
#line 1723 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 280 "cmparser.y" /* yacc.c:1646  */
    {
			(yyval.nodePtr) = new_StmtNode(WHILE_STMT);
			(yyval.nodePtr)->children[0] = (yyvsp[-2].nodePtr);
			(yyval.nodePtr)->children[1] = (yyvsp[0].nodePtr);
			(yyval.nodePtr)->nLinenumber = yylineno;
			}
#line 1734 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 288 "cmparser.y" /* yacc.c:1646  */
    {
		(yyval.nodePtr) = new_StmtNode(RETURN_STMT);
		(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);

			}
#line 1744 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 293 "cmparser.y" /* yacc.c:1646  */
    {
	    	(yyval.nodePtr) = new_StmtNode(RETURN_STMT);
		(yyval.nodePtr)->children[0] = NULL;
	    		}
#line 1753 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 299 "cmparser.y" /* yacc.c:1646  */
    {
			(yyval.nodePtr) = new_ExprNode(ASSI_EXP);
			(yyval.nodePtr)->children[0] = (yyvsp[-2].nodePtr);
			(yyval.nodePtr)->children[1] = (yyvsp[0].nodePtr);
			(yyval.nodePtr)->nLinenumber = yylineno;
			
			}
#line 1765 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 306 "cmparser.y" /* yacc.c:1646  */
    {
	    		(yyval.nodePtr) = (yyvsp[0].nodePtr);
	    		}
#line 1773 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 311 "cmparser.y" /* yacc.c:1646  */
    {
	if(symLookup((yyvsp[0].cVal))==NULL){
		yyerror((yyvsp[0].cVal));
	}
	else{
		(yyval.nodePtr) = new_ExprNode(VAR_EXP);
		(yyval.nodePtr)->nSymbolPtr = symLookup((yyvsp[0].cVal));
		(yyval.nodePtr)->nLinenumber = yylineno;
	}
	
			}
#line 1789 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 322 "cmparser.y" /* yacc.c:1646  */
    {
	if(symLookup((yyvsp[-3].cVal))==NULL){
		yyerror((yyvsp[-3].cVal));
	}
	else{
		(yyval.nodePtr) = new_ExprNode(ARRAY_EXP);
		(yyval.nodePtr)->nSymbolPtr = symLookup((yyvsp[-3].cVal));
		(yyval.nodePtr)->nLinenumber = yylineno;
		(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);
	}
	
    
    			}
#line 1807 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 337 "cmparser.y" /* yacc.c:1646  */
    {
				(yyval.nodePtr) = new_ExprNode(GT_EXP);
				(yyval.nodePtr)->nLinenumber = yylineno;
				(yyval.nodePtr)->children[0] = (yyvsp[-2].nodePtr);
				(yyval.nodePtr)->children[1] = (yyvsp[0].nodePtr);	
			}
#line 1818 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 343 "cmparser.y" /* yacc.c:1646  */
    {
				(yyval.nodePtr) = new_ExprNode(LT_EXP);
				(yyval.nodePtr)->nLinenumber = yylineno;
				(yyval.nodePtr)->children[0] = (yyvsp[-2].nodePtr);
				(yyval.nodePtr)->children[1] = (yyvsp[0].nodePtr);		  
		
		  	}
#line 1830 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 350 "cmparser.y" /* yacc.c:1646  */
    {
		  		(yyval.nodePtr) = new_ExprNode(GE_EXP);
				(yyval.nodePtr)->nLinenumber = yylineno;
				(yyval.nodePtr)->children[0] = (yyvsp[-2].nodePtr);
				(yyval.nodePtr)->children[1] = (yyvsp[0].nodePtr);
		  	}
#line 1841 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 356 "cmparser.y" /* yacc.c:1646  */
    {
		  		(yyval.nodePtr) = new_ExprNode(LE_EXP);
				(yyval.nodePtr)->nLinenumber = yylineno;
				(yyval.nodePtr)->children[0] = (yyvsp[-2].nodePtr);
				(yyval.nodePtr)->children[1] = (yyvsp[0].nodePtr);
			}
#line 1852 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 362 "cmparser.y" /* yacc.c:1646  */
    {
		  		(yyval.nodePtr) = new_ExprNode(EQ_EXP);
				(yyval.nodePtr)->nLinenumber = yylineno;
				(yyval.nodePtr)->children[0] = (yyvsp[-2].nodePtr);
				(yyval.nodePtr)->children[1] = (yyvsp[0].nodePtr);
		  	}
#line 1863 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 368 "cmparser.y" /* yacc.c:1646  */
    {
		  		(yyval.nodePtr) = new_ExprNode(NE_EXP);
				(yyval.nodePtr)->nLinenumber = yylineno;
				(yyval.nodePtr)->children[0] = (yyvsp[-2].nodePtr);
				(yyval.nodePtr)->children[1] = (yyvsp[0].nodePtr);
		  	}
#line 1874 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 374 "cmparser.y" /* yacc.c:1646  */
    {
		  		(yyval.nodePtr) = (yyvsp[0].nodePtr);
		  	}
#line 1882 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 379 "cmparser.y" /* yacc.c:1646  */
    {
				(yyval.nodePtr) = new_ExprNode(ADD_EXP);
				(yyval.nodePtr)->nLinenumber = yylineno;
				(yyval.nodePtr)->children[0] = (yyvsp[-2].nodePtr);
				(yyval.nodePtr)->children[1] = (yyvsp[0].nodePtr);
			}
#line 1893 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 385 "cmparser.y" /* yacc.c:1646  */
    {
		    		(yyval.nodePtr) = new_ExprNode(SUB_EXP);
				(yyval.nodePtr)->nLinenumber = yylineno;
				(yyval.nodePtr)->children[0] = (yyvsp[-2].nodePtr);
				(yyval.nodePtr)->children[1] = (yyvsp[0].nodePtr);
		    	}
#line 1904 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 391 "cmparser.y" /* yacc.c:1646  */
    {
		    		(yyval.nodePtr) = (yyvsp[0].nodePtr);
		    	}
#line 1912 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 396 "cmparser.y" /* yacc.c:1646  */
    {
				(yyval.nodePtr) = new_ExprNode(MULT_EXP);
				(yyval.nodePtr)->nLinenumber = yylineno;
				(yyval.nodePtr)->children[0] = (yyvsp[-2].nodePtr);
				(yyval.nodePtr)->children[1] = (yyvsp[0].nodePtr);
			}
#line 1923 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 402 "cmparser.y" /* yacc.c:1646  */
    {
				(yyval.nodePtr) = new_ExprNode(DIV_EXP);
				(yyval.nodePtr)->nLinenumber = yylineno;
				(yyval.nodePtr)->children[0] = (yyvsp[-2].nodePtr);
				(yyval.nodePtr)->children[1] = (yyvsp[0].nodePtr);
     
     			}
#line 1935 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 409 "cmparser.y" /* yacc.c:1646  */
    {
			(yyval.nodePtr) = (yyvsp[0].nodePtr);
     			
			}
#line 1944 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 415 "cmparser.y" /* yacc.c:1646  */
    {
			(yyval.nodePtr) = (yyvsp[-1].nodePtr);
			}
#line 1952 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 418 "cmparser.y" /* yacc.c:1646  */
    {
 			(yyval.nodePtr) = (yyvsp[0].nodePtr);
       			
			}
#line 1961 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 422 "cmparser.y" /* yacc.c:1646  */
    {
			(yyval.nodePtr) = (yyvsp[0].nodePtr);
       
       			}
#line 1970 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 426 "cmparser.y" /* yacc.c:1646  */
    {
			(yyval.nodePtr) = new_ExprNode(CONST_EXP);
			(yyval.nodePtr)->nValue = (yyvsp[0].iVal);
			(yyval.nodePtr)->nLinenumber = yylineno;
       
       			}
#line 1981 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 434 "cmparser.y" /* yacc.c:1646  */
    {
			(yyval.nodePtr) = new_ExprNode(CALL_EXP);
			(yyval.nodePtr)->children[0] = (yyvsp[-1].nodePtr);
			(yyval.nodePtr)->nLinenumber = yylineno;
			(yyval.nodePtr)->fname = (yyvsp[-3].cVal);

			}
#line 1993 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 443 "cmparser.y" /* yacc.c:1646  */
    {
		(yyval.nodePtr) = (yyvsp[0].nodePtr);
			
			}
#line 2002 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 447 "cmparser.y" /* yacc.c:1646  */
    {
     		(yyval.nodePtr) = NULL;
     			}
#line 2010 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 452 "cmparser.y" /* yacc.c:1646  */
    {
			AstNodePtr temp = (yyvsp[-2].nodePtr);
			while(temp->sibling!=NULL){
				temp = temp->sibling;
			}
			temp->sibling = (yyvsp[0].nodePtr);
			(yyval.nodePtr) = (yyvsp[-2].nodePtr);
			}
#line 2023 "cmparser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 460 "cmparser.y" /* yacc.c:1646  */
    {
	  		(yyval.nodePtr) = (yyvsp[0].nodePtr);
	  		}
#line 2031 "cmparser.tab.c" /* yacc.c:1646  */
    break;


#line 2035 "cmparser.tab.c" /* yacc.c:1646  */
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
#line 465 "cmparser.y" /* yacc.c:1906  */

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
