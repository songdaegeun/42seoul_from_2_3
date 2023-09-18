/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     INTIGER = 259,
     INT_CONSTANT = 260,
     CHAR_CONSTANT = 261,
     STRING_CONSTANT = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LE_OP = 265,
     GE_OP = 266,
     EQ_OP = 267,
     NE_OP = 268,
     AND_OP = 269,
     OR_OP = 270,
     MUL_ASSIGN = 271,
     DIV_ASSIGN = 272,
     MOD_ASSIGN = 273,
     ADD_ASSIGN = 274,
     SUB_ASSIGN = 275,
     TYPE_NAME = 276,
     TYPEDEF = 277,
     CHAR = 278,
     INT = 279,
     VOID = 280,
     ELIPSIS = 281,
     IF = 282,
     ELSE = 283,
     WHILE = 284,
     DO = 285,
     FOR = 286,
     CONTINUE = 287,
     BREAK = 288,
     RETURN = 289
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INTIGER 259
#define INT_CONSTANT 260
#define CHAR_CONSTANT 261
#define STRING_CONSTANT 262
#define INC_OP 263
#define DEC_OP 264
#define LE_OP 265
#define GE_OP 266
#define EQ_OP 267
#define NE_OP 268
#define AND_OP 269
#define OR_OP 270
#define MUL_ASSIGN 271
#define DIV_ASSIGN 272
#define MOD_ASSIGN 273
#define ADD_ASSIGN 274
#define SUB_ASSIGN 275
#define TYPE_NAME 276
#define TYPEDEF 277
#define CHAR 278
#define INT 279
#define VOID 280
#define ELIPSIS 281
#define IF 282
#define ELSE 283
#define WHILE 284
#define DO 285
#define FOR 286
#define CONTINUE 287
#define BREAK 288
#define RETURN 289




/* Copy the first part of user declarations.  */


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 175 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   855

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNRULES -- Number of states.  */
#define YYNSTATES  270

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,     2,     2,    46,    40,     2,
      35,    36,    41,    42,    39,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    52,
      47,    51,    48,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    17,    19,
      24,    28,    33,    36,    39,    41,    45,    47,    50,    53,
      56,    58,    60,    62,    64,    66,    68,    73,    75,    79,
      83,    87,    89,    93,    97,    99,   103,   107,   111,   115,
     117,   121,   125,   127,   131,   133,   137,   139,   145,   147,
     151,   153,   155,   157,   159,   161,   163,   165,   169,   171,
     174,   178,   180,   183,   185,   188,   190,   194,   196,   200,
     202,   204,   206,   208,   210,   213,   215,   219,   223,   228,
     232,   237,   242,   244,   247,   250,   254,   256,   259,   261,
     265,   267,   271,   273,   277,   279,   283,   286,   288,   290,
     293,   295,   297,   300,   304,   307,   311,   315,   320,   323,
     327,   331,   336,   338,   342,   347,   349,   353,   355,   357,
     359,   361,   363,   366,   370,   374,   379,   381,   384,   386,
     389,   391,   394,   400,   408,   414,   422,   429,   437,   445,
     454,   462,   471,   480,   490,   493,   496,   499,   503,   505,
     508,   510,   512,   515,   519,   521,   524
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
     100,     0,    -1,   104,    -1,     4,    -1,     5,    -1,     6,
      -1,     7,    -1,    35,    71,    36,    -1,    56,    -1,    57,
      37,    71,    38,    -1,    57,    35,    36,    -1,    57,    35,
      58,    36,    -1,    57,     8,    -1,    57,     9,    -1,    69,
      -1,    58,    39,    69,    -1,    57,    -1,     8,    59,    -1,
       9,    59,    -1,    60,    61,    -1,    40,    -1,    41,    -1,
      42,    -1,    43,    -1,    44,    -1,    59,    -1,    35,    87,
      36,    61,    -1,    61,    -1,    62,    41,    61,    -1,    62,
      45,    61,    -1,    62,    46,    61,    -1,    62,    -1,    63,
      42,    62,    -1,    63,    43,    62,    -1,    63,    -1,    64,
      47,    63,    -1,    64,    48,    63,    -1,    64,    10,    63,
      -1,    64,    11,    63,    -1,    64,    -1,    65,    12,    64,
      -1,    65,    13,    64,    -1,    65,    -1,    66,    14,    65,
      -1,    66,    -1,    67,    15,    66,    -1,    67,    -1,    67,
      49,    67,    50,    68,    -1,    68,    -1,    59,    70,    69,
      -1,    51,    -1,    16,    -1,    17,    -1,    18,    -1,    19,
      -1,    20,    -1,    69,    -1,    71,    39,    69,    -1,    68,
      -1,    74,    52,    -1,    74,    75,    52,    -1,    22,    -1,
      22,    74,    -1,    77,    -1,    77,    74,    -1,    76,    -1,
      75,    39,    76,    -1,    78,    -1,    78,    51,    90,    -1,
      23,    -1,    24,    -1,    25,    -1,    21,    -1,    79,    -1,
      80,    79,    -1,   104,    -1,    35,    78,    36,    -1,    79,
      37,    38,    -1,    79,    37,    72,    38,    -1,    79,    35,
      36,    -1,    79,    35,    84,    36,    -1,    79,    35,    82,
      36,    -1,    41,    -1,    41,    81,    -1,    41,    80,    -1,
      41,    81,    80,    -1,    77,    -1,    81,    77,    -1,    83,
      -1,    83,    39,    26,    -1,   104,    -1,    83,    39,   104,
      -1,    85,    -1,    85,    39,    26,    -1,    86,    -1,    85,
      39,    86,    -1,    81,    78,    -1,    87,    -1,    81,    -1,
      81,    88,    -1,    80,    -1,    89,    -1,    80,    89,    -1,
      35,    88,    36,    -1,    37,    38,    -1,    37,    72,    38,
      -1,    89,    37,    38,    -1,    89,    37,    72,    38,    -1,
      35,    36,    -1,    35,    84,    36,    -1,    89,    35,    36,
      -1,    89,    35,    84,    36,    -1,    69,    -1,    53,    91,
      54,    -1,    53,    91,    39,    54,    -1,    90,    -1,    91,
      39,    90,    -1,    93,    -1,    96,    -1,    97,    -1,    98,
      -1,    99,    -1,    53,    54,    -1,    53,    95,    54,    -1,
      53,    94,    54,    -1,    53,    94,    95,    54,    -1,    73,
      -1,    94,    73,    -1,    92,    -1,    95,    92,    -1,    52,
      -1,    71,    52,    -1,    27,    35,    71,    36,    92,    -1,
      27,    35,    71,    36,    92,    28,    92,    -1,    29,    35,
      71,    36,    92,    -1,    30,    92,    29,    35,    71,    36,
      52,    -1,    31,    35,    52,    52,    36,    92,    -1,    31,
      35,    52,    52,    71,    36,    92,    -1,    31,    35,    52,
      71,    52,    36,    92,    -1,    31,    35,    52,    71,    52,
      71,    36,    92,    -1,    31,    35,    71,    52,    52,    36,
      92,    -1,    31,    35,    71,    52,    52,    71,    36,    92,
      -1,    31,    35,    71,    52,    71,    52,    36,    92,    -1,
      31,    35,    71,    52,    71,    52,    71,    36,    92,    -1,
      32,    52,    -1,    33,    52,    -1,    34,    52,    -1,    34,
      71,    52,    -1,   101,    -1,   100,   101,    -1,   102,    -1,
      73,    -1,    78,   103,    -1,    74,    78,   103,    -1,    93,
      -1,    94,    93,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    17,    17,    18,    19,    20,    21,    22,    26,    27,
      28,    29,    30,    31,    35,    36,    40,    41,    42,    43,
      47,    48,    49,    50,    51,    55,    56,    60,    61,    62,
      63,    67,    68,    69,    73,    74,    75,    76,    77,    81,
      82,    83,    87,    88,    92,    93,    97,    98,   102,   103,
     107,   108,   109,   110,   111,   112,   116,   117,   121,   125,
     126,   130,   131,   132,   133,   137,   138,   142,   143,   147,
     148,   149,   150,   154,   155,   159,   160,   161,   162,   163,
     164,   165,   169,   170,   171,   172,   176,   177,   181,   182,
     186,   187,   191,   192,   196,   197,   201,   202,   206,   207,
     211,   212,   213,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   229,   230,   231,   235,   236,   240,   241,   242,
     243,   244,   248,   249,   250,   251,   255,   256,   260,   261,
     265,   266,   270,   271,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   288,   289,   290,   291,   295,   296,
     300,   301,   305,   306,   310,   311,   315
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTIGER", "INT_CONSTANT",
  "CHAR_CONSTANT", "STRING_CONSTANT", "INC_OP", "DEC_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "TYPE_NAME", "TYPEDEF", "CHAR",
  "INT", "VOID", "ELIPSIS", "IF", "ELSE", "WHILE", "DO", "FOR", "CONTINUE",
  "BREAK", "RETURN", "'('", "')'", "'['", "']'", "','", "'&'", "'*'",
  "'+'", "'-'", "'!'", "'/'", "'%'", "'<'", "'>'", "'?'", "':'", "'='",
  "';'", "'{'", "'}'", "$accept", "primary_expr", "postfix_expr",
  "argument_expr_list", "unary_expr", "unary_operator", "cast_expr",
  "multiplicative_expr", "additive_expr", "relational_expr",
  "equality_expr", "logical_and_expr", "logical_or_expr",
  "conditional_expr", "assignment_expr", "assignment_operator", "expr",
  "constant_expr", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "type_specifier",
  "declarator", "declarator2", "pointer", "type_specifier_list",
  "parameter_identifier_list", "identifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "type_name",
  "abstract_declarator", "abstract_declarator2", "initializer",
  "initializer_list", "statement", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement", "file",
  "external_definition", "function_definition", "function_body",
  "identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    40,    41,    91,    93,    44,
      38,    42,    43,    45,    33,    47,    37,    60,    62,    63,
      58,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    57,    57,    57,    58,    58,    59,    59,    59,    59,
      60,    60,    60,    60,    60,    61,    61,    62,    62,    62,
      62,    63,    63,    63,    64,    64,    64,    64,    64,    65,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    70,    71,    71,    72,    73,
      73,    74,    74,    74,    74,    75,    75,    76,    76,    77,
      77,    77,    77,    78,    78,    79,    79,    79,    79,    79,
      79,    79,    80,    80,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    85,    86,    86,    87,    87,
      88,    88,    88,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    91,    91,    92,    92,    92,
      92,    92,    93,    93,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    99,    99,    99,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   104
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     4,
       3,     4,     2,     2,     1,     3,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     4,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       3,     1,     2,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     2,     1,     3,     3,     4,     3,
       4,     4,     1,     2,     2,     3,     1,     2,     1,     3,
       1,     3,     1,     3,     1,     3,     2,     1,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     2,     3,     3,     4,     1,     2,     1,     2,
       1,     2,     5,     7,     5,     7,     6,     7,     7,     8,
       7,     8,     8,     9,     2,     2,     2,     3,     1,     2,
       1,     1,     2,     3,     1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   156,    72,    61,    69,    70,    71,     0,    82,   151,
       0,    63,     0,    73,     0,     0,   148,   150,    75,    62,
       0,    86,    84,    83,    59,     0,    65,    67,    64,     0,
     126,     0,   154,     0,   152,     0,     0,    74,     1,   149,
      76,    87,    85,     0,    60,     0,   153,     3,     4,     5,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    21,    22,    23,    24,   130,   122,     8,    16,
      25,     0,    27,    31,    34,    39,    42,    44,    46,    48,
      56,     0,   128,   117,     0,     0,   118,   119,   120,   121,
       2,    67,   127,   155,    79,    98,     0,    88,     0,    92,
      94,    97,    90,    77,    25,    58,     0,    66,     0,   112,
      68,     0,    17,    18,     0,     0,     0,     0,   144,   145,
     146,     0,     0,    98,     0,    12,    13,     0,     0,    51,
      52,    53,    54,    55,    50,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,   124,     0,   123,   129,     0,     0,    96,
     100,    99,   101,    81,     0,    80,     0,    78,   115,     0,
       0,     0,     0,     0,     0,   147,     7,     0,   100,     0,
      10,     0,    14,     0,    49,    28,    29,    30,    32,    33,
      37,    38,    35,    36,    40,    41,    43,    45,     0,    57,
     125,   108,     0,     0,   104,     0,   102,     0,     0,    89,
      91,    93,    95,     0,   113,     0,     0,     0,     0,     0,
       0,    26,    11,     0,     9,     0,   109,   103,   105,   110,
       0,   106,     0,   114,   116,   132,   134,     0,     0,     0,
       0,     0,     0,    15,    47,   111,   107,     0,     0,   136,
       0,     0,     0,     0,     0,     0,   133,   135,   137,   138,
       0,   140,     0,     0,     0,   139,   141,   142,     0,   143
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    68,    69,   181,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,   135,    81,   106,    30,    31,
      25,    26,    11,    12,    13,    14,    95,    96,    97,   202,
      99,   100,   101,   161,   162,   110,   169,    82,    83,    33,
      85,    86,    87,    88,    89,    15,    16,    17,    34,    90
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -145
static const yytype_int16 yypact[] =
{
      17,  -145,  -145,   300,  -145,  -145,  -145,    24,   148,  -145,
      10,   300,   336,    93,    19,   790,  -145,  -145,  -145,  -145,
     -11,  -145,  -145,   148,  -145,   -18,  -145,   193,  -145,   218,
    -145,    10,  -145,   336,  -145,    81,   577,    93,  -145,  -145,
    -145,  -145,  -145,    24,  -145,   415,  -145,  -145,  -145,  -145,
    -145,   756,   756,    -6,    40,   401,    45,    77,   113,   457,
     567,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,   112,
      74,   766,  -145,   165,   114,     8,   266,   183,    22,  -145,
    -145,    59,  -145,  -145,   260,   302,  -145,  -145,  -145,  -145,
    -145,   126,  -145,  -145,  -145,   799,   168,   180,   202,   196,
    -145,  -145,  -145,  -145,  -145,  -145,   236,  -145,   415,  -145,
    -145,   766,  -145,  -145,   766,   766,   251,   470,  -145,  -145,
    -145,    62,    -4,   814,   250,  -145,  -145,   590,   766,  -145,
    -145,  -145,  -145,  -145,  -145,   766,  -145,   766,   766,   766,
     766,   766,   766,   766,   766,   766,   766,   766,   766,   766,
     766,   766,  -145,  -145,   344,  -145,  -145,   446,   632,  -145,
      46,  -145,   219,  -145,    47,  -145,   294,  -145,  -145,    73,
     115,   145,   281,   512,    70,  -145,  -145,   502,   220,   766,
    -145,   152,  -145,   288,  -145,  -145,  -145,  -145,   165,   165,
     114,   114,   114,   114,     8,     8,   266,   183,    18,  -145,
    -145,  -145,   292,   305,  -145,   334,   219,   252,   642,  -145,
    -145,  -145,  -145,   359,  -145,   401,   401,   766,   652,    71,
     525,  -145,  -145,   766,  -145,   766,  -145,  -145,  -145,  -145,
     345,  -145,   342,  -145,  -145,   310,  -145,   163,   401,   173,
     694,   704,   116,  -145,  -145,  -145,  -145,   401,   278,  -145,
     401,   401,   192,   401,   194,   714,  -145,  -145,  -145,  -145,
     401,  -145,   401,   401,   198,  -145,  -145,  -145,   401,  -145
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,  -145,    -5,  -145,   -61,   199,   154,   223,
     234,   241,   233,   -32,   -38,  -145,   -54,  -144,    11,   179,
    -145,   348,    -7,     5,   -12,     1,     9,  -145,  -145,   -27,
    -145,   226,   333,  -134,   -93,  -105,  -145,   -55,   119,   366,
     327,  -145,  -145,  -145,  -145,  -145,   399,  -145,   388,    72
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     116,    21,    37,   168,   105,   121,   122,   109,    98,    22,
     136,     9,    20,     1,   205,    27,    41,    23,   142,   143,
       1,    43,     1,   203,    42,    40,     9,     1,    21,   114,
     156,   104,   176,   149,    44,   151,    91,   149,     2,     3,
       4,     5,     6,   203,    92,     7,   112,   113,    91,     1,
       1,     8,     7,    21,     7,   144,   145,   122,     8,     7,
     170,   171,    24,   174,   232,     8,   104,   206,   225,   123,
     109,   150,    18,   209,   183,   115,   185,   186,   187,    18,
     117,   157,    18,   158,     1,   206,    18,    18,    41,   182,
     129,   130,   131,   132,   133,    92,   160,   184,   151,   156,
     159,   151,     2,    18,     4,     5,     6,   102,   234,   151,
     151,   152,   213,   199,   175,    18,    41,    94,   221,   219,
     125,   126,   220,   240,   178,   134,   105,   214,    35,   118,
      36,    32,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,    32,   127,    37,   128,
      21,   215,    93,   104,   151,   151,   140,   141,   160,    21,
     235,   236,    20,   237,   239,   119,   242,    18,   255,     2,
      21,     4,     5,     6,   104,   109,   105,    45,   178,    10,
     230,   216,    19,   249,   151,   243,   252,   254,   222,     8,
      28,   223,   256,   244,    10,   258,   259,   148,   261,   248,
      21,   264,   151,   104,   163,   265,   137,   266,   267,   250,
     138,   139,   151,   269,     2,     3,     4,     5,     6,   164,
     104,     1,    47,    48,    49,    50,    51,    52,   260,    18,
     262,   151,    18,   151,   268,   166,   210,   151,   165,     2,
       3,     4,     5,     6,    45,    53,    29,    54,    55,    56,
      57,    58,    59,    60,   207,   177,   208,   158,    61,    62,
      63,    64,    65,     1,    47,    48,    49,    50,    51,    52,
      66,    29,    67,     2,   167,     4,     5,     6,   146,   147,
     172,     2,     3,     4,     5,     6,   179,    53,   229,    54,
      55,    56,    57,    58,    59,    60,   190,   191,   192,   193,
      61,    62,    63,    64,    65,     1,    47,    48,    49,    50,
      51,    52,    66,    29,   153,     2,   217,     4,     5,     6,
     211,     2,     3,     4,     5,     6,   224,   151,   226,    53,
     257,    54,    55,    56,    57,    58,    59,    60,   247,   188,
     189,   227,    61,    62,    63,    64,    65,     1,    47,    48,
      49,    50,    51,    52,    66,    29,   155,     2,     3,     4,
       5,     6,     1,    47,    48,    49,    50,    51,    52,   194,
     195,    53,   228,    54,    55,    56,    57,    58,    59,    60,
     246,   245,   196,   198,    61,    62,    63,    64,    65,    29,
     197,   107,   212,   124,    60,    84,    66,    29,   200,    61,
      62,    63,    64,    65,     1,    47,    48,    49,    50,    51,
      52,   154,   108,   233,    39,    46,     0,     0,     1,    47,
      48,    49,    50,    51,    52,     0,     0,     0,    53,     0,
      54,    55,    56,    57,    58,    59,    60,     0,     0,     0,
       0,    61,    62,    63,    64,    65,     0,     0,     0,     1,
      60,     0,     0,    66,    29,    61,    62,    63,    64,    65,
       1,    47,    48,    49,    50,    51,    52,     2,   108,     4,
       5,     6,     0,     1,    47,    48,    49,    50,    51,    52,
       0,   157,   201,   158,     0,     0,     0,     8,     0,     0,
       0,     0,    60,     0,     0,     0,     0,    61,    62,    63,
      64,    65,     0,     0,     0,    60,     0,     0,     0,   120,
      61,    62,    63,    64,    65,     1,    47,    48,    49,    50,
      51,    52,   173,     2,     0,     4,     5,     6,     1,    47,
      48,    49,    50,    51,    52,     0,     0,   177,   201,   158,
       0,     0,     0,     8,     0,     0,     0,    60,     0,     0,
       0,     0,    61,    62,    63,    64,    65,     0,     0,     0,
      60,     0,     0,     0,   218,    61,    62,    63,    64,    65,
       1,    47,    48,    49,    50,    51,    52,   241,     0,     0,
       1,    47,    48,    49,    50,    51,    52,     0,     2,     0,
       4,     5,     6,     1,    47,    48,    49,    50,    51,    52,
       0,     0,    60,     0,     0,     0,     0,    61,    62,    63,
      64,    65,    60,     0,     0,   103,     0,    61,    62,    63,
      64,    65,     0,     0,     0,    60,   180,     0,     0,     0,
      61,    62,    63,    64,    65,     1,    47,    48,    49,    50,
      51,    52,     0,     0,     0,     1,    47,    48,    49,    50,
      51,    52,     0,     0,     0,     1,    47,    48,    49,    50,
      51,    52,     0,     0,     0,     0,     0,    60,     0,     0,
     204,     0,    61,    62,    63,    64,    65,    60,     0,     0,
     231,     0,    61,    62,    63,    64,    65,    60,   238,     0,
       0,     0,    61,    62,    63,    64,    65,     1,    47,    48,
      49,    50,    51,    52,     0,     0,     0,     1,    47,    48,
      49,    50,    51,    52,     0,     0,     0,     1,    47,    48,
      49,    50,    51,    52,     0,     0,     0,     0,     0,    60,
     251,     0,     0,     0,    61,    62,    63,    64,    65,    60,
     253,     0,     0,     0,    61,    62,    63,    64,    65,    60,
     263,     0,     0,     0,    61,    62,    63,    64,    65,     1,
      47,    48,    49,    50,    51,    52,     0,     0,     0,     1,
      47,    48,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,   111,     0,     1,     0,     0,    61,    62,    63,    64,
      65,    60,     1,     0,     0,     0,    61,    62,    63,    64,
      65,     2,     3,     4,     5,     6,     0,     0,     0,     0,
       2,     0,     4,     5,     6,     7,     0,     0,     0,     0,
       0,     8,     0,     0,   157,     2,   158,     4,     5,     6,
       8,     0,     0,     0,     0,     0,     0,     0,     0,   177,
       0,   158,     0,     0,     0,     8
};

static const yytype_int16 yycheck[] =
{
      55,     8,    14,   108,    36,    59,    60,    45,    35,     8,
      71,     0,     7,     3,   158,    10,    23,     8,    10,    11,
       3,    39,     3,   157,    23,    36,    15,     3,    35,    35,
      85,    36,    36,    15,    52,    39,    31,    15,    21,    22,
      23,    24,    25,   177,    33,    35,    51,    52,    43,     3,
       3,    41,    35,    60,    35,    47,    48,   111,    41,    35,
     114,   115,    52,   117,   208,    41,    71,   160,    50,    60,
     108,    49,     0,    26,   128,    35,   137,   138,   139,     7,
      35,    35,    10,    37,     3,   178,    14,    15,    95,   127,
      16,    17,    18,    19,    20,    84,    95,   135,    39,   154,
      95,    39,    21,    31,    23,    24,    25,    35,   213,    39,
      39,    52,    39,   151,    52,    43,   123,    36,   179,   173,
       8,     9,    52,    52,   123,    51,   158,    54,    35,    52,
      37,    12,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,    27,    35,   160,    37,
     157,    36,    33,   158,    39,    39,    42,    43,   157,   166,
     215,   216,   157,   217,   218,    52,   220,    95,    52,    21,
     177,    23,    24,    25,   179,   213,   208,    51,   177,     0,
     207,    36,     3,   238,    39,   223,   240,   241,    36,    41,
      11,    39,   247,   225,    15,   250,   251,    14,   253,    36,
     207,   255,    39,   208,    36,   260,    41,   262,   263,    36,
      45,    46,    39,   268,    21,    22,    23,    24,    25,    39,
     225,     3,     4,     5,     6,     7,     8,     9,    36,   157,
      36,    39,   160,    39,    36,    39,   164,    39,    36,    21,
      22,    23,    24,    25,    51,    27,    53,    29,    30,    31,
      32,    33,    34,    35,    35,    35,    37,    37,    40,    41,
      42,    43,    44,     3,     4,     5,     6,     7,     8,     9,
      52,    53,    54,    21,    38,    23,    24,    25,    12,    13,
      29,    21,    22,    23,    24,    25,    36,    27,    36,    29,
      30,    31,    32,    33,    34,    35,   142,   143,   144,   145,
      40,    41,    42,    43,    44,     3,     4,     5,     6,     7,
       8,     9,    52,    53,    54,    21,    35,    23,    24,    25,
      26,    21,    22,    23,    24,    25,    38,    39,    36,    27,
      52,    29,    30,    31,    32,    33,    34,    35,    28,   140,
     141,    36,    40,    41,    42,    43,    44,     3,     4,     5,
       6,     7,     8,     9,    52,    53,    54,    21,    22,    23,
      24,    25,     3,     4,     5,     6,     7,     8,     9,   146,
     147,    27,    38,    29,    30,    31,    32,    33,    34,    35,
      38,    36,   148,   150,    40,    41,    42,    43,    44,    53,
     149,    43,   166,    60,    35,    29,    52,    53,    54,    40,
      41,    42,    43,    44,     3,     4,     5,     6,     7,     8,
       9,    84,    53,    54,    15,    27,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,     3,
      35,    -1,    -1,    52,    53,    40,    41,    42,    43,    44,
       3,     4,     5,     6,     7,     8,     9,    21,    53,    23,
      24,    25,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    35,    36,    37,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    35,    -1,    -1,    -1,    52,
      40,    41,    42,    43,    44,     3,     4,     5,     6,     7,
       8,     9,    52,    21,    -1,    23,    24,    25,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    35,    36,    37,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    52,    40,    41,    42,    43,    44,
       3,     4,     5,     6,     7,     8,     9,    52,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    21,    -1,
      23,    24,    25,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    40,    41,    42,
      43,    44,    35,    -1,    -1,    38,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      38,    -1,    40,    41,    42,    43,    44,    35,    -1,    -1,
      38,    -1,    40,    41,    42,    43,    44,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    43,    44,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    43,    44,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    43,    44,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    43,    44,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       0,    35,    -1,     3,    -1,    -1,    40,    41,    42,    43,
      44,    35,     3,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      21,    -1,    23,    24,    25,    35,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    35,    21,    37,    23,    24,    25,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    37,    -1,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    21,    22,    23,    24,    25,    35,    41,    73,
      74,    77,    78,    79,    80,   100,   101,   102,   104,    74,
      78,    77,    80,    81,    52,    75,    76,    78,    74,    53,
      73,    74,    93,    94,   103,    35,    37,    79,     0,   101,
      36,    77,    80,    39,    52,    51,   103,     4,     5,     6,
       7,     8,     9,    27,    29,    30,    31,    32,    33,    34,
      35,    40,    41,    42,    43,    44,    52,    54,    56,    57,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    71,    92,    93,    94,    95,    96,    97,    98,    99,
     104,    78,    73,    93,    36,    81,    82,    83,    84,    85,
      86,    87,   104,    38,    59,    68,    72,    76,    53,    69,
      90,    35,    59,    59,    35,    35,    92,    35,    52,    52,
      52,    71,    71,    81,    87,     8,     9,    35,    37,    16,
      17,    18,    19,    20,    51,    70,    61,    41,    45,    46,
      42,    43,    10,    11,    47,    48,    12,    13,    14,    15,
      49,    39,    52,    54,    95,    54,    92,    35,    37,    78,
      80,    88,    89,    36,    39,    36,    39,    38,    90,    91,
      71,    71,    29,    52,    71,    52,    36,    35,    80,    36,
      36,    58,    69,    71,    69,    61,    61,    61,    62,    62,
      63,    63,    63,    63,    64,    64,    65,    66,    67,    69,
      54,    36,    84,    88,    38,    72,    89,    35,    37,    26,
     104,    26,    86,    39,    54,    36,    36,    35,    52,    71,
      52,    61,    36,    39,    38,    50,    36,    36,    38,    36,
      84,    38,    72,    54,    90,    92,    92,    71,    36,    71,
      52,    52,    71,    69,    68,    36,    38,    28,    36,    92,
      36,    36,    71,    36,    71,    52,    92,    52,    92,    92,
      36,    92,    36,    36,    71,    92,    92,    92,    36,    92
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      
/* Line 1267 of yacc.c.  */
#line 1751 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 317 "gram.y"


#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

