/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING_LITERAL = 259,
     NUMBER = 260,
     CHAR_LITERAL = 261,
     FSTRING_LITERAL = 262,
     LEFT_QUOTE = 263,
     RIGHT_QUOTE = 264,
     DEF = 265,
     PRINT = 266,
     INT = 267,
     FLOAT = 268,
     LET = 269,
     LIBRARY = 270,
     OUTPUT = 271,
     AR_CHAR = 272,
     IMPORT = 273,
     INPUT = 274,
     IF = 275,
     ELSE = 276,
     RETURN = 277,
     AS = 278,
     FROM = 279,
     ARROW = 280,
     THEN = 281,
     MAIN = 282,
     IO = 283,
     WEB = 284,
     EMDEDDED = 285,
     OPENFILE = 286,
     READ = 287,
     WRITE = 288,
     CLOSE = 289,
     USE = 290,
     BUFFER = 291,
     FLOAT_NUMBER = 292,
     SQRT = 293,
     CBRT = 294,
     POW = 295,
     EXP = 296,
     EXP2 = 297,
     EXPM1 = 298,
     LOG = 299,
     LOG10 = 300,
     LOG2 = 301,
     LOG1P = 302,
     SIN = 303,
     COS = 304,
     TAN = 305,
     ASIN = 306,
     ACOS = 307,
     ATAN = 308,
     ATAN2 = 309,
     SINH = 310,
     COSH = 311,
     TANH = 312,
     ASINH = 313,
     ACOSH = 314,
     ATANH = 315,
     CEIL = 316,
     FLOOR = 317,
     ROUND = 318,
     TRUNC = 319,
     FMOD = 320,
     REMAINDER = 321,
     FABS = 322,
     ABS = 323,
     COPYSIGN = 324,
     FMIN = 325,
     FMAX = 326,
     FDIM = 327,
     DEGREES = 328,
     RADIANS = 329,
     HYPOT = 330,
     GAMMA = 331,
     LGAMMA = 332,
     ERF = 333,
     ERFC = 334,
     ISNAN = 335,
     ISINF = 336,
     FPCLASSIFY = 337,
     DOT = 338,
     SEMICOLON = 339,
     EQUALS = 340,
     LPAREN = 341,
     RPAREN = 342,
     CLPAREN = 343,
     CRPAREN = 344,
     COMMA = 345,
     PLUS = 346,
     MINUS = 347,
     MULT = 348,
     DIV = 349,
     LT = 350,
     GT = 351,
     LE = 352,
     GE = 353,
     EQ = 354,
     NE = 355,
     LBRACKET = 356,
     RBRACKET = 357
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING_LITERAL 259
#define NUMBER 260
#define CHAR_LITERAL 261
#define FSTRING_LITERAL 262
#define LEFT_QUOTE 263
#define RIGHT_QUOTE 264
#define DEF 265
#define PRINT 266
#define INT 267
#define FLOAT 268
#define LET 269
#define LIBRARY 270
#define OUTPUT 271
#define AR_CHAR 272
#define IMPORT 273
#define INPUT 274
#define IF 275
#define ELSE 276
#define RETURN 277
#define AS 278
#define FROM 279
#define ARROW 280
#define THEN 281
#define MAIN 282
#define IO 283
#define WEB 284
#define EMDEDDED 285
#define OPENFILE 286
#define READ 287
#define WRITE 288
#define CLOSE 289
#define USE 290
#define BUFFER 291
#define FLOAT_NUMBER 292
#define SQRT 293
#define CBRT 294
#define POW 295
#define EXP 296
#define EXP2 297
#define EXPM1 298
#define LOG 299
#define LOG10 300
#define LOG2 301
#define LOG1P 302
#define SIN 303
#define COS 304
#define TAN 305
#define ASIN 306
#define ACOS 307
#define ATAN 308
#define ATAN2 309
#define SINH 310
#define COSH 311
#define TANH 312
#define ASINH 313
#define ACOSH 314
#define ATANH 315
#define CEIL 316
#define FLOOR 317
#define ROUND 318
#define TRUNC 319
#define FMOD 320
#define REMAINDER 321
#define FABS 322
#define ABS 323
#define COPYSIGN 324
#define FMIN 325
#define FMAX 326
#define FDIM 327
#define DEGREES 328
#define RADIANS 329
#define HYPOT 330
#define GAMMA 331
#define LGAMMA 332
#define ERF 333
#define ERFC 334
#define ISNAN 335
#define ISINF 336
#define FPCLASSIFY 337
#define DOT 338
#define SEMICOLON 339
#define EQUALS 340
#define LPAREN 341
#define RPAREN 342
#define CLPAREN 343
#define CRPAREN 344
#define COMMA 345
#define PLUS 346
#define MINUS 347
#define MULT 348
#define DIV 349
#define LT 350
#define GT 351
#define LE 352
#define GE 353
#define EQ 354
#define NE 355
#define LBRACKET 356
#define RBRACKET 357




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 181 "sultanc.y"
{
    char *str;  // For identifiers and model names
    int num;    // For numbers
}
/* Line 1529 of yacc.c.  */
#line 258 "sultanc.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

