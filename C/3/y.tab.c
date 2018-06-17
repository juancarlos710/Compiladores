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
#line 1 "parser3.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symbol_table.h"
#include "type_table.h"

extern FILE* yyin;
extern int yylex();
extern FILE* yyout;
//simbolo que va entrar a la tabla de simbolos
symbol ctr_symbol;

void insert(char *id, int dir, int tipo, int sym, int args[], int num);
void amp(char *dir, int t1, int t2, char* res);
int max(int t1, int t2);
void newTemp(char *dir);
void newLabel(char *label);

void yyerror(char* s);

// variables que sustituye en atributo tipo
// de el no terminal list
int w=0, t=0;

// globales para B
int w_b, t_b;

int dir = 0;

int tipo_func;

struct _dir_stack{
    int dir[20];
    int count;
};

typedef struct _dir_stack  dir_stack;

dir_stack dirStack;
int index_temp = 0;
int index_label = 0;

#line 110 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    ID = 258,
    NUM = 259,
    COMA = 260,
    PYC = 261,
    INT = 262,
    FLOAT = 263,
    CHAR = 264,
    VOID = 265,
    DOUBLE = 266,
    DEFINE = 267,
    STRUCT = 268,
    RETURN = 269,
    TRUE = 270,
    FALSE = 271,
    IF = 272,
    WHILE = 273,
    LKEY = 274,
    RKEY = 275,
    ASIG = 276,
    OR = 277,
    AND = 278,
    EQ = 279,
    DIF = 280,
    GT = 281,
    LT = 282,
    GET = 283,
    LET = 284,
    MAS = 285,
    MUL = 286,
    NOT = 287,
    LPAR = 288,
    RPAR = 289,
    LCOR = 290,
    RCOR = 291
  };
#endif
/* Tokens.  */
#define ID 258
#define NUM 259
#define COMA 260
#define PYC 261
#define INT 262
#define FLOAT 263
#define CHAR 264
#define VOID 265
#define DOUBLE 266
#define DEFINE 267
#define STRUCT 268
#define RETURN 269
#define TRUE 270
#define FALSE 271
#define IF 272
#define WHILE 273
#define LKEY 274
#define RKEY 275
#define ASIG 276
#define OR 277
#define AND 278
#define EQ 279
#define DIF 280
#define GT 281
#define LT 282
#define GET 283
#define LET 284
#define MAS 285
#define MUL 286
#define NOT 287
#define LPAR 288
#define RPAR 289
#define LCOR 290
#define RCOR 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 46 "parser3.y" /* yacc.c:355  */

    struct{
        int ival;
        double dval;
        //char *sval;
        char sval[20];
        int tipo;
    } num;
    
    struct{
        char dir[20];
        int tipo;        
    }exp;
    
    struct{
        int tipo;
        int dim;        
    } tipo;
    
    struct{
        int args[30];
        int count;
    } arg_list;
    
    struct{
        char next[20];  
        int tipo;
    } sent;
    
    struct{
        char _true[20];
        char _false[20];
    }sent_bool;
    
    int line;
    
    char sval[20];

#line 261 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 278 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   96

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  86

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   120,   120,   120,   129,   129,   136,   140,   140,   151,
     156,   161,   166,   171,   179,   193,   200,   206,   214,   222,
     214,   236,   241,   245,   252,   259,   268,   271,   281,   287,
     307,   313,   322,   331,   339,   342,   356,   361,   362,   363,
     364,   367,   370,   374,   374,   374,   374,   374,   374
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "COMA", "PYC", "INT",
  "FLOAT", "CHAR", "VOID", "DOUBLE", "DEFINE", "STRUCT", "RETURN", "TRUE",
  "FALSE", "IF", "WHILE", "LKEY", "RKEY", "ASIG", "OR", "AND", "EQ", "DIF",
  "GT", "LT", "GET", "LET", "MAS", "MUL", "NOT", "LPAR", "RPAR", "LCOR",
  "RCOR", "$accept", "program", "$@1", "decl", "$@2", "type", "$@3",
  "base", "c_array", "list", "funcs", "$@4", "$@5", "args_list", "args",
  "body", "sents", "sent", "expresion", "sent_bool", "op_rel", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -57

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-57)))

#define YYTABLE_NINF -24

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -57,    19,   -57,   -57,    17,   -57,   -57,   -57,   -57,   -57,
      49,   -57,   -57,   -57,     4,    18,    43,    20,   -57,    28,
      58,   -57,   -57,    76,   -57,    45,    64,   -57,    43,    48,
      80,    50,    81,   -57,   -57,    66,    49,   -57,    84,    37,
     -57,    67,     6,    56,    70,    38,   -57,     6,   -57,   -57,
       6,     7,    -1,   -57,   -57,    12,    46,   -57,     6,     6,
     -57,   -57,    -1,    39,    27,    79,   -57,   -57,    61,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,     6,    -1,    -1,
      38,   -57,   -19,    71,   -57,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     6,     1,    21,    11,    12,    10,     9,    13,
       0,     4,     7,     3,     0,     0,    15,     0,    17,     0,
       0,     8,    18,     0,     5,     0,     0,    16,    15,     9,
       0,     0,    22,    14,    25,     0,     0,     6,     0,     0,
      24,     0,     0,     0,     0,    26,    28,     0,    35,    36,
       0,     0,     0,    19,    27,     0,     0,    30,     0,     0,
      40,    41,     0,     0,     0,    21,    29,    34,    32,    33,
      39,    45,    46,    43,    44,    47,    48,     0,     0,     0,
       0,    20,    42,    37,    38,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -57,    59,   -57,    -6,   -57,   -57,    65,   -57,
      30,   -57,   -57,   -57,   -57,   -57,   -57,   -44,   -42,   -56,
     -57
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     4,    15,    11,    16,    12,    21,    19,
      13,    26,    65,    31,    32,    44,    45,    46,    63,    64,
      77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      51,    54,    48,    49,    14,    55,    70,    17,    56,    48,
      49,    58,    59,    57,    60,    61,    68,    69,    66,     3,
      30,    18,    83,    84,     5,     6,     7,     8,     9,    10,
      38,    62,    50,    23,    24,    82,    85,    58,    59,    50,
      41,    41,    58,    59,     5,     6,     7,     8,     9,    78,
      79,    42,    42,    22,    43,    43,     5,     6,     7,     8,
       9,    80,    25,    71,    72,    73,    74,    75,    76,    58,
      59,     5,     6,     7,    29,     9,    58,    59,    20,    27,
      67,    28,   -23,    34,    35,    37,    36,    40,    47,    52,
      53,    10,    59,    33,    79,    81,    39
};

static const yytype_uint8 yycheck[] =
{
      42,    45,     3,     4,    10,    47,    62,     3,    50,     3,
       4,    30,    31,     6,    15,    16,    58,    59,     6,     0,
      26,     3,    78,    79,     7,     8,     9,    10,    11,    12,
      36,    32,    33,     5,     6,    77,    80,    30,    31,    33,
       3,     3,    30,    31,     7,     8,     9,    10,    11,    22,
      23,    14,    14,    33,    17,    17,     7,     8,     9,    10,
      11,    34,     4,    24,    25,    26,    27,    28,    29,    30,
      31,     7,     8,     9,    10,    11,    30,    31,    35,     3,
      34,    36,    34,     3,    34,    19,     5,     3,    21,    33,
      20,    12,    31,    28,    23,    65,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    39,     0,    40,     7,     8,     9,    10,    11,
      12,    42,    44,    47,    42,    41,    43,     3,     3,    46,
      35,    45,    33,     5,     6,     4,    48,     3,    36,    10,
      42,    50,    51,    45,     3,    34,     5,    19,    42,    40,
       3,     3,    14,    17,    52,    53,    54,    21,     3,     4,
      33,    55,    33,    20,    54,    55,    55,     6,    30,    31,
      15,    16,    32,    55,    56,    49,     6,    34,    55,    55,
      56,    24,    25,    26,    27,    28,    29,    57,    22,    23,
      34,    47,    55,    56,    56,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    39,    38,    41,    40,    40,    43,    42,    44,
      44,    44,    44,    44,    45,    45,    46,    46,    48,    49,
      47,    47,    50,    50,    51,    51,    52,    53,    53,    54,
      54,    54,    55,    55,    55,    55,    55,    56,    56,    56,
      56,    56,    56,    57,    57,    57,    57,    57,    57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     5,     0,     0,     3,     1,
       1,     1,     1,     1,     4,     0,     3,     1,     0,     0,
      13,     0,     1,     1,     4,     2,     1,     2,     1,     4,
       3,     5,     3,     3,     3,     1,     1,     3,     3,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     1
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
#line 120 "parser3.y" /* yacc.c:1646  */
    {
    init();
    dirStack.count = 0;
    create_symbol_table();
    create_type_table();
}
#line 1418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 126 "parser3.y" /* yacc.c:1646  */
    { print_symbols(0, "global");}
#line 1424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 129 "parser3.y" /* yacc.c:1646  */
    { 
        t = (yyvsp[0].tipo).tipo;
        w = (yyvsp[0].tipo).dim;
    }
#line 1433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 132 "parser3.y" /* yacc.c:1646  */
    {
    //printf("D-> D T L;\n");
    }
#line 1441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 136 "parser3.y" /* yacc.c:1646  */
    { //printf("D->3\n");
    }
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 140 "parser3.y" /* yacc.c:1646  */
    {
	t_b = (yyvsp[0].tipo).tipo;
	w_b = (yyvsp[0].tipo).dim;
        
     }
#line 1458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 144 "parser3.y" /* yacc.c:1646  */
    { 
	(yyval.tipo).tipo = (yyvsp[0].tipo).tipo;
	(yyval.tipo).dim = (yyvsp[0].tipo).dim;
        //printf("T -> B C\n");
     }
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 151 "parser3.y" /* yacc.c:1646  */
    {        
        (yyval.tipo).tipo = 0;
        (yyval.tipo).dim = 1;
        //printf("B->void\n");
        }
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 156 "parser3.y" /* yacc.c:1646  */
    {            
            (yyval.tipo).tipo = 1;
            (yyval.tipo).dim = 2;
            //printf("B->char\n");
        }
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 161 "parser3.y" /* yacc.c:1646  */
    {        
        (yyval.tipo).tipo = 2;
        (yyval.tipo).dim = 4;
        //printf("B->int\n");
        }
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 166 "parser3.y" /* yacc.c:1646  */
    {            
            (yyval.tipo).tipo = 3;
            (yyval.tipo).dim = 8;
            //printf("B->float\n");
        }
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 171 "parser3.y" /* yacc.c:1646  */
    {
            (yyval.tipo).tipo = 4;
            (yyval.tipo).dim = 16;
            //printf("B->double\n");
        }
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 179 "parser3.y" /* yacc.c:1646  */
    {
        type t;
        if((yyvsp[-2].num).tipo ==0){
            strcpy(t.tipo, "array");
            t.dim = (yyvsp[-2].num).ival;
            t.base = (yyvsp[0].tipo).tipo;
            (yyval.tipo).tipo = insert_type(t);
            (yyval.tipo).dim = (yyvsp[0].tipo).dim*(yyvsp[-2].num).ival;
            //printf("C -> [ num ] C1\n");
        }else{
            yyerror("La dimensión debe de ser un valor entero");
        }
    }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 193 "parser3.y" /* yacc.c:1646  */
    {	
		(yyval.tipo).tipo = t_b;
		(yyval.tipo).dim = w_b;
                //printf("C -> null\n");
	}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 200 "parser3.y" /* yacc.c:1646  */
    {
        //printf("L->L,id\n");
        insert((yyvsp[0].sval), dir, t, 0, NULL, -1);
        dir = dir + w;
        //printf("L->L1, id\n");
        }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 206 "parser3.y" /* yacc.c:1646  */
    {
            //printf("L->id\n");
            insert((yyvsp[0].sval), dir, t, 0, NULL, -1);
            dir = dir + w;
            //printf("L->id\n");
        }
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 214 "parser3.y" /* yacc.c:1646  */
    {
        tipo_func = (yyvsp[-2].tipo).tipo;
        create_symbol_table();
        create_type_table();
        dirStack.count++;
        dirStack.dir[dirStack.count] = dir;
        dir = 0;
        fprintf(yyout, "%s:", (yyvsp[-1].sval));
    }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 222 "parser3.y" /* yacc.c:1646  */
    {
        print_symbols(symStack.sp,(yyvsp[-8].sval));
        delete_symbol_table();
        delete_type_table();
        dir = dirStack.dir[dirStack.count];
        dirStack.count--;    
        insert((yyvsp[-8].sval), -1 , tipo_func, 1, (yyvsp[-5].arg_list).args, (yyvsp[-5].arg_list).count); 
        if(tipo_func == (yyvsp[-1].sent).tipo){
                fprintf(yyout, "halt\n");
        }else{
            yyerror("El tipo de retorno no coincide con el tipo definido");
        }        
    }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 236 "parser3.y" /* yacc.c:1646  */
    {
        //printf("F -> null\n");
    }
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 241 "parser3.y" /* yacc.c:1646  */
    {
        (yyval.arg_list) = (yyvsp[0].arg_list);
    //printf("A->E\n");
    }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 245 "parser3.y" /* yacc.c:1646  */
    {
        (yyval.arg_list).count = -1;
        //printf("A-> void\n");
    }
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 252 "parser3.y" /* yacc.c:1646  */
    {
       insert((yyvsp[0].sval), dir, (yyvsp[-1].tipo).tipo, 2, NULL, -1); 
       dir = dir + (yyvsp[-1].tipo).dim;
       (yyvsp[-3].arg_list).count++;
       (yyvsp[-3].arg_list).args[(yyvsp[-3].arg_list).count] = (yyvsp[-1].tipo).tipo;
       (yyval.arg_list) = (yyvsp[-3].arg_list);
    }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 259 "parser3.y" /* yacc.c:1646  */
    {    
       insert((yyvsp[0].sval), dir, (yyvsp[-1].tipo).tipo, 2, NULL, -1); 
       dir = dir + (yyvsp[-1].tipo).dim;
       (yyval.arg_list).count= 0;
       (yyval.arg_list).args[(yyval.arg_list).count] = (yyvsp[-1].tipo).tipo;
       
    }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 268 "parser3.y" /* yacc.c:1646  */
    { (yyval.sent).tipo = (yyvsp[0].sent).tipo; }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 271 "parser3.y" /* yacc.c:1646  */
    {
        //printf("S->S I\n");
        if((yyvsp[-1].sent).tipo != 0){
            (yyval.sent).tipo = (yyvsp[-1].sent).tipo;
        }else if((yyvsp[0].sent).tipo != 0){
            (yyval.sent).tipo = (yyvsp[0].sent).tipo;
        }else{
            (yyval.sent).tipo = 0;
        }
    }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 281 "parser3.y" /* yacc.c:1646  */
    {
        (yyval.sent).tipo = (yyvsp[0].sent).tipo;
        //printf("S->I\n");
    }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 287 "parser3.y" /* yacc.c:1646  */
    {   
    if(search_symbol((yyvsp[-3].sval), symStack.sp) == 1){
        if(get_tipo((yyvsp[-3].sval), symStack.sp)  == (yyvsp[-1].exp).tipo){
            fprintf(yyout, "%s = %s\n", (yyvsp[-3].sval), (yyvsp[-1].exp).dir);
        }else{
            yyerror("Error Semántico: los tipos no coincide");
        }
    }else if(search_symbol((yyvsp[-3].sval), 0) == 1){
        if(get_tipo((yyvsp[-3].sval), 0)  == (yyvsp[-1].exp).tipo){
            fprintf(yyout, "%s = %s\n", (yyvsp[-3].sval), (yyvsp[-1].exp).dir);
        }else{
            yyerror("Error Semántico: los tipos no coincide");
        }
    }else{
        yyerror("Error Semántico: el id no ha sido declarado");
    }
    (yyval.sent).tipo = 0;
    newLabel((yyval.sent).next);
    //printf("X->id= E;\n");
    }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 307 "parser3.y" /* yacc.c:1646  */
    {
        newLabel((yyval.sent).next);
        (yyval.sent).tipo = (yyvsp[-1].exp).tipo;
        //printf("X->return G;\n");
    }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 313 "parser3.y" /* yacc.c:1646  */
    {
        (yyval.sent).tipo = 0;
        //printf("X-> if( B ) X\n");
    }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 322 "parser3.y" /* yacc.c:1646  */
    {
        (yyval.exp).tipo = max((yyvsp[-2].exp).tipo, (yyvsp[0].exp).tipo);        
        newTemp((yyval.exp).dir);
        char dirAlpha1[20], dirAlpha2[20];   
        amp((yyvsp[-2].exp).dir, (yyvsp[-2].exp).tipo, (yyval.exp).tipo, dirAlpha1);
        amp((yyvsp[0].exp).dir, (yyvsp[0].exp).tipo, (yyval.exp).tipo, dirAlpha2);
        fprintf(yyout, "%s = %s + %s\n", (yyval.exp).dir, dirAlpha1, dirAlpha2);
        //printf("E->E+E\n");
    }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 331 "parser3.y" /* yacc.c:1646  */
    {
        (yyval.exp).tipo = max((yyvsp[-2].exp).tipo, (yyvsp[0].exp).tipo);        
        newTemp((yyval.exp).dir);
        char dirAlpha1[20], dirAlpha2[20];   
        amp((yyvsp[-2].exp).dir, (yyvsp[-2].exp).tipo, (yyval.exp).tipo, dirAlpha1);
        amp((yyvsp[0].exp).dir, (yyvsp[0].exp).tipo, (yyval.exp).tipo, dirAlpha2);
        fprintf(yyout, "%s = %s * %s\n", (yyval.exp).dir, dirAlpha1, dirAlpha2);        
    }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 339 "parser3.y" /* yacc.c:1646  */
    {
        (yyval.exp) = (yyvsp[-1].exp);	
    }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 342 "parser3.y" /* yacc.c:1646  */
    {
        if(search_symbol((yyvsp[0].sval), symStack.sp) == 1){            
            (yyval.exp).tipo = get_tipo((yyvsp[0].sval), symStack.sp);
            //printf("El tipo de %s es %d\n", $1, $$.tipo);
            strcpy((yyval.exp).dir, (yyvsp[0].sval));          
        }else if(search_symbol((yyvsp[0].sval), 0) == 1){
            (yyval.exp).tipo = get_tipo((yyvsp[0].sval), 0);
            //printf("El tipo de %s es %d\n", $1, $$.tipo);
            strcpy((yyval.exp).dir, (yyvsp[0].sval));
        }else{
            yyerror("El id no fue declarado\n");
            return 0;
        }                   
    }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 356 "parser3.y" /* yacc.c:1646  */
    {
        (yyval.exp).tipo = (yyvsp[0].num).tipo;
        strcpy((yyval.exp).dir, (yyvsp[0].num).sval);        
    }
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 361 "parser3.y" /* yacc.c:1646  */
    {}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 364 "parser3.y" /* yacc.c:1646  */
    {
    //printf("B-> true\n");
    }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 367 "parser3.y" /* yacc.c:1646  */
    {
    //printf("B->false\n");
    }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 370 "parser3.y" /* yacc.c:1646  */
    {
        //printf("B-> E oprel E\n");
        }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1821 "y.tab.c" /* yacc.c:1646  */
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
#line 376 "parser3.y" /* yacc.c:1906  */




void yyerror(char* s){
    printf("%s , en  la linea %d\n", s, yylval.line);
}


void newTemp(char *dir){
    char temp[20];
    strcpy(temp , "t");
    char num[19];
    sprintf(num, "%d", index_temp);	
    index_temp++;
    strcat(temp,num);
    strcpy(dir, temp);
}

void newLabel(char *label){
    char temp[20];
    strcpy(temp , "L");
    char num[19];
    sprintf(num, "%d", index_label);	
    index_label++;
    strcat(temp,num);
    strcpy(label, temp);
}

void insert(char *id, int dir, int tipo, int sym, int args[], int num){    
    int i;
    strcpy(ctr_symbol.id, id);
    ctr_symbol.dir = dir;
    ctr_symbol.tipo = tipo;
    ctr_symbol.sym = sym;
    if(num != -1){
       for(i=0 ; i<num+1; i++){
            ctr_symbol.args[i] = args[i];
        }
    }
    ctr_symbol.num_args = num;
    //printf("el sp %d\n", symStack.sp);
    if(insert_symbol(ctr_symbol, symStack.sp)==0)
        yyerror("Id duplicado\n");
}


/*void = 0,  char = 1, int = 2, float = 3 y doble =4 */
int  max(int t1, int t2){
    if(t1 == t2)
        return t1;
    else if(t1==1 && t2 == 2){
        return t2;
    }else if( t1 == 2 && t2==1){
        return t1;
    }else if(t1==2 && t2 == 3){
        return t2;
    }else if( t1 == 3 && t2==2){
        return t1;
    }else if(t1==2 && t2 == 4){
        return t2;
    }else if( t1 == 4 && t2==2){
        return t1;
    }
    else if(t1==3 && t2 == 4){
        return t2;
    }else if( t1 == 4 && t2==3){
        return t1;
    }
    else{
        yyerror("Error Semántico: Los tipos no son compatibles funcion max");
        return -1;
    }
}


void amp(char *dir, int t1, int t2, char* res){
    if(t1 == t2){
        strcpy(res, dir);;
    }else if((t1==1 && t2==2) || (t1== 2 && t2 == 1)){
        char temp[20];
        newTemp(temp);
        fprintf(yyout, "%s = (int) %s\n", temp, dir);
        strcpy(res, temp);
    }else if((t1==2 && t2==3) || (t1== 3 && t2 == 2)){
        char temp[20];
        newTemp(temp);
        fprintf(yyout, "%s = (float) %s\n", temp, dir);
        strcpy(res, temp);
    }else if((t1==2 && t2==4) || (t1== 4 && t2 == 2)){
        char temp[20];
        newTemp(temp);
        fprintf(yyout, "%s = (double) %s\n", temp, dir);
        strcpy(res, temp);
    }else if((t1==3 && t2==4) || (t1== 4 && t2 == 3)){
        char temp[20];
        newTemp(temp);
        fprintf(yyout, "%s = (double) %s\n", temp, dir);
        strcpy(res, temp);
    }
    else{
        yyerror("Error Semántico: Los tipos no son compatibles funcion amp");
    }
}


int main(int argc, char** argv){
    FILE* file;
    if(argc >1){
        file = fopen(argv[1], "r");
        if(file==NULL){
            printf("no existe el fichero %s\n", argv[1]);
            exit(1);
        }
        char nombre[50];
        strcpy(nombre, argv[1]);
        strcat(nombre, ".ci");
        yyout = fopen(nombre, "w");
        //printf("se abrio el archivo\n");
        yyin = file;        
        //yylval.sval = (char*) malloc(2*sizeof(char));
        yyparse();
        fclose(yyin);
        fclose(yyout);
    }
    
    return 1;
}
