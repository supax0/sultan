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
     DEF = 263,
     PRINT = 264,
     MAIN = 265,
     INT = 266,
     FLOAT = 267,
     LET = 268,
     LIBRARY = 269,
     OUTPUT = 270,
     AR_CHAR = 271,
     IMPORT = 272,
     INPUT = 273,
     IF = 274,
     ELSE = 275,
     RETURN = 276,
     AS = 277,
     FROM = 278,
     ARROW = 279,
     THEN = 280,
     DOT = 281,
     SEMICOLON = 282,
     EQUALS = 283,
     LPAREN = 284,
     RPAREN = 285,
     CLPAREN = 286,
     CRPAREN = 287,
     COMMA = 288,
     PLUS = 289,
     MINUS = 290,
     MULT = 291,
     DIV = 292
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING_LITERAL 259
#define NUMBER 260
#define CHAR_LITERAL 261
#define FSTRING_LITERAL 262
#define DEF 263
#define PRINT 264
#define MAIN 265
#define INT 266
#define FLOAT 267
#define LET 268
#define LIBRARY 269
#define OUTPUT 270
#define AR_CHAR 271
#define IMPORT 272
#define INPUT 273
#define IF 274
#define ELSE 275
#define RETURN 276
#define AS 277
#define FROM 278
#define ARROW 279
#define THEN 280
#define DOT 281
#define SEMICOLON 282
#define EQUALS 283
#define LPAREN 284
#define RPAREN 285
#define CLPAREN 286
#define CRPAREN 287
#define COMMA 288
#define PLUS 289
#define MINUS 290
#define MULT 291
#define DIV 292




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 59 "sultanc.y"
{
    char *str;  // For identifiers and model names
    int num;    // For numbers
}
/* Line 1529 of yacc.c.  */
#line 128 "sultanc.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

