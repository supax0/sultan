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
     FSTRING_LITERAL = 261,
     DEF = 262,
     PRINT = 263,
     LET = 264,
     MAIN = 265,
     IF = 266,
     ELSE = 267,
     SEMICOLON = 268,
     EQUALS = 269,
     LPAREN = 270,
     RPAREN = 271,
     CLPAREN = 272,
     CRPAREN = 273,
     COMMA = 274,
     PLUS = 275,
     MINUS = 276,
     MULT = 277,
     DIV = 278,
     LT = 279,
     GT = 280,
     DOT = 281,
     INT = 282,
     FLOAT = 283,
     LIBRARY = 284,
     OUTPUT = 285,
     AR_CHAR = 286,
     IMPORT = 287,
     INPUT = 288,
     FROM = 289,
     RETURN = 290,
     AS = 291,
     ARROW = 292,
     THEN = 293,
     EQ = 294,
     NE = 295,
     LE = 296,
     GE = 297,
     CHAR_LITERAL = 298
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING_LITERAL 259
#define NUMBER 260
#define FSTRING_LITERAL 261
#define DEF 262
#define PRINT 263
#define LET 264
#define MAIN 265
#define IF 266
#define ELSE 267
#define SEMICOLON 268
#define EQUALS 269
#define LPAREN 270
#define RPAREN 271
#define CLPAREN 272
#define CRPAREN 273
#define COMMA 274
#define PLUS 275
#define MINUS 276
#define MULT 277
#define DIV 278
#define LT 279
#define GT 280
#define DOT 281
#define INT 282
#define FLOAT 283
#define LIBRARY 284
#define OUTPUT 285
#define AR_CHAR 286
#define IMPORT 287
#define INPUT 288
#define FROM 289
#define RETURN 290
#define AS 291
#define ARROW 292
#define THEN 293
#define EQ 294
#define NE 295
#define LE 296
#define GE 297
#define CHAR_LITERAL 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 25 "sultanc.y"
{
    char *str;  // For identifiers and model names
    int num;    // For numbers
}
/* Line 1529 of yacc.c.  */
#line 140 "sultanc.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

