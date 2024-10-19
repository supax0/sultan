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




/* Copy the first part of user declarations.  */
#line 1 "sultanc.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h> 
#include "sultanc.tab.h"  // Ensure this path points to the correct Bison header
#include "../utils/helpers.h"
#include "../utils/error_handling.h"
#include "../builder/outputmsg.h"
extern FILE *irFile;  // External declaration of irFile
// #define BUFFER_SIZE 255

// // Declare buffer globally
// char *buffer = NULL;  
// Declare yylex to avoid implicit declaration
int yylex(void);
void yyerror(const char *s);

// Global variables
int main_defined = 0;      // Track if the main function is defined
char *function_calls = NULL;  // Store function calls in the main function

int yycolumn = 0;  // Column tracking
extern int compile_mode;  // Declare compile_mode as extern



void handle_parse_error(const char *error_msg);

// Header tracking linked list structure
typedef struct HeaderNode {
    char *header;
    struct HeaderNode *next;
} HeaderNode;

HeaderNode *header_list = NULL;  // Head of the linked list

// Check if a header is already included
bool is_header_included(const char *header) {
    HeaderNode *current = header_list;
    while (current) {
        if (strcmp(current->header, header) == 0) return true;
        current = current->next;
    }
    return false;
}

// Add a header to the list and print it if not already included
void add_header(const char *header) {
    if (!is_header_included(header)) {
        HeaderNode *new_node = (HeaderNode *)malloc(sizeof(HeaderNode));
        new_node->header = strdup(header);
        new_node->next = header_list;
        header_list = new_node;
        fprintf(irFile, "#include %s\n", header);  // Print the header to the IR file
    }
}

// Free the header list to prevent memory leaks
void free_header_list() {
    HeaderNode *current = header_list;
    while (current) {
        HeaderNode *temp = current;
        current = current->next;
        free(temp->header);
        free(temp);
    }
}


// Raise an error for division by zero and exit the program.
void check_division_by_zero(const char* denominator) {
    if (strcmp(denominator, "0") == 0) {
        // Print the first error message on a separate line
        fprintf(stderr, POINTER_FORMAT "\n", RED, "I cannot divide by zero.", RESET);

        // Print the second message on a new line
        fprintf(stderr, POINTER_FORMAT "\n", RED, ";) You have nothing, what are you dividing for!", RESET);

        // Exit the program immediately
        exit(1);
    }
}

/* Helper function to safely format floating-point or integer values */
char* format_float(const char* value) {
    char* result = malloc(64);  // Allocate enough space for precision
    if (!result) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    double val = atof(value);

    // Check for division by zero
    if (isinf(val) || isnan(val)) {
        fprintf(stderr, "Error: Invalid mathematical operation (e.g., division by zero).\n");
        free(result);
        exit(1);
    }

    // Format the float value with 15 significant digits, truncate if longer than 20 chars.
    snprintf(result, 64, "%.15g", val);
    if (strlen(result) > 20) {
        result[20] = '\0';
    }
    return result;
}

/* Helper function to format function calls with a single argument */
char* format_function(const char* func, const char* arg) {
    size_t size = strlen(func) + strlen(arg) + 4;
    char* result = malloc(size);
    if (!result) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    snprintf(result, size, "%s(%s)", func, arg);
    if (strlen(result) > 20) {
        result[20] = '\0';
    }
    return result;
}

/* Helper function to format function calls with two arguments */
char* format_function2(const char* func, const char* arg1, const char* arg2) {
    size_t size = strlen(func) + strlen(arg1) + strlen(arg2) + 6;
    char* result = malloc(size);
    if (!result) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    snprintf(result, size, "%s(%s, %s)", func, arg1, arg2);
    if (strlen(result) > 20) {
        result[20] = '\0';
    }
    return result;
}



// Parameter list node structure
typedef struct ParameterNode {
    char *name;                   // Name of the parameter
    struct ParameterNode *next;   // Pointer to the next parameter in the list
} ParameterNode;

ParameterNode *parameter_list_head = NULL;  // Head of the parameter list

// Function to create a new parameter node
ParameterNode* create_parameter_node(const char *name) {
    ParameterNode *node = (ParameterNode *)malloc(sizeof(ParameterNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    node->name = strdup(name);
    node->next = NULL;
    return node;
}

// Function to free the entire parameter list
void free_parameter_list() {
    ParameterNode *current = parameter_list_head;
    while (current) {
        ParameterNode *temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }
    parameter_list_head = NULL;
}





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
#line 181 "sultanc.y"
{
    char *str;  // For identifiers and model names
    int num;    // For numbers
}
/* Line 193 of yacc.c.  */
#line 482 "sultanc.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 495 "sultanc.tab.c"

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
#define YYFINAL  91
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1060

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  103
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNRULES -- Number of states.  */
#define YYNSTATES  330

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   357

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    37,    43,    51,
      60,    64,    67,    71,    77,    82,    90,    95,   101,   107,
     113,   115,   119,   123,   127,   131,   137,   143,   149,   157,
     167,   169,   171,   173,   175,   179,   183,   187,   191,   195,
     199,   203,   207,   211,   216,   221,   226,   231,   236,   243,
     248,   253,   258,   263,   268,   273,   278,   283,   288,   293,
     300,   305,   310,   315,   320,   325,   330,   335,   340,   345,
     350,   357,   364,   369,   374,   381,   388,   395,   402,   407,
     412,   419,   424,   429,   434,   439,   444,   449
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
     104,     0,    -1,   105,    -1,   105,   106,    -1,   106,    -1,
     108,    -1,   111,    -1,   109,    -1,   115,    -1,   112,    -1,
     107,    -1,   113,    -1,   114,    -1,   117,    -1,   118,    -1,
     110,    -1,     3,    86,    87,    84,    -1,     3,    86,   119,
      87,    84,    -1,    10,    27,    86,    87,    88,   105,    89,
      -1,    10,     3,    86,   116,    87,    88,   105,    89,    -1,
      22,   119,    84,    -1,    22,    84,    -1,    14,     3,    84,
      -1,    14,     3,    85,   119,    84,    -1,     3,    85,   119,
      84,    -1,    20,    86,   119,    87,    88,   105,    89,    -1,
      21,    88,   105,    89,    -1,    11,    86,     4,    87,    84,
      -1,    11,    86,     7,    87,    84,    -1,    11,    86,   116,
      87,    84,    -1,     3,    -1,     3,    90,   116,    -1,    18,
      28,    84,    -1,    18,    29,    84,    -1,    18,    30,    84,
      -1,    24,    28,    18,     3,    84,    -1,    24,    29,    18,
       3,    84,    -1,    24,    30,    18,     3,    84,    -1,    31,
      83,    32,    86,     4,    87,    84,    -1,    31,    83,    33,
      86,     4,    90,     4,    87,    84,    -1,     3,    -1,     5,
      -1,    37,    -1,     4,    -1,   119,    91,   119,    -1,   119,
      92,   119,    -1,   119,    93,   119,    -1,   119,    94,   119,
      -1,   119,    99,   119,    -1,   119,   100,   119,    -1,   119,
      95,   119,    -1,   119,    96,   119,    -1,   119,    97,   119,
      -1,    38,    86,   119,    87,    -1,    39,    86,   119,    87,
      -1,    41,    86,   119,    87,    -1,    42,    86,   119,    87,
      -1,    43,    86,   119,    87,    -1,    40,    86,   119,    90,
     119,    87,    -1,    44,    86,   119,    87,    -1,    45,    86,
     119,    87,    -1,    46,    86,   119,    87,    -1,    47,    86,
     119,    87,    -1,    48,    86,   119,    87,    -1,    49,    86,
     119,    87,    -1,    50,    86,   119,    87,    -1,    51,    86,
     119,    87,    -1,    52,    86,   119,    87,    -1,    53,    86,
     119,    87,    -1,    54,    86,   119,    90,   119,    87,    -1,
      55,    86,   119,    87,    -1,    56,    86,   119,    87,    -1,
      57,    86,   119,    87,    -1,    58,    86,   119,    87,    -1,
      59,    86,   119,    87,    -1,    60,    86,   119,    87,    -1,
      61,    86,   119,    87,    -1,    62,    86,   119,    87,    -1,
      63,    86,   119,    87,    -1,    64,    86,   119,    87,    -1,
      65,    86,   119,    90,   119,    87,    -1,    66,    86,   119,
      90,   119,    87,    -1,    67,    86,   119,    87,    -1,    68,
      86,   119,    87,    -1,    69,    86,   119,    90,   119,    87,
      -1,    70,    86,   119,    90,   119,    87,    -1,    71,    86,
     119,    90,   119,    87,    -1,    72,    86,   119,    90,   119,
      87,    -1,    73,    86,   119,    87,    -1,    74,    86,   119,
      87,    -1,    75,    86,   119,    90,   119,    87,    -1,    76,
      86,   119,    87,    -1,    77,    86,   119,    87,    -1,    78,
      86,   119,    87,    -1,    79,    86,   119,    87,    -1,    80,
      86,   119,    87,    -1,    81,    86,   119,    87,    -1,    82,
      86,   119,    87,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   342,   342,   377,   385,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   415,   430,   450,   517,
     534,   541,   571,   582,   611,   632,   644,   654,   659,   744,
     795,   805,   823,   839,   851,   868,   883,   896,   951,   961,
     985,   994,   999,  1003,  1007,  1014,  1021,  1028,  1038,  1045,
    1052,  1059,  1066,  1115,  1119,  1123,  1127,  1131,  1135,  1142,
    1146,  1150,  1154,  1160,  1164,  1168,  1172,  1176,  1180,  1184,
    1191,  1195,  1199,  1203,  1207,  1211,  1217,  1221,  1225,  1229,
    1233,  1238,  1245,  1249,  1253,  1260,  1265,  1270,  1277,  1281,
    1287,  1292,  1296,  1300,  1304,  1311,  1315,  1319
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
  "IO", "WEB", "EMDEDDED", "OPENFILE", "READ", "WRITE", "CLOSE", "USE",
  "BUFFER", "FLOAT_NUMBER", "SQRT", "CBRT", "POW", "EXP", "EXP2", "EXPM1",
  "LOG", "LOG10", "LOG2", "LOG1P", "SIN", "COS", "TAN", "ASIN", "ACOS",
  "ATAN", "ATAN2", "SINH", "COSH", "TANH", "ASINH", "ACOSH", "ATANH",
  "CEIL", "FLOOR", "ROUND", "TRUNC", "FMOD", "REMAINDER", "FABS", "ABS",
  "COPYSIGN", "FMIN", "FMAX", "FDIM", "DEGREES", "RADIANS", "HYPOT",
  "GAMMA", "LGAMMA", "ERF", "ERFC", "ISNAN", "ISINF", "FPCLASSIFY", "DOT",
  "SEMICOLON", "EQUALS", "LPAREN", "RPAREN", "CLPAREN", "CRPAREN", "COMMA",
  "PLUS", "MINUS", "MULT", "DIV", "LT", "GT", "LE", "GE", "EQ", "NE",
  "LBRACKET", "RBRACKET", "$accept", "program", "statements", "statement",
  "function_call", "main_statement", "def_statement", "return_statement",
  "let_declaration", "assignment_statement", "if_statement",
  "else_statement", "print_statement", "parameter_list",
  "import_statement", "file_operation_statement", "expression", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   103,   104,   105,   105,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   107,   107,   108,   109,
     110,   110,   111,   111,   112,   113,   114,   115,   115,   115,
     116,   116,   117,   117,   117,   117,   117,   117,   118,   118,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     7,     8,
       3,     2,     3,     5,     4,     7,     4,     5,     5,     5,
       1,     3,     3,     3,     3,     5,     5,     5,     7,     9,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     4,     4,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     6,     4,     4,     6,     6,     6,     6,     4,     4,
       6,     4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     4,    10,     5,     7,    15,     6,     9,
      11,    12,     8,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    40,    43,    41,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     1,     3,     0,     0,     0,     0,     0,    30,     0,
       0,     0,    22,     0,    32,    33,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    45,    46,    47,
      50,    51,    52,    48,    49,     0,     0,     0,     0,     0,
      17,     0,     0,    31,    27,    28,    29,    23,     0,    53,
      54,     0,    55,    56,    57,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,    82,    83,
       0,     0,     0,     0,    88,    89,     0,    91,    92,    93,
      94,    95,    96,    97,    35,    36,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    25,    58,    69,    80,    81,
      84,    85,    86,    87,    90,    38,     0,    19,     0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   101,    23,    24,    86
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -94
static const yytype_int16 yypact[] =
{
      15,   -80,     1,   -74,    11,    13,   -64,   -61,   354,    42,
     -49,    38,    15,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   436,   274,   -29,   -24,     4,
     -53,   -30,    -6,    -4,   436,    15,   -94,   -94,   -94,   -94,
      -3,    -2,     3,     5,     6,     8,     9,    69,    70,    71,
      72,    74,    77,    78,    82,    93,    98,    99,   100,   109,
     117,   120,   121,   124,   126,   127,   129,   140,   148,   152,
     153,   160,   161,   172,   173,   174,   175,   176,   177,   178,
     182,   183,   188,   189,   194,   -94,   -44,    56,    64,    67,
      12,   -94,   -94,    97,    14,   136,    84,    10,     0,    96,
     150,   155,   -94,   436,   -94,   -94,   -94,   157,    -1,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   -94,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   208,   240,   278,   196,   197,   -94,
     -94,   200,   198,   209,    84,   203,   216,   218,   125,   215,
     -94,   199,   273,   872,   284,   355,   366,   432,   443,   454,
     465,   476,   487,   498,   509,   520,   531,   883,   542,   553,
     564,   575,   586,   597,   608,   619,   630,   641,   894,   905,
     652,   663,   916,   927,   938,   949,   674,   685,   960,   696,
     707,   718,   729,   740,   751,   762,   105,   105,   -36,   -36,
     -32,   -32,   -32,   -94,   -94,   220,   221,   222,   303,   304,
     -94,   275,    15,   -94,   -94,   -94,   -94,   -94,    15,   -94,
     -94,   436,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   436,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   436,   436,   -94,   -94,
     436,   436,   436,   436,   -94,   -94,   436,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   223,   219,    15,
      55,   151,   773,   784,   795,   806,   817,   828,   839,   850,
     861,   290,   358,   156,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   295,   -94,   301,   -94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -34,   -12,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -93,   -94,   -94,   -10
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      92,   108,     1,   172,    27,    25,    26,    98,    99,     2,
       3,   100,    29,     4,    30,    93,    95,     5,     1,     6,
       7,     8,    34,     9,   107,     2,     3,    35,    28,     4,
      10,   102,   103,     5,    90,     6,     7,     8,    91,     9,
     154,    31,    32,    33,   167,   168,    10,   155,   156,   157,
     158,   159,   160,   161,   104,   162,   163,    96,     1,   159,
     160,   161,    97,   162,   163,     2,     3,   162,   163,     4,
      87,    88,    89,     5,   164,     6,     7,     8,   105,     9,
     106,   243,   165,   109,   110,   166,    10,    98,   180,   111,
     174,   112,   113,   178,   114,   115,    92,   173,   170,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   314,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     1,   116,   117,   118,   119,     1,
     120,     2,     3,   121,   122,     4,     2,     3,   123,     5,
       4,     6,     7,     8,     5,     9,     6,     7,     8,   124,
       9,   169,    10,   175,   125,   126,   127,    10,   155,   156,
     157,   158,   159,   160,   161,   128,   162,   163,   157,   158,
     159,   160,   161,   129,   162,   163,   130,   131,   300,   247,
     132,   235,   133,   134,   301,   135,   155,   156,   157,   158,
     159,   160,   161,   171,   162,   163,   136,   155,   156,   157,
     158,   159,   160,   161,   137,   162,   163,   176,   138,   139,
     315,   302,   177,   236,   179,   327,   140,   141,   155,   156,
     157,   158,   159,   160,   161,   303,   162,   163,   142,   143,
     144,   145,   146,   147,   148,   313,   304,   305,   149,   150,
     306,   307,   308,   309,   151,   152,   310,    36,    37,    38,
     153,   237,   238,   239,   240,   241,   249,   244,    92,    92,
     155,   156,   157,   158,   159,   160,   161,   242,   162,   163,
     245,    92,   246,   248,   294,   295,   296,   297,   298,   312,
     311,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    36,    37,    38,
     250,    94,   326,   299,   155,   156,   157,   158,   159,   160,
     161,   252,   162,   163,   325,   155,   156,   157,   158,   159,
     160,   161,   328,   162,   163,   329,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,    36,
      37,    38,   253,     0,     0,     0,   155,   156,   157,   158,
     159,   160,   161,   254,   162,   163,     0,   155,   156,   157,
     158,   159,   160,   161,     0,   162,   163,     0,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,   255,
       0,     0,     0,   155,   156,   157,   158,   159,   160,   161,
     256,   162,   163,     0,   155,   156,   157,   158,   159,   160,
     161,   257,   162,   163,     0,   155,   156,   157,   158,   159,
     160,   161,   258,   162,   163,     0,   155,   156,   157,   158,
     159,   160,   161,   259,   162,   163,     0,   155,   156,   157,
     158,   159,   160,   161,   260,   162,   163,     0,   155,   156,
     157,   158,   159,   160,   161,   261,   162,   163,     0,   155,
     156,   157,   158,   159,   160,   161,   262,   162,   163,     0,
     155,   156,   157,   158,   159,   160,   161,   263,   162,   163,
       0,   155,   156,   157,   158,   159,   160,   161,   264,   162,
     163,     0,   155,   156,   157,   158,   159,   160,   161,   266,
     162,   163,     0,   155,   156,   157,   158,   159,   160,   161,
     267,   162,   163,     0,   155,   156,   157,   158,   159,   160,
     161,   268,   162,   163,     0,   155,   156,   157,   158,   159,
     160,   161,   269,   162,   163,     0,   155,   156,   157,   158,
     159,   160,   161,   270,   162,   163,     0,   155,   156,   157,
     158,   159,   160,   161,   271,   162,   163,     0,   155,   156,
     157,   158,   159,   160,   161,   272,   162,   163,     0,   155,
     156,   157,   158,   159,   160,   161,   273,   162,   163,     0,
     155,   156,   157,   158,   159,   160,   161,   274,   162,   163,
       0,   155,   156,   157,   158,   159,   160,   161,   275,   162,
     163,     0,   155,   156,   157,   158,   159,   160,   161,   278,
     162,   163,     0,   155,   156,   157,   158,   159,   160,   161,
     279,   162,   163,     0,   155,   156,   157,   158,   159,   160,
     161,   284,   162,   163,     0,   155,   156,   157,   158,   159,
     160,   161,   285,   162,   163,     0,   155,   156,   157,   158,
     159,   160,   161,   287,   162,   163,     0,   155,   156,   157,
     158,   159,   160,   161,   288,   162,   163,     0,   155,   156,
     157,   158,   159,   160,   161,   289,   162,   163,     0,   155,
     156,   157,   158,   159,   160,   161,   290,   162,   163,     0,
     155,   156,   157,   158,   159,   160,   161,   291,   162,   163,
       0,   155,   156,   157,   158,   159,   160,   161,   292,   162,
     163,     0,   155,   156,   157,   158,   159,   160,   161,   293,
     162,   163,     0,   155,   156,   157,   158,   159,   160,   161,
     316,   162,   163,     0,   155,   156,   157,   158,   159,   160,
     161,   317,   162,   163,     0,   155,   156,   157,   158,   159,
     160,   161,   318,   162,   163,     0,   155,   156,   157,   158,
     159,   160,   161,   319,   162,   163,     0,   155,   156,   157,
     158,   159,   160,   161,   320,   162,   163,     0,   155,   156,
     157,   158,   159,   160,   161,   321,   162,   163,     0,   155,
     156,   157,   158,   159,   160,   161,   322,   162,   163,     0,
     155,   156,   157,   158,   159,   160,   161,   323,   162,   163,
       0,   155,   156,   157,   158,   159,   160,   161,   324,   162,
     163,     0,   155,   156,   157,   158,   159,   160,   161,     0,
     162,   163,   251,   155,   156,   157,   158,   159,   160,   161,
       0,   162,   163,   265,   155,   156,   157,   158,   159,   160,
     161,     0,   162,   163,   276,   155,   156,   157,   158,   159,
     160,   161,     0,   162,   163,   277,   155,   156,   157,   158,
     159,   160,   161,     0,   162,   163,   280,   155,   156,   157,
     158,   159,   160,   161,     0,   162,   163,   281,   155,   156,
     157,   158,   159,   160,   161,     0,   162,   163,   282,   155,
     156,   157,   158,   159,   160,   161,     0,   162,   163,   283,
     155,   156,   157,   158,   159,   160,   161,     0,   162,   163,
     286,   155,   156,   157,   158,   159,   160,   161,     0,   162,
     163
};

static const yytype_int16 yycheck[] =
{
      12,    35,     3,    96,     3,    85,    86,     3,     4,    10,
      11,     7,    86,    14,     3,    25,    26,    18,     3,    20,
      21,    22,    86,    24,    34,    10,    11,    88,    27,    14,
      31,    84,    85,    18,    83,    20,    21,    22,     0,    24,
      84,    28,    29,    30,    32,    33,    31,    91,    92,    93,
      94,    95,    96,    97,    84,    99,   100,    86,     3,    95,
      96,    97,    86,    99,   100,    10,    11,    99,   100,    14,
      28,    29,    30,    18,    18,    20,    21,    22,    84,    24,
      84,   174,    18,    86,    86,    18,    31,     3,    89,    86,
      90,    86,    86,   103,    86,    86,   108,    87,    84,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    89,   155,   156,   157,   158,   159,
     160,   161,   162,   163,     3,    86,    86,    86,    86,     3,
      86,    10,    11,    86,    86,    14,    10,    11,    86,    18,
      14,    20,    21,    22,    18,    24,    20,    21,    22,    86,
      24,    84,    31,    87,    86,    86,    86,    31,    91,    92,
      93,    94,    95,    96,    97,    86,    99,   100,    93,    94,
      95,    96,    97,    86,    99,   100,    86,    86,   242,    84,
      86,     3,    86,    86,   248,    86,    91,    92,    93,    94,
      95,    96,    97,    87,    99,   100,    86,    91,    92,    93,
      94,    95,    96,    97,    86,    99,   100,    87,    86,    86,
      89,   251,    87,     3,    87,    89,    86,    86,    91,    92,
      93,    94,    95,    96,    97,   265,    99,   100,    86,    86,
      86,    86,    86,    86,    86,   299,   276,   277,    86,    86,
     280,   281,   282,   283,    86,    86,   286,     3,     4,     5,
      86,     3,    86,    86,    84,    87,    87,    84,   300,   301,
      91,    92,    93,    94,    95,    96,    97,    88,    99,   100,
      84,   313,    84,    88,    84,    84,    84,     4,     4,    90,
      87,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,     3,     4,     5,
      87,    87,     4,    88,    91,    92,    93,    94,    95,    96,
      97,    87,    99,   100,    84,    91,    92,    93,    94,    95,
      96,    97,    87,    99,   100,    84,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    -1,    84,     3,
       4,     5,    87,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    96,    97,    87,    99,   100,    -1,    91,    92,    93,
      94,    95,    96,    97,    -1,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    87,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      87,    99,   100,    -1,    91,    92,    93,    94,    95,    96,
      97,    87,    99,   100,    -1,    91,    92,    93,    94,    95,
      96,    97,    87,    99,   100,    -1,    91,    92,    93,    94,
      95,    96,    97,    87,    99,   100,    -1,    91,    92,    93,
      94,    95,    96,    97,    87,    99,   100,    -1,    91,    92,
      93,    94,    95,    96,    97,    87,    99,   100,    -1,    91,
      92,    93,    94,    95,    96,    97,    87,    99,   100,    -1,
      91,    92,    93,    94,    95,    96,    97,    87,    99,   100,
      -1,    91,    92,    93,    94,    95,    96,    97,    87,    99,
     100,    -1,    91,    92,    93,    94,    95,    96,    97,    87,
      99,   100,    -1,    91,    92,    93,    94,    95,    96,    97,
      87,    99,   100,    -1,    91,    92,    93,    94,    95,    96,
      97,    87,    99,   100,    -1,    91,    92,    93,    94,    95,
      96,    97,    87,    99,   100,    -1,    91,    92,    93,    94,
      95,    96,    97,    87,    99,   100,    -1,    91,    92,    93,
      94,    95,    96,    97,    87,    99,   100,    -1,    91,    92,
      93,    94,    95,    96,    97,    87,    99,   100,    -1,    91,
      92,    93,    94,    95,    96,    97,    87,    99,   100,    -1,
      91,    92,    93,    94,    95,    96,    97,    87,    99,   100,
      -1,    91,    92,    93,    94,    95,    96,    97,    87,    99,
     100,    -1,    91,    92,    93,    94,    95,    96,    97,    87,
      99,   100,    -1,    91,    92,    93,    94,    95,    96,    97,
      87,    99,   100,    -1,    91,    92,    93,    94,    95,    96,
      97,    87,    99,   100,    -1,    91,    92,    93,    94,    95,
      96,    97,    87,    99,   100,    -1,    91,    92,    93,    94,
      95,    96,    97,    87,    99,   100,    -1,    91,    92,    93,
      94,    95,    96,    97,    87,    99,   100,    -1,    91,    92,
      93,    94,    95,    96,    97,    87,    99,   100,    -1,    91,
      92,    93,    94,    95,    96,    97,    87,    99,   100,    -1,
      91,    92,    93,    94,    95,    96,    97,    87,    99,   100,
      -1,    91,    92,    93,    94,    95,    96,    97,    87,    99,
     100,    -1,    91,    92,    93,    94,    95,    96,    97,    87,
      99,   100,    -1,    91,    92,    93,    94,    95,    96,    97,
      87,    99,   100,    -1,    91,    92,    93,    94,    95,    96,
      97,    87,    99,   100,    -1,    91,    92,    93,    94,    95,
      96,    97,    87,    99,   100,    -1,    91,    92,    93,    94,
      95,    96,    97,    87,    99,   100,    -1,    91,    92,    93,
      94,    95,    96,    97,    87,    99,   100,    -1,    91,    92,
      93,    94,    95,    96,    97,    87,    99,   100,    -1,    91,
      92,    93,    94,    95,    96,    97,    87,    99,   100,    -1,
      91,    92,    93,    94,    95,    96,    97,    87,    99,   100,
      -1,    91,    92,    93,    94,    95,    96,    97,    87,    99,
     100,    -1,    91,    92,    93,    94,    95,    96,    97,    -1,
      99,   100,    90,    91,    92,    93,    94,    95,    96,    97,
      -1,    99,   100,    90,    91,    92,    93,    94,    95,    96,
      97,    -1,    99,   100,    90,    91,    92,    93,    94,    95,
      96,    97,    -1,    99,   100,    90,    91,    92,    93,    94,
      95,    96,    97,    -1,    99,   100,    90,    91,    92,    93,
      94,    95,    96,    97,    -1,    99,   100,    90,    91,    92,
      93,    94,    95,    96,    97,    -1,    99,   100,    90,    91,
      92,    93,    94,    95,    96,    97,    -1,    99,   100,    90,
      91,    92,    93,    94,    95,    96,    97,    -1,    99,   100,
      90,    91,    92,    93,    94,    95,    96,    97,    -1,    99,
     100
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    10,    11,    14,    18,    20,    21,    22,    24,
      31,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   117,   118,    85,    86,     3,    27,    86,
       3,    28,    29,    30,    86,    88,     3,     4,     5,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    84,   119,    28,    29,    30,
      83,     0,   106,   119,    87,   119,    86,    86,     3,     4,
       7,   116,    84,    85,    84,    84,    84,   119,   105,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    84,    91,    92,    93,    94,    95,
      96,    97,    99,   100,    18,    18,    18,    32,    33,    84,
      84,    87,   116,    87,    90,    87,    87,    87,   119,    87,
      89,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,     3,     3,     3,    86,    86,
      84,    87,    88,   116,    84,    84,    84,    84,    88,    87,
      87,    90,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    90,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    90,    90,    87,    87,
      90,    90,    90,    90,    87,    87,    90,    87,    87,    87,
      87,    87,    87,    87,    84,    84,    84,     4,     4,    88,
     105,   105,   119,   119,   119,   119,   119,   119,   119,   119,
     119,    87,    90,   105,    89,    89,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    84,     4,    89,    87,    84
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
#line 343 "sultanc.y"
    {
        if (!main_defined) {
            yyerror("Error: 'main' function must be declared.");
            YYABORT;  // Abort parsing if 'main' is missing
        }

        // Add default headers only if not already included
        add_header("<stdio.h>");
        add_header("<stdlib.h>");
        add_header("<string.h>");
        add_header("<errno.h>");
        add_header("<math.h>");

        // Print the collected statements to the IR file
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

        // Free the header list to prevent memory leaks
        free_header_list();
    ;}
    break;

  case 3:
#line 378 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (2)].str)) + strlen((yyvsp[(2) - (2)].str)) + 1);
        strcpy((yyval.str), (yyvsp[(1) - (2)].str));
        strcat((yyval.str), (yyvsp[(2) - (2)].str));
        free((yyvsp[(1) - (2)].str));
        free((yyvsp[(2) - (2)].str));
    ;}
    break;

  case 4:
#line 386 "sultanc.y"
    {
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
        free((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 15:
#line 408 "sultanc.y"
    {
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 16:
#line 416 "sultanc.y"
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

  case 17:
#line 431 "sultanc.y"
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

  case 18:
#line 451 "sultanc.y"
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

  case 19:
#line 518 "sultanc.y"
    {
        // Allocate memory for the function definition string
        size_t size = strlen((yyvsp[(2) - (8)].str)) + strlen((yyvsp[(4) - (8)].str)) + strlen((yyvsp[(7) - (8)].str)) + 64;
        (yyval.str) = malloc(size);

        // Format the function definition with parameters
        sprintf((yyval.str), "void %s(%s) {\n%s\n}\n", (yyvsp[(2) - (8)].str), (yyvsp[(4) - (8)].str), (yyvsp[(7) - (8)].str));

        // Free allocated memory
        free((yyvsp[(4) - (8)].str));  // Parameter list string
        free((yyvsp[(7) - (8)].str));  // Function body string
    ;}
    break;

  case 20:
#line 535 "sultanc.y"
    {
        size_t size = strlen((yyvsp[(2) - (3)].str)) + 16;
        (yyval.str) = malloc(size);
        sprintf((yyval.str), "return (%s);\n", (yyvsp[(2) - (3)].str));
        free((yyvsp[(2) - (3)].str));  // Free expression memory
    ;}
    break;

  case 21:
#line 542 "sultanc.y"
    {
        (yyval.str) = strdup("return;\n");  // Handle return without expression
    ;}
    break;

  case 22:
#line 572 "sultanc.y"
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

  case 23:
#line 583 "sultanc.y"
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

  case 24:
#line 612 "sultanc.y"
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

  case 25:
#line 633 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(3) - (7)].str)) + strlen((yyvsp[(6) - (7)].str)) + 32);
        sprintf((yyval.str), "if (%s) {\n%s\n}\n", (yyvsp[(3) - (7)].str), (yyvsp[(6) - (7)].str));

        free((yyvsp[(3) - (7)].str));
        free((yyvsp[(6) - (7)].str));
    ;}
    break;

  case 26:
#line 645 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(3) - (4)].str)) + 16);
        sprintf((yyval.str), "else {\n%s\n}\n", (yyvsp[(3) - (4)].str));

        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 27:
#line 655 "sultanc.y"
    {
        (yyval.str) = malloc(64 + strlen((yyvsp[(3) - (5)].str)) + 20);  
        sprintf((yyval.str), "printf(%s\"\\n\");\n", (yyvsp[(3) - (5)].str));  // Print string with newline
    ;}
    break;

  case 28:
#line 660 "sultanc.y"
    {
        char *formatted_str = strdup((yyvsp[(3) - (5)].str) + 2);  // Skip 'f"' prefix
        formatted_str[strlen(formatted_str) - 1] = '\0';  // Remove trailing '"'

        char *output_str = malloc(256);  // Allocate memory for the output string
        if (!output_str) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }

        // Construct the format string from the f-string
        char *format_string = strdup("");
        char *start = formatted_str;
        char *placeholder = NULL;

        while ((placeholder = strstr(start, "{")) != NULL) {
            *placeholder = '\0';  // Split the string before '{'
            strcat(format_string, start);  // Append text before the placeholder

            char *var_name = placeholder + 1;
            char *end = strstr(var_name, "}");
            *end = '\0';  // Extract variable name

            const char *var_type = get_var_type(var_name);
            if (!var_type) {
                yyerror("Undeclared variable in f-string");
                (yyval.str) = strdup("");  // Return an empty string on error
                free(formatted_str);
                free(format_string);
                free(output_str);
                return 1;  // Return error code
            }

            // Add the appropriate format specifier
            char *format_specifier = 
                (strcmp(var_type, "char*") == 0) ? "%s" :
                (strcmp(var_type, "float") == 0 || strcmp(var_type, "double") == 0) ? "%g" : "%d";

            strcat(format_string, format_specifier);  // Add the format specifier
            start = end + 1;  // Move to the next part of the string
        }
        strcat(format_string, start);  // Append the remaining part

        // Construct the printf statement
        sprintf(output_str, "printf(\"%s\\n\"", format_string);

        // Extract variables and add them as arguments
        char *arg_start = strstr(formatted_str, "{");
        while (arg_start) {
            char *arg_name = arg_start + 1;
            char *arg_end = strstr(arg_name, "}");
            *arg_end = '\0';  // Extract the variable name

            size_t new_size = strlen(output_str) + strlen(arg_name) + 4;
            output_str = realloc(output_str, new_size);
            strcat(output_str, ", ");
            strcat(output_str, arg_name);

            arg_start = strstr(arg_end + 1, "{");  // Move to the next placeholder
        }

        strcat(output_str, ");\n");  // Close the printf statement
        (yyval.str) = output_str;  // Store the generated printf statement

        // Free allocated memory
        free(formatted_str);
        free(format_string);
    ;}
    break;

  case 29:
#line 745 "sultanc.y"
    {
        char *output_str = malloc(256);  // Allocate memory for the output string
        if (!output_str) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }

        // Construct the format string
        char *format_string = strdup("");
        ParameterNode *current = parameter_list_head;

        while (current) {
            const char *var_type = get_var_type(current->name);
            char *format_specifier =
                (strcmp(var_type, "char*") == 0) ? "%s" :
                (strcmp(var_type, "float") == 0 || strcmp(var_type, "double") == 0) ? "%g" : "%d";

            size_t new_size = strlen(format_string) + strlen(format_specifier) + 2;
            format_string = realloc(format_string, new_size);
            strcat(format_string, format_specifier);
            strcat(format_string, " ");

            current = current->next;
        }

        // Generate the printf statement with arguments
        sprintf(output_str, "printf(\"%s\\n\"", format_string);

        current = parameter_list_head;
        while (current) {
            size_t new_size = strlen(output_str) + strlen(current->name) + 4;
            output_str = realloc(output_str, new_size);
            strcat(output_str, ", ");
            strcat(output_str, current->name);

            current = current->next;
        }
        strcat(output_str, ");\n");

        (yyval.str) = output_str;  // Store the generated printf statement

        // Free the parameter list after use
        free_parameter_list();
        free(format_string);
    ;}
    break;

  case 30:
#line 796 "sultanc.y"
    {
        // Create a new parameter node for the single identifier
        ParameterNode *node = create_parameter_node((yyvsp[(1) - (1)].str));
        node->next = parameter_list_head;
        parameter_list_head = node;

        // Format the parameter into a string for yyval
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 31:
#line 806 "sultanc.y"
    {
        // Create a new parameter node and add it to the list
        ParameterNode *node = create_parameter_node((yyvsp[(1) - (3)].str));
        node->next = parameter_list_head;
        parameter_list_head = node;

        // Concatenate the new parameter with the existing list as a string
        size_t new_size = strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 3;
        (yyval.str) = malloc(new_size);
        snprintf((yyval.str), new_size, "%s, %s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));

        free((yyvsp[(3) - (3)].str));  // Free the previous parameter list string
    ;}
    break;

  case 32:
#line 824 "sultanc.y"
    {
        // Add all IO headers
        add_header("<stdio.h>");
        add_header("<stdlib.h>");
        add_header("<string.h>");
        add_header("<fcntl.h>");
        add_header("<unistd.h>");
        add_header("<sys/types.h>");
        add_header("<sys/stat.h>");
        add_header("<dirent.h>");
        add_header("<errno.h>");
        add_header("<poll.h>");
        add_header("<pthread.h>");
        (yyval.str) = strdup("");
    ;}
    break;

  case 33:
#line 840 "sultanc.y"
    {
        // Add all Web headers
        add_header("<sys/socket.h>");
        add_header("<arpa/inet.h>");
        add_header("<netinet/in.h>");
        add_header("<unistd.h>");
        add_header("<string.h>");
        add_header("<pthread.h>");
        add_header("<regex.h>");
        (yyval.str) = strdup("");
    ;}
    break;

  case 34:
#line 852 "sultanc.y"
    {
        // Add all Embedded System headers
        add_header("<stdint.h>");
        add_header("<stdbool.h>");
        add_header("<stdio.h>");
        add_header("<stdlib.h>");
        add_header("<string.h>");
        add_header("<unistd.h>");
        add_header("<math.h>");
        add_header("<time.h>");
        add_header("<limits.h>");
        add_header("<float.h>");
        add_header("<signal.h>");
        add_header("<fcntl.h>");
        (yyval.str) = strdup("");
    ;}
    break;

  case 35:
#line 869 "sultanc.y"
    {
        // Handle selective IO imports
        if (strcmp((yyvsp[(4) - (5)].str), "stdio") == 0) {
            add_header("<stdio.h>");
        } else if (strcmp((yyvsp[(4) - (5)].str), "fcntl") == 0) {
            add_header("<fcntl.h>");
        } else if (strcmp((yyvsp[(4) - (5)].str), "pthread") == 0) {
            add_header("<pthread.h>");
        } else {
            yyerror("Invalid IO import.");
            YYABORT;
        }
        (yyval.str) = strdup("");
    ;}
    break;

  case 36:
#line 884 "sultanc.y"
    {
        // Handle selective Web imports
        if (strcmp((yyvsp[(4) - (5)].str), "socket") == 0) {
            add_header("<sys/socket.h>");
        } else if (strcmp((yyvsp[(4) - (5)].str), "inet") == 0) {
            add_header("<arpa/inet.h>");
        } else {
            yyerror("Invalid WEB import.");
            YYABORT;
        }
        (yyval.str) = strdup("");
    ;}
    break;

  case 37:
#line 897 "sultanc.y"
    {
        // Handle selective Embedded imports
        if (strcmp((yyvsp[(4) - (5)].str), "stdint") == 0) {
            add_header("<stdint.h>");
        } else if (strcmp((yyvsp[(4) - (5)].str), "math") == 0) {
            add_header("<math.h>");
        } else {
            yyerror("Invalid EMBEDDED import.");
            YYABORT;
        }
        (yyval.str) = strdup("");
    ;}
    break;

  case 38:
#line 952 "sultanc.y"
    {
        char read_operation[300];
        snprintf(read_operation, sizeof(read_operation),
            "FILE *read_file = fopen(%s, \"r\");\n"
            "if (!read_file) { fprintf(stderr, \"Error opening file: %%s\\n\", %s); exit(1); }\n"
            "if (!fgets(user_buffer, sizeof(user_buffer), read_file))"
            "fclose(read_file);\n", (yyvsp[(5) - (7)].str), (yyvsp[(5) - (7)].str));
        (yyval.str) = strdup(read_operation);
    ;}
    break;

  case 39:
#line 962 "sultanc.y"
    {
        char write_operation[300];
        snprintf(write_operation, sizeof(write_operation),
            "FILE *write_file = fopen(%s, \"a\");\n"
            "if (!write_file) { fprintf(stderr, \"Error opening file: %%s\\n\", %s); exit(1); }\n"
            "if (fprintf(write_file, %s) < 0) { "
            "fprintf(stderr, \"Error writing to file\\n\"); }\n"
            "fclose(write_file);\n", (yyvsp[(5) - (9)].str), (yyvsp[(5) - (9)].str), (yyvsp[(7) - (9)].str));
        (yyval.str) = strdup(write_operation);
    ;}
    break;

  case 40:
#line 986 "sultanc.y"
    {
        if (!is_declared((yyvsp[(1) - (1)].str))) {
            yyerror("Undeclared variable used in expression");
            (yyval.str) = strdup("");
        } else {
            (yyval.str) = strdup((yyvsp[(1) - (1)].str));
        }
    ;}
    break;

  case 41:
#line 995 "sultanc.y"
    {
        (yyval.str) = malloc(32);
        sprintf((yyval.str), "%d", (yyvsp[(1) - (1)].num));
    ;}
    break;

  case 42:
#line 1000 "sultanc.y"
    {
        (yyval.str) = format_float((yyvsp[(1) - (1)].str));  // Automatically formats and caps length
    ;}
    break;

  case 43:
#line 1004 "sultanc.y"
    {
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 44:
#line 1008 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 5);
        sprintf((yyval.str), "(%s + %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 45:
#line 1015 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 5);
        sprintf((yyval.str), "(%s - %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 46:
#line 1022 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 5);
        sprintf((yyval.str), "(%s * %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 47:
#line 1029 "sultanc.y"
    {
        // Ensure denominator is not zero.
        check_division_by_zero((yyvsp[(3) - (3)].str));

        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 5);
        sprintf((yyval.str), "(%s / %s)", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 48:
#line 1039 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 6);
        sprintf((yyval.str), "%s == %s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 49:
#line 1046 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 6);
        sprintf((yyval.str), "%s != %s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 50:
#line 1053 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 5);
        sprintf((yyval.str), "%s < %s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 51:
#line 1060 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 5);
        sprintf((yyval.str), "%s > %s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 52:
#line 1067 "sultanc.y"
    {
        (yyval.str) = malloc(strlen((yyvsp[(1) - (3)].str)) + strlen((yyvsp[(3) - (3)].str)) + 6);
        sprintf((yyval.str), "%s <= %s", (yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].str));
        free((yyvsp[(1) - (3)].str));
        free((yyvsp[(3) - (3)].str));
    ;}
    break;

  case 53:
#line 1115 "sultanc.y"
    {
        (yyval.str) = format_function("sqrt", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 54:
#line 1119 "sultanc.y"
    {
        (yyval.str) = format_function("cbrt", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 55:
#line 1123 "sultanc.y"
    {
        (yyval.str) = format_function("exp", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 56:
#line 1127 "sultanc.y"
    {
        (yyval.str) = format_function("exp2", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 57:
#line 1131 "sultanc.y"
    {
        (yyval.str) = format_function("expm1", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 58:
#line 1135 "sultanc.y"
    {
        (yyval.str) = format_function2("pow", (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].str));
        free((yyvsp[(3) - (6)].str));
        free((yyvsp[(5) - (6)].str));
    ;}
    break;

  case 59:
#line 1142 "sultanc.y"
    {
        (yyval.str) = format_function("log", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 60:
#line 1146 "sultanc.y"
    {
        (yyval.str) = format_function("log10", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 61:
#line 1150 "sultanc.y"
    {
        (yyval.str) = format_function("log2", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 62:
#line 1154 "sultanc.y"
    {
        (yyval.str) = format_function("log1p", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 63:
#line 1160 "sultanc.y"
    {
        (yyval.str) = format_function("sin", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 64:
#line 1164 "sultanc.y"
    {
        (yyval.str) = format_function("cos", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 65:
#line 1168 "sultanc.y"
    {
        (yyval.str) = format_function("tan", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 66:
#line 1172 "sultanc.y"
    {
        (yyval.str) = format_function("asin", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 67:
#line 1176 "sultanc.y"
    {
        (yyval.str) = format_function("acos", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 68:
#line 1180 "sultanc.y"
    {
        (yyval.str) = format_function("atan", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 69:
#line 1184 "sultanc.y"
    {
        (yyval.str) = format_function2("atan2", (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].str));
        free((yyvsp[(3) - (6)].str));
        free((yyvsp[(5) - (6)].str));
    ;}
    break;

  case 70:
#line 1191 "sultanc.y"
    {
        (yyval.str) = format_function("sinh", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 71:
#line 1195 "sultanc.y"
    {
        (yyval.str) = format_function("cosh", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 72:
#line 1199 "sultanc.y"
    {
        (yyval.str) = format_function("tanh", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 73:
#line 1203 "sultanc.y"
    {
        (yyval.str) = format_function("asinh", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 74:
#line 1207 "sultanc.y"
    {
        (yyval.str) = format_function("acosh", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 75:
#line 1211 "sultanc.y"
    {
        (yyval.str) = format_function("atanh", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 76:
#line 1217 "sultanc.y"
    {
        (yyval.str) = format_function("ceil", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 77:
#line 1221 "sultanc.y"
    {
        (yyval.str) = format_function("floor", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 78:
#line 1225 "sultanc.y"
    {
        (yyval.str) = format_function("round", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 79:
#line 1229 "sultanc.y"
    {
        (yyval.str) = format_function("trunc", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 80:
#line 1233 "sultanc.y"
    {
        (yyval.str) = format_function2("fmod", (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].str));
        free((yyvsp[(3) - (6)].str));
        free((yyvsp[(5) - (6)].str));
    ;}
    break;

  case 81:
#line 1238 "sultanc.y"
    {
        (yyval.str) = format_function2("remainder", (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].str));
        free((yyvsp[(3) - (6)].str));
        free((yyvsp[(5) - (6)].str));
    ;}
    break;

  case 82:
#line 1245 "sultanc.y"
    {
        (yyval.str) = format_function("fabs", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 83:
#line 1249 "sultanc.y"
    {
        (yyval.str) = format_function("abs", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 84:
#line 1253 "sultanc.y"
    {
        (yyval.str) = format_function2("copysign", (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].str));
        free((yyvsp[(3) - (6)].str));
        free((yyvsp[(5) - (6)].str));
    ;}
    break;

  case 85:
#line 1260 "sultanc.y"
    {
        (yyval.str) = format_function2("fmin", (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].str));
        free((yyvsp[(3) - (6)].str));
        free((yyvsp[(5) - (6)].str));
    ;}
    break;

  case 86:
#line 1265 "sultanc.y"
    {
        (yyval.str) = format_function2("fmax", (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].str));
        free((yyvsp[(3) - (6)].str));
        free((yyvsp[(5) - (6)].str));
    ;}
    break;

  case 87:
#line 1270 "sultanc.y"
    {
        (yyval.str) = format_function2("fdim", (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].str));
        free((yyvsp[(3) - (6)].str));
        free((yyvsp[(5) - (6)].str));
    ;}
    break;

  case 88:
#line 1277 "sultanc.y"
    {
        (yyval.str) = format_function("degrees", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 89:
#line 1281 "sultanc.y"
    {
        (yyval.str) = format_function("radians", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 90:
#line 1287 "sultanc.y"
    {
        (yyval.str) = format_function2("hypot", (yyvsp[(3) - (6)].str), (yyvsp[(5) - (6)].str));
        free((yyvsp[(3) - (6)].str));
        free((yyvsp[(5) - (6)].str));
    ;}
    break;

  case 91:
#line 1292 "sultanc.y"
    {
        (yyval.str) = format_function("tgamma", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 92:
#line 1296 "sultanc.y"
    {
        (yyval.str) = format_function("lgamma", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 93:
#line 1300 "sultanc.y"
    {
        (yyval.str) = format_function("erf", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 94:
#line 1304 "sultanc.y"
    {
        (yyval.str) = format_function("erfc", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 95:
#line 1311 "sultanc.y"
    {
        (yyval.str) = format_function("isnan", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 96:
#line 1315 "sultanc.y"
    {
        (yyval.str) = format_function("isinf", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;

  case 97:
#line 1319 "sultanc.y"
    {
        (yyval.str) = format_function("fpclassify", (yyvsp[(3) - (4)].str));
        free((yyvsp[(3) - (4)].str));
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 3129 "sultanc.tab.c"
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


#line 1329 "sultanc.y"


/* void free_buffer() {
    if (buffer) {
        free(buffer);
        buffer = NULL;
    }
} */

void yyerror(const char *s) {
    handle_parse_error(s);  // Call the error handling function in error_handling.c
}

