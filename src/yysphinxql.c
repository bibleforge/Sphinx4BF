/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_IDENT = 258,
     TOK_ATIDENT = 259,
     TOK_CONST_INT = 260,
     TOK_CONST_FLOAT = 261,
     TOK_CONST_MVA = 262,
     TOK_QUOTED_STRING = 263,
     TOK_USERVAR = 264,
     TOK_SYSVAR = 265,
     TOK_CONST_STRINGS = 266,
     TOK_AS = 267,
     TOK_ASC = 268,
     TOK_ATTACH = 269,
     TOK_AVG = 270,
     TOK_BEGIN = 271,
     TOK_BETWEEN = 272,
     TOK_BY = 273,
     TOK_CALL = 274,
     TOK_COLLATION = 275,
     TOK_COMMIT = 276,
     TOK_COMMITTED = 277,
     TOK_COUNT = 278,
     TOK_CREATE = 279,
     TOK_DELETE = 280,
     TOK_DESC = 281,
     TOK_DESCRIBE = 282,
     TOK_DISTINCT = 283,
     TOK_DIV = 284,
     TOK_DROP = 285,
     TOK_FALSE = 286,
     TOK_FLOAT = 287,
     TOK_FLUSH = 288,
     TOK_FROM = 289,
     TOK_FUNCTION = 290,
     TOK_GLOBAL = 291,
     TOK_GROUP = 292,
     TOK_ID = 293,
     TOK_IN = 294,
     TOK_INDEX = 295,
     TOK_INSERT = 296,
     TOK_INT = 297,
     TOK_INTO = 298,
     TOK_ISOLATION = 299,
     TOK_LEVEL = 300,
     TOK_LIMIT = 301,
     TOK_MATCH = 302,
     TOK_MAX = 303,
     TOK_META = 304,
     TOK_MIN = 305,
     TOK_MOD = 306,
     TOK_NAMES = 307,
     TOK_NULL = 308,
     TOK_OPTION = 309,
     TOK_ORDER = 310,
     TOK_RAND = 311,
     TOK_READ = 312,
     TOK_REPEATABLE = 313,
     TOK_REPLACE = 314,
     TOK_RETURNS = 315,
     TOK_ROLLBACK = 316,
     TOK_RTINDEX = 317,
     TOK_SELECT = 318,
     TOK_SERIALIZABLE = 319,
     TOK_SET = 320,
     TOK_SESSION = 321,
     TOK_SHOW = 322,
     TOK_SONAME = 323,
     TOK_START = 324,
     TOK_STATUS = 325,
     TOK_SUM = 326,
     TOK_TABLES = 327,
     TOK_TO = 328,
     TOK_TRANSACTION = 329,
     TOK_TRUE = 330,
     TOK_UNCOMMITTED = 331,
     TOK_UPDATE = 332,
     TOK_VALUES = 333,
     TOK_VARIABLES = 334,
     TOK_WARNINGS = 335,
     TOK_WEIGHT = 336,
     TOK_WHERE = 337,
     TOK_WITHIN = 338,
     TOK_OR = 339,
     TOK_AND = 340,
     TOK_NE = 341,
     TOK_GTE = 342,
     TOK_LTE = 343,
     TOK_NOT = 344,
     TOK_NEG = 345
   };
#endif
#define TOK_IDENT 258
#define TOK_ATIDENT 259
#define TOK_CONST_INT 260
#define TOK_CONST_FLOAT 261
#define TOK_CONST_MVA 262
#define TOK_QUOTED_STRING 263
#define TOK_USERVAR 264
#define TOK_SYSVAR 265
#define TOK_CONST_STRINGS 266
#define TOK_AS 267
#define TOK_ASC 268
#define TOK_ATTACH 269
#define TOK_AVG 270
#define TOK_BEGIN 271
#define TOK_BETWEEN 272
#define TOK_BY 273
#define TOK_CALL 274
#define TOK_COLLATION 275
#define TOK_COMMIT 276
#define TOK_COMMITTED 277
#define TOK_COUNT 278
#define TOK_CREATE 279
#define TOK_DELETE 280
#define TOK_DESC 281
#define TOK_DESCRIBE 282
#define TOK_DISTINCT 283
#define TOK_DIV 284
#define TOK_DROP 285
#define TOK_FALSE 286
#define TOK_FLOAT 287
#define TOK_FLUSH 288
#define TOK_FROM 289
#define TOK_FUNCTION 290
#define TOK_GLOBAL 291
#define TOK_GROUP 292
#define TOK_ID 293
#define TOK_IN 294
#define TOK_INDEX 295
#define TOK_INSERT 296
#define TOK_INT 297
#define TOK_INTO 298
#define TOK_ISOLATION 299
#define TOK_LEVEL 300
#define TOK_LIMIT 301
#define TOK_MATCH 302
#define TOK_MAX 303
#define TOK_META 304
#define TOK_MIN 305
#define TOK_MOD 306
#define TOK_NAMES 307
#define TOK_NULL 308
#define TOK_OPTION 309
#define TOK_ORDER 310
#define TOK_RAND 311
#define TOK_READ 312
#define TOK_REPEATABLE 313
#define TOK_REPLACE 314
#define TOK_RETURNS 315
#define TOK_ROLLBACK 316
#define TOK_RTINDEX 317
#define TOK_SELECT 318
#define TOK_SERIALIZABLE 319
#define TOK_SET 320
#define TOK_SESSION 321
#define TOK_SHOW 322
#define TOK_SONAME 323
#define TOK_START 324
#define TOK_STATUS 325
#define TOK_SUM 326
#define TOK_TABLES 327
#define TOK_TO 328
#define TOK_TRANSACTION 329
#define TOK_TRUE 330
#define TOK_UNCOMMITTED 331
#define TOK_UPDATE 332
#define TOK_VALUES 333
#define TOK_VARIABLES 334
#define TOK_WARNINGS 335
#define TOK_WEIGHT 336
#define TOK_WHERE 337
#define TOK_WITHIN 338
#define TOK_OR 339
#define TOK_AND 340
#define TOK_NE 341
#define TOK_GTE 342
#define TOK_LTE 343
#define TOK_NOT 344
#define TOK_NEG 345




/* Copy the first part of user declarations.  */


#if USE_WINDOWS
#pragma warning(push,1)
#pragma warning(disable:4702) // unreachable code
#endif


// some helpers
#include <float.h> // for FLT_MAX



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */


#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  91
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   778

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  83
/* YYNRULES -- Number of rules. */
#define YYNRULES  235
/* YYNRULES -- Number of states. */
#define YYNSTATES  438

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   345

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    98,    87,     2,
     103,   104,    96,    94,   102,    95,     2,    97,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   101,
      90,    88,    91,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    86,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    89,    92,    93,    99,   100
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    38,
      40,    42,    44,    46,    50,    52,    54,    65,    67,    71,
      73,    76,    77,    79,    82,    84,    89,    94,    99,   104,
     109,   113,   119,   121,   125,   126,   128,   131,   133,   137,
     142,   146,   150,   156,   163,   167,   172,   178,   182,   186,
     190,   194,   198,   202,   206,   210,   216,   220,   224,   226,
     228,   233,   237,   239,   241,   244,   246,   249,   251,   255,
     256,   258,   262,   263,   265,   271,   272,   274,   278,   284,
     286,   290,   292,   295,   298,   299,   301,   304,   309,   310,
     312,   315,   317,   321,   325,   329,   335,   342,   346,   348,
     352,   356,   358,   360,   362,   364,   366,   368,   371,   374,
     378,   382,   386,   390,   394,   398,   402,   406,   410,   414,
     418,   422,   426,   430,   434,   438,   442,   446,   448,   453,
     458,   462,   469,   476,   478,   482,   484,   486,   489,   491,
     493,   495,   497,   499,   501,   503,   505,   510,   515,   520,
     524,   529,   537,   543,   545,   547,   549,   551,   553,   555,
     557,   559,   561,   564,   571,   573,   575,   576,   580,   582,
     586,   588,   592,   596,   598,   602,   604,   606,   608,   612,
     615,   623,   633,   640,   642,   646,   648,   652,   654,   658,
     659,   662,   664,   668,   672,   673,   675,   677,   679,   682,
     684,   686,   689,   695,   697,   701,   705,   709,   715,   720,
     724,   727,   734,   735,   737,   739,   742,   745,   748,   750,
     758,   760,   762,   766,   773,   777
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     106,     0,    -1,   107,    -1,   108,    -1,   108,   101,    -1,
     153,    -1,   161,    -1,   147,    -1,   148,    -1,   151,    -1,
     162,    -1,   171,    -1,   173,    -1,   174,    -1,   177,    -1,
     178,    -1,   182,    -1,   184,    -1,   185,    -1,   186,    -1,
     179,    -1,   187,    -1,   109,    -1,   108,   101,   109,    -1,
     110,    -1,   144,    -1,    63,   111,    34,   115,   116,   124,
     126,   128,   132,   134,    -1,   112,    -1,   111,   102,   112,
      -1,    96,    -1,   114,   113,    -1,    -1,     3,    -1,    12,
       3,    -1,   140,    -1,    15,   103,   140,   104,    -1,    48,
     103,   140,   104,    -1,    50,   103,   140,   104,    -1,    71,
     103,   140,   104,    -1,    23,   103,    96,   104,    -1,    81,
     103,   104,    -1,    23,   103,    28,     3,   104,    -1,     3,
      -1,   115,   102,     3,    -1,    -1,   117,    -1,    82,   118,
      -1,   119,    -1,   118,    85,   119,    -1,    47,   103,     8,
     104,    -1,   120,    88,   121,    -1,   120,    89,   121,    -1,
     120,    39,   103,   123,   104,    -1,   120,    99,    39,   103,
     123,   104,    -1,   120,    39,     9,    -1,   120,    99,    39,
       9,    -1,   120,    17,   121,    85,   121,    -1,   120,    91,
     121,    -1,   120,    90,   121,    -1,   120,    92,   121,    -1,
     120,    93,   121,    -1,   120,    88,   122,    -1,   120,    89,
     122,    -1,   120,    91,   122,    -1,   120,    90,   122,    -1,
     120,    17,   122,    85,   122,    -1,   120,    92,   122,    -1,
     120,    93,   122,    -1,     3,    -1,     4,    -1,    23,   103,
      96,   104,    -1,    81,   103,   104,    -1,    38,    -1,     5,
      -1,    95,     5,    -1,     6,    -1,    95,     6,    -1,   121,
      -1,   123,   102,   121,    -1,    -1,   125,    -1,    37,    18,
     120,    -1,    -1,   127,    -1,    83,    37,    55,    18,   130,
      -1,    -1,   129,    -1,    55,    18,   130,    -1,    55,    18,
      56,   103,   104,    -1,   131,    -1,   130,   102,   131,    -1,
     120,    -1,   120,    13,    -1,   120,    26,    -1,    -1,   133,
      -1,    46,     5,    -1,    46,     5,   102,     5,    -1,    -1,
     135,    -1,    54,   136,    -1,   137,    -1,   136,   102,   137,
      -1,     3,    88,     3,    -1,     3,    88,     5,    -1,     3,
      88,   103,   138,   104,    -1,     3,    88,     3,   103,     8,
     104,    -1,     3,    88,     8,    -1,   139,    -1,   138,   102,
     139,    -1,     3,    88,   121,    -1,     3,    -1,     4,    -1,
      38,    -1,     5,    -1,     6,    -1,     9,    -1,    95,   140,
      -1,    99,   140,    -1,   140,    94,   140,    -1,   140,    95,
     140,    -1,   140,    96,   140,    -1,   140,    97,   140,    -1,
     140,    90,   140,    -1,   140,    91,   140,    -1,   140,    87,
     140,    -1,   140,    86,   140,    -1,   140,    98,   140,    -1,
     140,    29,   140,    -1,   140,    51,   140,    -1,   140,    93,
     140,    -1,   140,    92,   140,    -1,   140,    88,   140,    -1,
     140,    89,   140,    -1,   140,    85,   140,    -1,   140,    84,
     140,    -1,   103,   140,   104,    -1,   141,    -1,     3,   103,
     142,   104,    -1,    39,   103,   142,   104,    -1,     3,   103,
     104,    -1,    50,   103,   140,   102,   140,   104,    -1,    48,
     103,   140,   102,   140,   104,    -1,   143,    -1,   142,   102,
     143,    -1,   140,    -1,     8,    -1,    67,   145,    -1,    80,
      -1,    70,    -1,    49,    -1,     3,    -1,    53,    -1,     8,
      -1,     5,    -1,     6,    -1,    65,     3,    88,   150,    -1,
      65,     3,    88,   149,    -1,    65,     3,    88,    53,    -1,
      65,    52,   146,    -1,    65,    10,    88,   146,    -1,    65,
      36,     9,    88,   103,   123,   104,    -1,    65,    36,     3,
      88,   149,    -1,     3,    -1,     8,    -1,    75,    -1,    31,
      -1,   121,    -1,    21,    -1,    61,    -1,   152,    -1,    16,
      -1,    69,    74,    -1,   154,    43,     3,   155,    78,   157,
      -1,    41,    -1,    59,    -1,    -1,   103,   156,   104,    -1,
     120,    -1,   156,   102,   120,    -1,   158,    -1,   157,   102,
     158,    -1,   103,   159,   104,    -1,   160,    -1,   159,   102,
     160,    -1,   121,    -1,   122,    -1,     8,    -1,   103,   123,
     104,    -1,   103,   104,    -1,    25,    34,     3,    82,    38,
      88,   121,    -1,    25,    34,     3,    82,    38,    39,   103,
     123,   104,    -1,    19,     3,   103,   163,   166,   104,    -1,
     164,    -1,   163,   102,   164,    -1,   160,    -1,   103,   165,
     104,    -1,     8,    -1,   165,   102,     8,    -1,    -1,   102,
     167,    -1,   168,    -1,   167,   102,   168,    -1,   160,   169,
     170,    -1,    -1,    12,    -1,     3,    -1,    46,    -1,   172,
       3,    -1,    27,    -1,    26,    -1,    67,    72,    -1,    77,
     115,    65,   175,   117,    -1,   176,    -1,   175,   102,   176,
      -1,     3,    88,   121,    -1,     3,    88,   122,    -1,     3,
      88,   103,   123,   104,    -1,     3,    88,   103,   104,    -1,
      67,   180,    79,    -1,    67,    20,    -1,    65,   180,    74,
      44,    45,   181,    -1,    -1,    36,    -1,    66,    -1,    57,
      76,    -1,    57,    22,    -1,    58,    57,    -1,    64,    -1,
      24,    35,     3,    60,   183,    68,     8,    -1,    42,    -1,
      32,    -1,    30,    35,     3,    -1,    14,    40,     3,    73,
      62,     3,    -1,    33,    62,     3,    -1,    63,    10,   132,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   119,   119,   120,   121,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   147,   148,   152,   153,   157,   172,   173,   177,
     178,   181,   183,   184,   188,   189,   190,   191,   192,   193,
     194,   195,   199,   200,   203,   205,   209,   213,   214,   218,
     223,   230,   238,   246,   255,   260,   265,   270,   275,   280,
     285,   290,   291,   292,   293,   298,   303,   308,   316,   317,
     322,   328,   334,   343,   344,   348,   349,   353,   359,   365,
     367,   371,   378,   380,   384,   390,   392,   396,   400,   407,
     408,   412,   413,   414,   417,   419,   423,   428,   435,   437,
     441,   445,   446,   450,   455,   460,   466,   471,   479,   484,
     491,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   531,   532,
     533,   534,   535,   539,   540,   544,   545,   551,   555,   556,
     557,   563,   564,   565,   566,   567,   571,   576,   581,   586,
     587,   591,   596,   604,   605,   609,   610,   611,   625,   626,
     627,   631,   632,   638,   646,   647,   650,   652,   656,   657,
     661,   662,   666,   670,   671,   675,   676,   677,   678,   679,
     685,   691,   703,   711,   715,   722,   723,   730,   740,   746,
     748,   752,   757,   761,   768,   770,   774,   775,   781,   789,
     790,   796,   802,   810,   811,   815,   819,   823,   827,   837,
     844,   851,   857,   858,   859,   863,   864,   865,   866,   872,
     883,   884,   888,   899,   911,   922
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_IDENT", "TOK_ATIDENT", 
  "TOK_CONST_INT", "TOK_CONST_FLOAT", "TOK_CONST_MVA", 
  "TOK_QUOTED_STRING", "TOK_USERVAR", "TOK_SYSVAR", "TOK_CONST_STRINGS", 
  "TOK_AS", "TOK_ASC", "TOK_ATTACH", "TOK_AVG", "TOK_BEGIN", 
  "TOK_BETWEEN", "TOK_BY", "TOK_CALL", "TOK_COLLATION", "TOK_COMMIT", 
  "TOK_COMMITTED", "TOK_COUNT", "TOK_CREATE", "TOK_DELETE", "TOK_DESC", 
  "TOK_DESCRIBE", "TOK_DISTINCT", "TOK_DIV", "TOK_DROP", "TOK_FALSE", 
  "TOK_FLOAT", "TOK_FLUSH", "TOK_FROM", "TOK_FUNCTION", "TOK_GLOBAL", 
  "TOK_GROUP", "TOK_ID", "TOK_IN", "TOK_INDEX", "TOK_INSERT", "TOK_INT", 
  "TOK_INTO", "TOK_ISOLATION", "TOK_LEVEL", "TOK_LIMIT", "TOK_MATCH", 
  "TOK_MAX", "TOK_META", "TOK_MIN", "TOK_MOD", "TOK_NAMES", "TOK_NULL", 
  "TOK_OPTION", "TOK_ORDER", "TOK_RAND", "TOK_READ", "TOK_REPEATABLE", 
  "TOK_REPLACE", "TOK_RETURNS", "TOK_ROLLBACK", "TOK_RTINDEX", 
  "TOK_SELECT", "TOK_SERIALIZABLE", "TOK_SET", "TOK_SESSION", "TOK_SHOW", 
  "TOK_SONAME", "TOK_START", "TOK_STATUS", "TOK_SUM", "TOK_TABLES", 
  "TOK_TO", "TOK_TRANSACTION", "TOK_TRUE", "TOK_UNCOMMITTED", 
  "TOK_UPDATE", "TOK_VALUES", "TOK_VARIABLES", "TOK_WARNINGS", 
  "TOK_WEIGHT", "TOK_WHERE", "TOK_WITHIN", "TOK_OR", "TOK_AND", "'|'", 
  "'&'", "'='", "TOK_NE", "'<'", "'>'", "TOK_GTE", "TOK_LTE", "'+'", 
  "'-'", "'*'", "'/'", "'%'", "TOK_NOT", "TOK_NEG", "';'", "','", "'('", 
  "')'", "$accept", "request", "statement", "multi_stmt_list", 
  "multi_stmt", "select_from", "select_items_list", "select_item", 
  "opt_alias", "select_expr", "ident_list", "opt_where_clause", 
  "where_clause", "where_expr", "where_item", "expr_ident", "const_int", 
  "const_float", "const_list", "opt_group_clause", "group_clause", 
  "opt_group_order_clause", "group_order_clause", "opt_order_clause", 
  "order_clause", "order_items_list", "order_item", "opt_limit_clause", 
  "limit_clause", "opt_option_clause", "option_clause", "option_list", 
  "option_item", "named_const_list", "named_const", "expr", "function", 
  "arglist", "arg", "show_stmt", "show_variable", "set_value", "set_stmt", 
  "set_global_stmt", "set_string_value", "boolean_value", "transact_op", 
  "start_transaction", "insert_into", "insert_or_replace", 
  "opt_column_list", "column_list", "insert_rows_list", "insert_row", 
  "insert_vals_list", "insert_val", "delete_from", "call_proc", 
  "call_args_list", "call_arg", "const_string_list", "opt_call_opts_list", 
  "call_opts_list", "call_opt", "opt_as", "call_opt_name", "describe", 
  "describe_tok", "show_tables", "update", "update_items_list", 
  "update_item", "show_variables", "show_collation", "set_transaction", 
  "opt_scope", "isolation_level", "create_function", "udf_type", 
  "drop_function", "attach_index", "flush_rtindex", "select_sysvar", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   124,    38,    61,   341,
      60,    62,   342,   343,    43,    45,    42,    47,    37,   344,
     345,    59,    44,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   105,   106,   106,   106,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   108,   108,   109,   109,   110,   111,   111,   112,
     112,   113,   113,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   115,   115,   116,   116,   117,   118,   118,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   120,   120,
     120,   120,   120,   121,   121,   122,   122,   123,   123,   124,
     124,   125,   126,   126,   127,   128,   128,   129,   129,   130,
     130,   131,   131,   131,   132,   132,   133,   133,   134,   134,
     135,   136,   136,   137,   137,   137,   137,   137,   138,   138,
     139,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   141,   141,
     141,   141,   141,   142,   142,   143,   143,   144,   145,   145,
     145,   146,   146,   146,   146,   146,   147,   147,   147,   147,
     147,   148,   148,   149,   149,   150,   150,   150,   151,   151,
     151,   152,   152,   153,   154,   154,   155,   155,   156,   156,
     157,   157,   158,   159,   159,   160,   160,   160,   160,   160,
     161,   161,   162,   163,   163,   164,   164,   165,   165,   166,
     166,   167,   167,   168,   169,   169,   170,   170,   171,   172,
     172,   173,   174,   175,   175,   176,   176,   176,   176,   177,
     178,   179,   180,   180,   180,   181,   181,   181,   181,   182,
     183,   183,   184,   185,   186,   187
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,    10,     1,     3,     1,
       2,     0,     1,     2,     1,     4,     4,     4,     4,     4,
       3,     5,     1,     3,     0,     1,     2,     1,     3,     4,
       3,     3,     5,     6,     3,     4,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     3,     3,     1,     1,
       4,     3,     1,     1,     2,     1,     2,     1,     3,     0,
       1,     3,     0,     1,     5,     0,     1,     3,     5,     1,
       3,     1,     2,     2,     0,     1,     2,     4,     0,     1,
       2,     1,     3,     3,     3,     5,     6,     3,     1,     3,
       3,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     4,     4,
       3,     6,     6,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     3,
       4,     7,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     6,     1,     1,     0,     3,     1,     3,
       1,     3,     3,     1,     3,     1,     1,     1,     3,     2,
       7,     9,     6,     1,     3,     1,     3,     1,     3,     0,
       2,     1,     3,     3,     0,     1,     1,     1,     2,     1,
       1,     2,     5,     1,     3,     3,     3,     5,     4,     3,
       2,     6,     0,     1,     1,     2,     2,     2,     1,     7,
       1,     1,     3,     6,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,   171,     0,   168,     0,     0,   210,   209,     0,
       0,   174,   175,   169,     0,   222,   222,     0,     0,     0,
       2,     3,    22,    24,    25,     7,     8,     9,   170,     5,
       0,     6,    10,    11,     0,    12,    13,    14,    15,    20,
      16,    17,    18,    19,    21,     0,     0,     0,     0,     0,
       0,   111,   112,   114,   115,   116,    94,     0,     0,   113,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
      27,    31,    34,   137,     0,     0,   223,     0,   224,     0,
     220,   223,   150,   149,   211,   148,   147,     0,   172,    42,
       0,     1,     4,     0,   208,     0,     0,     0,     0,   232,
     234,     0,     0,   235,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   118,     0,     0,     0,    32,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   151,   154,   155,   153,   152,   159,     0,
     219,     0,     0,     0,     0,    23,   176,     0,    73,    75,
     187,     0,     0,   185,   186,   195,   199,   193,     0,     0,
     146,   140,   145,     0,   143,    96,     0,     0,     0,     0,
       0,     0,     0,    40,     0,     0,   136,    44,    28,    33,
     128,   129,   135,   134,   126,   125,   132,   133,   123,   124,
     131,   130,   119,   120,   121,   122,   127,   163,   164,   166,
     158,   165,     0,   167,   157,   156,   160,     0,     0,     0,
       0,     0,   213,    43,     0,     0,     0,    74,    76,   197,
     189,    77,     0,     0,     0,     0,   231,   230,     0,     0,
       0,   138,     0,    35,     0,    39,   139,     0,    36,     0,
      37,    38,     0,     0,     0,    79,    45,   162,     0,     0,
       0,     0,   212,    68,    69,     0,    72,     0,   178,     0,
       0,   233,     0,   188,     0,   196,   195,   194,   200,   201,
     192,     0,     0,     0,   144,    97,    41,     0,     0,     0,
      46,    47,     0,     0,    82,    80,     0,     0,     0,   228,
     221,     0,   215,   216,   214,     0,     0,     0,   177,     0,
     173,   180,    78,   198,   205,     0,     0,   229,     0,   190,
     142,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    83,   161,   226,   225,
     227,   218,     0,     0,    71,   179,     0,     0,   183,     0,
     206,   207,   203,   204,   202,     0,     0,    48,     0,     0,
      54,     0,    50,    61,    51,    62,    58,    64,    57,    63,
      59,    66,    60,    67,     0,    81,     0,     0,    94,    86,
     217,    70,     0,   182,   181,   191,    49,     0,     0,     0,
      55,     0,     0,     0,    98,   184,    56,     0,    65,    52,
       0,     0,     0,    91,    87,    89,     0,    26,    99,    53,
      84,     0,    92,    93,     0,     0,   100,   101,    88,    90,
       0,     0,   103,   104,   107,     0,   102,     0,     0,     0,
     108,     0,     0,     0,   105,   106,   110,   109
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,    19,    20,    21,    22,    23,    69,    70,   121,    71,
      90,   255,   256,   290,   291,   403,   231,   164,   232,   294,
     295,   335,   336,   378,   379,   404,   405,   103,   104,   407,
     408,   416,   417,   429,   430,    72,    73,   173,   174,    24,
      86,   148,    25,    26,   214,   215,    27,    28,    29,    30,
     225,   269,   310,   311,   347,   165,    31,    32,   166,   167,
     233,   235,   278,   279,   315,   352,    33,    34,    35,    36,
     221,   222,    37,    38,    39,    79,   300,    40,   238,    41,
      42,    43,    44
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -243
static const short yypact[] =
{
     701,   -11,  -243,    52,  -243,    19,    83,  -243,  -243,   116,
     107,  -243,  -243,  -243,   156,   137,   683,    98,   182,   190,
    -243,    74,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
     155,  -243,  -243,  -243,   205,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,  -243,   215,   120,   216,   221,   222,
     236,   138,  -243,  -243,  -243,  -243,   194,   143,   154,  -243,
     177,   178,   181,   186,   187,   244,  -243,   244,   244,    -7,
    -243,   133,   494,  -243,   170,   197,    49,   121,  -243,   201,
    -243,  -243,  -243,  -243,  -243,  -243,  -243,   220,  -243,  -243,
     -49,  -243,    91,   297,  -243,   231,    16,   251,   238,  -243,
    -243,    93,   317,  -243,  -243,   244,    11,   258,   244,   244,
     244,   219,   223,   224,  -243,  -243,   326,   182,   206,  -243,
     321,  -243,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   147,
     121,   242,   243,  -243,  -243,  -243,  -243,  -243,  -243,   288,
    -243,   330,   331,   206,   -29,  -243,   232,   276,  -243,  -243,
    -243,   175,     9,  -243,  -243,  -243,   235,  -243,     8,   302,
    -243,  -243,   494,    40,  -243,   239,   349,   339,   240,    66,
     278,   299,   375,  -243,   244,   244,  -243,   -70,  -243,  -243,
    -243,  -243,   520,   543,   568,   591,   616,   616,   574,   574,
     574,   574,   -18,   -18,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,   340,  -243,  -243,  -243,  -243,   131,   245,   304,
     263,    51,  -243,  -243,   275,   274,   351,  -243,  -243,  -243,
    -243,  -243,    89,    97,    16,   254,  -243,  -243,   291,    42,
     258,  -243,   355,  -243,   277,  -243,  -243,   244,  -243,   244,
    -243,  -243,   446,   471,   179,   342,  -243,  -243,    -2,    99,
      25,   330,  -243,  -243,  -243,   295,  -243,   296,  -243,   103,
     303,  -243,    -2,  -243,   394,  -243,    45,  -243,   305,  -243,
    -243,   397,   306,    -2,  -243,  -243,  -243,   398,   423,   322,
     323,  -243,   226,   410,   346,  -243,   112,    34,   374,  -243,
    -243,    10,  -243,  -243,  -243,   336,   344,   275,  -243,    20,
     348,  -243,  -243,  -243,  -243,    46,    20,  -243,    -2,  -243,
    -243,  -243,   443,   179,    30,    -3,    30,    30,    30,    30,
      30,    30,   415,   275,   418,   401,  -243,  -243,  -243,  -243,
    -243,  -243,   134,   353,  -243,  -243,    14,   168,  -243,   303,
    -243,  -243,  -243,   464,  -243,   169,   354,  -243,   392,   393,
    -243,    -2,  -243,  -243,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,  -243,     0,  -243,   425,   463,   194,  -243,
    -243,  -243,    20,  -243,  -243,  -243,  -243,    -2,    17,   172,
    -243,    -2,   480,   265,   445,  -243,  -243,   495,  -243,  -243,
     191,   275,   400,   122,   402,  -243,   502,  -243,  -243,  -243,
     402,   420,  -243,  -243,   275,   437,   404,  -243,  -243,  -243,
       5,   502,   426,  -243,  -243,   523,  -243,   538,   440,   208,
    -243,   447,    -2,   523,  -243,  -243,  -243,  -243
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -243,  -243,  -243,  -243,   455,  -243,  -243,   432,  -243,  -243,
     435,  -243,   332,  -243,   247,  -217,   -96,  -242,  -224,  -243,
    -243,  -243,  -243,  -243,  -243,   153,   160,   198,  -243,  -243,
    -243,  -243,   174,  -243,   142,   -63,  -243,   470,   356,  -243,
    -243,   453,  -243,  -243,   381,  -243,  -243,  -243,  -243,  -243,
    -243,  -243,  -243,   250,  -243,  -233,  -243,  -243,  -243,   366,
    -243,  -243,  -243,   285,  -243,  -243,  -243,  -243,  -243,  -243,
    -243,   341,  -243,  -243,  -243,   588,  -243,  -243,  -243,  -243,
    -243,  -243,  -243
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -205
static const short yytable[] =
{
     163,   276,   114,   158,   115,   116,   360,   268,   422,   390,
     423,   122,   254,   424,   158,   158,   151,   229,   303,   158,
      82,   158,   159,   159,   160,   158,   159,   117,   160,    45,
     158,   159,   152,   123,   296,   158,   159,   292,   172,   177,
     236,    83,   176,   213,   172,   180,   181,   182,  -204,   350,
     237,    85,   141,   152,    47,    46,   338,   314,   142,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   348,   342,   136,   137,
     138,   282,   359,   353,   363,   365,   367,   369,   371,   373,
     345,  -204,   351,   212,   355,   118,    51,    52,    53,    54,
     361,   170,    55,   391,   212,   212,   292,   178,   425,   212,
     339,   161,   397,   230,   341,   161,   375,    48,   230,   162,
     161,   252,   253,   346,   143,   161,   144,   145,   301,   146,
     283,    59,    60,   254,   207,   412,   119,   389,   163,   208,
      74,   112,   240,   113,   241,   120,   398,    75,   413,   395,
     207,    49,   158,   261,   153,   208,   297,   298,   154,    51,
      52,    53,    54,   299,   302,    55,    56,   400,   240,    50,
     246,    57,    88,    76,   147,    92,   312,   172,   209,    58,
     227,   228,   263,   264,   287,    89,   288,   319,    65,    77,
      91,   272,    67,   273,    59,    60,    68,   171,    93,   274,
     210,   275,   265,    78,    61,   307,    62,   308,    94,    51,
      52,    53,    54,   163,   272,    55,   337,   266,    95,    97,
     163,    57,   211,    96,    98,    99,   289,    63,   358,    58,
     362,   364,   366,   368,   370,   372,   272,    64,   380,   100,
     102,   101,   212,   324,    59,    60,   105,    51,    52,    53,
      54,    65,    66,    55,    61,    67,    62,   106,   139,    68,
     267,    51,    52,    53,    54,   325,   170,    55,   263,   264,
     382,   272,   383,   385,   272,   149,   399,    63,   263,   264,
     107,   108,    59,    60,   109,   140,   163,    64,   265,   110,
     111,   396,   112,   272,   113,   409,    59,    60,   265,   150,
     156,    65,    66,   266,   157,    67,   112,   122,   113,    68,
     433,   168,   434,   266,   326,   327,   328,   329,   330,   331,
     169,   402,   175,   183,   189,   332,   184,   185,   122,   123,
     217,   218,   219,   220,   223,   224,   436,   234,   226,    65,
     239,   242,   244,    67,   245,   227,   267,    68,   258,   259,
     123,   260,   270,    65,   271,   122,   267,    67,   280,   281,
     285,    68,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   123,   122,   293,
     247,   286,   248,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   305,   306,
     123,   249,   313,   250,   122,   317,   309,   316,   323,   318,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   322,   123,   122,   333,   334,
     186,   340,   343,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   344,   123,
     349,   356,   122,   243,   374,   376,   377,   381,   386,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   123,   122,   314,   387,   388,   251,
     392,   393,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   123,   401,   406,
     122,   228,   320,   411,   414,   415,   421,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   123,   122,   418,   420,   428,   321,   432,   427,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   123,   431,   155,   247,   122,
     188,   435,   187,   262,   410,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     357,   123,   122,   249,   419,   437,   394,   179,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   216,   123,   426,   284,   122,   257,   384,
     277,   354,   304,   122,    87,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   123,
     122,     0,     0,     0,     0,   123,     0,     0,     0,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   123,     0,     0,   122,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   123,   134,   135,
     136,   137,   138,     0,     0,     0,     0,     0,     0,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,     0,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,     1,     0,     2,     0,    81,
       3,     0,     4,     0,     0,     5,     6,     7,     8,     0,
       0,     9,    82,     0,    10,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,    83,     0,    84,     0,     0,     0,     0,
      12,     0,    13,    85,    14,     0,    15,     0,    16,     0,
      17,     0,     0,     0,     0,     0,     0,     0,    18
};

static const short yycheck[] =
{
      96,   234,    65,     5,    67,    68,     9,   224,     3,     9,
       5,    29,    82,     8,     5,     5,    65,     8,   260,     5,
      49,     5,     6,     6,     8,     5,     6,    34,     8,    40,
       5,     6,   102,    51,   258,     5,     6,   254,   101,    28,
      32,    70,   105,   139,   107,   108,   109,   110,     3,     3,
      42,    80,     3,   102,    35,     3,    22,    12,     9,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   309,   301,    96,    97,
      98,    39,   324,   316,   326,   327,   328,   329,   330,   331,
     307,    46,    46,    95,   318,   102,     3,     4,     5,     6,
     103,     8,     9,   103,    95,    95,   323,    96,   103,    95,
      76,    95,    95,   104,   104,    95,   333,    34,   104,   103,
      95,   184,   185,   103,     3,    95,     5,     6,   103,     8,
      88,    38,    39,    82,     3,    13,     3,   361,   234,     8,
       3,    48,   102,    50,   104,    12,   388,    10,    26,   382,
       3,    35,     5,   102,    63,     8,    57,    58,    67,     3,
       4,     5,     6,    64,   260,     9,    10,   391,   102,    62,
     104,    15,    74,    36,    53,   101,   272,   240,    31,    23,
       5,     6,     3,     4,   247,     3,   249,   283,    95,    52,
       0,   102,    99,   104,    38,    39,   103,   104,    43,   102,
      53,   104,    23,    66,    48,   102,    50,   104,     3,     3,
       4,     5,     6,   309,   102,     9,   104,    38,     3,     3,
     316,    15,    75,   103,     3,     3,    47,    71,   324,    23,
     326,   327,   328,   329,   330,   331,   102,    81,   104,     3,
      46,   103,    95,    17,    38,    39,   103,     3,     4,     5,
       6,    95,    96,     9,    48,    99,    50,   103,    88,   103,
      81,     3,     4,     5,     6,    39,     8,     9,     3,     4,
     102,   102,   104,   104,   102,    74,   104,    71,     3,     4,
     103,   103,    38,    39,   103,    88,   382,    81,    23,   103,
     103,   387,    48,   102,    50,   104,    38,    39,    23,    79,
       3,    95,    96,    38,    73,    99,    48,    29,    50,   103,
     102,    60,   104,    38,    88,    89,    90,    91,    92,    93,
      82,    56,     5,   104,     3,    99,   103,   103,    29,    51,
      88,    88,    44,     3,     3,   103,   432,   102,    62,    95,
      38,   102,     3,    99,   104,     5,    81,   103,   103,    45,
      51,    88,    78,    95,     3,    29,    81,    99,   104,    68,
       5,   103,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    51,    29,    37,
     102,   104,   104,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   103,   103,
      51,   102,     8,   104,    29,     8,   103,   102,    85,   103,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,   103,    51,    29,    18,    83,
     104,    57,    96,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   104,    51,
     102,     8,    29,   104,    39,    37,    55,   104,   104,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    51,    29,    12,    85,    85,   104,
      55,    18,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    51,    18,    54,
      29,     6,   104,   103,   102,     3,   102,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    51,    29,   104,    88,     3,   104,    88,   103,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    51,     8,    92,   102,    29,
     118,   104,   117,   221,   401,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
     323,    51,    29,   102,   414,   433,   378,   107,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,   140,    51,   421,   240,    29,   217,   349,
     234,   316,   261,    29,    16,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    51,
      29,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    51,    -1,    -1,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    51,    94,    95,
      96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    14,    -1,    16,    -1,    36,
      19,    -1,    21,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    30,    49,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    -1,    70,    -1,    72,    -1,    -1,    -1,    -1,
      59,    -1,    61,    80,    63,    -1,    65,    -1,    67,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    14,    16,    19,    21,    24,    25,    26,    27,    30,
      33,    41,    59,    61,    63,    65,    67,    69,    77,   106,
     107,   108,   109,   110,   144,   147,   148,   151,   152,   153,
     154,   161,   162,   171,   172,   173,   174,   177,   178,   179,
     182,   184,   185,   186,   187,    40,     3,    35,    34,    35,
      62,     3,     4,     5,     6,     9,    10,    15,    23,    38,
      39,    48,    50,    71,    81,    95,    96,    99,   103,   111,
     112,   114,   140,   141,     3,    10,    36,    52,    66,   180,
      20,    36,    49,    70,    72,    80,   145,   180,    74,     3,
     115,     0,   101,    43,     3,     3,   103,     3,     3,     3,
       3,   103,    46,   132,   133,   103,   103,   103,   103,   103,
     103,   103,    48,    50,   140,   140,   140,    34,   102,     3,
      12,   113,    29,    51,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    88,
      88,     3,     9,     3,     5,     6,     8,    53,   146,    74,
      79,    65,   102,    63,    67,   109,     3,    73,     5,     6,
       8,    95,   103,   121,   122,   160,   163,   164,    60,    82,
       8,   104,   140,   142,   143,     5,   140,    28,    96,   142,
     140,   140,   140,   104,   103,   103,   104,   115,   112,     3,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   140,     3,     8,    31,
      53,    75,    95,   121,   149,   150,   146,    88,    88,    44,
       3,   175,   176,     3,   103,   155,    62,     5,     6,     8,
     104,   121,   123,   165,   102,   166,    32,    42,   183,    38,
     102,   104,   102,   104,     3,   104,   104,   102,   104,   102,
     104,   104,   140,   140,    82,   116,   117,   149,   103,    45,
      88,   102,   117,     3,     4,    23,    38,    81,   120,   156,
      78,     3,   102,   104,   102,   104,   160,   164,   167,   168,
     104,    68,    39,    88,   143,     5,   104,   140,   140,    47,
     118,   119,   120,    37,   124,   125,   123,    57,    58,    64,
     181,   103,   121,   122,   176,   103,   103,   102,   104,   103,
     157,   158,   121,     8,    12,   169,   102,     8,   103,   121,
     104,   104,   103,    85,    17,    39,    88,    89,    90,    91,
      92,    93,    99,    18,    83,   126,   127,   104,    22,    76,
      57,   104,   123,    96,   104,   120,   103,   159,   160,   102,
       3,    46,   170,   160,   168,   123,     8,   119,   121,   122,
       9,   103,   121,   122,   121,   122,   121,   122,   121,   122,
     121,   122,   121,   122,    39,   120,    37,    55,   128,   129,
     104,   104,   102,   104,   158,   104,   104,    85,    85,   123,
       9,   103,    55,    18,   132,   160,   121,    95,   122,   104,
     123,    18,    56,   120,   130,   131,    54,   134,   135,   104,
     130,   103,    13,    26,   102,     3,   136,   137,   104,   131,
      88,   102,     3,     5,     8,   103,   137,   103,     3,   138,
     139,     8,    88,   102,   104,   104,   121,   139
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror (pParser, "syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, pParser)
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
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse ( SqlParser_c * pParser );
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse ( SqlParser_c * pParser )
#else
int
yyparse (pParser)
     SqlParser_c * pParser ;
#endif
#endif
{
  /* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
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

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
        case 2:

    { pParser->PushQuery(); ;}
    break;

  case 22:

    { pParser->PushQuery(); ;}
    break;

  case 23:

    { pParser->PushQuery(); ;}
    break;

  case 26:

    {
			pParser->m_pStmt->m_eStmt = STMT_SELECT;
			pParser->m_pQuery->m_sIndexes.SetBinary ( pParser->m_pBuf+yyvsp[-6].m_iStart, yyvsp[-6].m_iEnd-yyvsp[-6].m_iStart );
		;}
    break;

  case 29:

    { pParser->AddItem ( &yyvsp[0] ); ;}
    break;

  case 32:

    { pParser->AliasLastItem ( &yyvsp[0] ); ;}
    break;

  case 33:

    { pParser->AliasLastItem ( &yyvsp[0] ); ;}
    break;

  case 34:

    { pParser->AddItem ( &yyvsp[0] ); ;}
    break;

  case 35:

    { pParser->AddItem ( &yyvsp[-1], SPH_AGGR_AVG, &yyvsp[-3], &yyvsp[0] ); ;}
    break;

  case 36:

    { pParser->AddItem ( &yyvsp[-1], SPH_AGGR_MAX, &yyvsp[-3], &yyvsp[0] ); ;}
    break;

  case 37:

    { pParser->AddItem ( &yyvsp[-1], SPH_AGGR_MIN, &yyvsp[-3], &yyvsp[0] ); ;}
    break;

  case 38:

    { pParser->AddItem ( &yyvsp[-1], SPH_AGGR_SUM, &yyvsp[-3], &yyvsp[0] ); ;}
    break;

  case 39:

    { if ( !pParser->AddItem ( "count(*)", &yyvsp[-3], &yyvsp[0] ) ) YYERROR; ;}
    break;

  case 40:

    { if ( !pParser->AddItem ( "weight()", &yyvsp[-2], &yyvsp[0] ) ) YYERROR; ;}
    break;

  case 41:

    { if ( !pParser->AddDistinct ( &yyvsp[-1], &yyvsp[-4], &yyvsp[0] ) ) YYERROR; ;}
    break;

  case 43:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 49:

    {
			if ( !pParser->SetMatch(yyvsp[-1]) )
				YYERROR;
		;}
    break;

  case 50:

    {
			CSphFilterSettings * pFilter = pParser->AddValuesFilter ( yyvsp[-2] );
			if ( !pFilter )
				YYERROR;
			pFilter->m_dValues.Add ( yyvsp[0].m_iValue );
		;}
    break;

  case 51:

    {
			CSphFilterSettings * pFilter = pParser->AddValuesFilter ( yyvsp[-2] );
			if ( !pFilter )
				YYERROR;
			pFilter->m_dValues.Add ( yyvsp[0].m_iValue );
			pFilter->m_bExclude = true;
		;}
    break;

  case 52:

    {
			CSphFilterSettings * pFilter = pParser->AddValuesFilter ( yyvsp[-4] );
			if ( !pFilter )
				YYERROR;
			pFilter->m_dValues = *yyvsp[-1].m_pValues.Ptr();
			pFilter->m_dValues.Sort();
		;}
    break;

  case 53:

    {
			CSphFilterSettings * pFilter = pParser->AddValuesFilter ( yyvsp[-5] );
			if ( !pFilter )
				YYERROR;
			pFilter->m_dValues = *yyvsp[-1].m_pValues.Ptr();
			pFilter->m_bExclude = true;
			pFilter->m_dValues.Sort();
		;}
    break;

  case 54:

    {
			if ( !pParser->AddUservarFilter ( yyvsp[-2].m_sValue, yyvsp[0].m_sValue, false ) )
				YYERROR;
		;}
    break;

  case 55:

    {
			if ( !pParser->AddUservarFilter ( yyvsp[-3].m_sValue, yyvsp[0].m_sValue, true ) )
				YYERROR;
		;}
    break;

  case 56:

    {
			if ( !pParser->AddUintRangeFilter ( yyvsp[-4].m_sValue, yyvsp[-2].m_iValue, yyvsp[0].m_iValue ) )
				YYERROR;
		;}
    break;

  case 57:

    {
			if ( !pParser->AddUintRangeFilter ( yyvsp[-2].m_sValue, yyvsp[0].m_iValue+1, UINT_MAX ) )
				YYERROR;
		;}
    break;

  case 58:

    {
			if ( !pParser->AddUintRangeFilter ( yyvsp[-2].m_sValue, 0, yyvsp[0].m_iValue-1 ) )
				YYERROR;
		;}
    break;

  case 59:

    {
			if ( !pParser->AddUintRangeFilter ( yyvsp[-2].m_sValue, yyvsp[0].m_iValue, UINT_MAX ) )
				YYERROR;
		;}
    break;

  case 60:

    {
			if ( !pParser->AddUintRangeFilter ( yyvsp[-2].m_sValue, 0, yyvsp[0].m_iValue ) )
				YYERROR;
		;}
    break;

  case 64:

    {
			yyerror ( pParser, "only >=, <=, and BETWEEN floating-point filter types are supported in this version" );
			YYERROR;
		;}
    break;

  case 65:

    {
			if ( !pParser->AddFloatRangeFilter ( yyvsp[-4].m_sValue, yyvsp[-2].m_fValue, yyvsp[0].m_fValue ) )
				YYERROR;
		;}
    break;

  case 66:

    {
			if ( !pParser->AddFloatRangeFilter ( yyvsp[-2].m_sValue, yyvsp[0].m_fValue, FLT_MAX ) )
				YYERROR;
		;}
    break;

  case 67:

    {
			if ( !pParser->AddFloatRangeFilter ( yyvsp[-2].m_sValue, -FLT_MAX, yyvsp[0].m_fValue ) )
				YYERROR;
		;}
    break;

  case 69:

    {
			if ( !pParser->SetOldSyntax() )
				YYERROR;
		;}
    break;

  case 70:

    {
			yyval.m_sValue = "@count";
			if ( !pParser->SetNewSyntax() )
				YYERROR;
		;}
    break;

  case 71:

    {
			yyval.m_sValue = "@weight";
			if ( !pParser->SetNewSyntax() )
				YYERROR;
		;}
    break;

  case 72:

    {
			yyval.m_sValue = "@id";
			if ( !pParser->SetNewSyntax() )
				YYERROR;
		;}
    break;

  case 73:

    { yyval.m_iInstype = TOK_CONST_INT; yyval.m_iValue = yyvsp[0].m_iValue; ;}
    break;

  case 74:

    { yyval.m_iInstype = TOK_CONST_INT; yyval.m_iValue = -yyvsp[0].m_iValue; ;}
    break;

  case 75:

    { yyval.m_iInstype = TOK_CONST_FLOAT; yyval.m_fValue = yyvsp[0].m_fValue; ;}
    break;

  case 76:

    { yyval.m_iInstype = TOK_CONST_FLOAT; yyval.m_fValue = -yyvsp[0].m_fValue; ;}
    break;

  case 77:

    {
			assert ( !yyval.m_pValues.Ptr() );
			yyval.m_pValues = new RefcountedVector_c<SphAttr_t> ();
			yyval.m_pValues->Add ( yyvsp[0].m_iValue ); 
		;}
    break;

  case 78:

    {
			yyval.m_pValues->Add ( yyvsp[0].m_iValue );
		;}
    break;

  case 81:

    {
			pParser->m_pQuery->m_eGroupFunc = SPH_GROUPBY_ATTR;
			pParser->m_pQuery->m_sGroupBy = yyvsp[0].m_sValue;
		;}
    break;

  case 84:

    {
			pParser->m_pQuery->m_sSortBy.SetBinary ( pParser->m_pBuf+yyvsp[0].m_iStart, yyvsp[0].m_iEnd-yyvsp[0].m_iStart );
		;}
    break;

  case 87:

    {
			pParser->m_pQuery->m_sOrderBy.SetBinary ( pParser->m_pBuf+yyvsp[0].m_iStart, yyvsp[0].m_iEnd-yyvsp[0].m_iStart );
		;}
    break;

  case 88:

    {
			pParser->m_pQuery->m_sOrderBy = "@random";
		;}
    break;

  case 90:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 92:

    { yyval = yyvsp[-1]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 93:

    { yyval = yyvsp[-1]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 96:

    {
			pParser->m_pQuery->m_iOffset = 0;
			pParser->m_pQuery->m_iLimit = yyvsp[0].m_iValue;
		;}
    break;

  case 97:

    {
			pParser->m_pQuery->m_iOffset = yyvsp[-2].m_iValue;
			pParser->m_pQuery->m_iLimit = yyvsp[0].m_iValue;
		;}
    break;

  case 103:

    {
			if ( !pParser->AddOption ( yyvsp[-2], yyvsp[0] ) )
				YYERROR;
		;}
    break;

  case 104:

    {
			if ( !pParser->AddOption ( yyvsp[-2], yyvsp[0] ) )
				YYERROR;
		;}
    break;

  case 105:

    {
			if ( !pParser->AddOption ( yyvsp[-4], pParser->GetNamedVec ( yyvsp[-1].m_iValue ) ) )
				YYERROR;
			pParser->FreeNamedVec ( yyvsp[-1].m_iValue );
		;}
    break;

  case 106:

    {
			if ( !pParser->AddOption ( yyvsp[-5], yyvsp[-2], yyvsp[-1].m_sValue ) )
				YYERROR;
		;}
    break;

  case 107:

    {
			if ( !pParser->AddOption ( yyvsp[-2], yyvsp[0] ) )
				YYERROR;
		;}
    break;

  case 108:

    {
			yyval.m_iValue = pParser->AllocNamedVec ();
			pParser->AddConst ( yyval.m_iValue, yyvsp[0] );
		;}
    break;

  case 109:

    {
			pParser->AddConst( yyval.m_iValue, yyvsp[0] );
		;}
    break;

  case 110:

    {
			yyval.m_sValue = yyvsp[-2].m_sValue;
			yyval.m_iValue = yyvsp[0].m_iValue;
		;}
    break;

  case 112:

    { if ( !pParser->SetOldSyntax() ) YYERROR; ;}
    break;

  case 113:

    { if ( !pParser->SetNewSyntax() ) YYERROR; ;}
    break;

  case 117:

    { yyval = yyvsp[-1]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 118:

    { yyval = yyvsp[-1]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 119:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 120:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 121:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 122:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 123:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 124:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 125:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 126:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 127:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 128:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 129:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 130:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 131:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 132:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 133:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 134:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 135:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 136:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 138:

    { yyval = yyvsp[-3]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 139:

    { yyval = yyvsp[-3]; yyval.m_iEnd = yyvsp[0].m_iEnd; ;}
    break;

  case 140:

    { yyval = yyvsp[-2]; yyval.m_iEnd = yyvsp[0].m_iEnd ;}
    break;

  case 141:

    { yyval = yyvsp[-5]; yyval.m_iEnd = yyvsp[0].m_iEnd ;}
    break;

  case 142:

    { yyval = yyvsp[-5]; yyval.m_iEnd = yyvsp[0].m_iEnd ;}
    break;

  case 148:

    { pParser->m_pStmt->m_eStmt = STMT_SHOW_WARNINGS; ;}
    break;

  case 149:

    { pParser->m_pStmt->m_eStmt = STMT_SHOW_STATUS; ;}
    break;

  case 150:

    { pParser->m_pStmt->m_eStmt = STMT_SHOW_META; ;}
    break;

  case 156:

    {
			pParser->SetStatement ( yyvsp[-2], SET_LOCAL );
			pParser->m_pStmt->m_iSetValue = yyvsp[0].m_iValue;
		;}
    break;

  case 157:

    {
			pParser->SetStatement ( yyvsp[-2], SET_LOCAL );
			pParser->m_pStmt->m_sSetValue = yyvsp[0].m_sValue;
		;}
    break;

  case 158:

    {
			pParser->SetStatement ( yyvsp[-2], SET_LOCAL );
			pParser->m_pStmt->m_bSetNull = true;
		;}
    break;

  case 159:

    { pParser->m_pStmt->m_eStmt = STMT_DUMMY; ;}
    break;

  case 160:

    { pParser->m_pStmt->m_eStmt = STMT_DUMMY; ;}
    break;

  case 161:

    {
			pParser->SetStatement ( yyvsp[-4], SET_GLOBAL_UVAR );
			pParser->m_pStmt->m_dSetValues = *yyvsp[-1].m_pValues.Ptr();
		;}
    break;

  case 162:

    {
			pParser->SetStatement ( yyvsp[-2], SET_GLOBAL_SVAR );
			pParser->m_pStmt->m_sSetValue = yyvsp[0].m_sValue;
		;}
    break;

  case 165:

    { yyval.m_iValue = 1; ;}
    break;

  case 166:

    { yyval.m_iValue = 0; ;}
    break;

  case 167:

    {
			yyval.m_iValue = yyvsp[0].m_iValue;
			if ( yyval.m_iValue!=0 && yyval.m_iValue!=1 )
			{
				yyerror ( pParser, "only 0 and 1 could be used as boolean values" );
				YYERROR;
			}
		;}
    break;

  case 168:

    { pParser->m_pStmt->m_eStmt = STMT_COMMIT; ;}
    break;

  case 169:

    { pParser->m_pStmt->m_eStmt = STMT_ROLLBACK; ;}
    break;

  case 170:

    { pParser->m_pStmt->m_eStmt = STMT_BEGIN; ;}
    break;

  case 173:

    {
			// everything else is pushed directly into parser within the rules
			pParser->m_pStmt->m_sIndex = yyvsp[-3].m_sValue;
		;}
    break;

  case 174:

    { pParser->m_pStmt->m_eStmt = STMT_INSERT; ;}
    break;

  case 175:

    { pParser->m_pStmt->m_eStmt = STMT_REPLACE; ;}
    break;

  case 178:

    { if ( !pParser->AddSchemaItem ( &yyvsp[0] ) ) { yyerror ( pParser, "unknown field" ); YYERROR; } ;}
    break;

  case 179:

    { if ( !pParser->AddSchemaItem ( &yyvsp[0] ) ) { yyerror ( pParser, "unknown field" ); YYERROR; } ;}
    break;

  case 182:

    { if ( !pParser->m_pStmt->CheckInsertIntegrity() ) { yyerror ( pParser, "wrong number of values here" ); YYERROR; } ;}
    break;

  case 183:

    { AddInsval ( pParser->m_pStmt->m_dInsertValues, yyvsp[0] ); ;}
    break;

  case 184:

    { AddInsval ( pParser->m_pStmt->m_dInsertValues, yyvsp[0] ); ;}
    break;

  case 185:

    { yyval.m_iInstype = TOK_CONST_INT; yyval.m_iValue = yyvsp[0].m_iValue; ;}
    break;

  case 186:

    { yyval.m_iInstype = TOK_CONST_FLOAT; yyval.m_fValue = yyvsp[0].m_fValue; ;}
    break;

  case 187:

    { yyval.m_iInstype = TOK_QUOTED_STRING; yyval.m_sValue = yyvsp[0].m_sValue; ;}
    break;

  case 188:

    { yyval.m_iInstype = TOK_CONST_MVA; yyval.m_pValues = yyvsp[-1].m_pValues; ;}
    break;

  case 189:

    { yyval.m_iInstype = TOK_CONST_MVA; ;}
    break;

  case 190:

    {
			pParser->m_pStmt->m_eStmt = STMT_DELETE;
			pParser->m_pStmt->m_sIndex = yyvsp[-4].m_sValue;
			pParser->m_pStmt->m_dDeleteIds.Add ( yyvsp[0].m_iValue );
		;}
    break;

  case 191:

    {
			pParser->m_pStmt->m_eStmt = STMT_DELETE;
			pParser->m_pStmt->m_sIndex = yyvsp[-6].m_sValue;
			for ( int i=0; i<yyvsp[-1].m_pValues.Ptr()->GetLength(); i++ )
				pParser->m_pStmt->m_dDeleteIds.Add ( (*yyvsp[-1].m_pValues.Ptr())[i] );
		;}
    break;

  case 192:

    {
			pParser->m_pStmt->m_eStmt = STMT_CALL;
			pParser->m_pStmt->m_sCallProc = yyvsp[-4].m_sValue;
		;}
    break;

  case 193:

    {
			AddInsval ( pParser->m_pStmt->m_dInsertValues, yyvsp[0] );
		;}
    break;

  case 194:

    {
			AddInsval ( pParser->m_pStmt->m_dInsertValues, yyvsp[0] );
		;}
    break;

  case 196:

    {
			yyval.m_iInstype = TOK_CONST_STRINGS;
		;}
    break;

  case 197:

    {
			// FIXME? for now, one such array per CALL statement, tops
			if ( pParser->m_pStmt->m_dCallStrings.GetLength() )
			{
				yyerror ( pParser, "unexpected constant string list" );
				YYERROR;
			}
			pParser->m_pStmt->m_dCallStrings.Add ( yyvsp[0].m_sValue );
		;}
    break;

  case 198:

    {
			pParser->m_pStmt->m_dCallStrings.Add ( yyvsp[0].m_sValue );
		;}
    break;

  case 201:

    {
			assert ( pParser->m_pStmt->m_dCallOptNames.GetLength()==1 );
			assert ( pParser->m_pStmt->m_dCallOptValues.GetLength()==1 );
		;}
    break;

  case 203:

    {
			pParser->m_pStmt->m_dCallOptNames.Add ( yyvsp[0].m_sValue );
			AddInsval ( pParser->m_pStmt->m_dCallOptValues, yyvsp[-2] );
		;}
    break;

  case 207:

    { yyval.m_sValue = "limit"; ;}
    break;

  case 208:

    {
			pParser->m_pStmt->m_eStmt = STMT_DESC;
			pParser->m_pStmt->m_sIndex = yyvsp[0].m_sValue;
		;}
    break;

  case 211:

    { pParser->m_pStmt->m_eStmt = STMT_SHOW_TABLES; ;}
    break;

  case 212:

    {
			if ( !pParser->UpdateStatement ( &yyvsp[-3] ) )
				YYERROR;
		;}
    break;

  case 215:

    {
			pParser->UpdateAttr ( yyvsp[-2].m_sValue, &yyvsp[0] );
		;}
    break;

  case 216:

    {
			pParser->UpdateAttr ( yyvsp[-2].m_sValue, &yyvsp[0], SPH_ATTR_FLOAT);
		;}
    break;

  case 217:

    {
			pParser->UpdateMVAAttr ( yyvsp[-4].m_sValue, yyvsp[-1] );
		;}
    break;

  case 218:

    {
			SqlNode_t tNoValues;
			pParser->UpdateMVAAttr ( yyvsp[-3].m_sValue, tNoValues );
		;}
    break;

  case 219:

    {
			pParser->m_pStmt->m_eStmt = STMT_SHOW_VARIABLES;
		;}
    break;

  case 220:

    {
			pParser->m_pStmt->m_eStmt = STMT_DUMMY;
		;}
    break;

  case 221:

    {
			pParser->m_pStmt->m_eStmt = STMT_DUMMY;
		;}
    break;

  case 229:

    {
			SqlStmt_t & tStmt = *pParser->m_pStmt;
			tStmt.m_eStmt = STMT_CREATE_FUNC;
			tStmt.m_sUdfName = yyvsp[-4].m_sValue;
			tStmt.m_sUdfLib = yyvsp[0].m_sValue;
			tStmt.m_eUdfType = (ESphAttr) yyvsp[-2].m_iValue;
		;}
    break;

  case 230:

    { yyval.m_iValue = SPH_ATTR_INTEGER; ;}
    break;

  case 231:

    { yyval.m_iValue = SPH_ATTR_FLOAT; ;}
    break;

  case 232:

    {
			SqlStmt_t & tStmt = *pParser->m_pStmt;
			tStmt.m_eStmt = STMT_DROP_FUNC;
			tStmt.m_sUdfName = yyvsp[0].m_sValue;
		;}
    break;

  case 233:

    {
			SqlStmt_t & tStmt = *pParser->m_pStmt;
			tStmt.m_eStmt = STMT_ATTACH_INDEX;
			tStmt.m_sIndex = yyvsp[-3].m_sValue;
			tStmt.m_sSetName = yyvsp[0].m_sValue;
		;}
    break;

  case 234:

    {
			SqlStmt_t & tStmt = *pParser->m_pStmt;
			tStmt.m_eStmt = STMT_FLUSH_RTINDEX;
			tStmt.m_sIndex = yyvsp[0].m_sValue;
		;}
    break;

  case 235:

    {
			pParser->m_pStmt->m_eStmt = STMT_DUMMY;
		;}
    break;


    }

/* Line 991 of yacc.c.  */


  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 4)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      else
		{
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			snprintf (yyp, (int)(yysize - (yyp - yymsg)), ", expecting %s (or %d other tokens)", yytname[yyx], yycount - 1);
			while (*yyp++);
			break;
		      }
		}

	      yyerror (pParser, yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror (pParser, "syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (pParser, "syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
//  __attribute__ ((__unused__))
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror (pParser, "parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}





#if USE_WINDOWS
#pragma warning(pop)
#endif

