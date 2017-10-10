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
/* Line 1447 of yacc.c.  */
#line 295 "yacc.hpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



