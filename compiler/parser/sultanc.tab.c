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




/* Copy the first part of user declarations.  */
#line 1 "sultanc.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sultanc.tab.h"  // Ensure this path points to the correct Bison header
#include "../utils/helpers.h"
#include "../utils/error_handling.h"

extern FILE *irFile;  // External declaration of irFile

// Declare yylex to avoid implicit declaration
int yylex(void);
void yyerror(const char *s);

// Global variables
int main_defined = 0;      // Track if the main function is defined
char *function_calls = NULL;  // Store function calls in the main function

int yycolumn = 0;  // Column tracking
extern int compile_mode;  // Declare compile_mode as extern


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

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "sultanc.y"
{
    char *str;  // For identifiers and model names
    int num;    // For numbers
}
/* Line 193 of yacc.c.  */
#line 213 "sultanc.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 226 "sultanc.tab.c"

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
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  36
/* YYNRULES -- Number of states.  */
#define YYNSTATES  85

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    31,    37,    45,    53,    57,    63,
      68,    76,    81,    87,    93,    95,    97,    99,   103,   107,
     111,   115,   119,   123,   127,   131,   135
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    48,    49,    -1,    49,    -1,
      51,    -1,    53,    -1,    52,    -1,    57,    -1,    54,    -1,
      50,    -1,    55,    -1,    56,    -1,     3,    31,    32,    29,
      -1,     3,    31,    58,    32,    29,    -1,    10,    27,    31,
      32,    33,    48,    34,    -1,    10,     3,    31,    32,    33,
      48,    34,    -1,    14,     3,    29,    -1,    14,     3,    30,
      58,    29,    -1,     3,    30,    58,    29,    -1,    20,    31,
      58,    32,    33,    48,    34,    -1,    21,    33,    48,    34,
      -1,    11,    31,     4,    32,    29,    -1,    11,    31,     7,
      32,    29,    -1,     3,    -1,     5,    -1,     4,    -1,    58,
      36,    58,    -1,    58,    37,    58,    -1,    58,    38,    58,
      -1,    58,    39,    58,    -1,    58,    44,    58,    -1,    58,
      45,    58,    -1,    58,    40,    58,    -1,    58,    41,    58,
      -1,    58,    42,    58,    -1,    58,    43,    58,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   133,   141,   150,   151,   152,   153,   154,
     155,   156,   157,   166,   181,   201,   229,   237,   248,   277,
     298,   310,   320,   325,   365,   374,   379,   383,   390,   397,
     404,   411,   418,   425,   432,   439,   446
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING_LITERAL", "NUMBER",
  "CHAR_LITERAL", "FSTRING_LITERAL", "LEFT_QUOTE", "RIGHT_QUOTE", "DEF",
  "PRINT", "INT", "FLOAT", "LET", "LIBRARY", "OUTPUT", "AR_CHAR", "IMPORT",
  "INPUT", "IF", "ELSE", "RETURN", "AS", "FROM", "ARROW", "THEN", "MAIN",
  "DOT", "SEMICOLON", "EQUALS", "LPAREN", "RPAREN", "CLPAREN", "CRPAREN",
  "COMMA", "PLUS", "MINUS", "MULT", "DIV", "LT", "GT", "LE", "GE", "EQ",
  "NE", "$accept", "program", "statements", "statement", "function_call",
  "main_statement", "def_statement", "let_declaration",
  "assignment_statement", "if_statement", "else_statement",
  "print_statement", "expression", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    50,    50,    51,    52,    53,    53,    54,
      55,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     5,     7,     7,     3,     5,     4,
       7,     4,     5,     5,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     2,     4,
      10,     5,     7,     6,     9,    11,    12,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     3,    24,    26,
      25,     0,     0,     0,     0,     0,     0,     0,    17,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,     0,     0,
       0,    21,    27,    28,    29,    30,    33,    34,    35,    36,
      31,    32,    14,     0,     0,    22,    23,    18,     0,     0,
       0,     0,    16,    15,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    31
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -38
static const yytype_int8 yypact[] =
{
      83,    -7,    -1,   -20,    10,   -15,   -13,    53,    83,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,    24,    14,
      27,    29,     5,    18,    24,    83,   -38,   -38,   -38,   -38,
     -38,    70,    34,   101,    32,    33,    36,    37,   -38,    24,
     115,    11,   -38,    24,    24,    24,    24,    24,    24,    24,
      24,    24,    24,   -38,    49,    46,    47,    54,    55,    87,
      62,   -38,   123,   123,   -37,   -37,    12,    12,    12,    12,
     -38,   -38,   -38,    83,    83,   -38,   -38,   -38,    83,    41,
      56,    71,   -38,   -38,   -38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,   -24,    -8,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,    -9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      27,    41,    20,    47,    48,    49,    50,    51,    52,    36,
      33,    22,    37,    23,     1,    40,    24,    28,    29,    30,
      25,     2,     3,    18,    19,     4,    21,    28,    29,    30,
      59,     5,     6,    27,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     1,    61,    32,    38,    39,    79,
      80,     2,     3,    26,    81,     4,    51,    52,    34,     1,
      35,     5,     6,    53,    55,    56,     2,     3,    57,    58,
       4,    27,    27,    27,     1,    82,     5,     6,    72,    73,
      74,     2,     3,    75,    76,     4,     1,     0,     0,     0,
      83,     5,     6,     2,     3,    78,     0,     4,     0,    42,
       0,     0,     0,     5,     6,    84,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    77,     0,     0,     0,
       0,     0,     0,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    54,     0,     0,     0,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    60,     0,     0,
       0,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    45,    46,    47,    48,    49,    50,    51,    52
};

static const yytype_int8 yycheck[] =
{
       8,    25,     3,    40,    41,    42,    43,    44,    45,     4,
      19,    31,     7,     3,     3,    24,    31,     3,     4,     5,
      33,    10,    11,    30,    31,    14,    27,     3,     4,     5,
      39,    20,    21,    41,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     3,    34,    32,    29,    30,    73,
      74,    10,    11,     0,    78,    14,    44,    45,    31,     3,
      31,    20,    21,    29,    32,    32,    10,    11,    32,    32,
      14,    79,    80,    81,     3,    34,    20,    21,    29,    33,
      33,    10,    11,    29,    29,    14,     3,    -1,    -1,    -1,
      34,    20,    21,    10,    11,    33,    -1,    14,    -1,    29,
      -1,    -1,    -1,    20,    21,    34,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    32,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    32,    -1,    -1,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    38,    39,    40,    41,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    10,    11,    14,    20,    21,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    30,    31,
       3,    27,    31,     3,    31,    33,     0,    49,     3,     4,
       5,    58,    32,    58,    31,    31,     4,     7,    29,    30,
      58,    48,    29,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    29,    32,    32,    32,    32,    32,    58,
      32,    34,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    29,    33,    33,    29,    29,    29,    33,    48,
      48,    48,    34,    34,    34
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
        case 2:
#line 103 "sultanc.y"
    {
        if (!main_defined) {
            yyerror("Error: 'main' function must be declared.");
            YYABORT;  // Abort parsing if 'main' is missing
        }

        // Generate the necessary includes
        fprintf(irFile, "#include <stdio.h>\n");
        fprintf(irFile, "#include <stdlib.h>\n");
        fprintf(irFile, "#include <string.h>\n");
        fprintf(irFile, "#include <errno.h>\n");

        // Print the statements to the file
        fprintf(irFile, "%s\n", (yyvsp[(1) - (1)].str));

        // Add function calls if present
        if (function_calls) {
            fprintf(irFile, "    %s\n", function_calls);
        }

        // Free allocated memory
        free((yyvsp[(1) - (1)].str));
        if (function_calls) {
            free(function_calls);
        }
    ;}
    break;

  case 3:
#line 134 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (2)].str)) + strlen((yyvsp[(2) - (2)].str)) + 1);
        strcpy((yyval.str), (yyvsp[(1) - (2)].str));
        strcat((yyval.str), (yyvsp[(2) - (2)].str));
        free((yyvsp[(1) - (2)].str));
        free((yyvsp[(2) - (2)].str));
    ;}
    break;

  case 4:
#line 142 "sultanc.y"
    {
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
        free((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 12:
#line 159 "sultanc.y"
    {
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 13:
#line 167 "sultanc.y"
    {
        // Initialize or expand the function_calls buffer to store function call strings
        if (function_calls == NULL) {
            function_calls = malloc(strlen((yyvsp[(1) - (4)].str)) + 10);
            sprintf(function_calls, "    %s();\n", (yyvsp[(1) - (4)].str));
        } else {
            function_calls = realloc(function_calls, strlen(function_calls) + strlen((yyvsp[(1) - (4)].str)) + 10);
            strcat(function_calls, "    ");
            strcat(function_calls, (yyvsp[(1) - (4)].str));
            strcat(function_calls, "();\n");
        }

        (yyval.str) = strdup("");  // Return an empty string since calls are handled separately
    ;}
    break;

  case 14:
#line 182 "sultanc.y"
    {
        // Handle function calls with a single argument
        if (function_calls == NULL) {
            function_calls = malloc(strlen((yyvsp[(1) - (5)].str)) + strlen((yyvsp[(3) - (5)].str)) + 10);
            sprintf(function_calls, "    %s(%s);\n", (yyvsp[(1) - (5)].str), (yyvsp[(3) - (5)].str));
        } else {
            function_calls = realloc(function_calls, strlen(function_calls) + strlen((yyvsp[(1) - (5)].str)) + strlen((yyvsp[(3) - (5)].str)) + 10);
            strcat(function_calls, "    ");
            strcat(function_calls, (yyvsp[(1) - (5)].str));
            strcat(function_calls, "(");
            strcat(function_calls, (yyvsp[(3) - (5)].str));
            strcat(function_calls, ");\n");
        }

        free((yyvsp[(3) - (5)].str));  // Free the expression string
        (yyval.str) = strdup("");  // Return an empty string
    ;}
    break;

  case 15:
#line 202 "sultanc.y"
    {
        if (main_defined) {
            yyerror("Error: Multiple definitions of the 'main' function.");
            YYABORT;  // Abort on multiple definitions
        }

        main_defined = 1;  // Mark that the main function is defined.

        size_t main_body_size = strlen((yyvsp[(6) - (7)].str)) + (function_calls ? strlen(function_calls) : 0) + 64;
        (yyval.str) = malloc(main_body_size);

        if (function_calls) {
            sprintf((yyval.str), "int main() {\n%s\n%s\nreturn 0;\n}\n", (yyvsp[(6) - (7)].str), function_calls);
        } else {
            sprintf((yyval.str), "int main() {\n%s\nreturn 0;\n}\n", (yyvsp[(6) - (7)].str));
        }

        free((yyvsp[(6) - (7)].str));
        if (function_calls) {
            free(function_calls);
            function_calls = NULL;
        }
    ;}
    break;

  case 16:
#line 230 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(2) - (7)].str)) + strlen((yyvsp[(6) - (7)].str)) + 64);
        sprintf((yyval.str), "void %s() {\n%s\n}\n", (yyvsp[(2) - (7)].str), (yyvsp[(6) - (7)].str));
        free((yyvsp[(6) - (7)].str));
    ;}
    break;

  case 17:
#line 238 "sultanc.y"
    {
        if (is_declared((yyvsp[(2) - (3)].str))) {
            yyerror("Error: Variable already declared.");
            (yyval.str) = strdup("");
        } else {
            declare_var((yyvsp[(2) - (3)].str), "int");
            (yyval.str) = malloc(strlen((yyvsp[(2) - (3)].str)) + 16);
            sprintf((yyval.str), "int %s = 0;\n", (yyvsp[(2) - (3)].str));
        }
    ;}
    break;

  case 18:
#line 249 "sultanc.y"
    {
        if (is_declared((yyvsp[(2) - (5)].str))) {
            yyerror("Error: Variable already declared.");
            (yyval.str) = strdup("");
        } else {
            const char *type = ((yyvsp[(4) - (5)].str)[0] == '"' && (yyvsp[(4) - (5)].str)[strlen((yyvsp[(4) - (5)].str)) - 1] == '"') ? "char*" : "int";
            declare_var((yyvsp[(2) - (5)].str), type);

            // Ensure the string literal is generated correctly with only one set of quotes
            char *value = strdup((yyvsp[(4) - (5)].str));
            if (strcmp(type, "char*") == 0) {
                // Remove outer quotes if they exist to avoid duplicate quotes in the output
                if (value[0] == '"' && value[strlen(value) - 1] == '"') {
                    value[strlen(value) - 1] = '\0';  // Remove trailing quote
                    value++;  // Shift pointer to skip leading quote
                }
                (yyval.str) = malloc(strlen(type) + strlen((yyvsp[(2) - (5)].str)) + strlen(value) + 16);
                sprintf((yyval.str), "%s %s = \"%s\";\n", type, (yyvsp[(2) - (5)].str), value);
            } else {
                (yyval.str) = malloc(strlen(type) + strlen((yyvsp[(2) - (5)].str)) + strlen((yyvsp[(4) - (5)].str)) + 16);
                sprintf((yyval.str), "%s %s = %s;\n", type, (yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].str));
            }
        }
        free((yyvsp[(4) - (5)].str));
    ;}
    break;

  case 19:
#line 278 "sultanc.y"
    {
        const char* var_type = get_var_type((yyvsp[(1) - (4)].str));
        if (!var_type) {
            yyerror("Undeclared variable used in assignment");
            (yyval.str) = strdup("");  // Return an empty string to avoid further processing
        } else {
            (yyval.str) = malloc(strlen((yyvsp[(1) - (4)].str)) + strlen((yyvsp[(3) - (4)].str)) + 8);
            if (strcmp(var_type, "char*") == 0) {
                sprintf((yyval.str), "%s = %s;\n", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].str));  // Use "%s" for string literals
            } else {
                sprintf((yyval.str), "%s = %s;\n", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].str));  // Use "%s" for numbers
            }
        }
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 20:
#line 299 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(3) - (7)].str)) + strlen((yyvsp[(6) - (7)].str)) + 32);
        sprintf((yyval.str), "if (%s) {\n%s\n}\n", (yyvsp[(3) - (7)].str), (yyvsp[(6) - (7)].str));

        free((yyvsp[(3) - (7)].str));
        free((yyvsp[(6) - (7)].str));
    ;}
    break;

  case 21:
#line 311 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(3) - (4)].str)) + 16);
        sprintf((yyval.str), "else {\n%s\n}\n", (yyvsp[(3) - (4)].str));

        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 22:
#line 321 "sultanc.y"
    {
        (yyval.str) = malloc(64 + strlen((yyvsp[(3) - (5)].str)) + 20);  // Adjust memory allocation
        sprintf((yyval.str), "printf(%s\"\\n\");\n", (yyvsp[(3) - (5)].str));  // Add \\n inside the string
    ;}
    break;

  case 23:
#line 326 "sultanc.y"
    {
        // Handle f-string or ت-string logic (same behavior for both)
        char *formatted_str = strdup((yyvsp[(3) - (5)].str) + 2);  // Skip the 'f"' or 'ت"' part
        formatted_str[strlen(formatted_str) - 1] = '\0';  // Remove ending '"'

        // Allocate memory for the output string
        char *output_str = malloc(strlen(formatted_str) + 128);  // Extra space for formatting
        char *placeholder_start = strstr(formatted_str, "{");

        if (placeholder_start) {
            *placeholder_start = '\0';  // Split string before '{'
            char *variable_name = placeholder_start + 1;
            char *placeholder_end = strstr(variable_name, "}");
            *placeholder_end = '\0';  // Isolate variable name

            // Check if the variable is declared
            const char *var_type = get_var_type(variable_name);
            if (!var_type) {
                yyerror("Undeclared variable used in f-string");
                (yyval.str) = strdup("");  // Return empty string on error
            } else {
                // Determine correct format specifier
                char *format_specifier = (strcmp(var_type, "char*") == 0) ? "%s" : "%d";

                // Generate the final printf statement
                sprintf(output_str, "printf(\"%s%s\\n\", %s);\n", formatted_str, format_specifier, variable_name);
                (yyval.str) = output_str;
            }
        } else {
            // No placeholders, treat as a normal string
            (yyval.str) = malloc(64 + strlen(formatted_str) + 20);
            sprintf((yyval.str), "printf(\"%s\\n\");\n", formatted_str);
        }

        free(formatted_str);  // Free allocated memory
    ;}
    break;

  case 24:
#line 366 "sultanc.y"
    {
        if (!is_declared((yyvsp[(1) - (1)].str))) {
            yyerror("Undeclared variable used in expression");
            (yyval.str) = strdup("");
        } else {
            (yyval.str) = strdup((yyvsp[(1) - (1)].str));
        }
    ;}
    break;

  case 25:
#line 375 "sultanc.y"
    {
        (yyval.str) = malloc(32);
        sprintf((yyval.str), "%d", (yyvsp[(1) - (1)].num));
    ;}
    break;

  case 26:
#line 380 "sultanc.y"
    {
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 27:
#line 384 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 5);
        sprintf((yyval.str), "(%s + %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 28:
#line 391 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 5);
        sprintf((yyval.str), "(%s - %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 29:
#line 398 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 5);
        sprintf((yyval.str), "(%s * %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 30:
#line 405 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 5);
        sprintf((yyval.str), "(%s / %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 31:
#line 412 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 6);
        sprintf((yyval.str), "%s == %s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 32:
#line 419 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 6);
        sprintf((yyval.str), "%s != %s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 33:
#line 426 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 5);
        sprintf((yyval.str), "%s < %s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 34:
#line 433 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 5);
        sprintf((yyval.str), "%s > %s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 35:
#line 440 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 6);
        sprintf((yyval.str), "%s <= %s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 36:
#line 447 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 6);
        sprintf((yyval.str), "%s >= %s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1894 "sultanc.tab.c"
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


#line 455 "sultanc.y"


void yyerror(const char *s) {
    handle_parse_error(s);  // Call the error handling function in error_handling.c
}

