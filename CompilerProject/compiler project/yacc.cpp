/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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

/* Bison version.  */
#define YYBISON_VERSION "2.1"

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
     _def_val_2 = 258,
     test0 = 259,
     test2 = 260,
     test = 261,
     _def_val_ = 262,
     test3 = 263,
     T_INCLUDE_ONCE = 264,
     T_INCLUDE = 265,
     T_LOGICAL_OR = 266,
     T_LOGICAL_XOR = 267,
     T_LOGICAL_AND = 268,
     T_DOUBLE_ARROW = 269,
     T_POW_EQUAL = 270,
     T_SR_EQUAL = 271,
     T_XOR_EQUAL = 272,
     T_OR_EQUAL = 273,
     T_AND_EQUAL = 274,
     T_MOD_EQUAL = 275,
     T_CONCAT_EQUAL = 276,
     T_DIV_EQUAL = 277,
     T_MUL_EQUAL = 278,
     T_MINUS_EQUAL = 279,
     T_PLUS_EQUAL = 280,
     T_COALESCE = 281,
     T_BOOLEAN_OR = 282,
     T_BOOLEAN_AND = 283,
     T_IS_NOT_EQUAL = 284,
     T_IS_EQUAL = 285,
     T_IS_GREATER_OR_EQUAL = 286,
     T_IS_SMALLER_OR_EQUAL = 287,
     T_SR = 288,
     T_SL = 289,
     T_BOOL_CAST = 290,
     T_STRING_CAST = 291,
     T_DOUBLE_CAST = 292,
     T_INT_CAST = 293,
     T_DEC = 294,
     T_INC = 295,
     T_POW = 296,
     T_CLONE = 297,
     T_NEW = 298,
     T_IF = 299,
     elseif_list_test = 300,
     T_ELSEIF = 302,
     T_ELSE = 304,
     T_LNUMBER = 305,
     T_DNUMBER = 306,
     T_STRING = 307,
     T_VARIABLE = 308,
     T_NUM_STRING = 309,
     T_ENCAPSED_AND_WHITESPACE = 310,
     T_CONSTANT_ENCAPSED_STRING = 311,
     T_TRUE = 312,
     T_FALSE = 313,
     T_NULL = 314,
     T_SUPER = 315,
     T_READ_INT = 316,
     T_READ_DOUBLE = 317,
     T_READ_STRING = 318,
     T_ECHO = 319,
     T_DO = 320,
     T_WHILE = 321,
     T_ENDWHILE = 322,
     T_FOR = 323,
     T_ENDFOR = 324,
     T_FOREACH = 325,
     T_ENDFOREACH = 326,
     T_AS = 327,
     T_SWITCH = 328,
     T_ENDSWITCH = 329,
     T_CASE = 330,
     T_DEFAULT = 331,
     T_BREAK = 332,
     T_CONTINUE = 333,
     T_GOTO = 334,
     T_FUNCTION = 335,
     T_CONST = 336,
     T_RETURN = 337,
     T_TRY = 338,
     T_CATCH = 339,
     T_FINALLY = 340,
     T_THROW = 341,
     T_PUBLIC = 342,
     T_PROTECTED = 343,
     T_PRIVATE = 344,
     T_FINAL = 345,
     T_ABSTRACT = 346,
     T_STATIC = 347,
     T_CLASS = 348,
     T_INTERFACE = 349,
     T_EXTENDS = 350,
     T_IMPLEMENTS = 351,
     T_OBJECT_OPERATOR = 352,
     T_OPEN_TAG_PHP = 353,
     T_CLOSE_TAG_PHP = 354,
     T_PAAMAYIM_NEKUDOTAYIM = 355,
     T_ELLIPSIS = 356,
     T_V_INT = 357,
     T_V_STRING = 358,
     T_V_BOOL = 359,
     T_V_CHAR = 360,
     T_V_DOUBLE = 361,
     T_V_FLOAT = 362,
     T_V_REAL = 363,
     T_V_LONG = 364,
     T_V_BYTE = 365,
     T_V_UINT = 366,
     T_V_ULONG = 367,
     T_V_UBYTE = 368,
     lowpriority = 369,
     lowpriority2 = 370,
     lowpriority3 = 371,
     lowpriority4 = 372
   };
#endif
/* Tokens.  */
#define _def_val_2 258
#define test0 259
#define test2 260
#define test 261
#define _def_val_ 262
#define test3 263
#define T_INCLUDE_ONCE 264
#define T_INCLUDE 265
#define T_LOGICAL_OR 266
#define T_LOGICAL_XOR 267
#define T_LOGICAL_AND 268
#define T_DOUBLE_ARROW 269
#define T_POW_EQUAL 270
#define T_SR_EQUAL 271
#define T_XOR_EQUAL 272
#define T_OR_EQUAL 273
#define T_AND_EQUAL 274
#define T_MOD_EQUAL 275
#define T_CONCAT_EQUAL 276
#define T_DIV_EQUAL 277
#define T_MUL_EQUAL 278
#define T_MINUS_EQUAL 279
#define T_PLUS_EQUAL 280
#define T_COALESCE 281
#define T_BOOLEAN_OR 282
#define T_BOOLEAN_AND 283
#define T_IS_NOT_EQUAL 284
#define T_IS_EQUAL 285
#define T_IS_GREATER_OR_EQUAL 286
#define T_IS_SMALLER_OR_EQUAL 287
#define T_SR 288
#define T_SL 289
#define T_BOOL_CAST 290
#define T_STRING_CAST 291
#define T_DOUBLE_CAST 292
#define T_INT_CAST 293
#define T_DEC 294
#define T_INC 295
#define T_POW 296
#define T_CLONE 297
#define T_NEW 298
#define T_IF 299
#define elseif_list_test 300
#define T_ELSEIF 302
#define T_ELSE 304
#define T_LNUMBER 305
#define T_DNUMBER 306
#define T_STRING 307
#define T_VARIABLE 308
#define T_NUM_STRING 309
#define T_ENCAPSED_AND_WHITESPACE 310
#define T_CONSTANT_ENCAPSED_STRING 311
#define T_TRUE 312
#define T_FALSE 313
#define T_NULL 314
#define T_SUPER 315
#define T_READ_INT 316
#define T_READ_DOUBLE 317
#define T_READ_STRING 318
#define T_ECHO 319
#define T_DO 320
#define T_WHILE 321
#define T_ENDWHILE 322
#define T_FOR 323
#define T_ENDFOR 324
#define T_FOREACH 325
#define T_ENDFOREACH 326
#define T_AS 327
#define T_SWITCH 328
#define T_ENDSWITCH 329
#define T_CASE 330
#define T_DEFAULT 331
#define T_BREAK 332
#define T_CONTINUE 333
#define T_GOTO 334
#define T_FUNCTION 335
#define T_CONST 336
#define T_RETURN 337
#define T_TRY 338
#define T_CATCH 339
#define T_FINALLY 340
#define T_THROW 341
#define T_PUBLIC 342
#define T_PROTECTED 343
#define T_PRIVATE 344
#define T_FINAL 345
#define T_ABSTRACT 346
#define T_STATIC 347
#define T_CLASS 348
#define T_INTERFACE 349
#define T_EXTENDS 350
#define T_IMPLEMENTS 351
#define T_OBJECT_OPERATOR 352
#define T_OPEN_TAG_PHP 353
#define T_CLOSE_TAG_PHP 354
#define T_PAAMAYIM_NEKUDOTAYIM 355
#define T_ELLIPSIS 356
#define T_V_INT 357
#define T_V_STRING 358
#define T_V_BOOL 359
#define T_V_CHAR 360
#define T_V_DOUBLE 361
#define T_V_FLOAT 362
#define T_V_REAL 363
#define T_V_LONG 364
#define T_V_BYTE 365
#define T_V_UINT 366
#define T_V_ULONG 367
#define T_V_UBYTE 368
#define lowpriority 369
#define lowpriority2 370
#define lowpriority3 371
#define lowpriority4 372




/* Copy the first part of user declarations.  */
#line 2 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"

    #define YYDEBUG 1
	 
	#include "Code\HelperCode.h"
	#include "Code\AST\AST.h"
	using namespace banana;

	#include <iostream>
	using namespace std;
	#include "FlexLexer.h"


	#define YYERROR_VERBOSE
	#define yyerrok		(yyerrstatus = 0)
	#define yyclearin	(yychar = YYEMPTY)
	int yyerrstatus;



	int yylex(void);
	int yyparse();
	void yyerror(const char *);
	

	FlexLexer* lexer = new yyFlexLexer();
	class Parser
	{
		public:
		int	parse()
		{
			return yyparse();
		}
	};


	AST * ast = new AST();

	TreeNode * finalTree = new TreeNode();
	TreeNode * TempTree = NULL;


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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 153 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
typedef union YYSTYPE {
	struct R{

		int intvalue;
		double floatvalue;
		char* stringvalue;

		char* identifier;
		char* name;

		char* type_name;


		float f;
		char c;
		char* str;
		int myLineNo;
		int myColno;
		bool worngID;
		
		Type* type;
		
		}r;
		
		class TreeNode * ast;
	} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 383 "yacc.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 395 "yacc.cpp"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
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
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3145

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  143
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  80
/* YYNRULES -- Number of rules. */
#define YYNRULES  269
/* YYNRULES -- Number of states. */
#define YYNSTATES  502

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   373

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,     2,    49,    35,     2,
     138,   137,    47,    44,    11,    45,    46,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,   140,
      38,    16,    39,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   135,     2,   142,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   136,    33,   139,    51,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    12,    13,    14,    15,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    30,    31,    32,    36,    37,    40,    41,    42,    43,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   141
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     4,     9,    10,    13,    16,    17,    19,
      21,    23,    26,    27,    29,    31,    33,    34,    39,    41,
      48,    53,    57,    63,    64,    75,    79,    82,    86,    89,
      93,    96,   100,   104,   108,   111,   119,   121,   126,   130,
     134,   137,   141,   148,   150,   151,   154,   161,   162,   165,
     166,   168,   169,   171,   172,   182,   183,   192,   199,   201,
     204,   207,   210,   214,   218,   219,   222,   223,   226,   227,
     230,   232,   236,   238,   243,   245,   250,   254,   259,   260,
     263,   268,   272,   274,   279,   280,   283,   287,   291,   293,
     295,   296,   298,   302,   304,   308,   312,   317,   324,   327,
     328,   331,   334,   338,   342,   344,   346,   349,   352,   356,
     358,   361,   366,   369,   370,   371,   376,   377,   388,   390,
     392,   394,   396,   399,   402,   404,   406,   407,   409,   411,
     413,   415,   417,   419,   421,   425,   428,   433,   439,   442,
     445,   450,   451,   454,   456,   458,   460,   462,   464,   466,
     468,   470,   472,   474,   476,   478,   482,   484,   485,   487,
     489,   493,   495,   501,   504,   508,   512,   516,   520,   524,
     528,   532,   536,   540,   544,   548,   551,   554,   557,   560,
     564,   568,   572,   576,   580,   584,   588,   592,   596,   600,
     604,   608,   612,   616,   620,   624,   628,   631,   634,   637,
     640,   644,   648,   652,   656,   660,   664,   666,   670,   676,
     681,   685,   688,   691,   694,   697,   702,   709,   711,   713,
     715,   717,   721,   722,   724,   728,   734,   740,   746,   755,
     763,   765,   767,   772,   774,   777,   780,   785,   787,   789,
     791,   793,   795,   797,   799,   803,   806,   809,   811,   815,
     816,   818,   820,   822,   824,   828,   833,   836,   841,   843,
     847,   849,   851,   855,   860,   861,   864,   868,   870,   872
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     144,     0,    -1,    -1,   145,   115,   146,   116,    -1,    -1,
     147,   148,    -1,   148,   149,    -1,    -1,   154,    -1,   161,
      -1,   163,    -1,   150,   151,    -1,    -1,   154,    -1,   161,
      -1,   163,    -1,    -1,   136,   153,   150,   139,    -1,   152,
      -1,    61,   205,   154,   176,    66,   154,    -1,    61,   205,
     154,   176,    -1,    83,   205,   175,    -1,    82,   154,    83,
     205,   140,    -1,    -1,    85,   155,   138,   203,   140,   203,
     140,   203,   137,   170,    -1,    90,   205,   172,    -1,    94,
     140,    -1,    94,   204,   140,    -1,    95,   140,    -1,    95,
     204,   140,    -1,    99,   140,    -1,    99,   204,   140,    -1,
     109,   187,   140,    -1,    81,   202,   140,    -1,   204,   140,
      -1,    87,   138,   204,    89,   215,   137,   171,    -1,   140,
      -1,   100,   152,   156,   158,    -1,   103,   204,   140,    -1,
      96,    69,   140,    -1,    69,    29,    -1,    77,   184,   140,
      -1,    98,   199,    70,    16,   212,   140,    -1,     1,    -1,
      -1,   156,   157,    -1,   101,   138,    69,    70,   137,   152,
      -1,    -1,   102,   152,    -1,    -1,    35,    -1,    -1,   118,
      -1,    -1,    97,   159,    69,   138,   178,   137,   183,   162,
     152,    -1,    -1,   165,    69,   164,   166,   168,   136,   189,
     139,    -1,   111,    69,   167,   136,   189,   139,    -1,   110,
      -1,   108,   110,    -1,   107,   110,    -1,   109,   110,    -1,
     109,   108,   110,    -1,   109,   107,   110,    -1,    -1,   112,
      69,    -1,    -1,   112,   169,    -1,    -1,   113,   169,    -1,
      69,    -1,   169,    11,    69,    -1,   154,    -1,    29,   150,
      86,   140,    -1,   154,    -1,    29,   150,    88,   140,    -1,
     136,   173,   139,    -1,   136,   140,   173,   139,    -1,    -1,
     174,   173,    -1,    92,   204,    29,   150,    -1,    93,    29,
     150,    -1,   154,    -1,    29,   150,    84,   140,    -1,    -1,
     176,   177,    -1,    64,   205,   154,    -1,   179,    11,   180,
      -1,   179,    -1,   180,    -1,    -1,   181,    -1,   179,    11,
     181,    -1,   182,    -1,   180,    11,   182,    -1,   180,    11,
     181,    -1,   199,   159,   160,    70,    -1,   199,   159,   160,
      70,    16,   212,    -1,    29,   141,    -1,    -1,    29,   199,
      -1,   138,   137,    -1,   138,   185,   137,    -1,   185,    11,
     186,    -1,   186,    -1,   204,    -1,    35,   215,    -1,   118,
     204,    -1,   187,    11,   188,    -1,   188,    -1,   199,    70,
      -1,   199,    70,    16,   212,    -1,   189,   190,    -1,    -1,
      -1,   194,   191,   197,   140,    -1,    -1,   194,    97,   159,
      69,   138,   178,   137,   183,   192,   193,    -1,   163,    -1,
       1,    -1,   140,    -1,   152,    -1,   195,   196,    -1,   196,
     195,    -1,   196,    -1,   195,    -1,    -1,   104,    -1,   105,
      -1,   106,    -1,   109,    -1,   108,    -1,   107,    -1,   198,
      -1,   197,    11,   198,    -1,   199,    70,    -1,   199,    70,
      16,   212,    -1,    98,   199,    70,    16,   212,    -1,   201,
     200,    -1,    69,   200,    -1,    69,   117,    69,   200,    -1,
      -1,   135,   142,    -1,   119,    -1,   120,    -1,   121,    -1,
     122,    -1,   123,    -1,   124,    -1,   125,    -1,   126,    -1,
     127,    -1,   128,    -1,   129,    -1,   130,    -1,   202,    11,
     204,    -1,   204,    -1,    -1,   202,    -1,   215,    -1,   215,
      16,   204,    -1,   207,    -1,    16,    70,   114,    69,   184,
      -1,    59,   204,    -1,   215,    27,   204,    -1,   215,    26,
     204,    -1,   215,    25,   204,    -1,   215,    24,   204,    -1,
     215,    23,   204,    -1,   215,    22,   204,    -1,   215,    21,
     204,    -1,   215,    20,   204,    -1,   215,    19,   204,    -1,
     215,    18,   204,    -1,   215,    17,   204,    -1,   215,    57,
      -1,    57,   215,    -1,   215,    56,    -1,    56,   215,    -1,
     204,    31,   204,    -1,   204,    32,   204,    -1,   204,    12,
     204,    -1,   204,    14,   204,    -1,   204,    13,   204,    -1,
     204,    33,   204,    -1,   204,    35,   204,    -1,   204,    34,
     204,    -1,   204,    46,   204,    -1,   204,    44,   204,    -1,
     204,    45,   204,    -1,   204,    47,   204,    -1,   204,    48,
     204,    -1,   204,    49,   204,    -1,   204,    43,   204,    -1,
     204,    42,   204,    -1,   204,    58,   204,    -1,    44,   204,
      -1,    45,   204,    -1,    50,   204,    -1,    51,   204,    -1,
     204,    37,   204,    -1,   204,    36,   204,    -1,   204,    38,
     204,    -1,   204,    41,   204,    -1,   204,    39,   204,    -1,
     204,    40,   204,    -1,   205,    -1,   138,   207,   137,    -1,
     204,    28,   204,    29,   204,    -1,   204,    28,    29,   204,
      -1,   204,    30,   204,    -1,    55,   204,    -1,    54,   204,
      -1,    53,   204,    -1,    52,   204,    -1,   138,    69,   137,
     204,    -1,   138,    69,   135,   142,   137,   204,    -1,   213,
      -1,    78,    -1,    80,    -1,    79,    -1,   138,   204,   137,
      -1,    -1,   204,    -1,    60,    69,   184,    -1,    60,    69,
     117,    69,   184,    -1,    70,    15,    60,    69,   184,    -1,
      60,   208,   135,   204,   142,    -1,    60,   208,   135,   204,
     142,   136,   220,   139,    -1,    60,   208,   135,   142,   136,
     220,   139,    -1,   201,    -1,    69,    -1,   209,   135,   204,
     142,    -1,    70,    -1,   199,    70,    -1,    69,   184,    -1,
      69,   117,    69,   184,    -1,    67,    -1,    68,    -1,    73,
      -1,    74,    -1,    75,    -1,    76,    -1,   211,    -1,    69,
     117,    69,    -1,    45,    67,    -1,    45,    68,    -1,   211,
      -1,    69,   117,    69,    -1,    -1,    11,    -1,   216,    -1,
     218,    -1,   210,    -1,   217,   114,    70,    -1,   217,   114,
      69,   184,    -1,   216,   184,    -1,   216,   135,   206,   142,
      -1,   215,    -1,   138,   207,   137,    -1,   209,    -1,   219,
      -1,    69,   117,    70,    -1,   219,   135,   204,   142,    -1,
      -1,   221,   214,    -1,   221,    11,   222,    -1,   222,    -1,
     204,    -1,    35,   215,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   183,   183,   183,   194,   194,   206,   207,   211,   212,
     213,   217,   218,   223,   224,   225,   229,   229,   233,   234,
     244,   253,   254,   255,   255,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   283,   284,   286,   287,
     288,   289,   290,   291,   295,   296,   300,   304,   305,   309,
     310,   314,   315,   319,   319,   323,   323,   324,   329,   330,
     331,   333,   334,   335,   339,   340,   344,   345,   349,   350,
     354,   355,   359,   360,   364,   365,   369,   370,   374,   375,
     379,   380,   385,   386,   390,   391,   395,   406,   407,   408,
     409,   413,   414,   418,   419,   420,   424,   428,   432,   433,
     434,   438,   439,   443,   444,   448,   449,   450,   455,   456,
     460,   461,   465,   466,   470,   470,   471,   471,   480,   482,
     486,   487,   491,   492,   493,   494,   495,   499,   500,   501,
     505,   506,   507,   511,   512,   516,   517,   524,   529,   530,
     531,   537,   538,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   557,   558,   562,   563,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   626,   628,   629,
     630,   634,   638,   639,   644,   645,   646,   648,   649,   650,
     654,   655,   660,   661,   663,   673,   674,   678,   679,   681,
     682,   683,   684,   688,   689,   690,   691,   694,   695,   699,
     700,   704,   705,   706,   710,   711,   713,   714,   718,   719,
     723,   724,   728,   729,   733,   734,   738,   739,   743,   744
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_def_val_2", "test0", "test2", "test",
  "_def_val_", "test3", "T_INCLUDE_ONCE", "T_INCLUDE", "','",
  "T_LOGICAL_OR", "T_LOGICAL_XOR", "T_LOGICAL_AND",
  "\"=> (T_DOUBLE_ARROW)\"", "'='", "T_POW_EQUAL", "T_SR_EQUAL",
  "T_XOR_EQUAL", "T_OR_EQUAL", "T_AND_EQUAL", "T_MOD_EQUAL",
  "T_CONCAT_EQUAL", "T_DIV_EQUAL", "T_MUL_EQUAL", "T_MINUS_EQUAL",
  "T_PLUS_EQUAL", "'?'", "':'", "T_COALESCE", "T_BOOLEAN_OR",
  "T_BOOLEAN_AND", "'|'", "'^'", "'&'", "T_IS_NOT_EQUAL", "T_IS_EQUAL",
  "'<'", "'>'", "T_IS_GREATER_OR_EQUAL", "T_IS_SMALLER_OR_EQUAL", "T_SR",
  "T_SL", "'+'", "'-'", "'.'", "'*'", "'/'", "'%'", "'!'", "'~'",
  "T_BOOL_CAST", "T_STRING_CAST", "T_DOUBLE_CAST", "T_INT_CAST", "T_DEC",
  "T_INC", "T_POW", "T_CLONE", "T_NEW", "\"if (T_IF)\"",
  "elseif_list_test", "\"elseif (T_ELSEIF)\"", "T_ELSEIF",
  "\"else (T_ELSE)\"", "T_ELSE", "\"integer number (T_LNUMBER)\"",
  "\"floating-point number (T_DNUMBER)\"", "\"identifier (T_STRING)\"",
  "\"variable (T_VARIABLE)\"", "\"number (T_NUM_STRING)\"",
  "\"quoted-string and whitespace (T_ENCAPSED_AND_WHITESPACE)\"",
  "\"quoted-string (T_CONSTANT_ENCAPSED_STRING)\"", "\"true (T_TRUE)\"",
  "\"false (T_FALSE)\"", "\"null (T_NULL)\"", "\"super (T_SUPER)\"",
  "\"read int (T_READ_INT)\"", "\"read double (T_READ_DOUBLE)\"",
  "\"read string (T_READ_STRING)\"", "\"echo (T_ECHO)\"", "\"do (T_DO)\"",
  "\"while (T_WHILE)\"", "\"endwhile (T_ENDWHILE)\"", "\"for (T_FOR)\"",
  "\"endfor (T_ENDFOR)\"", "\"foreach (T_FOREACH)\"",
  "\"endforeach (T_ENDFOREACH)\"", "\"as (T_AS)\"",
  "\"switch (T_SWITCH)\"", "\"endswitch (T_ENDSWITCH)\"",
  "\"case (T_CASE)\"", "\"default (T_DEFAULT)\"", "\"break (T_BREAK)\"",
  "\"continue (T_CONTINUE)\"", "\"goto (T_GOTO)\"",
  "\"function (T_FUNCTION)\"", "\"const (T_CONST)\"",
  "\"return (T_RETURN)\"", "\"try (T_TRY)\"", "\"catch (T_CATCH)\"",
  "\"finally (T_FINALLY)\"", "\"throw (T_THROW)\"", "T_PUBLIC",
  "T_PROTECTED", "T_PRIVATE", "T_FINAL", "T_ABSTRACT", "T_STATIC",
  "\"class (T_CLASS)\"", "\"interface (T_INTERFACE)\"",
  "\"extends (T_EXTENDS)\"", "\"implements (T_IMPLEMENTS)\"",
  "\"-> (T_OBJECT_OPERATOR)\"", "T_OPEN_TAG_PHP", "T_CLOSE_TAG_PHP",
  "\":: (T_PAAMAYIM_NEKUDOTAYIM)\"", "\"... (T_ELLIPSIS)\"",
  "\"int (T_V_INT)\"", "\"string (T_V_STRING)\"", "\"bool (T_V_BOOL)\"",
  "\"char (T_V_CHAR) \"", "\"double (T_V_DOUBLE) \"",
  "\"float (T_V_FLOAT) \"", "\"real (T_V_REAL) \"", "\"long (T_V_LONG) \"",
  "\"byte (T_V_BYTE) \"", "\"uint (T_V_UINT) \"", "\"ulong (T_V_ULONG) \"",
  "\"ubyte (T_V_UBYTE) \"", "lowpriority", "lowpriority2", "lowpriority3",
  "lowpriority4", "'['", "'{'", "')'", "'('", "'}'", "';'", "\"void\"",
  "']'", "$accept", "start", "@1", "top_statement_listX", "@2",
  "top_statement_list", "top_statement", "inner_statement_list",
  "inner_statement", "scope", "@3", "statement", "@4", "catches", "catch",
  "optional_finally", "optional_ref", "optional_ellipsis",
  "function_declaration_statement", "@5", "class_declaration_statement",
  "@6", "class_entry_type", "extends_from", "interface_extends_list",
  "implements_list", "name_list", "for_statement", "foreach_statement",
  "switch_case_list", "case_list", "case", "while_statement",
  "elseif_list", "elseif", "parameter_list", "non_empty_parameter_list",
  "non_empty_optional_parameter_list", "parameter", "optional_parameter",
  "optional_return_type", "argument_list", "non_empty_argument_list",
  "argument", "static_var_list", "static_var", "class_statement_list",
  "class_statement", "@7", "@8", "method_body", "modifiers",
  "member_access_modifier", "member_storage_modifier",
  "property_declaration_list", "property_declaration", "var_type_or_name",
  "optional_array", "var_types", "expr_list", "for_expr", "expr",
  "parentheses_expr", "dim_offset", "new_expr", "array_type",
  "variable_without_objects", "function_call", "common_scalar",
  "static_scalar", "scalar", "optional_comma", "variable", "object_access",
  "variable_or_new_expr", "base_variable", "static_property",
  "array_pair_list", "non_empty_array_pair_list", "array_pair", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    44,   266,   267,   268,   269,    61,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,    63,    58,
     281,   282,   283,   124,    94,    38,   284,   285,    60,    62,
     286,   287,   288,   289,    43,    45,    46,    42,    47,    37,
      33,   126,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,    91,   123,    41,    40,   125,
      59,   373,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   143,   145,   144,   147,   146,   148,   148,   149,   149,
     149,   150,   150,   151,   151,   151,   153,   152,   154,   154,
     154,   154,   154,   155,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   156,   156,   157,   158,   158,   159,
     159,   160,   160,   162,   161,   164,   163,   163,   165,   165,
     165,   165,   165,   165,   166,   166,   167,   167,   168,   168,
     169,   169,   170,   170,   171,   171,   172,   172,   173,   173,
     174,   174,   175,   175,   176,   176,   177,   178,   178,   178,
     178,   179,   179,   180,   180,   180,   181,   182,   183,   183,
     183,   184,   184,   185,   185,   186,   186,   186,   187,   187,
     188,   188,   189,   189,   191,   190,   192,   190,   190,   190,
     193,   193,   194,   194,   194,   194,   194,   195,   195,   195,
     196,   196,   196,   197,   197,   198,   198,   198,   199,   199,
     199,   200,   200,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   202,   202,   203,   203,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   205,   206,   206,   207,   207,   207,   207,   207,   207,
     208,   208,   209,   209,   209,   210,   210,   211,   211,   211,
     211,   211,   211,   212,   212,   212,   212,   213,   213,   214,
     214,   215,   215,   215,   216,   216,   216,   216,   217,   217,
     218,   218,   219,   219,   220,   220,   221,   221,   222,   222
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     4,     0,     2,     2,     0,     1,     1,
       1,     2,     0,     1,     1,     1,     0,     4,     1,     6,
       4,     3,     5,     0,    10,     3,     2,     3,     2,     3,
       2,     3,     3,     3,     2,     7,     1,     4,     3,     3,
       2,     3,     6,     1,     0,     2,     6,     0,     2,     0,
       1,     0,     1,     0,     9,     0,     8,     6,     1,     2,
       2,     2,     3,     3,     0,     2,     0,     2,     0,     2,
       1,     3,     1,     4,     1,     4,     3,     4,     0,     2,
       4,     3,     1,     4,     0,     2,     3,     3,     1,     1,
       0,     1,     3,     1,     3,     3,     4,     6,     2,     0,
       2,     2,     3,     3,     1,     1,     2,     2,     3,     1,
       2,     4,     2,     0,     0,     4,     0,    10,     1,     1,
       1,     1,     2,     2,     1,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     4,     5,     2,     2,
       4,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     1,     1,
       3,     1,     5,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       3,     3,     3,     3,     3,     3,     1,     3,     5,     4,
       3,     2,     2,     2,     2,     4,     6,     1,     1,     1,
       1,     3,     0,     1,     3,     5,     5,     5,     8,     7,
       1,     1,     4,     1,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     2,     1,     3,     0,
       1,     1,     1,     1,     3,     4,     2,     4,     1,     3,
       1,     1,     3,     4,     0,     2,     3,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       2,     0,     0,     1,     4,     0,     7,     3,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   141,   233,   239,   240,
     241,   242,     0,   218,   220,   219,     0,     0,     0,    23,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,    58,     0,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    16,     0,    36,
       6,    18,     8,     9,    10,     0,     0,   141,     0,   206,
     161,   260,   253,   247,   217,   159,   251,     0,   252,   261,
       0,   141,   196,   197,   198,   199,   214,   213,   212,   211,
     141,   233,     0,   178,   176,   163,   231,   230,     0,     0,
       0,    40,     0,     0,     0,   235,   139,     0,     0,     0,
     156,     0,     0,     0,     0,     0,     0,    26,     0,    28,
       0,     0,    50,     0,   141,     0,    30,     0,    44,     0,
      60,    59,     0,     0,    61,     0,   109,     0,    66,    12,
     141,     0,   161,    55,   234,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   175,   222,   256,     0,
       0,     0,     0,     0,     0,     0,   224,     0,    84,   248,
     262,   142,     0,     0,   101,     0,   104,   105,     0,    41,
       0,    33,     0,    12,    82,    21,   157,     0,    78,    25,
      27,    29,    39,     0,     0,     0,    31,    47,    38,    63,
      62,     0,    32,   110,     0,     0,     0,     0,     0,   221,
     207,    64,   181,   183,   182,     0,     0,   210,   179,   180,
     184,   186,   185,   201,   200,   202,   204,   205,   203,   194,
     193,   188,   189,   187,   190,   191,   192,   195,     0,   160,
     174,   173,   172,   171,   170,   169,   168,   167,   166,   165,
     164,   223,     0,     0,   254,     0,     0,   141,   259,     0,
       0,     0,    20,   236,   140,   106,   107,     0,   102,     0,
     155,     0,     0,   158,     0,     0,     0,     0,    78,     0,
      78,    90,   141,     0,     0,     0,    45,    37,   108,     0,
      70,    67,   113,    17,    11,    13,    14,    15,   142,   215,
       0,    68,   209,     0,   232,   257,   255,   263,   162,   225,
     264,   227,     0,     0,    85,   103,   226,    22,     0,   157,
     258,     0,    12,     0,    76,    79,     0,    88,    89,    91,
      93,    49,     0,     0,   243,     0,     0,    48,   111,     0,
       0,     0,    65,     0,     0,   208,     0,   268,     0,   249,
     267,   264,     0,    19,    83,     0,     0,    12,     0,    77,
      99,     0,     0,    51,   245,   246,     0,    42,     0,    71,
     119,   127,   128,   129,   132,   131,   130,    57,   118,   112,
     114,   125,   124,   216,    69,   113,   269,   229,   250,   265,
       0,    86,   157,    12,    74,    35,     0,     0,    53,    87,
      92,    95,    94,    52,     0,   244,     0,    49,     0,   132,
     131,   130,   122,   123,     0,   266,   228,     0,     0,    98,
     100,     0,    96,     0,     0,     0,     0,   133,     0,    56,
       0,     0,    54,     0,    46,     0,     0,     0,   115,   135,
      12,    72,    24,    75,    97,    90,     0,   134,     0,     0,
       0,     0,   136,     0,    99,   137,    73,   116,     0,   120,
     121,   117
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,     2,     5,     6,     8,    70,   246,   334,    71,
     149,   335,   124,   237,   326,   327,   133,   444,   336,   461,
     337,   251,    75,   341,   245,   384,   331,   482,   435,   229,
     319,   320,   225,   302,   354,   366,   367,   368,   369,   370,
     438,   115,   215,   216,   145,   146,   380,   419,   448,   498,
     501,   420,   421,   422,   466,   467,    76,   116,    77,   313,
     314,    78,    79,   292,    80,   108,    81,    82,    83,   375,
      84,   429,    85,    86,    87,    88,    89,   388,   389,   390
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -367
static const short int yypact[] =
{
    -367,    24,   -85,  -367,  -367,   -50,  -367,  -367,   616,  -367,
     -21,  2719,  2719,  2719,  2719,  2719,  2719,  2719,  2719,  1801,
    1801,  2719,  1160,   -69,  -367,  -367,    39,    79,  -367,  -367,
    -367,  -367,   -38,  -367,  -367,  -367,  2719,  1462,   -69,  -367,
      26,   -69,  2044,  2135,   101,    41,  1275,  2226,    37,  2719,
      66,    81,  1956,  -367,   129,  -367,  -367,  -367,  -367,  -367,
    -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  2808,  -367,
    -367,  -367,  -367,  -367,  -367,   172,   175,   117,  1702,  -367,
    -367,   119,  -367,  -367,  -367,    15,  -117,   141,  -367,   121,
     143,   -25,   200,   200,   200,   200,   200,   200,   200,   200,
      28,  -367,    31,   146,   146,  -367,   -94,  -367,   128,  2719,
    1462,  -367,    47,   131,  2323,  -367,  -367,   201,   130,     6,
    3043,  1275,   185,  1132,   133,  2719,   138,  -367,  1741,  -367,
    1779,   135,  -367,   207,   -90,   199,  -367,  1817,  -367,  1855,
    -367,  -367,   174,   176,  -367,     8,  -367,   215,   177,  -367,
     127,  2010,   150,  -367,  -367,  -367,  2719,  2719,  2719,  2534,
    2719,  2719,  2719,  2719,  2719,  2719,  2719,  2719,  2719,  2719,
    2719,  2719,  2719,  2719,  2719,  2719,  2719,  2719,  2719,  2719,
    2719,  -367,  2719,  2719,  2719,  2719,  2719,  2719,  2719,  2719,
    2719,  2719,  2719,  2719,  2719,  -367,  -367,  2719,  -367,    57,
    2719,   219,    61,    79,   153,   222,  -367,  1891,  -367,   -58,
    -367,  -367,  1801,  2719,  -367,    -5,  -367,  3043,   223,  -367,
    2719,  -367,   -69,  -367,  -367,  -367,  2719,  2927,   -67,  -367,
    -367,  -367,  -367,   157,   227,   281,  -367,    93,  -367,  -367,
    -367,  1275,  -367,   282,   230,   164,   717,   160,  2719,  -367,
     189,   193,  2284,  2192,  2097,  2719,  2965,  2374,  2468,  2582,
    2678,  2765,  2853,  3066,  3066,  3087,  3087,  3087,  3087,     7,
       7,    38,    38,    38,   200,   200,   200,   200,   294,  2097,
    2097,  2097,  2097,  2097,  2097,  2097,  2097,  2097,  2097,  2097,
    2097,  3043,   167,   -38,  -367,  1626,   -38,   -88,  -367,   -38,
     178,  1664,   126,  -367,  -367,   146,  3043,  2419,  -367,   -38,
    3043,   170,   817,   300,   173,  1801,  2719,   283,   104,   180,
     104,  1275,   117,    30,   179,    37,  -367,  -367,  -367,    30,
    -367,   304,  -367,  -367,  -367,  -367,  -367,  -367,   183,  -367,
     247,   208,  2374,  2719,  -367,  -367,  -367,  -367,  -367,  -367,
    2630,   187,   -69,  1462,  -367,  -367,  -367,  -367,   204,  2719,
     209,  3005,  -367,   210,  -367,  -367,   211,   336,   339,  -367,
    -367,    41,   181,   234,  -367,   214,   286,  -367,  -367,   287,
      14,  2719,  -367,   230,   225,  2374,  1801,  3043,   224,   347,
    -367,  2630,  1462,  -367,  -367,   226,  1247,  -367,   416,  -367,
     335,  1275,  1275,   249,  -367,  -367,   299,  -367,   301,  -367,
    -367,  -367,  -367,  -367,    66,    81,    51,  -367,  -367,  -367,
     272,    43,    63,  -367,   304,  -367,   146,  -367,  2630,  -367,
     231,  -367,  2719,  -367,  -367,  -367,   516,    59,  -367,   339,
    -367,  -367,  -367,  -367,   302,  -367,   236,    41,  1864,  -367,
    -367,  -367,  -367,  -367,  1507,  -367,  -367,   239,   917,  -367,
    -367,    37,   361,    37,   309,  1275,     9,  -367,   310,  -367,
    1362,   241,  -367,    30,  -367,   244,   313,  1864,  -367,   363,
    -367,  -367,  -367,  -367,  -367,  1275,   369,  -367,    30,  1017,
     250,    30,  -367,   246,   335,  -367,  -367,  -367,   -62,  -367,
    -367,  -367
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -367,  -367,  -367,  -367,  -367,  -367,  -367,  -115,  -367,   -47,
    -367,    -8,  -367,  -367,  -367,  -367,  -366,  -367,   382,  -367,
      -6,  -367,  -367,  -367,  -367,  -367,    10,  -367,  -367,  -367,
    -211,  -367,  -367,  -367,  -367,   -93,  -367,   -10,  -151,    -4,
    -100,   -16,  -367,    90,  -367,   158,   -24,  -367,  -367,  -367,
    -367,  -367,   -22,   -19,  -367,   -74,   -42,   -55,   385,   368,
    -348,    46,     5,  -367,   -54,  -367,  -367,  -367,  -316,  -326,
    -367,  -367,   -11,  -367,  -367,  -367,  -367,    17,  -367,   -18
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -260
static const short int yytable[] =
{
      72,   138,    74,   378,   135,   403,   307,   374,   103,   104,
     147,   395,  -141,   374,   152,   410,   118,   220,   197,   241,
     477,   114,   155,   205,     3,   316,   317,   234,   110,   122,
       4,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   123,   114,   113,   126,   113,   204,    90,
     114,   174,   175,   176,   177,   178,   179,    92,    93,    94,
      95,    96,    97,    98,    99,   180,     7,   105,   111,   109,
     198,   195,   196,   318,    67,   372,   132,   113,   499,   147,
     114,   464,   120,  -126,   457,   177,   178,   179,   128,   130,
     206,    22,   112,   137,   117,   139,   180,    24,    25,   373,
     114,   203,   208,    28,    29,    30,    31,   363,   312,   365,
     113,  -126,  -126,   114,   151,   224,   209,   210,   411,   412,
     413,   414,   415,   416,    53,    54,   293,   294,   134,  -258,
     297,   210,   308,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,   202,   221,   484,   242,   478,
     449,   450,   451,   417,   304,   151,   112,   374,   142,   143,
     217,   144,   492,   113,   125,   495,   114,   411,   412,   413,
     131,   227,   374,    67,   113,   374,   140,   114,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
     352,   141,   353,   303,   324,   325,   316,   317,   148,   147,
     459,   305,   252,   253,   254,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   311,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   153,   304,   291,   112,   154,   295,   398,   404,   405,
     440,   441,   113,   301,   182,   199,   200,   201,   180,   306,
    -258,   218,   247,   207,   248,   114,   310,   304,   222,   235,
     219,   226,   120,   211,   228,   232,   233,   346,   377,   371,
     348,   303,   436,   349,   239,   243,   240,   250,   296,   244,
     298,   299,   309,   356,   339,   321,   322,   323,   329,   330,
     332,   342,   338,  -259,   360,   340,   156,   157,   158,   345,
     357,   220,   362,   359,   350,   379,   382,   376,   458,   364,
     381,   383,   159,   391,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   394,   393,   396,   401,   400,   399,
     402,   406,   180,   217,   407,   408,   409,   392,   428,   371,
     371,   425,   361,   427,   437,   489,   432,   443,   445,   447,
     456,   446,   462,   463,   418,   426,   470,   473,   475,   488,
     479,   483,   485,   486,   431,   491,   496,   494,   434,   385,
      73,   439,   490,   424,   497,   460,   387,   355,   442,   328,
     453,   454,   452,   487,   119,   120,   468,   107,   430,     0,
     455,     0,     0,     0,   472,     0,   474,     9,     0,     0,
       0,     0,     0,   476,     0,     0,     0,   423,     0,     0,
       0,     0,    10,     0,     0,   468,   344,   387,     0,     0,
       0,     0,     0,   371,     0,     0,     0,     0,   418,     0,
       0,   500,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,   481,     0,     0,     0,    13,    14,    15,    16,
      17,    18,    19,    20,   387,    21,    22,    23,   120,     0,
       0,     0,     0,    24,    25,    26,    27,     0,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
       0,    39,     0,    40,     0,     0,    41,     0,   -81,   -81,
      42,    43,    44,    45,    46,    47,    48,     9,     0,    49,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
       0,     0,    10,     0,     0,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,     0,    67,     0,    68,   -81,    69,     0,     0,     0,
      11,    12,     0,     0,     0,     0,    13,    14,    15,    16,
      17,    18,    19,    20,     0,    21,    22,    23,     0,     0,
       0,     0,     0,    24,    25,    26,    27,     0,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
       0,    39,     0,    40,     0,     0,    41,     0,   -80,   -80,
      42,    43,    44,    45,    46,    47,    48,     9,     0,    49,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
       0,     0,    10,     0,     0,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,     0,    67,     0,    68,   -80,    69,     0,     0,     0,
      11,    12,     0,     0,     0,     0,    13,    14,    15,    16,
      17,    18,    19,    20,     0,    21,    22,    23,     0,     0,
       0,     0,     0,    24,    25,    26,    27,     0,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
       0,    39,     0,    40,     0,     0,    41,     0,     0,     0,
      42,    43,    44,    45,    46,    47,    48,     0,     9,    49,
       0,     0,     0,    50,    51,    52,    53,    54,     0,     0,
       0,     0,    -5,    10,     0,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,     0,    67,     0,    68,     0,    69,     0,     0,     0,
       0,    11,    12,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,     0,    21,    22,    23,     0,
       0,     0,     0,     0,    24,    25,    26,    27,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,     0,    39,     0,    40,     0,     0,    41,     0,     0,
       0,    42,    43,    44,    45,    46,    47,    48,     9,     0,
      49,     0,     0,     0,    50,    51,    52,    53,    54,     0,
       0,     0,     0,    10,     0,     0,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,     0,
       0,     0,     0,    67,     0,    68,   333,    69,     0,     0,
       0,    11,    12,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,     0,    21,    22,    23,     0,
       0,     0,     0,     0,    24,    25,    26,    27,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,   358,    39,     0,    40,     0,     0,    41,     0,     0,
       0,    42,    43,    44,    45,    46,    47,    48,     9,     0,
      49,     0,     0,     0,    50,    51,    52,    53,    54,     0,
       0,     0,     0,    10,     0,     0,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,     0,
       0,     0,     0,    67,     0,    68,     0,    69,     0,     0,
       0,    11,    12,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,     0,    21,    22,    23,     0,
       0,     0,     0,     0,    24,    25,    26,    27,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,     0,    39,     0,    40,   471,     0,    41,     0,     0,
       0,    42,    43,    44,    45,    46,    47,    48,     9,     0,
      49,     0,     0,     0,    50,    51,    52,    53,    54,     0,
       0,     0,     0,    10,     0,     0,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,     0,
       0,     0,     0,    67,     0,    68,     0,    69,     0,     0,
       0,    11,    12,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,     0,    21,    22,    23,     0,
       0,     0,     0,     0,    24,    25,    26,    27,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,     0,    39,   493,    40,     0,     0,    41,     0,     0,
       0,    42,    43,    44,    45,    46,    47,    48,     0,     0,
      49,     0,     0,     0,    50,    51,    52,    53,    54,     0,
       0,     0,     0,     9,     0,     0,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    10,     0,
       0,     0,     0,    67,     0,    68,     0,    69,     0,     0,
       0,   223,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
       0,    21,    22,    23,     0,     0,     0,     0,     0,    24,
      25,    26,    27,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     0,    39,     0,    40,
       0,     0,    41,     0,     0,     0,    42,    43,    44,   106,
      46,    47,    48,     0,     0,    49,     0,     0,     0,     0,
       0,   121,     0,     0,     0,     0,     0,     0,     9,     0,
       0,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    10,     0,     0,     0,     0,    67,     0,
      68,     0,    69,     0,     0,     0,   433,     0,     0,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    11,    12,     0,     0,     0,     0,    13,    14,    15,
      16,    17,    18,    19,    20,     0,    21,    22,    23,     0,
       0,     0,     0,     0,    24,    25,    26,    27,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,     0,    39,     0,    40,     0,     0,    41,     0,     0,
       0,    42,    43,    44,   134,    46,    47,    48,     0,     0,
      49,     0,     0,     0,     0,     0,   121,     0,     0,     0,
       0,     0,     0,     9,     0,     0,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    10,     0,
       0,     0,     0,    67,     0,    68,     0,    69,     0,     0,
       0,   480,     0,     0,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    11,    12,     0,     0,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
       0,    21,    22,    23,     0,     0,     0,     0,     0,    24,
      25,    26,    27,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     0,    39,     0,    40,
       0,     0,    41,     0,     0,     0,    42,    43,    44,     0,
      46,    47,    48,     9,     0,    49,     0,     0,     0,     0,
       0,   121,     0,     0,     0,     0,     0,     0,    10,     0,
       0,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,     0,     0,     0,     0,    67,     0,
      68,     0,    69,     0,     0,     0,    11,    12,   410,     0,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
       0,    21,    22,    23,     0,     0,     0,     0,     0,    24,
      25,    26,    27,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,     0,    39,     0,    40,
       0,     0,    41,     0,     0,     0,    42,    43,    44,     0,
      46,    47,    48,     0,     0,    49,     0,     0,     0,     0,
       0,   121,     0,     0,     0,     0,  -126,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,     0,     0,     0,     0,    67,     0,
      68,     0,    69,     0,  -126,  -126,     0,     0,     0,     0,
       0,   411,   412,   413,   414,   415,   416,    53,    54,     0,
       0,     0,     0,     0,     0,     0,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,   156,   157,
     158,     0,     0,     0,     0,     0,   469,     0,     0,     0,
       0,     0,     0,     0,   159,     0,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   156,   157,   158,     0,
       0,     0,     0,     0,   180,     0,     0,     0,     0,     0,
       0,     0,   159,     0,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   156,   157,   158,     0,     0,     0,
       0,     0,   180,     0,     0,     0,     0,     0,     0,     0,
     159,     0,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     0,   156,   157,   158,     0,     0,     0,     0,
     180,     0,     0,     0,     0,     0,     0,     0,   347,   159,
       0,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   156,   157,   158,     0,     0,     0,     0,     0,   180,
       0,     0,     0,     0,     0,     0,   351,   159,     0,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   156,
     157,   158,     0,     0,     0,     0,     0,   180,     0,     0,
       0,     0,   181,     0,     0,   159,     0,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   156,   157,   158,
     100,   101,     0,     0,     0,   180,     0,     0,     0,     0,
       0,   230,     0,   159,     0,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,     0,     0,    10,     0,     0,
       0,     0,     0,   180,     0,     0,     0,     0,     0,   231,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,     0,   134,     0,    11,    12,     0,     0,   102,
       0,    13,    14,    15,    16,    17,    18,    19,    20,     0,
      21,    22,     0,     0,     0,     0,     0,   236,    24,    25,
      91,    27,   465,     0,    28,    29,    30,    31,     0,    33,
      34,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,   156,   157,   158,   134,     0,     0,     0,    68,
       0,     0,     0,   300,     0,     0,     0,     0,   159,     0,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
      10,     0,     0,   142,   143,     0,   144,     0,   180,     0,
       0,     0,     0,     0,     0,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,    11,    12,
       0,     0,     0,     0,    13,    14,    15,    16,    17,    18,
      19,    20,     0,    21,    22,     0,     0,     0,     0,     0,
       0,    24,    25,    91,    27,     0,     0,    28,    29,    30,
      31,     0,    33,    34,    35,   159,     0,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   249,     0,     0,
       0,    10,     0,     0,     0,   180,     0,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,     0,     0,    11,
      12,     0,    68,     0,   127,    13,    14,    15,    16,    17,
      18,    19,    20,     0,    21,    22,     0,     0,     0,     0,
       0,     0,    24,    25,    91,    27,   158,     0,    28,    29,
      30,    31,     0,    33,    34,    35,     0,     0,     0,     0,
     159,     0,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,    10,     0,     0,     0,     0,     0,     0,     0,
     180,     0,     0,     0,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,     0,     0,     0,
      11,    12,     0,    68,     0,   129,    13,    14,    15,    16,
      17,    18,    19,    20,     0,    21,    22,     0,     0,     0,
       0,     0,     0,    24,    25,    91,    27,   157,   158,    28,
      29,    30,    31,     0,    33,    34,    35,     0,     0,     0,
       0,     0,   159,     0,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,     0,     0,     0,     0,     0,    10,
       0,     0,   180,     0,     0,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,   212,     0,
       0,     0,     0,     0,    68,     0,   136,    11,    12,     0,
       0,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,     0,    21,    22,     0,     0,     0,     0,     0,     0,
      24,    25,    91,    27,     0,     0,    28,    29,    30,    31,
       0,    33,    34,    35,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,     0,     0,     0,     0,     0,     0,
       0,     0,   180,     0,     0,    10,     0,     0,     0,     0,
       0,   213,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,   212,     0,     0,     0,     0,     0,
     214,    68,     0,    11,    12,     0,     0,     0,     0,    13,
      14,    15,    16,    17,    18,    19,    20,     0,    21,    22,
       0,     0,     0,     0,     0,     0,    24,    25,    91,    27,
       0,     0,    28,    29,    30,    31,     0,    33,    34,    35,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,     0,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   213,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      10,     0,     0,     0,     0,     0,     0,    68,     0,     0,
       0,     0,     0,   255,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
       0,     0,     0,     0,    13,    14,    15,    16,    17,    18,
      19,    20,     0,    21,    22,     0,     0,     0,     0,     0,
       0,    24,    25,    91,    27,     0,     0,    28,    29,    30,
      31,     0,    33,    34,    35,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,     0,     0,     0,     0,     0,     0,     0,     0,
     180,     0,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,   386,     0,     0,     0,     0,
       0,     0,    68,     0,    11,    12,     0,     0,     0,     0,
      13,    14,    15,    16,    17,    18,    19,    20,     0,    21,
      22,     0,     0,     0,     0,     0,     0,    24,    25,    91,
      27,     0,     0,    28,    29,    30,    31,     0,    33,    34,
      35,     0,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,     0,     0,
       0,     0,     0,     0,     0,    10,   180,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,     0,    11,    12,     0,     0,     0,    68,    13,
      14,    15,    16,    17,    18,    19,    20,     0,    21,    22,
       0,     0,     0,     0,     0,     0,    24,    25,    91,    27,
       0,     0,    28,    29,    30,    31,     0,    33,    34,    35,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,     0,     0,     0,     0,     0,
       0,     0,     0,   180,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,     0,    11,    12,     0,     0,     0,    68,    13,    14,
      15,    16,    17,    18,    19,    20,     0,    21,    22,     0,
       0,     0,     0,     0,     0,    24,    25,   150,    27,     0,
       0,    28,    29,    30,    31,     0,    33,    34,    35,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,     0,     0,     0,     0,     0,     0,     0,
       0,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,   156,
     157,   158,     0,     0,     0,     0,    68,     0,     0,     0,
       0,     0,     0,     0,     0,   159,     0,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   156,   157,   158,
       0,     0,     0,     0,     0,   180,     0,     0,     0,     0,
       0,     0,     0,   159,   343,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,     0,   315,   156,   157,   158,
       0,     0,     0,   180,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,   397,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   156,   157,   158,     0,     0,
       0,     0,     0,   180,     0,     0,     0,     0,     0,     0,
       0,   159,     0,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,     0,     0,     0,     0,     0,     0,     0,
       0,   180,  -260,  -260,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,     0,     0,     0,     0,
       0,     0,     0,     0,   180,  -260,  -260,  -260,  -260,   172,
     173,   174,   175,   176,   177,   178,   179,     0,     0,     0,
       0,     0,     0,     0,     0,   180
};

static const short int yycheck[] =
{
       8,    48,     8,   329,    46,   371,    11,   323,    19,    20,
      52,   359,    70,   329,    68,     1,    32,    11,   135,    11,
      11,   138,    77,   117,     0,    92,    93,   117,    23,    37,
     115,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    38,   138,   135,    41,   135,   102,    70,
     138,    44,    45,    46,    47,    48,    49,    11,    12,    13,
      14,    15,    16,    17,    18,    58,   116,    21,    29,   138,
      86,    56,    57,   140,   136,    45,    35,   135,   140,   121,
     138,   447,    36,    69,   432,    47,    48,    49,    42,    43,
     106,    60,   117,    47,    15,    49,    58,    67,    68,    69,
     138,    70,   110,    73,    74,    75,    76,   318,   223,   320,
     135,    97,    98,   138,    68,   123,    69,    70,   104,   105,
     106,   107,   108,   109,   110,   111,    69,    70,    69,   114,
      69,    70,   137,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   117,   140,   473,   140,   140,
     107,   108,   109,   139,   209,   109,   117,   473,   107,   108,
     114,   110,   488,   135,   138,   491,   138,   104,   105,   106,
      69,   125,   488,   136,   135,   491,   110,   138,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      64,   110,    66,   209,   101,   102,    92,    93,    69,   241,
     141,   212,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   222,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    69,   297,   197,   117,    70,   200,   362,    67,    68,
     401,   402,   135,   207,   135,   114,   135,   114,    58,   213,
     114,    60,   135,   135,   137,   138,   220,   322,    83,    70,
     140,   138,   226,   142,   136,   140,    69,   293,   325,   321,
     296,   297,   397,   299,   110,    70,   110,   137,    69,   112,
     137,    69,    69,   309,   248,   138,    69,    16,    16,    69,
     136,   255,   142,   114,   315,   112,    12,    13,    14,   142,
     140,    11,    29,   140,   136,    11,    69,   138,   433,   139,
     137,   113,    28,   136,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,   140,   353,   137,    11,   137,   139,
      11,   117,    58,   307,   140,    69,    69,   352,    11,   401,
     402,   136,   316,   139,    29,   480,   140,   118,    69,    97,
     139,    70,    70,   137,   380,   386,   137,    16,    69,    16,
      70,   140,   138,    70,   392,    16,   140,   137,   396,   343,
       8,   401,   485,   383,   494,   437,   350,   307,   402,   241,
     422,   425,   421,   477,    36,   359,   448,    22,   391,    -1,
     428,    -1,    -1,    -1,   461,    -1,   463,     1,    -1,    -1,
      -1,    -1,    -1,   465,    -1,    -1,    -1,   381,    -1,    -1,
      -1,    -1,    16,    -1,    -1,   477,   142,   391,    -1,    -1,
      -1,    -1,    -1,   485,    -1,    -1,    -1,    -1,   454,    -1,
      -1,   498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,   470,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,   428,    59,    60,    61,   432,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    -1,    -1,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    85,    -1,    87,    -1,    -1,    90,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     1,    -1,   103,
      -1,    -1,    -1,   107,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,    16,    -1,    -1,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,   140,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    -1,    -1,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    85,    -1,    87,    -1,    -1,    90,    -1,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     1,    -1,   103,
      -1,    -1,    -1,   107,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,    16,    -1,    -1,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,   140,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    -1,    -1,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    85,    -1,    87,    -1,    -1,    90,    -1,    -1,    -1,
      94,    95,    96,    97,    98,    99,   100,    -1,     1,   103,
      -1,    -1,    -1,   107,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,   116,    16,    -1,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,    -1,   140,    -1,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    85,    -1,    87,    -1,    -1,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,     1,    -1,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,    16,    -1,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,   136,    -1,   138,   139,   140,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    87,    -1,    -1,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,     1,    -1,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,    16,    -1,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    85,    -1,    87,    88,    -1,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,     1,    -1,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,    16,    -1,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    -1,    -1,
      -1,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,    -1,
      -1,    44,    45,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    85,    86,    87,    -1,    -1,    90,    -1,    -1,
      -1,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
     103,    -1,    -1,    -1,   107,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,     1,    -1,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    16,    -1,
      -1,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    -1,    -1,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    85,    -1,    87,
      -1,    -1,    90,    -1,    -1,    -1,    94,    95,    96,    69,
      98,    99,   100,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      -1,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    16,    -1,    -1,    -1,    -1,   136,    -1,
     138,    -1,   140,    -1,    -1,    -1,    29,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    44,    45,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    -1,    -1,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    85,    -1,    87,    -1,    -1,    90,    -1,    -1,
      -1,    94,    95,    96,    69,    98,    99,   100,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    16,    -1,
      -1,    -1,    -1,   136,    -1,   138,    -1,   140,    -1,    -1,
      -1,    29,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    44,    45,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    -1,    -1,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    85,    -1,    87,
      -1,    -1,    90,    -1,    -1,    -1,    94,    95,    96,    -1,
      98,    99,   100,     1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      -1,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,    -1,   140,    -1,    -1,    -1,    44,    45,     1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    -1,    -1,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    85,    -1,    87,
      -1,    -1,    90,    -1,    -1,    -1,    94,    95,    96,    -1,
      98,    99,   100,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,    -1,   140,    -1,    97,    98,    -1,    -1,    -1,    -1,
      -1,   104,   105,   106,   107,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    12,    13,    14,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    12,    13,    14,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    12,    13,    14,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    28,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    28,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    -1,   140,    -1,    -1,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    12,    13,    14,
      69,    70,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,   140,    -1,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,   140,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    -1,    69,    -1,    44,    45,    -1,    -1,   138,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    -1,    -1,    -1,    -1,    -1,   140,    67,    68,
      69,    70,    98,    -1,    73,    74,    75,    76,    -1,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    12,    13,    14,    69,    -1,    -1,    -1,   138,
      -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      16,    -1,    -1,   107,   108,    -1,   110,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    44,    45,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    -1,    -1,    73,    74,    75,
      76,    -1,    78,    79,    80,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,   137,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,    44,
      45,    -1,   138,    -1,   140,    50,    51,    52,    53,    54,
      55,    56,    57,    -1,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    14,    -1,    73,    74,
      75,    76,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,
      28,    -1,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,    -1,    -1,    -1,    -1,
      44,    45,    -1,   138,    -1,   140,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    13,    14,    73,
      74,    75,    76,    -1,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    58,    -1,    -1,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    -1,    35,    -1,
      -1,    -1,    -1,    -1,   138,    -1,   140,    44,    45,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    -1,    -1,    73,    74,    75,    76,
      -1,    78,    79,    80,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,    35,    -1,    -1,    -1,    -1,    -1,
     137,   138,    -1,    44,    45,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      -1,    -1,    73,    74,    75,    76,    -1,    78,    79,    80,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      16,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,
      -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    68,    69,    70,    -1,    -1,    73,    74,    75,
      76,    -1,    78,    79,    80,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,    35,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    44,    45,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    -1,    -1,    73,    74,    75,    76,    -1,    78,    79,
      80,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    -1,    -1,    44,    45,    -1,    -1,    -1,   138,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      -1,    -1,    73,    74,    75,    76,    -1,    78,    79,    80,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    58,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
      -1,    -1,    44,    45,    -1,    -1,    -1,   138,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    -1,
      -1,    73,    74,    75,    76,    -1,    78,    79,    80,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,    12,
      13,    14,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    -1,    89,    12,    13,    14,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,   144,   145,     0,   115,   146,   147,   116,   148,     1,
      16,    44,    45,    50,    51,    52,    53,    54,    55,    56,
      57,    59,    60,    61,    67,    68,    69,    70,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    85,
      87,    90,    94,    95,    96,    97,    98,    99,   100,   103,
     107,   108,   109,   110,   111,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   136,   138,   140,
     149,   152,   154,   161,   163,   165,   199,   201,   204,   205,
     207,   209,   210,   211,   213,   215,   216,   217,   218,   219,
      70,    69,   204,   204,   204,   204,   204,   204,   204,   204,
      69,    70,   138,   215,   215,   204,    69,   201,   208,   138,
     205,    29,   117,   135,   138,   184,   200,    15,   184,   202,
     204,   109,   154,   205,   155,   138,   205,   140,   204,   140,
     204,    69,    35,   159,    69,   199,   140,   204,   152,   204,
     110,   110,   107,   108,   110,   187,   188,   199,    69,   153,
      69,   204,   207,    69,    70,   200,    12,    13,    14,    28,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      58,   140,   135,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    56,    57,   135,   184,   114,
     135,   114,   117,    70,   207,   117,   184,   135,   154,    69,
      70,   142,    35,   118,   137,   185,   186,   204,    60,   140,
      11,   140,    83,    29,   154,   175,   138,   204,   136,   172,
     140,   140,   140,    69,   117,    70,   140,   156,   140,   110,
     110,    11,   140,    70,   112,   167,   150,   135,   137,   137,
     137,   164,   204,   204,   204,    29,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   204,   204,   204,   204,   204,   204,   204,   204,
     204,   204,   206,    69,    70,   204,    69,    69,   137,    69,
     142,   204,   176,   184,   200,   215,   204,    11,   137,    69,
     204,   205,   150,   202,   203,    89,    92,    93,   140,   173,
     174,   138,    69,    16,   101,   102,   157,   158,   188,    16,
      69,   169,   136,   139,   151,   154,   161,   163,   142,   204,
     112,   166,   204,    29,   142,   142,   184,   142,   184,   184,
     136,   142,    64,    66,   177,   186,   184,   140,    84,   140,
     215,   204,    29,   173,   139,   173,   178,   179,   180,   181,
     182,   199,    45,    69,   211,   212,   138,   152,   212,    11,
     189,   137,    69,   113,   168,   204,    35,   204,   220,   221,
     222,   136,   205,   154,   140,   203,   137,    29,   150,   139,
     137,    11,    11,   159,    67,    68,   117,   140,    69,    69,
       1,   104,   105,   106,   107,   108,   109,   139,   163,   190,
     194,   195,   196,   204,   169,   136,   215,   139,    11,   214,
     220,   154,   140,    29,   154,   171,   150,    29,   183,   180,
     181,   181,   182,   118,   160,    69,    70,    97,   191,   107,
     108,   109,   196,   195,   189,   222,   139,   203,   150,   141,
     199,   162,    70,   137,   159,    98,   197,   198,   199,   139,
     137,    88,   152,    16,   152,    69,   199,    11,   140,    70,
      29,   154,   170,   140,   212,   138,    70,   198,    16,   150,
     178,    16,   212,    86,   137,   212,   140,   183,   192,   140,
     152,   193
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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
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
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
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
  const char *yys = yystr;

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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



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
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
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

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



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
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
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

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

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

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

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
#line 183 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { EatUntilGetPhpTag(); startNewScope();;}
    break;

  case 3:
#line 183 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { 
																						  EndOfPhpCode();
																						  debuggerYACC(" X205 - start << T_OPEN_TAG_PHP top_statement_list T_CLOSE_TAG_PHP");
																						  EatUntilEndOfFile();

																						  (yyval.ast) = ast->createNode((yyvsp[-1].ast),0,scopeNode)->addScopeSize(closeScope());
																						  finalTree = (yyval.ast);
																						;}
    break;

  case 4:
#line 194 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {	 
			 ClassDeclaration("Object"); 
			 TempTree = ast->createNode(ast->createNode(0,0,classListNode),0,classNode);
			 TempTree->addSymbolTableElement(ClassDeclarationEnd());
		;}
    break;

  case 5:
#line 200 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {
			 (yyval.ast) = ast->addToLastRight(ast->createNode(TempTree,0,stmtListNode), (yyvsp[0].ast));
		;}
    break;

  case 6:
#line 206 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->addToLastRight((yyvsp[-1].ast), (yyvsp[0].ast));     debuggerYACC(" X211 - top_statement_list << top_statement_list top_statement"); ;}
    break;

  case 7:
#line 207 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,stmtListNode);       debuggerYACC(" X212 - top_statement_list << | /* empty */"); ;}
    break;

  case 8:
#line 211 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[0].ast),0,stmtListNode);  debuggerYACC(" X304 - top_statement << statement"); ;}
    break;

  case 9:
#line 212 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[0].ast),0,stmtListNode); debuggerYACC(" X305 - top_statement << | function_declaration_statement"); ;}
    break;

  case 10:
#line 213 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[0].ast),0,stmtListNode); debuggerYACC(" X306 - top_statement << | class_declaration_statement"); ;}
    break;

  case 11:
#line 217 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->addToLastRight((yyvsp[-1].ast),(yyvsp[0].ast));   debuggerYACC(" X382 - inner_statement_list << inner_statement_list inner_statement"); ;}
    break;

  case 12:
#line 218 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,stmtListNode);    debuggerYACC(" X383 - inner_statement_list << | /* empty */"); ;}
    break;

  case 13:
#line 223 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { IncreceStatementNumber(); (yyval.ast) = ast->createNode((yyvsp[0].ast),0,stmtListNode); debuggerYACC(" X387 - inner_statement << statement"); ;}
    break;

  case 14:
#line 224 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[0].ast),0,stmtListNode); debuggerYACC(" X388 - inner_statement << | function_declaration_statement"); ;}
    break;

  case 15:
#line 225 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[0].ast),0,stmtListNode); debuggerYACC(" X389 - inner_statement << | class_declaration_statement"); ;}
    break;

  case 16:
#line 229 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { startNewScope(); ;}
    break;

  case 17:
#line 229 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-1].ast),0,scopeNode)->addScopeSize(closeScope());  debuggerYACC(" X395 - scope << '{' inner_statement_list '}'"); ;}
    break;

  case 19:
#line 235 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { 
			(yyval.ast)=ast->createNode(
						ast->createNode((yyvsp[-4].ast),(yyvsp[-3].ast),ifConditionAndBodyNode),
						
						ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),elseNode),
						
						ifNode);
			debuggerYACC(" X396 - statement << | T_IF parentheses_expr statement elseif_list T_ELSE statement"); 
		;}
    break;

  case 20:
#line 245 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  
			(yyval.ast)=ast->createNode(
						ast->createNode((yyvsp[-2].ast),(yyvsp[-1].ast),ifConditionAndBodyNode),
						ast->createNode((yyvsp[0].ast),0,elseNode),
						ifNode);
			debuggerYACC(" X397 - statement << | T_IF parentheses_expr statement elseif_list %prec    elseif_list_test"); 
		;}
    break;

  case 21:
#line 253 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=ast->createNode((yyvsp[-1].ast),(yyvsp[0].ast),whileNode);     debuggerYACC(" X401 - statement << | T_WHILE parentheses_expr while_statement"); ;}
    break;

  case 22:
#line 254 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=ast->createNode((yyvsp[-3].ast),(yyvsp[-1].ast),doWhileNode);    debuggerYACC(" X402 - statement << | T_DO statement T_WHILE parentheses_expr ';'"); ;}
    break;

  case 23:
#line 255 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { startNewScope(); ;}
    break;

  case 24:
#line 256 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {
			(yyval.ast)=
				ast->createNode
				(
					ast->createNode
					(
						ast->createNode((yyvsp[-6].ast),(yyvsp[-4].ast),forHeaderNode),
						ast->createNode((yyvsp[0].ast),(yyvsp[-2].ast),forBodyNode),
						forNode
					)
				,0,scopeNode)->addScopeSize(closeScope());

		    debuggerYACC(" X403 - statement << | T_FOR '(' for_expr ';'  for_expr ';' for_expr ')' for_statement"); 
		;}
    break;

  case 25:
#line 271 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-1].ast), (yyvsp[0].ast),switchNode);  debuggerYACC(" X405 - statement << | T_SWITCH parentheses_expr switch_case_list"); ;}
    break;

  case 26:
#line 272 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0, 0,breakNode);                                                         debuggerYACC(" X406 - statement << | T_BREAK ';'"); ;}
    break;

  case 27:
#line 273 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-1].ast),0,breakNode);                               debuggerYACC(" X407 - statement << | T_BREAK expr ';'"); ;}
    break;

  case 28:
#line 274 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,continueNode);     debuggerYACC(" X408 - statement << | T_CONTINUE ';'"); ;}
    break;

  case 29:
#line 275 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-1].ast),0,continueNode);       debuggerYACC(" X409 - statement << | T_CONTINUE expr ';'"); ;}
    break;

  case 30:
#line 276 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,returnNode);                                                          debuggerYACC(" X410 - statement << | T_RETURN ';'"); ;}
    break;

  case 31:
#line 277 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-1].ast),0,returnNode);  debuggerYACC(" X411 - statement << | T_RETURN expr ';'"); ;}
    break;

  case 32:
#line 278 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = (yyvsp[-1].ast);  debuggerYACC(" X414 - statement << | T_STATIC static_var_list ';'"); ;}
    break;

  case 33:
#line 279 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-1].ast),0,echoNode);     debuggerYACC(" X415 - statement << | T_ECHO expr_list ';'"); ;}
    break;

  case 34:
#line 280 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[-1].ast); debuggerYACC(" X417 - statement << | expr ';'"); ;}
    break;

  case 35:
#line 281 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(ast->createNode((yyvsp[-4].ast),(yyvsp[-2].ast),asNode),(yyvsp[0].ast),foreachNode); debuggerYACC(" X419 - statement << | T_FOREACH '('expr T_AS foreach_variable ')'foreach_statement"); ;}
    break;

  case 36:
#line 283 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,emptyNode); debuggerYACC(" X424 - statement << | ';'"); ;}
    break;

  case 37:
#line 284 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[-1].ast),tryNode);  debuggerYACC(" X425 - statement << | T_TRY '{' inner_statement_list '}' catches optional_finally"); ;}
    break;

  case 38:
#line 286 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X427 - statement << | T_THROW expr ';'"); ;}
    break;

  case 39:
#line 287 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X428 - statement << | T_GOTO T_STRING ';'"); ;}
    break;

  case 40:
#line 288 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X429 - statement << | T_STRING ':'"); ;}
    break;

  case 41:
#line 289 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {    (yyval.ast)=ast->createNode(0,(yyvsp[-1].ast),functionCallNode); (yyval.ast)->addSymbolTableElement(SuperKeywordShowedUp()); ;}
    break;

  case 42:
#line 290 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-4].ast),0,idVariableNode); (yyval.ast)->addSymbolTableElement(addVariable((yyvsp[-4].r.str),(yyvsp[-3].r.str),(yyvsp[-1].r.str),true));  debuggerYACC(" X369 -  << T_STRING '=' static_scalar"); ;}
    break;

  case 43:
#line 291 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { EatUntilNewLine(); (yyval.ast)=NULL;  debuggerYACC(" X430 - statement << | error"); ;}
    break;

  case 44:
#line 295 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = NULL;    debuggerYACC(" X438 - catches << /* empty */"); ;}
    break;

  case 45:
#line 296 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->addToLastRight((yyvsp[-1].ast),(yyvsp[0].ast));    debuggerYACC(" X439 - catches << | catches catch"); ;}
    break;

  case 46:
#line 300 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-1].ast),0,tryNode);    debuggerYACC(" X443 - catch << T_CATCH '('name T_VARIABLE ')''{' inner_statement_list '}'"); ;}
    break;

  case 47:
#line 304 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X447 - optional_finally << /* empty */"); ;}
    break;

  case 48:
#line 305 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X448 - optional_finally << | T_FINALLY '{' inner_statement_list '}'"); ;}
    break;

  case 49:
#line 309 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { Optional_ref = false;  debuggerYACC(" X457 - optional_ref << /* empty */"); ;}
    break;

  case 50:
#line 310 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { Optional_ref = true;  debuggerYACC(" X458 - optional_ref << | '&'"); ;}
    break;

  case 51:
#line 314 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X462 - optional_ellipsis << /* empty */"); ;}
    break;

  case 52:
#line 315 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X463 - optional_ellipsis << | T_ELLIPSIS"); ;}
    break;

  case 53:
#line 319 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { FunctionDeclaration((yyvsp[-4].r.str),false); resetStatementNumber(); ;}
    break;

  case 54:
#line 319 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-4].ast),(yyvsp[0].ast),functionNode); (yyval.ast)->addSymbolTableElement(FunctionDeclarationEnd());                debuggerYACC(" X467 - function_declaration_statement << T_FUNCTION optional_ref T_STRING '('parameter_list ')' optional_return_type '{' inner_statement_list '}' "); ;}
    break;

  case 55:
#line 323 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { ClassDeclaration((yyvsp[0].r.str)); ;}
    break;

  case 56:
#line 323 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-1].ast),0,classNode); (yyval.ast)->addSymbolTableElement(ClassDeclarationEnd()); debuggerYACC(" X472 - class_declaration_statement << class_entry_type T_STRING extends_from implements_list '{' class_statement_list '}'"); ;}
    break;

  case 57:
#line 324 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X474 - class_declaration_statement << | T_INTERFACE T_STRING interface_extends_list '{' class_statement_list '}'"); ;}
    break;

  case 58:
#line 329 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {												debuggerYACC(" X480 - class_entry_type << T_CLASS"); ;}
    break;

  case 59:
#line 330 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { isClassAbstract = true;						debuggerYACC(" X481 - class_entry_type << | T_ABSTRACT T_CLASS"); ;}
    break;

  case 60:
#line 331 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { isClassFinal = true;							debuggerYACC(" X482 - class_entry_type << | T_FINAL T_CLASS"); ;}
    break;

  case 61:
#line 333 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { isClassStatic = true;							debuggerYACC(" X482 - class_entry_type << | T_FINAL T_CLASS"); ;}
    break;

  case 62:
#line 334 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { isClassStatic = true; isClassAbstract = true; debuggerYACC(" X481 - class_entry_type << | T_ABSTRACT T_CLASS"); ;}
    break;

  case 63:
#line 335 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { isClassStatic = true; isClassFinal = true;	debuggerYACC(" X482 - class_entry_type << | T_FINAL T_CLASS"); ;}
    break;

  case 64:
#line 339 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X486 - extends_from << /* empty */"); ;}
    break;

  case 65:
#line 340 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { ClassDeclarationAddInheritedClass((yyvsp[0].r.str));      debuggerYACC(" X487 - extends_from << | T_EXTENDS name"); ;}
    break;

  case 66:
#line 344 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X491 - interface_extends_list << /* empty */"); ;}
    break;

  case 67:
#line 345 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X492 - interface_extends_list << | T_EXTENDS name_list"); ;}
    break;

  case 68:
#line 349 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X496 - implements_list << /* empty */"); ;}
    break;

  case 69:
#line 350 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X497 - implements_list << | T_IMPLEMENTS name_list"); ;}
    break;

  case 70:
#line 354 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { ClassDeclarationAddImplementInterface((yyvsp[0].r.str));   debuggerYACC(" X501 - name_list << name"); ;}
    break;

  case 71:
#line 355 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {ClassDeclarationAddImplementInterface((yyvsp[0].r.str));   debuggerYACC(" X502 - name_list << | name_list ',' name"); ;}
    break;

  case 72:
#line 359 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast);   debuggerYACC(" X506 - for_statement << statement"); ;}
    break;

  case 73:
#line 360 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X507 - for_statement << | ':' inner_statement_list T_ENDFOR ';'"); ;}
    break;

  case 74:
#line 364 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast);     debuggerYACC(" X511 - foreach_statement << statement"); ;}
    break;

  case 75:
#line 365 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X512 - foreach_statement << | ':' inner_statement_list T_ENDFOREACH ';'"); ;}
    break;

  case 76:
#line 369 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = (yyvsp[-1].ast);                                       debuggerYACC(" X530 - switch_case_list << '{' case_list '}'"); ;}
    break;

  case 77:
#line 370 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = (yyvsp[-1].ast);                                       debuggerYACC(" X531 - switch_case_list << | '{' ';' case_list '}'"); ;}
    break;

  case 78:
#line 374 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {            (yyval.ast) = ast->createNode(0,0,listcaseNode);                                           debuggerYACC(" X537 - case_list << /* empty */"); ;}
    break;

  case 79:
#line 375 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {           (yyval.ast) = ast->addToLastRight((yyvsp[-1].ast),(yyvsp[0].ast));                                                                     debuggerYACC(" X538 - case_list << | case_list case"); ;}
    break;

  case 80:
#line 379 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),caseNode); (yyval.ast) = ast->createNode((yyval.ast),0,listcaseNode); debuggerYACC(" X542 - case << T_CASE expr case_separator inner_statement_list"); ;}
    break;

  case 81:
#line 380 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,(yyvsp[0].ast),defaultNode);   (yyval.ast) = ast->createNode((yyval.ast),0,listcaseNode);  debuggerYACC(" X543 - case << | T_DEFAULT case_separator inner_statement_list"); ;}
    break;

  case 82:
#line 385 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast);     debuggerYACC(" X552 - while_statement << statement"); ;}
    break;

  case 83:
#line 386 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X553 - while_statement << | ':' inner_statement_list T_ENDWHILE ';'"); ;}
    break;

  case 84:
#line 390 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = ast->createNode(0,0,elseNode); debuggerYACC(" X557 - elseif_list << /* empty */"); ;}
    break;

  case 85:
#line 391 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = ast->addToLastRight((yyvsp[-1].ast),(yyvsp[0].ast));  debuggerYACC(" X558 - elseif_list << | elseif_list elseif"); ;}
    break;

  case 86:
#line 396 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { 
						(yyval.ast) = ast->createNode(
												  ast->createNode((yyvsp[-1].ast),(yyvsp[0].ast),elseifConditionAndBodyNode),
												  0,elseNode);
						
						debuggerYACC(" X563 - elseif << T_ELSEIF parentheses_expr statement"); 
				;}
    break;

  case 87:
#line 406 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->addToLastRight((yyvsp[-2].ast),(yyvsp[0].ast)); debuggerYACC(" X589 - parameter_list << non_empty_parameter_list ',' non_empty_optional_parameter_list"); ;}
    break;

  case 88:
#line 407 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast);  debuggerYACC(" X590 - parameter_list << | non_empty_parameter_list"); ;}
    break;

  case 89:
#line 408 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast); debuggerYACC(" X591 - parameter_list << | non_empty_optional_parameter_list"); ;}
    break;

  case 90:
#line 409 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = NULL; debuggerYACC(" X592 - parameter_list << |"); ;}
    break;

  case 91:
#line 413 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast);  debuggerYACC(" X596 - non_empty_parameter_list << parameter"); ;}
    break;

  case 92:
#line 414 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->addToLastRight((yyvsp[-2].ast),(yyvsp[0].ast)); debuggerYACC(" X597 - non_empty_parameter_list << | non_empty_parameter_list ',' parameter"); ;}
    break;

  case 93:
#line 418 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast);  debuggerYACC(" X601 - non_empty_optional_parameter_list << optional_parameter"); ;}
    break;

  case 94:
#line 419 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->addToLastRight((yyvsp[-2].ast),(yyvsp[0].ast));  debuggerYACC(" X602 - non_empty_optional_parameter_list << | non_empty_optional_parameter_list ',' optional_parameter"); ;}
    break;

  case 95:
#line 420 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->addToLastRight((yyvsp[-2].ast),(yyvsp[0].ast));  errorhandler("optional parameter not at end of parameter list"); ;}
    break;

  case 96:
#line 424 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-3].ast),0,paramNode); (yyval.ast)->addSymbolTableElement(addParametertoFunction((yyvsp[-3].r.str),(yyvsp[0].r.str),NULL));  debuggerYACC(" X606 - parameter << optional_param_type optional_ref optional_ellipsis var_type_or_nameT_VARIABLE"); ;}
    break;

  case 97:
#line 428 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-5].ast),0,paramNode); (yyval.ast)->addSymbolTableElement(addParametertoFunction((yyvsp[-5].r.str),(yyvsp[-2].r.str),(yyvsp[0].r.str),(yyvsp[0].ast)));   debuggerYACC(" X610 - optional_parameter << optional_param_type optional_ref optional_ellipsis var_type_or_nameT_VARIABLE '=' static_scalar"); ;}
    break;

  case 98:
#line 432 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { returnType = "void"; ;}
    break;

  case 99:
#line 433 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { returnType = "$";      debuggerYACC(" X626 - optional_return_type << /* empty */"); ;}
    break;

  case 100:
#line 434 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { returnType = (yyvsp[0].r.str); (yyval.ast)=ast->createNode((yyvsp[0].ast),0,returnTypeNode);  debuggerYACC(" X628 - optional_return_type << | ':' var_type_or_name"); ;}
    break;

  case 101:
#line 438 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)= NULL; debuggerYACC(" X632 - argument_list << '('')'"); ;}
    break;

  case 102:
#line 439 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)= (yyvsp[-1].ast);  debuggerYACC(" X633 - argument_list << | '('non_empty_argument_list ')'"); ;}
    break;

  case 103:
#line 443 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->addToLastRight((yyvsp[-2].ast),(yyvsp[0].ast)); debuggerYACC(" X639 - non_empty_argument_list << | non_empty_argument_list ',' argument"); ;}
    break;

  case 104:
#line 444 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast);     debuggerYACC(" X638 - non_empty_argument_list << argument"); ;}
    break;

  case 105:
#line 448 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[0].ast),0,argumentNode);      debuggerYACC(" X643 - argument << expr"); ;}
    break;

  case 106:
#line 449 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[0].ast),0,argumentReferencNode);      debuggerYACC(" X644 - argument << | '&' variable"); ;}
    break;

  case 107:
#line 450 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = NULL;/*????*/      debuggerYACC(" X645 - argument << | T_ELLIPSIS expr"); ;}
    break;

  case 108:
#line 455 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast)=ast->addToLastRight((yyvsp[-2].ast),(yyvsp[0].ast)); debuggerYACC(" X660 - static_var_list << static_var_list ',' static_var"); ;}
    break;

  case 109:
#line 456 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast)=(yyvsp[0].ast); debuggerYACC(" X661 - static_var_list << | static_var"); ;}
    break;

  case 110:
#line 460 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-1].ast),0,staticVariableNode); (yyval.ast)->addSymbolTableElement(addStaticVariable((yyvsp[-1].r.str),(yyvsp[0].r.str),0));                   debuggerYACC(" X665 - static_var << var_type_or_nameT_VARIABLE"); ;}
    break;

  case 111:
#line 461 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-3].ast),0,staticVariableNode); (yyval.ast)->addSymbolTableElement(addStaticVariable((yyvsp[-3].r.str),(yyvsp[-2].r.str),(yyvsp[0].r.str)));          debuggerYACC(" X666 - static_var << | var_type_or_nameT_VARIABLE '=' static_scalar"); ;}
    break;

  case 112:
#line 465 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->addToLastRight((yyvsp[-1].ast),(yyvsp[0].ast));		  debuggerYACC(" X670 - class_statement_list << class_statement_list class_statement"); ;}
    break;

  case 113:
#line 466 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,classListNode);    debuggerYACC(" X671 - class_statement_list << | /* empty */"); ;}
    break;

  case 114:
#line 470 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { addDataMemeberStart(); ;}
    break;

  case 115:
#line 470 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { addDataMemeberEnd(); (yyval.ast) = ast->createNode((yyvsp[-1].ast),0,classListNode);  debuggerYACC(" X675 - class_statement << modifiers property_declaration_list ';'"); ;}
    break;

  case 116:
#line 471 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { FunctionDeclaration((yyvsp[-4].r.str),true);  resetStatementNumber(); ;}
    break;

  case 117:
#line 472 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {
		    (yyval.ast) = ast->createNode((yyvsp[-4].ast),(yyvsp[0].ast),functionNode);
		    (yyval.ast)->addSymbolTableElement(FunctionDeclarationEnd(true));
			
			(yyval.ast) = ast->createNode((yyval.ast),0,classListNode);

		    debuggerYACC(" X677 - class_statement << | modifiers T_FUNCTION optional_ref T_STRING '('parameter_list ')' optional_return_type method_body"); 
		;}
    break;

  case 118:
#line 480 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[0].ast),0,classListNode);  debuggerYACC(" X679.5 - class_statement << | class_declaration_statement"); ;}
    break;

  case 119:
#line 482 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {EatUntilNewLine();  (yyval.ast) = ast->createNode(0,0,classListNode);    debuggerYACC(" X430 - class_statement << | error"); ;}
    break;

  case 120:
#line 486 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { checkAbstractFunction(false); (yyval.ast) = ast->createNode(0,0,functionBody);   debuggerYACC(" X718 - method_body << ';' /* abstract method */"); ;}
    break;

  case 121:
#line 487 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { checkAbstractFunction(true);  (yyval.ast) = ast->createNode((yyvsp[0].ast),0,functionBody);  debuggerYACC(" X719 - method_body << | '{' inner_statement_list '}'"); ;}
    break;

  case 122:
#line 491 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X723 - modifiers << member_access_modifier member_storage_modifier"); ;}
    break;

  case 123:
#line 492 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X724 - modifiers << | member_storage_modifier member_access_modifier"); ;}
    break;

  case 124:
#line 493 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X725 - modifiers << | member_storage_modifier"); ;}
    break;

  case 125:
#line 494 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X726 - modifiers << |  member_access_modifier"); ;}
    break;

  case 126:
#line 495 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X727 - modifiers << |"); ;}
    break;

  case 127:
#line 499 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { MemberAccessPublic();        debuggerYACC(" X731 - member_access_modifier << T_PUBLIC"); ;}
    break;

  case 128:
#line 500 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { MemberAccessProtacted();     debuggerYACC(" X732 - member_access_modifier << | T_PROTECTED"); ;}
    break;

  case 129:
#line 501 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { MemberAccessPrivate();       debuggerYACC(" X733 - member_access_modifier << | T_PRIVATE"); ;}
    break;

  case 130:
#line 505 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { MemberStorageStatic();     debuggerYACC(" X738 - member_storage_modifier << T_STATIC"); ;}
    break;

  case 131:
#line 506 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { MemberStorageAbstract();   debuggerYACC(" X739 - member_storage_modifier << | T_ABSTRACT"); ;}
    break;

  case 132:
#line 507 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { MemberStorageFinal();       debuggerYACC(" X740 - member_storage_modifier << | T_FINAL"); ;}
    break;

  case 133:
#line 511 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = ast->createNode((yyvsp[0].ast),0,classListNode);  debuggerYACC(" X745 - property_declaration_list << property_declaration"); ;}
    break;

  case 134:
#line 512 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = ast->addToLastRight((yyvsp[-2].ast),ast->createNode((yyvsp[0].ast),0,classListNode));  debuggerYACC(" X746 - property_declaration_list << | property_declaration_list ',' property_declaration"); ;}
    break;

  case 135:
#line 516 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-1].ast),0,idVariableNode); (yyval.ast)->addSymbolTableElement(addVariable((yyvsp[-1].r.str),(yyvsp[0].r.str),false)); debuggerYACC(" X750 - property_declaration << var_type_or_nameT_VARIABLE"); ;}
    break;

  case 136:
#line 517 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { 
														Variable* v = addVariable((yyvsp[-3].r.str),(yyvsp[-2].r.str),(yyvsp[0].r.str),false);
														(yyval.ast) = ast->createNode((yyvsp[-3].ast),(yyvsp[0].ast),v->isStatic?staticVariableNode:idVariableNode); 
														(yyval.ast)->addSymbolTableElement(v);
	 
														debuggerYACC(" X751 - property_declaration << | var_type_or_nameT_VARIABLE '=' static_scalar"); 
													;}
    break;

  case 137:
#line 524 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-3].ast),0,idVariableNode); (yyval.ast)->addSymbolTableElement(addVariable((yyvsp[-3].r.str),(yyvsp[-2].r.str),(yyvsp[0].r.str),true));   debuggerYACC(" X369 - constant_declaration << T_STRING '=' static_scalar"); ;}
    break;

  case 138:
#line 529 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,classTypeNameNode); (yyval.ast)->addSymbolTableElement(NULL); (yyval.r.str) = (yyvsp[-1].r.str); debuggerYACC(" X7512 - var_type_or_name << var_types optional_array");;}
    break;

  case 139:
#line 530 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,classTypeNameNode); (yyval.ast)->addSymbolTableElement(findClassName((yyvsp[-1].r.str))); (yyval.r.str) = (yyvsp[-1].r.str);  debuggerYACC(" X7513 - var_type_or_name << T_STRING");;}
    break;

  case 140:
#line 531 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,classTypeNameNode); (yyval.ast)->addSymbolTableElement(findStaticClassName((yyvsp[-3].r.str),(yyvsp[-1].r.str),false)); (yyval.r.str) = (yyvsp[-1].r.str); debuggerYACC(" XXXXXXXXXXXXXXXXXXXXXXXXX ");;}
    break;

  case 141:
#line 537 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   itsArrayVariable(false);    debuggerYACC(" X7514 - optional_array");;}
    break;

  case 142:
#line 538 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   itsArrayVariable(true);    debuggerYACC(" X7515 - optional_array");;}
    break;

  case 143:
#line 542 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,intTypeNode); debuggerYACC(" X759 - var_types << T_V_INT"); ;}
    break;

  case 144:
#line 543 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,stringTypeNode); debuggerYACC(" X760 - var_types << | T_V_STRING"); ;}
    break;

  case 145:
#line 544 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,boolTypeNode); debuggerYACC(" X761 - var_types << | T_V_BOOL"); ;}
    break;

  case 146:
#line 545 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,charTypeNode); debuggerYACC(" X762 - var_types << | T_V_CHAR"); ;}
    break;

  case 147:
#line 546 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,doubleTypeNode); debuggerYACC(" X763 - var_types << | T_V_DOUBLE"); ;}
    break;

  case 148:
#line 547 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,floatTypeNode); debuggerYACC(" X764 - var_types << | T_V_FLOAT"); ;}
    break;

  case 149:
#line 548 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,realTypeNode); debuggerYACC(" X765 - var_types << | T_V_REAL"); ;}
    break;

  case 150:
#line 549 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,longTypeNode); debuggerYACC(" X766 - var_types << | T_V_LONG"); ;}
    break;

  case 151:
#line 550 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,byteTypeNode); debuggerYACC(" X767 - var_types << | T_V_BYTE"); ;}
    break;

  case 152:
#line 551 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,uintTypeNode); debuggerYACC(" X768 - var_types << | T_V_UINT"); ;}
    break;

  case 153:
#line 552 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,ulongTypeNode);  debuggerYACC(" X769 - var_types << | T_V_ULONG"); ;}
    break;

  case 154:
#line 553 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,ubyteTypeNode); debuggerYACC(" X770 - var_types << | T_V_UBYTE"); ;}
    break;

  case 155:
#line 557 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = ast->addToLastRight((yyvsp[-2].ast),ast->createNode((yyvsp[0].ast),0,expressionNode)); debuggerYACC(" X774 - expr_list << expr_list ',' expr"); ;}
    break;

  case 156:
#line 558 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) = ast->createNode((yyvsp[0].ast),0,expressionNode); debuggerYACC(" X775 - expr_list << | expr"); ;}
    break;

  case 157:
#line 562 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = NULL;  debuggerYACC(" X779 - for_expr << /* empty */"); ;}
    break;

  case 158:
#line 563 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast);  debuggerYACC(" X780 - for_expr << | expr_list"); ;}
    break;

  case 159:
#line 567 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast);														   debuggerYACC(" X784 - expr << variable"); ;}
    break;

  case 160:
#line 568 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),assignNode);                     debuggerYACC(" X786 - expr << | variable '=' expr"); ;}
    break;

  case 161:
#line 569 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X789 - expr << | new_expr      %prec _def_val_"); ;}
    break;

  case 162:
#line 570 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {;}
    break;

  case 163:
#line 571 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X790 - expr << | T_CLONE expr"); ;}
    break;

  case 164:
#line 572 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = ast->createNode((yyvsp[-2].ast),ast->createNode((yyvsp[0].ast),(yyvsp[-2].ast),plusNode),assignNode);  debuggerYACC(" X791 - expr << | variable T_PLUS_EQUAL expr"); ;}
    break;

  case 165:
#line 573 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = ast->createNode((yyvsp[-2].ast),ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),minusNode),assignNode);  debuggerYACC(" X792 - expr << | variable T_MINUS_EQUAL expr"); ;}
    break;

  case 166:
#line 574 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = ast->createNode((yyvsp[-2].ast),ast->createNode((yyvsp[0].ast),(yyvsp[-2].ast),multNode),assignNode);  debuggerYACC(" X793 - expr << | variable T_MUL_EQUAL expr"); ;}
    break;

  case 167:
#line 575 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = ast->createNode((yyvsp[-2].ast),ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),divNode),assignNode);  debuggerYACC(" X794 - expr << | variable T_DIV_EQUAL expr"); ;}
    break;

  case 168:
#line 576 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   debuggerYACC(" X795 - expr << | variable T_CONCAT_EQUAL expr"); ;}
    break;

  case 169:
#line 577 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = ast->createNode((yyvsp[-2].ast),ast->createNode((yyvsp[0].ast),(yyvsp[-2].ast),modNode),assignNode);  debuggerYACC(" X796 - expr << | variable T_MOD_EQUAL expr"); ;}
    break;

  case 170:
#line 578 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X797 - expr << | variable T_AND_EQUAL expr"); ;}
    break;

  case 171:
#line 579 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X798 - expr << | variable T_OR_EQUAL expr"); ;}
    break;

  case 172:
#line 580 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X799 - expr << | variable T_XOR_EQUAL expr"); ;}
    break;

  case 173:
#line 581 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X800 - expr << | variable T_SR_EQUAL expr"); ;}
    break;

  case 174:
#line 582 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X801 - expr << | variable T_POW_EQUAL expr"); ;}
    break;

  case 175:
#line 583 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {      (yyval.ast) = ast->createNode((yyvsp[-1].ast),0,plusplusNode);                       debuggerYACC(" X802 - expr << | variable T_INC"); ;}
    break;

  case 176:
#line 584 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {      (yyval.ast) = ast->createNode(0,(yyvsp[0].ast),plusplusNode);                       debuggerYACC(" X803 - expr << | T_INC variable"); ;}
    break;

  case 177:
#line 585 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {      (yyval.ast) = ast->createNode((yyvsp[-1].ast),0,minusminusNode);               debuggerYACC(" X804 - expr << | variable T_DEC"); ;}
    break;

  case 178:
#line 586 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {      (yyval.ast) = ast->createNode(0,(yyvsp[0].ast),minusminusNode);               debuggerYACC(" X805 - expr << | T_DEC variable"); ;}
    break;

  case 179:
#line 587 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),booleanOrOrNode);					   debuggerYACC(" X806 - expr << | expr T_BOOLEAN_OR expr"); ;}
    break;

  case 180:
#line 588 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),booleanAndAndNode);					   debuggerYACC(" X807 - expr << | expr T_BOOLEAN_AND expr"); ;}
    break;

  case 181:
#line 589 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X808 - expr << | expr T_LOGICAL_OR expr"); ;}
    break;

  case 182:
#line 590 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X809 - expr << | expr T_LOGICAL_AND expr"); ;}
    break;

  case 183:
#line 591 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X810 - expr << | expr T_LOGICAL_XOR expr"); ;}
    break;

  case 184:
#line 592 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),booleanOrNode);  debuggerYACC(" X811 - expr << | expr '|' expr"); ;}
    break;

  case 185:
#line 593 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),booleanAndNode);  debuggerYACC(" X812 - expr << | expr '&' expr"); ;}
    break;

  case 186:
#line 594 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X813 - expr << | expr '^' expr"); ;}
    break;

  case 187:
#line 595 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X814 - expr << | expr '.' expr"); ;}
    break;

  case 188:
#line 596 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),plusNode);                         debuggerYACC(" X815 - expr << | expr '+' expr"); ;}
    break;

  case 189:
#line 597 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),minusNode);						   debuggerYACC(" X816 - expr << | expr '-' expr"); ;}
    break;

  case 190:
#line 598 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),multNode);	                       debuggerYACC(" X817 - expr << | expr '*' expr"); ;}
    break;

  case 191:
#line 599 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),divNode);                          debuggerYACC(" X818 - expr << | expr '/' expr"); ;}
    break;

  case 192:
#line 600 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),modNode);                          debuggerYACC(" X819 - expr << | expr '%' expr"); ;}
    break;

  case 193:
#line 601 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X820 - expr << | expr T_SL expr"); ;}
    break;

  case 194:
#line 602 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X821 - expr << | expr T_SR expr"); ;}
    break;

  case 195:
#line 603 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X822 - expr << | expr T_POW expr"); ;}
    break;

  case 196:
#line 604 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = (yyvsp[0].ast); debuggerYACC(" X823 - expr << | '+' expr %prec T_INC"); ;}
    break;

  case 197:
#line 605 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = ast->createNode((yyvsp[0].ast),0,uneryPreMinusNode);             debuggerYACC(" X824 - expr << | '-' expr %prec T_INC"); ;}
    break;

  case 198:
#line 606 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {	(yyval.ast) = ast->createNode((yyvsp[0].ast),0,NotBooleanNode);																		debuggerYACC(" X825 - expr << | '!' expr"); ;}
    break;

  case 199:
#line 607 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X826 - expr << | '~' expr"); ;}
    break;

  case 200:
#line 608 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),IsEqualNode);                                                                            debuggerYACC(" X829 - expr << | expr T_IS_EQUAL expr"); ;}
    break;

  case 201:
#line 609 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),IsNotEqualNode);                                                                           debuggerYACC(" X830 - expr << | expr T_IS_NOT_EQUAL expr"); ;}
    break;

  case 202:
#line 610 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),lessThanNode);                debuggerYACC(" X832 - expr << | expr '<' expr"); ;}
    break;

  case 203:
#line 611 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),lessOrEqualNode);             debuggerYACC(" X833 - expr << | expr T_IS_SMALLER_OR_EQUAL expr"); ;}
    break;

  case 204:
#line 612 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),moreThanNode);                debuggerYACC(" X834 - expr << | expr '>' expr"); ;}
    break;

  case 205:
#line 613 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) = ast->createNode((yyvsp[-2].ast),(yyvsp[0].ast),moreOrEqualNode);             debuggerYACC(" X835 - expr << | expr T_IS_GREATER_OR_EQUAL expr"); ;}
    break;

  case 206:
#line 614 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) =  (yyvsp[0].ast);													   debuggerYACC(" X837 - expr << | parentheses_expr"); ;}
    break;

  case 207:
#line 615 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {   (yyval.ast) =  (yyvsp[-1].ast);                                                    debuggerYACC(" X838 - expr << | '('new_expr ')' "); ;}
    break;

  case 208:
#line 616 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X839 - expr << | expr '?' expr ':' expr"); ;}
    break;

  case 209:
#line 617 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X840 - expr << | expr '?' ':' expr"); ;}
    break;

  case 210:
#line 618 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X841 - expr << | expr T_COALESCE expr"); ;}
    break;

  case 211:
#line 619 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=ast->createNode((yyvsp[0].ast),0,intCastNode);                                    debuggerYACC(" X849 - expr << | T_INT_CAST expr"); ;}
    break;

  case 212:
#line 620 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=ast->createNode((yyvsp[0].ast),0,doubleCastNode);                                    debuggerYACC(" X850 - expr << | T_DOUBLE_CAST expr"); ;}
    break;

  case 213:
#line 621 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=ast->createNode((yyvsp[0].ast),0,stringCastNode);                                    debuggerYACC(" X851 - expr << | T_STRING_CAST expr"); ;}
    break;

  case 214:
#line 622 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=ast->createNode((yyvsp[0].ast),0,boolCastNode);                                    debuggerYACC(" X854 - expr << | T_BOOL_CAST expr"); ;}
    break;

  case 215:
#line 623 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=ast->createNode((yyvsp[0].ast),0,classTypeCastNode);    (yyval.ast)->addSymbolTableElement(findClassName((yyvsp[-2].r.str)));                                debuggerYACC(" X854 - expr << | '(' T_STRING ')' expr"); ;}
    break;

  case 216:
#line 624 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=ast->createNode((yyvsp[-2].ast),0,classTypeCastArrayNode);    (yyval.ast)->addSymbolTableElement(findClassName((yyvsp[-4].r.str)));                                debuggerYACC(" X854 - expr << | '(' T_STRING ')' expr"); ;}
    break;

  case 217:
#line 626 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast);																   debuggerYACC(" X858 - expr << | scalar"); ;}
    break;

  case 218:
#line 628 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {    (yyval.ast)=ast->createNode(0,0,readIntNode);         ;}
    break;

  case 219:
#line 629 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {    (yyval.ast)=ast->createNode(0,0,readStringNode);      ;}
    break;

  case 220:
#line 630 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {    (yyval.ast)=ast->createNode(0,0,readDoubleNode);      ;}
    break;

  case 221:
#line 634 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[-1].ast); debuggerYACC(" X872 - parentheses_expr << '('expr ')'"); ;}
    break;

  case 222:
#line 638 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = NULL;  debuggerYACC(" X1142 - dim_offset << /* empty */"); ;}
    break;

  case 223:
#line 639 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast); debuggerYACC(" X1143 - dim_offset << | expr"); ;}
    break;

  case 224:
#line 644 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = ast->createNode((yyvsp[0].ast),0,newClassInstance); (yyval.ast)->addSymbolTableElement(findClassName((yyvsp[-1].r.str),true));                  debuggerYACC(" X898 - new_expr << T_NEW namespace_name_parts ctor_arguments"); ;}
    break;

  case 225:
#line 645 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = ast->createNode((yyvsp[0].ast),0,newClassInstance); (yyval.ast)->addSymbolTableElement(findStaticClassName((yyvsp[-3].r.str),(yyvsp[-1].r.str),true));  debuggerYACC(" X898 - new_expr << T_NEW namespace_name_parts ctor_arguments"); ;}
    break;

  case 226:
#line 646 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = ast->createNode((yyvsp[0].ast),0,newClassInstance); (yyval.ast)->addSymbolTableElement(findInstanceClassName((yyvsp[-4].r.str),(yyvsp[-1].r.str)));  debuggerYACC(" X898 - new_expr << T_NEW namespace_name_parts ctor_arguments"); ;}
    break;

  case 227:
#line 648 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-3].ast),ast->createNode((yyvsp[-1].ast),0      ,arrayInitializingNode),arrayNode)->addValuestring((yyvsp[-3].r.str));					debuggerYACC(" X882 - array_expr <<  var_types '[' T_LNUMBER ']'"); ;}
    break;

  case 228:
#line 649 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {	(yyval.ast) = ast->createNode((yyvsp[-6].ast),ast->createNode((yyvsp[-4].ast),(yyvsp[-1].ast),arrayInitializingNode),arrayNode)->addValuestring((yyvsp[-6].r.str));	                debuggerYACC(" X883 - array_expr <<  var_types '[' T_LNUMBER ']'  '{' array_pair_list '}'"); ;}
    break;

  case 229:
#line 650 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {	(yyval.ast) = ast->createNode((yyvsp[-5].ast),ast->createNode(0      ,(yyvsp[-1].ast),arrayInitializingNode),arrayNode)->addValuestring((yyvsp[-5].r.str));	                debuggerYACC(" X883 - array_expr <<  var_types '[' T_LNUMBER ']'  '{' array_pair_list '}'"); ;}
    break;

  case 230:
#line 654 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.r.str) = (yyvsp[0].r.str);  (yyval.ast) = NULL;                        debuggerYACC(" X884 - array_type << var_types"); ;}
    break;

  case 231:
#line 655 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.r.str) = (yyvsp[0].r.str);  (yyval.ast) = ast->createNode(0,0,classTypeNameNode); (yyval.ast)->addSymbolTableElement(findClassName((yyvsp[0].r.str))); debuggerYACC(" X885 - array_type << T_STRING"); ;}
    break;

  case 232:
#line 660 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-3].ast),(yyvsp[-1].ast),callArrayVariableNode); (yyval.ast)->addSymbolTableElement((yyvsp[-3].ast)->symbolTableElement); debuggerYACC(" X1134 - reference_variable << reference_variable '[' T_LNUMBER ']'"); ;}
    break;

  case 233:
#line 661 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,callVariableNode); (yyval.ast)->addSymbolTableElement(callVariable((yyvsp[0].r.str)));   debuggerYACC(" X1136 - reference_variable << | T_VARIABLE"); ;}
    break;

  case 234:
#line 664 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { 
             			    (yyval.ast) = ast->createNode((yyvsp[-1].ast),0,idVariableNode);
						    (yyval.ast)->addSymbolTableElement(addVariable((yyvsp[-1].r.str),(yyvsp[0].r.str),false));
								
						    debuggerYACC(" X1110 - variable_without_objects << | var_type_or_name T_VARIABLE"); 
					;}
    break;

  case 235:
#line 673 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,(yyvsp[0].ast),functionCallNode); (yyval.ast)->addSymbolTableElement(callFunction((yyvsp[-1].r.str)))->addValuestring((yyvsp[-1].r.str));  debuggerYACC(" X918 - function_call << namespace_name_parts argument_list"); ;}
    break;

  case 236:
#line 674 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,(yyvsp[0].ast),functionCallNode); (yyval.ast)->addSymbolTableElement(findStaticFunction((yyvsp[-3].r.str),(yyvsp[-1].r.str))); debuggerYACC(" X919 - function_call << | class_name_or_var T_PAAMAYIM_NEKUDOTAYIM identifier argument_list");;}
    break;

  case 237:
#line 678 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.r.str) = strdup(to_string((yyvsp[0].r.intvalue)).c_str()); (yyval.ast) = ast->createNode(0,0,intValNode)->addValueint((yyvsp[0].r.intvalue));        debuggerYACC(" X983 - common_scalar << T_LNUMBER"); ;}
    break;

  case 238:
#line 679 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.r.str) = strdup(to_string((yyvsp[0].r.floatvalue)).c_str()); (yyval.ast) = ast->createNode(0,0,doubleValNode)->addValuedouble((yyvsp[0].r.floatvalue));								   debuggerYACC(" X984 - common_scalar << | T_DNUMBER"); ;}
    break;

  case 239:
#line 681 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.r.str) = (yyvsp[0].r.str); (yyval.ast) = ast->createNode(0,0,stringValNode)->addValuestring((yyvsp[0].r.str));       debuggerYACC(" X985 - common_scalar << | T_CONSTANT_ENCAPSED_STRING"); ;}
    break;

  case 240:
#line 682 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {    (yyval.ast)=ast->createNode(0,0,trueNode);            ;}
    break;

  case 241:
#line 683 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {    (yyval.ast)=ast->createNode(0,0,falseNode);           ;}
    break;

  case 242:
#line 684 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {    (yyval.ast)=ast->createNode(0,0,nullNode);            ;}
    break;

  case 243:
#line 688 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.r.str) = (yyvsp[0].r.str); (yyval.ast) = (yyvsp[0].ast); debuggerYACC(" X1001 - static_scalar << common_scalar"); ;}
    break;

  case 244:
#line 689 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,callVariableNode); (yyval.ast)->addSymbolTableElement(findStaticMember((yyvsp[-2].r.str),(yyvsp[0].r.str))); debuggerYACC(" X1002 - static_scalar << | class_name T_PAAMAYIM_NEKUDOTAYIM identifier"); ;}
    break;

  case 245:
#line 690 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.r.str) = strdup(to_string((yyvsp[0].r.intvalue) * -1).c_str()); (yyval.ast) = ast->createNode(0,0,intValNode)->addValueint((yyvsp[0].r.intvalue)*-1);    debuggerYACC(" X1006 - static_scalar << | '-' common_scalar"); ;}
    break;

  case 246:
#line 691 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.r.str) = strdup(to_string((yyvsp[0].r.floatvalue) * -1).c_str()); (yyval.ast) = ast->createNode(0,0,doubleValNode)->addValueint((yyvsp[0].r.floatvalue)*-1);   debuggerYACC(" X1006 - static_scalar << | '-' common_scalar"); ;}
    break;

  case 247:
#line 694 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast);  debuggerYACC(" X1052 - scalar << common_scalar"); ;}
    break;

  case 248:
#line 695 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,callVariableNode); (yyval.ast)->addSymbolTableElement(findStaticMember((yyvsp[-2].r.str),(yyvsp[0].r.str)));       debuggerYACC(" X1047 - constant << | class_name_or_var T_PAAMAYIM_NEKUDOTAYIM identifier"); ;}
    break;

  case 249:
#line 699 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X1066 - optional_comma << /* empty */"); ;}
    break;

  case 250:
#line 700 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X1067 - optional_comma << | ','"); ;}
    break;

  case 251:
#line 704 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=(yyvsp[0].ast); debuggerYACC(" X1081 - variable << object_access"); ;}
    break;

  case 252:
#line 705 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=(yyvsp[0].ast); debuggerYACC(" X1082 - variable << | base_variable"); ;}
    break;

  case 253:
#line 706 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=(yyvsp[0].ast); debuggerYACC(" X1083 - variable << | function_call"); ;}
    break;

  case 254:
#line 710 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-2].ast),0,objectAccessToVariableNode)->addValuestring((yyvsp[0].r.str));     (yyval.ast)->addSymbolTableElement(findInstanceVariable((yyvsp[-2].ast)->symbolTableElement,(yyvsp[0].r.str)));			  debuggerYACC(" X1093 - object_access << variable_or_new_expr T_OBJECT_OPERATOR object_property %prec test2"); ;}
    break;

  case 255:
#line 711 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-3].ast),(yyvsp[0].ast),objectAccessToFunctionNode)->addValuestring((yyvsp[-1].r.str));    (yyval.ast)->addSymbolTableElement(findInstanceFunction((yyvsp[-3].ast)->symbolTableElement,(yyvsp[-1].r.str)));;							debuggerYACC(" X1095 - object_access << | variable_or_new_expr T_OBJECT_OPERATOR object_property argument_list"); ;}
    break;

  case 256:
#line 713 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  debuggerYACC(" X1097 - object_access << | object_access argument_list"); ;}
    break;

  case 257:
#line 714 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    {  (yyval.ast) = ast->createNode((yyvsp[-3].ast),(yyvsp[-1].ast),objectAccessToArrayElementNode); debuggerYACC(" X1098 - object_access << | object_access '[' T_LNUMBER ']'");  ;}
    break;

  case 258:
#line 718 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast);  debuggerYACC(" X1103 - variable_or_new_expr << variable"); ;}
    break;

  case 259:
#line 719 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[-1].ast); debuggerYACC(" X1104 - variable_or_new_expr << | '('new_expr ')'"); ;}
    break;

  case 260:
#line 723 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast);  debuggerYACC(" X1114 - base_variable << variable_without_objects"); ;}
    break;

  case 261:
#line 724 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = (yyvsp[0].ast); debuggerYACC(" X1115 - base_variable << | static_property"); ;}
    break;

  case 262:
#line 728 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode(0,0,callVariableNode);                  (yyval.ast)->addSymbolTableElement(findStaticMember((yyvsp[-2].r.str),(yyvsp[0].r.str)));              debuggerYACC(" X1125 - static_property_with_arrays << class_name_or_var T_PAAMAYIM_NEKUDOTAYIM T_VARIABLE"); ;}
    break;

  case 263:
#line 729 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast) = ast->createNode((yyvsp[-3].ast),(yyvsp[-1].ast),callArrayVariableNode);       (yyval.ast)->addSymbolTableElement((yyvsp[-3].ast)->symbolTableElement);               debuggerYACC(" X1134 - reference_variable << reference_variable '[' T_LNUMBER ']'"); ;}
    break;

  case 264:
#line 733 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=NULL;   debuggerYACC(" X1168 - array_pair_list << /* empty */"); ;}
    break;

  case 265:
#line 734 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=(yyvsp[-1].ast);  debuggerYACC(" X1169 - array_pair_list << | non_empty_array_pair_list optional_comma"); ;}
    break;

  case 266:
#line 738 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=ast->addToLastRight((yyvsp[-2].ast),ast->createNode((yyvsp[0].ast),0,arrayPairListNode)); debuggerYACC(" X1173 - non_empty_array_pair_list << non_empty_array_pair_list ',' array_pair"); ;}
    break;

  case 267:
#line 739 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=ast->createNode((yyvsp[0].ast),0,arrayPairListNode); debuggerYACC(" X1174 - non_empty_array_pair_list << | array_pair"); ;}
    break;

  case 268:
#line 743 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=(yyvsp[0].ast); debuggerYACC(" X1179 - array_pair << | expr"); ;}
    break;

  case 269:
#line 744 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"
    { (yyval.ast)=(yyvsp[0].ast); debuggerYACC(" X1181 - array_pair << | '&' variable"); ;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 3836 "yacc.cpp"

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
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
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
	  int yychecklim = YYLAST - yyn;
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
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
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
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
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
	  yydestruct ("Error: discarding", yytoken, &yylval);
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
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 747 "C:\\Users\\01\\Desktop\\X\\CompilerProject\\compiler project\\yacc.y"


void yyerror(const char *s)
{
	yyerrok; yyclearin; errorhandler(s);
}

int yylex() 
{
	return lexer->yylex(); 
}


void main(int argc,char *argv[])
{
    for(int i = 1; i < argc; i++)
	{
	     if(string(argv[i])=="-o")
				enableOutPut(true);
		 else if(string(argv[i])=="-a")
				enableOutPutAST(true);
		 else if(string(argv[i])=="-c")
				enableCommentingASMCode(true);
         else if(string(argv[i])=="-q")
				enableCopyResultToClipboard(true);
		 else
				changeInputFile(argv[i]);
	}

	if(before_main())
	{
		Parser* p = new Parser();
		p->parse();
	}
		
	after_main(finalTree);
}
