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
     DOT = 283,
     SEMICOLON = 284,
     EQUALS = 285,
     LPAREN = 286,
     RPAREN = 287,
     CLPAREN = 288,
     CRPAREN = 289,
     COMMA = 290,
     PLUS = 291,
     MINUS = 292,
     MULT = 293,
     DIV = 294,
     LT = 295,
     GT = 296,
     LE = 297,
     GE = 298,
     EQ = 299,
     NE = 300
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
#define DOT 283
#define SEMICOLON 284
#define EQUALS 285
#define LPAREN 286
#define RPAREN 287
#define CLPAREN 288
#define CRPAREN 289
#define COMMA 290
#define PLUS 291
#define MINUS 292
#define MULT 293
#define DIV 294
#define LT 295
#define GT 296
#define LE 297
#define GE 298
#define EQ 299
#define NE 300




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "sultanc.y"
{
    char *str;  // For identifiers and model names
    int num;    // For numbers
}
/* Line 1529 of yacc.c.  */
#line 144 "sultanc.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

