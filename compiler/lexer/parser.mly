%{
(* Import the AST module *)
open Ast

(* Import function handlers *)
%}

%token <int> INT
%token <string> ID STRING
%token DEF CLASS IMPORT AS FROM INIT IF ELSE ELSE_IF WHILE READ WRITE IN AT FOR RETURN PASS BREAK CONTINUE
%token TRUE FALSE AND OR NOT
%token PLUS MINUS TIMES DIV MOD POW
%token EQ EQUALS NEQ LT GT LEQ GEQ EOL
%token LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE COMMA COLON DOT SEMICOLON
%token PRINT  (* PRINT token already added *)
%token MAIN   (* MAIN token defined here *)

%left PLUS MINUS
%left TIMES DIV MOD
%right POW
%right NOT
%left AND OR
%nonassoc LT GT LEQ GEQ EQUALS NEQ
%nonassoc EQ  /* Assignments should have the lowest precedence */

%start prog
%type <Ast.program> prog
%type <stmt> stmt
%type <expr> expr
%type <expr list> expr_list
%type <string list> param_list_opt

%%

prog:
  | MAIN LBRACE stmt_list RBRACE   { FunctionDef.handle_main_block ($3) }
  | stmt_list                      { FunctionDef.handle_program ($1) }

stmt_list:
  | stmt_list stmt                 { FunctionDef.handle_stmt_list ($1, $2) }
  | /* empty */                    { FunctionDef.handle_empty_stmt_list () }

stmt:
  | DEF ID LPAREN param_list_opt RPAREN COLON LBRACE stmt_list RBRACE
      { FunctionDef.handle_functiondef ($2, $4, $8) }
  | CLASS ID COLON LBRACE stmt_list RBRACE
      { ClassDef.handle_classdef ($2, $5) }
  | IF expr COLON LBRACE stmt_list RBRACE
      { If.handle_if ($2, $5) }
  | ELSE COLON LBRACE stmt_list RBRACE
      { Else.handle_else ($4) }
  | ELSE_IF expr COLON LBRACE stmt_list RBRACE
      { ElseIf.handle_elseif ($2, $5) }
  | WHILE expr COLON LBRACE stmt_list RBRACE
      { While.handle_while ($2, $5) }
  | FOR ID IN expr COLON LBRACE stmt_list RBRACE
      { For.handle_for ($2, $4, $7) }
  | RETURN expr SEMICOLON
      { Return.handle_return ($2) }
  | IMPORT ID SEMICOLON
      { Import.handle_import ($2) }
  | AS ID SEMICOLON
      { As.handle_as ($2) }
  | FROM ID SEMICOLON
      { From.handle_from ($2) }
  | WRITE expr SEMICOLON
      { Write.handle_write ($2) }
  | PRINT LPAREN expr RPAREN SEMICOLON
      { FunctionCall.handle_functioncall ("print", Some $3) }
  | PASS SEMICOLON
      { Pass.handle_pass () }
  | BREAK SEMICOLON
      { Break.handle_break () }
  | CONTINUE SEMICOLON
      { Continue.handle_continue () }
  | READ SEMICOLON
      { Read.handle_read () }
  | expr SEMICOLON
      { FunctionDef.handle_expr_stmt ($1) }
  | error
      { FunctionDef.handle_error_stmt () }

expr:
  | INT                           { Int.handle_int ($1) }
  | TRUE                          { Bool.handle_bool (true) }
  | FALSE                         { Bool.handle_bool (false) }
  | ID LPAREN RPAREN              { FunctionCall.handle_functioncall ($1, None) }
  | ID LPAREN expr RPAREN         { FunctionCall.handle_functioncall ($1, Some $3) }
  | ID                            { Var.handle_var ($1) }
  | expr PLUS expr                { BinOp.handle_binop ("+", $1, $3) }
  | expr MINUS expr               { BinOp.handle_binop ("-", $1, $3) }
  | expr TIMES expr               { BinOp.handle_binop ("*", $1, $3) }
  | expr DIV expr                 { BinOp.handle_binop ("/", $1, $3) }
  | expr MOD expr                 { BinOp.handle_binop ("%", $1, $3) }
  | expr POW expr                 { BinOp.handle_binop ("**", $1, $3) }
  | expr AND expr                 { BinOp.handle_binop ("and", $1, $3) }
  | expr OR expr                  { BinOp.handle_binop ("or", $1, $3) }
  | NOT expr %prec NOT            { UnOp.handle_unop ("not", $2) }
  | expr EQUALS expr              { BinOp.handle_binop ("==", $1, $3) }
  | expr NEQ expr                 { BinOp.handle_binop ("!=", $1, $3) }
  | expr LT expr                  { BinOp.handle_binop ("<", $1, $3) }
  | expr GT expr                  { BinOp.handle_binop (">", $1, $3) }
  | expr LEQ expr                 { BinOp.handle_binop ("<=", $1, $3) }
  | expr GEQ expr                 { BinOp.handle_binop (">=", $1, $3) }
  | LPAREN expr RPAREN            { FunctionDef.handle_parenthesized_expr ($2) }
  | ID EQ expr                    { Assign.handle_assign ($1, $3) }
  | LBRACKET expr_list RBRACKET   { ArrayLiteral.handle_arrayliteral ($2) }
  | error
      { FunctionDef.handle_error_expr () }

expr_list:
  | expr COMMA expr_list          { FunctionDef.handle_expr_list ($1, $3) }
  | expr                          { FunctionDef.handle_single_expr ($1) }

param_list_opt:
  | param_list                    { FunctionDef.handle_param_list ($1) }
  | /* empty */                   { FunctionDef.handle_empty_param_list () }

param_list:
  | ID COMMA param_list           { FunctionDef.handle_param_list ($1 :: $3) }
  | ID                            { FunctionDef.handle_param ($1) }
