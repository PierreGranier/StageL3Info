/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "verificateur.y" /* yacc.c:339  */

#include "global.h"
#include "fonctions.cpp"

// Permettre l'utilisation du C++
extern "C" int yylex(void);
extern "C" int yyparse(void);
extern "C" void yyerror(const std::string&);
extern FILE* yyin;

#line 77 "verificateur.tab.c" /* yacc.c:339  */

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
   by #include "verificateur.tab.h".  */
#ifndef YY_YY_VERIFICATEUR_TAB_H_INCLUDED
# define YY_YY_VERIFICATEUR_TAB_H_INCLUDED
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
    FIN = 258,
    FINFINALE = 259,
    MOT = 260,
    ENTIER = 261,
    AFF = 262,
    SEQ = 263,
    COND = 264,
    CONSEQ = 265,
    WHILE = 266,
    WHILET = 267,
    ACCOLADE_OUVRANTE = 268,
    ACCOLADE_FERMANTE = 269,
    AFFECTATION = 270,
    POINTVIRGULE = 271,
    INF_EGAL = 272,
    SUP_EGAL = 273,
    SUP = 274,
    INF = 275,
    EGAL = 276,
    NON_EGAL = 277,
    ET = 278,
    VRAI = 279,
    FAUX = 280,
    PLUS = 281,
    MOINS = 282,
    FOIS = 283
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 13 "verificateur.y" /* yacc.c:355  */

	string chaine;
	t_expression expression;
	t_proposition proposition;
	t_triplet triplet;
	t_instruction instruction;
	t_programme programme;

#line 155 "verificateur.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_VERIFICATEUR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 170 "verificateur.tab.c" /* yacc.c:358  */

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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  101

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

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
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    57,    58,    59,    60,    64,    76,   100,
     128,   164,   188,   232,   256,   271,   275,   282,   294,   301,
     305,   311,   320,   326,   332,   338,   344,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   363,   364,   368,
     373,   378,   383,   388,   392,   396,   403,   407,   411,   415,
     422,   427,   435,   442,   453
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FIN", "FINFINALE", "MOT", "ENTIER",
  "AFF", "SEQ", "COND", "CONSEQ", "WHILE", "WHILET", "ACCOLADE_OUVRANTE",
  "ACCOLADE_FERMANTE", "AFFECTATION", "POINTVIRGULE", "INF_EGAL",
  "SUP_EGAL", "SUP", "INF", "EGAL", "NON_EGAL", "ET", "VRAI", "FAUX",
  "PLUS", "MOINS", "FOIS", "$accept", "Entree", "Regle", "Triplet",
  "Predicat", "Conditions", "Condition", "Comparaison", "Expression",
  "ExpressionEntier", "ExpressionMot", "Programme", "ProgrammeCompose",
  "Instruction", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283
};
# endif

#define YYPACT_NINF -60

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-60)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      75,   -60,   -60,    23,    28,   -11,   -11,   -11,   -11,   -11,
     -11,   -60,   -60,     5,     6,    31,   -16,   -60,    95,   100,
      10,    10,    10,    10,    10,    10,    83,   -60,    13,    94,
      94,    94,    94,    94,   -60,    75,    75,    85,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
      17,    38,    47,   -11,   -11,    41,    94,    94,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
      10,    52,    47,   -60,   -60,    47,   -60,   -60,   -60,   -60,
     -60
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     3,     4,    49,    42,     0,     0,     0,     0,     0,
       0,    20,    21,     0,     0,     0,    18,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,     0,     0,
       0,     0,     0,     0,     1,     2,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    37,
      38,    47,    48,    39,    43,    40,    44,    41,    45,    16,
       0,    49,     0,     0,     0,    51,     0,     0,    10,    11,
      12,     5,     6,    17,    24,    34,    25,    35,    23,    33,
      22,    32,    26,    36,    29,    30,    28,    27,    31,    15,
       0,     0,    53,    13,    14,     0,     8,     9,    54,    52,
      50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -15,   -19,    86,    59,   -20,   -60,   -60,   -21,     4,
      35,   -59,   -60,   -60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    13,    14,    27,    28,    15,    16,    17,    48,    49,
      50,    63,    64,    65
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,    52,    26,    92,    18,    34,    60,    37,    62,    35,
      66,    67,    68,    69,    70,     3,     4,    73,    61,     4,
      71,    72,    84,    85,    86,    87,    88,    53,    55,    57,
      18,    89,    18,    99,    36,    19,   100,    11,    12,    18,
      18,    18,    74,    76,    78,    80,    82,    96,    97,    20,
      21,    22,    91,    90,    23,    24,    25,    95,    54,    56,
      58,    19,     0,    19,    20,    21,    22,    90,     0,    98,
      19,    19,    19,    75,    77,    79,    81,    83,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,     3,     4,
       3,     4,    29,    30,    31,    32,    33,    59,     0,    11,
      12,     5,     6,     7,     8,     9,    10,    11,    12,    11,
      12,     0,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    93,    94
};

static const yytype_int8 yycheck[] =
{
      21,    22,    13,    62,     0,     0,    26,    23,    28,     3,
      29,    30,    31,    32,    33,     5,     6,    37,     5,     6,
      35,    36,    43,    44,    45,    46,    47,    23,    24,    25,
      26,    14,    28,    92,     3,     0,    95,    24,    25,    35,
      36,    37,    38,    39,    40,    41,    42,    66,    67,    26,
      27,    28,     5,    15,    26,    27,    28,    16,    23,    24,
      25,    26,    -1,    28,    26,    27,    28,    15,    -1,    90,
      35,    36,    37,    38,    39,    40,    41,    42,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     5,     6,
       5,     6,     6,     7,     8,     9,    10,    14,    -1,    24,
      25,     7,     8,     9,    10,    11,    12,    24,    25,    24,
      25,    -1,    17,    18,    19,    20,    21,    17,    18,    19,
      20,    21,    63,    64
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    24,    25,    30,    31,    34,    35,    36,    38,    39,
      26,    27,    28,    26,    27,    28,    13,    32,    33,    32,
      32,    32,    32,    32,     0,     3,     3,    23,    17,    18,
      19,    20,    21,    17,    18,    19,    20,    21,    37,    38,
      39,    37,    37,    38,    39,    38,    39,    38,    39,    14,
      34,     5,    34,    40,    41,    42,    31,    31,    31,    31,
      31,    30,    30,    34,    38,    39,    38,    39,    38,    39,
      38,    39,    38,    39,    37,    37,    37,    37,    37,    14,
      15,     5,    40,    33,    33,    16,    31,    31,    37,    40,
      40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    30,    30,    30,    30,    30,    31,    31,    31,
      31,    31,    31,    32,    32,    33,    33,    34,    34,    35,
      35,    35,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    37,    37,    38,
      38,    38,    38,    38,    38,    38,    39,    39,    39,    39,
      40,    40,    41,    41,    42
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     3,     3,     2,     4,     4,
       3,     3,     3,     3,     3,     3,     2,     3,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       3,     1,     3,     2,     3
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
        case 3:
#line 57 "verificateur.y" /* yacc.c:1646  */
    { /*cout << "Fin du programme" << endl; */ return 0; }
#line 1317 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 58 "verificateur.y" /* yacc.c:1646  */
    { /*cout << "Fin du programme" << endl; */ return 0; }
#line 1323 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 59 "verificateur.y" /* yacc.c:1646  */
    { /*cout << "Fin du programme" << endl; */ return 0; }
#line 1329 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 65 "verificateur.y" /* yacc.c:1646  */
    {
			string gener;
			gener = (yyvsp[0].triplet).postcondition.affirmation;
			remplacer(gener, (yyvsp[0].triplet).programme.instruction.variable, (yyvsp[0].triplet).programme.instruction.valeur);
			// Vérification syntaxique du triplet (les prédicats sont vérifiés syntaxiquement)
			if(gener.compare((yyvsp[0].triplet).precondition.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La précondition de AFF " << (yyvsp[0].triplet).precondition.affirmation << " est différente de " << gener << endl;
			}
			(yyval.triplet) = (yyvsp[0].triplet); // copie les prédicats et les programmes
		}
#line 1345 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 77 "verificateur.y" /* yacc.c:1646  */
    {
			// Précondition de la conclusion comparée avec la précondition de la prémisse (1)
			if((yyvsp[-2].triplet).precondition.affirmation.compare((yyvsp[-1].triplet).precondition.affirmation) != 0) 
			{
				cout << "[ERREUR][SYNTAXIQUE] La précondition de SEQ " << (yyvsp[-2].triplet).precondition.affirmation << " est différente de la précondition de la prémisse (1) " << (yyvsp[-1].triplet).precondition.affirmation << endl; 
			}
			// Postcondition de la conclusion comparée avec la postcondition de la prémisse (2)
			if((yyvsp[-2].triplet).postcondition.affirmation.compare((yyvsp[0].triplet).postcondition.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La postcondition de SEQ " << (yyvsp[-2].triplet).postcondition.affirmation << " est différente de la postcondition de la prémisse (2) " << (yyvsp[0].triplet).postcondition.affirmation << endl;
			}
			// Postcondition de la prémisse (1) comparée avec la précondition de la prémisse (2)
			if((yyvsp[-1].triplet).postcondition.affirmation.compare((yyvsp[0].triplet).precondition.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La postcondition de (1) " << (yyvsp[-1].triplet).postcondition.affirmation << " est différente de la précondition de la prémisse (2) " << (yyvsp[0].triplet).precondition.affirmation << endl;
			}
			// Programme de la conclusion comparé avec le programmes de la prémisse (1) et (2)
			if((yyvsp[-2].triplet).programme.contenu.compare((yyvsp[-1].triplet).programme.contenu + ";" + (yyvsp[0].triplet).programme.contenu) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Les programmes de SEQ sont incorrects : " << (yyvsp[-2].triplet).programme.contenu << " est différent de " << (yyvsp[-1].triplet).programme.contenu + ";" + (yyvsp[0].triplet).programme.contenu  << endl;
			}
			(yyval.triplet) = (yyvsp[-2].triplet); // copie les prédicats et les programmes
		}
#line 1373 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 101 "verificateur.y" /* yacc.c:1646  */
    {
			//  Précondition de la prémisse (1) comparée avec B et P de la conclusion
			if((yyvsp[-1].triplet).precondition.affirmation.compare((yyvsp[-2].triplet).programme.si.affirmation + "^" + (yyvsp[-2].triplet).precondition.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La précondition de la prémisse (1) de COND " << (yyvsp[-1].triplet).precondition.affirmation << " est différente de " << (yyvsp[-2].triplet).programme.si.affirmation << "^" << (yyvsp[-2].triplet).precondition.affirmation << endl;
			}
			//  Postcondition de la conclusion comparée avec la postcondition de la prémisse (1) puis (2)
			if((yyvsp[-2].triplet).postcondition.affirmation.compare((yyvsp[-1].triplet).postcondition.affirmation) != 0 && (yyvsp[-1].triplet).postcondition.affirmation.compare((yyvsp[0].triplet).postcondition.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Les postconditions de COND sont différentes : " << (yyvsp[-2].triplet).postcondition.affirmation << " != " << (yyvsp[-1].triplet).postcondition.affirmation << "!=" << (yyvsp[0].triplet).postcondition.affirmation << endl;
			}
			// Précondition de la prémisse (2) comparée avec NON B et P de la conclusion
			if((yyvsp[0].triplet).precondition.affirmation.compare((yyvsp[-2].triplet).programme.si.negation + "^" + (yyvsp[-2].triplet).precondition.affirmation) != 0) {
				cout << "[ERREUR][SYNTAXIQUE] La précondition de la prémisse (2) de COND " << (yyvsp[0].triplet).precondition.affirmation << " est différente de " << (yyvsp[-2].triplet).programme.si.negation << "^" << (yyvsp[-2].triplet).precondition.affirmation << endl;
			}
			// Programme ALORS de la conclusion comparé avec le programme de la prémisse (1)
			if((yyvsp[-2].triplet).programme.alors.compare((yyvsp[-1].triplet).programme.contenu) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Le programme de la conclusion de COND " << (yyvsp[-2].triplet).programme.alors << " est différent du programme de la prémisse (1) " << (yyvsp[-1].triplet).programme.contenu << endl;
			}
			// Programme SINON de la conclusion comparé avec le programme de la prémisse (2)
			if((yyvsp[-2].triplet).programme.sinon.compare((yyvsp[0].triplet).programme.contenu) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Le programme de la conclusion de COND " << (yyvsp[-2].triplet).programme.sinon << " est différent du programme de la prémisse (2) " << (yyvsp[0].triplet).programme.contenu << endl;
			}
			(yyval.triplet) = (yyvsp[-2].triplet); // copie les prédicats et les programmes
		}
#line 1405 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 129 "verificateur.y" /* yacc.c:1646  */
    {
			// Programme de la conclusion comparé avec le programme de la prémisse
			if((yyvsp[-1].triplet).programme.contenu.compare((yyvsp[0].triplet).programme.contenu) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Le programme de la conclusion de CONSEQ " << (yyvsp[-1].triplet).programme.contenu << " est différent du programme de la prémisse " << (yyvsp[0].triplet).programme.contenu << endl;
			}
			// Si les préconditions sont différentes alors on check si elles sont conséquences
			if((yyvsp[-1].triplet).precondition.affirmation.compare((yyvsp[0].triplet).precondition.affirmation) != 0) 
			{				
				// Valeur booléenne de la précondition de la conclusion comparée à la valeur booléenne de la précondition de la prémisse
				if((yyvsp[-1].triplet).precondition.valeur != (yyvsp[0].triplet).precondition.valeur)
				{
					cout << "[ATTENTION][SEMANTIQUE] La précondition de la conclusion " << (yyvsp[-1].triplet).precondition.affirmation << " n'implique peut-être pas la précondition de la prémisse " << (yyvsp[0].triplet).precondition.affirmation << endl;
				}
			}
			// Si les postcondition sont différentes alors on check si elles sont conséquences
			if((yyvsp[-1].triplet).postcondition.affirmation.compare((yyvsp[0].triplet).postcondition.affirmation) != 0)
			{				
				// Valeur booléenne du programme et de la postcondition de la prémisse comparée à la valeur booléenne de la postcondition de la conclusion
				if((yyvsp[0].triplet).postcondition.valeur != (yyvsp[-1].triplet).postcondition.valeur)
				{
					cout << "[ATTENTION][SEMANTIQUE] La postcondition de la prémisse " << (yyvsp[0].triplet).postcondition.affirmation << " n'implique peut-être pas la postcondition de la conclusion " << (yyvsp[-1].triplet).postcondition.affirmation << endl;
				}
			}
			(yyval.triplet) = (yyvsp[-1].triplet); // copie les prédicats et les programmes
			/*
			[ATTENTION] Limite de l'analyse : on ne peut pas automatiquement savoir si une formule en implique une autre.
			Comparer l'égalité de la valeur booléenne de chaque formule implique d'avoir repéré tous les cas où une formule est fausse (rendue fausse par deux conditions).
			Or, certaines conditions ne peuvent êtres vérifiées si elles ne sont pas composées que d'entiers :
			x>=y^x<=z => false si y>z (y et z entiers)
			x>y^x<z => false si y>=z (y et z entiers)
			x=y^x=z => false si y!=z
			Nous n'avons automatisé que les cas où une formule contient une condition et sa négation et où une formule contient le token faux.
			*/
		}
#line 1445 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 165 "verificateur.y" /* yacc.c:1646  */
    {
			//  Postcondition de la conclusion comparée avec NON B et I de la conclusion 
			if((yyvsp[-1].triplet).postcondition.affirmation.compare((yyvsp[-1].triplet).programme.tantque.negation + "^" + (yyvsp[-1].triplet).precondition.affirmation))
			{
				cout << "[ERREUR][SYNTAXIQUE] La postcondition de la conclusion de WHILE " << (yyvsp[-1].triplet).postcondition.affirmation << " est différente de " << (yyvsp[-1].triplet).programme.tantque.negation << "^" << (yyvsp[-1].triplet).precondition.affirmation << endl;
			}
			//  Précondition de la prémisse comparée avec I et B de la conclusion
			if((yyvsp[0].triplet).precondition.affirmation.compare((yyvsp[-1].triplet).precondition.affirmation + "^" + (yyvsp[-1].triplet).programme.tantque.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La précondition de la prémisse de WHILE " << (yyvsp[0].triplet).precondition.affirmation << " est différente de " << (yyvsp[-1].triplet).precondition.affirmation << "^" << (yyvsp[-1].triplet).programme.tantque.affirmation << endl;
			}
			// Postcondition de la prémisse comparée avec la précondition de la conclusion
			if((yyvsp[0].triplet).postcondition.affirmation.compare((yyvsp[-1].triplet).precondition.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La postcondition de la prémisse de WHILE " << (yyvsp[0].triplet).precondition.affirmation << " est différente de la précondition de la conclusion " << (yyvsp[-1].triplet).precondition.affirmation << endl;
			}
			// Programme FAIRE de la conclusion comparé avec le programme de la prémisse
			if((yyvsp[-1].triplet).programme.faire.compare((yyvsp[0].triplet).programme.contenu) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Le programme de la conclusion de WHILE " << (yyvsp[-1].triplet).programme.faire << " est différent du programme de la prémisse " << (yyvsp[0].triplet).programme.contenu << endl;
			}
			(yyval.triplet) = (yyvsp[-1].triplet); // copie les prédicats et les programmes
		}
#line 1473 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 189 "verificateur.y" /* yacc.c:1646  */
    {
			// Postcondition de la conclusion comparée avec NON B et I de la conclusion 
			if((yyvsp[-1].triplet).postcondition.affirmation.compare((yyvsp[-1].triplet).programme.tantque.negation + "^" + (yyvsp[-1].triplet).precondition.affirmation) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La postcondition de WHILET " << (yyvsp[-1].triplet).postcondition.affirmation << " est différente de " << (yyvsp[-1].triplet).programme.tantque.negation << "^" << (yyvsp[-1].triplet).precondition.affirmation << endl;
			}
			// Précondition de la prémisse contient avec I et B de la conclusion
			if((yyvsp[0].triplet).precondition.affirmation.find((yyvsp[-1].triplet).precondition.affirmation) == -1 && (yyvsp[0].triplet).precondition.affirmation.find((yyvsp[-1].triplet).programme.tantque.affirmation) == -1)
			{
				cout << "[ERREUR][SYNTAXIQUE] La précondition de la prémisse de WHILET " << (yyvsp[0].triplet).precondition.affirmation << " ne contient pas la précondition de la conclusion " << (yyvsp[-1].triplet).precondition.affirmation << " ou la condition de la conclusion " << (yyvsp[-1].triplet).programme.tantque.affirmation << endl;
			}
			string premPrec = (yyvsp[0].triplet).precondition.affirmation;
			premPrec.erase(0, (yyvsp[-1].triplet).precondition.affirmation.length()+1+(yyvsp[-1].triplet).programme.tantque.affirmation.length()+1);
			string variantVariable = "";
			string variantValeur = "";
			if(premPrec == "")
			{
				cout << "[ERREUR][SYNTAXIQUE] La précondition de la prémisse de WHILET " << (yyvsp[0].triplet).precondition.affirmation << " ne contiennent pas de variant de boucle" << endl;
			}
			else
			{
				variantVariable = variable(premPrec);
				variantValeur = premPrec;
			}
			if(variantVariable.compare("") == 0 || variantValeur.compare("") == 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Le variant de boucle de WHILET " << variantVariable << "=" << variantValeur << " n'est pas correct" << endl;
			}
			// Postcondition de la prémisse contient la précondition de la conclusion
			if((yyvsp[0].triplet).postcondition.affirmation.compare((yyvsp[-1].triplet).precondition.affirmation + "^" + variantVariable + "<" + variantValeur) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] La postcondition de la prémisse de WHILET " << (yyvsp[0].triplet).precondition.affirmation << " est différent de " << (yyvsp[-1].triplet).precondition.affirmation << "^" << variantVariable << "<" << variantValeur << endl;
			}
			// Programme FAIRE de la conclusion comparé avec le programme de la prémisse
			if((yyvsp[-1].triplet).programme.faire.compare((yyvsp[0].triplet).programme.contenu) != 0)
			{
				cout << "[ERREUR][SYNTAXIQUE] Le programme de la conclusion de WHILET " << (yyvsp[-1].triplet).programme.faire << " est différent du programme de la prémisse " << (yyvsp[0].triplet).programme.contenu << endl;
			}
			(yyval.triplet) = (yyvsp[-1].triplet); // copie les prédicats et les programmes
		}
#line 1518 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 233 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.triplet).precondition = (yyvsp[-2].proposition);
			(yyval.triplet).programme = (yyvsp[-1].programme);
			(yyval.triplet).postcondition = (yyvsp[0].proposition);
			// Le seul triplet invalide est de la forme {vrai} ... {faux}
			if((yyval.triplet).precondition.valeur == true && (yyval.triplet).postcondition.valeur == false)
			{
				cout << "[ATTENTION][SEMANTIQUE] Le triplet {" << (yyval.triplet).precondition.affirmation << "} prog {" << (yyval.triplet).postcondition.affirmation << "} n'est peut-être pas valide : ";
				cout << (yyval.triplet).precondition.affirmation << "->" << (yyval.triplet).postcondition.affirmation << "=faux : " << endl;
			}
			
			// Correction partielle :
			// Si la précondition est vraie pour tout état initial vérifiant la précondition et si l'exécution du programme se termine
			// Alors la précondition est vraie après l'exécution du programme
			// Correction totale :
			// Si la précondition est vraie pour tout état initial vérifiant la précondition
			// Alors l'exécution du programme se termine et la précondition est vraie après l'exécution du programme
			
			/*
			[ATTENTION] Limite de l'analyse : on ne peut pas automatiquement savoir si un triplet est valide.
			Nous ne pouvons pas vérifier la correction partielle et la correction totale d'un triplet (l'axiome AFF permet de vérifier syntaxiquement à défaut de pouvoir vérifier sémantiquement).
			*/
		}
#line 1546 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 257 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.triplet).precondition = (yyvsp[-2].proposition);
			(yyval.triplet).programme = (yyvsp[-1].programme);
			(yyval.triplet).postcondition = (yyvsp[0].proposition);
			// Le seul triplet invalide est de la forme {vrai} ... {faux}
			if((yyval.triplet).precondition.valeur == true && (yyval.triplet).postcondition.valeur == false)
			{
				cout << "[ATTENTION][SEMANTIQUE] Le triplet {" << (yyval.triplet).precondition.affirmation << "} prog {" << (yyval.triplet).postcondition.affirmation << "} n'est peut-être pas valide : ";
				cout << (yyval.triplet).precondition.affirmation << "->" << (yyval.triplet).postcondition.affirmation << "=faux : " << endl;
			}
		}
#line 1562 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 272 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.proposition) = (yyvsp[-1].proposition);
		}
#line 1570 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 276 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.proposition).valeur = true;
		}
#line 1578 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 283 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.proposition).affirmation = (yyvsp[-2].proposition).affirmation + "^" + (yyvsp[0].proposition).affirmation;
			(yyval.proposition).negation = (yyvsp[-2].proposition).negation + "^" + (yyvsp[0].proposition).negation;
			(yyval.proposition).valeur = (yyvsp[-2].proposition).valeur && (yyvsp[0].proposition).valeur;
			
			// Une formule qui contient une condition et sa négation est fausse
			int pos = ((yyval.proposition).affirmation.find((yyvsp[-2].proposition).negation));
			if(pos > -1) {
				(yyval.proposition).valeur = false;
			}
		}
#line 1594 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 295 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.proposition) = (yyvsp[0].proposition);
		}
#line 1602 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 302 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.proposition) = (yyvsp[0].proposition);
		}
#line 1610 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 306 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.proposition).affirmation = "vrai";
			(yyval.proposition).negation = "faux";
			(yyval.proposition).valeur = true;
		}
#line 1620 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 312 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.proposition).affirmation = "faux";
			(yyval.proposition).negation = "vrai";
			(yyval.proposition).valeur = false;
		}
#line 1630 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 321 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.proposition).affirmation = (yyvsp[-2].expression).chaine + "<" + (yyvsp[0].expression).chaine;
			(yyval.proposition).negation = (yyvsp[-2].expression).chaine + ">=" + (yyvsp[0].expression).chaine;
			(yyval.proposition).valeur = (yyvsp[-2].expression).valeur < (yyvsp[0].expression).valeur;
		}
#line 1640 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 327 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.proposition).affirmation = (yyvsp[-2].expression).chaine + ">" + (yyvsp[0].expression).chaine;
			(yyval.proposition).negation = (yyvsp[-2].expression).chaine + "<=" + (yyvsp[0].expression).chaine;
			(yyval.proposition).valeur = (yyvsp[-2].expression).valeur > (yyvsp[0].expression).valeur;
		}
#line 1650 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 333 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.proposition).affirmation = (yyvsp[-2].expression).chaine + "<=" + (yyvsp[0].expression).chaine;
			(yyval.proposition).negation = (yyvsp[-2].expression).chaine + ">" + (yyvsp[0].expression).chaine;
			(yyval.proposition).valeur = (yyvsp[-2].expression).valeur <= (yyvsp[0].expression).valeur;
		}
#line 1660 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 339 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.proposition).affirmation = (yyvsp[-2].expression).chaine + ">=" + (yyvsp[0].expression).chaine;
			(yyval.proposition).negation = (yyvsp[-2].expression).chaine + "<" + (yyvsp[0].expression).chaine;
			(yyval.proposition).valeur = (yyvsp[-2].expression).valeur >= (yyvsp[0].expression).valeur;
		}
#line 1670 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 345 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.proposition).affirmation = (yyvsp[-2].expression).chaine + "=" + (yyvsp[0].expression).chaine;
			(yyval.proposition).negation = (yyvsp[-2].expression).chaine + "!=" + (yyvsp[0].expression).chaine;
			(yyval.proposition).valeur = (yyvsp[-2].expression).valeur == (yyvsp[0].expression).valeur;
		}
#line 1680 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 350 "verificateur.y" /* yacc.c:1646  */
    { (yyval.proposition).affirmation = (yyvsp[-2].expression).chaine + "<" + (yyvsp[0].expression).chaine; 		(yyval.proposition).negation = (yyvsp[-2].expression).chaine + ">=" + (yyvsp[0].expression).chaine;		(yyval.proposition).valeur = true; }
#line 1686 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 351 "verificateur.y" /* yacc.c:1646  */
    { (yyval.proposition).affirmation = (yyvsp[-2].expression).chaine + ">" + (yyvsp[0].expression).chaine;			(yyval.proposition).negation = (yyvsp[-2].expression).chaine + "<=" + (yyvsp[0].expression).chaine;		(yyval.proposition).valeur = true; }
#line 1692 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 352 "verificateur.y" /* yacc.c:1646  */
    { (yyval.proposition).affirmation = (yyvsp[-2].expression).chaine + "<=" + (yyvsp[0].expression).chaine;		(yyval.proposition).negation = (yyvsp[-2].expression).chaine + ">" + (yyvsp[0].expression).chaine; 		(yyval.proposition).valeur = true; }
#line 1698 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 353 "verificateur.y" /* yacc.c:1646  */
    { (yyval.proposition).affirmation = (yyvsp[-2].expression).chaine + ">=" + (yyvsp[0].expression).chaine;		(yyval.proposition).negation = (yyvsp[-2].expression).chaine + "<" + (yyvsp[0].expression).chaine; 		(yyval.proposition).valeur = true; }
#line 1704 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 354 "verificateur.y" /* yacc.c:1646  */
    { (yyval.proposition).affirmation = (yyvsp[-2].expression).chaine + "=" + (yyvsp[0].expression).chaine;			(yyval.proposition).negation = (yyvsp[-2].expression).chaine + "!=" + (yyvsp[0].expression).chaine;		(yyval.proposition).valeur = true; }
#line 1710 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 355 "verificateur.y" /* yacc.c:1646  */
    { (yyval.proposition).affirmation = (yyvsp[-2].expression).chaine + "<" + (yyvsp[0].expression).chaine; 		(yyval.proposition).negation = (yyvsp[-2].expression).chaine + ">=" + (yyvsp[0].expression).chaine;		(yyval.proposition).valeur = true; }
#line 1716 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 356 "verificateur.y" /* yacc.c:1646  */
    { (yyval.proposition).affirmation = (yyvsp[-2].expression).chaine + ">" + (yyvsp[0].expression).chaine; 		(yyval.proposition).negation = (yyvsp[-2].expression).chaine + "<=" + (yyvsp[0].expression).chaine;		(yyval.proposition).valeur = true; }
#line 1722 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 357 "verificateur.y" /* yacc.c:1646  */
    { (yyval.proposition).affirmation = (yyvsp[-2].expression).chaine + "<=" + (yyvsp[0].expression).chaine;		(yyval.proposition).negation = (yyvsp[-2].expression).chaine + ">" + (yyvsp[0].expression).chaine; 		(yyval.proposition).valeur = true; }
#line 1728 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 358 "verificateur.y" /* yacc.c:1646  */
    { (yyval.proposition).affirmation = (yyvsp[-2].expression).chaine + ">=" + (yyvsp[0].expression).chaine;		(yyval.proposition).negation = (yyvsp[-2].expression).chaine + ">" + (yyvsp[0].expression).chaine; 		(yyval.proposition).valeur = true; }
#line 1734 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 359 "verificateur.y" /* yacc.c:1646  */
    { (yyval.proposition).affirmation = (yyvsp[-2].expression).chaine + "=" + (yyvsp[0].expression).chaine; 		(yyval.proposition).negation = (yyvsp[-2].expression).chaine + "!=" + (yyvsp[0].expression).chaine;		(yyval.proposition).valeur = true; }
#line 1740 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 369 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.expression).valeur = (yyvsp[-2].expression).valeur + (yyvsp[0].expression).valeur;
			(yyval.expression).chaine = to_string((yyval.expression).valeur);
		}
#line 1749 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 374 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.expression).valeur = (yyvsp[-2].expression).valeur - (yyvsp[0].expression).valeur;
			(yyval.expression).chaine = to_string((yyval.expression).valeur);
		}
#line 1758 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 379 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.expression).valeur = (yyvsp[-2].expression).valeur * (yyvsp[0].expression).valeur;
			(yyval.expression).chaine = to_string((yyval.expression).valeur);
		}
#line 1767 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 384 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.expression).valeur = (yyvsp[0].expression).valeur;
			(yyval.expression).chaine = (yyvsp[0].expression).chaine;
		}
#line 1776 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 389 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.expression).chaine = (yyvsp[-2].expression).chaine + "+" + (yyvsp[0].expression).chaine;
		}
#line 1784 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 393 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.expression).chaine = (yyvsp[-2].expression).chaine + "-" + (yyvsp[0].expression).chaine;
		}
#line 1792 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 397 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.expression).chaine = (yyvsp[-2].expression).chaine + "*" + (yyvsp[0].expression).chaine;
		}
#line 1800 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 404 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.expression).chaine = (yyvsp[-2].expression).chaine + "+" + (yyvsp[0].expression).chaine;
		}
#line 1808 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 408 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.expression).chaine = (yyvsp[-2].expression).chaine + "-" + (yyvsp[0].expression).chaine;
		}
#line 1816 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 412 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.expression).chaine = (yyvsp[-2].expression).chaine + "*" + (yyvsp[0].expression).chaine;
		}
#line 1824 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 416 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.expression).chaine = (yyvsp[0].expression).chaine;
		}
#line 1832 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 423 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.programme).contenu = (yyvsp[-2].instruction).variable + ":=" + (yyvsp[-2].instruction).valeur + ";" + (yyvsp[0].programme).contenu;
			(yyval.programme).instruction = (yyvsp[-2].instruction);
		}
#line 1841 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 428 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.programme).contenu = (yyvsp[0].instruction).variable + ":=" + (yyvsp[0].instruction).valeur;
			(yyval.programme).instruction = (yyvsp[0].instruction);
		}
#line 1850 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 436 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.programme).contenu = (yyvsp[-2].proposition).affirmation + " " + (yyvsp[-1].programme).contenu + " " + (yyvsp[0].programme).contenu;
			(yyval.programme).si = (yyvsp[-2].proposition);
			(yyval.programme).alors = (yyvsp[-1].programme).contenu;
			(yyval.programme).sinon = (yyvsp[0].programme).contenu;
		}
#line 1861 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 443 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.programme).contenu = (yyvsp[-1].proposition).affirmation + " " + (yyvsp[0].programme).contenu;
			(yyval.programme).si = (yyvsp[-1].proposition);
			(yyval.programme).alors = (yyvsp[0].programme).contenu;
			(yyval.programme).tantque = (yyvsp[-1].proposition);
			(yyval.programme).faire = (yyvsp[0].programme).contenu;
		}
#line 1873 "verificateur.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 454 "verificateur.y" /* yacc.c:1646  */
    {
			(yyval.instruction).variable = (yyvsp[-2].expression).chaine;
			(yyval.instruction).valeur = (yyvsp[0].expression).chaine;
		}
#line 1882 "verificateur.tab.c" /* yacc.c:1646  */
    break;


#line 1886 "verificateur.tab.c" /* yacc.c:1646  */
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
#line 460 "verificateur.y" /* yacc.c:1906  */


void yyerror(const string& mess) {
  cerr << "[ERREUR][YYERROR] " << mess << endl;
  cout << "[ERREUR] Erreur de syntaxe" << endl;
}

int main(int argc, char **argv) {
	// Lecture du fichier si envoyé
	if(argc == 2) {
		yyin = fopen(argv[1], "r");
		// cout << "\nFichier utilisé\nLecture de la preuve" << endl;
	}
		
	// Verification de la preuve
	yyparse();
		
	// Fin de la vérification de la preuve
	// cout << "Preuve lue en entier\nPreuve vérifiée si pas de message d'erreur" << endl;

	return EXIT_SUCCESS;
}
