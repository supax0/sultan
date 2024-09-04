%{
(* Import the AST module *)
open Ast
open Printf
%}

%token <int> INT
%token <string> ID STRING
%token DEF CLASS IMPORT AS FROM INIT IF ELSE ELSE_IF WHILE READ WRITE IN AT FOR RETURN PASS BREAK CONTINUE
%token TRUE FALSE AND OR NOT
%token PLUS MINUS TIMES DIV MOD POW
%token EQ EQUALS NEQ LT GT LEQ GEQ EOL
%token LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE COMMA COLON DOT SEMICOLON
%token PRINT  (* PRINT token already added *)
%token MAIN  (* MAIN token defined here *)

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
  | MAIN LBRACE stmt_list RBRACE { $3 }  (* MAIN block rule *)
  | stmt_list { $1 }

stmt_list:
  | stmt_list stmt { $1 @ [$2] }
  | /* empty */ { [] }

stmt:
  | DEF ID LPAREN param_list_opt RPAREN COLON LBRACE stmt_list RBRACE
      { FunctionDef ($2, $4, $8) }
  | DEF ID error { failwith (sprintf "Error: Function definition '%s' is malformed or incomplete." $2) }
  | CLASS ID COLON LBRACE stmt_list RBRACE
      { ClassDef ($2, $5) }
  | CLASS ID error { failwith (sprintf "Error: Class definition '%s' is malformed or incomplete." $2) }
  | IF expr COLON LBRACE stmt_list RBRACE
      { If ($2, $5) }
  | IF error { failwith "Error: 'if' statement is malformed or incomplete." }
  | ELSE COLON LBRACE stmt_list RBRACE
      { Else $4 }
  | ELSE error { failwith "Error: 'else' statement is malformed or incomplete." }
  | ELSE_IF expr COLON LBRACE stmt_list RBRACE
      { ElseIf ($2, $5) }
  | ELSE_IF error { failwith "Error: 'else if' statement is malformed or incomplete." }
  | WHILE expr COLON LBRACE stmt_list RBRACE
      { While ($2, $5) }
  | WHILE error { failwith "Error: 'while' statement is malformed or incomplete." }
  | FOR ID IN expr COLON LBRACE stmt_list RBRACE
      { For ($2, $4, $7) }
  | FOR error { failwith "Error: 'for' loop is malformed or incomplete." }
  | RETURN expr SEMICOLON
      { Return $2 }
  | RETURN error { failwith "Error: 'return' statement is malformed or incomplete." }
  | IMPORT ID SEMICOLON
      { Import $2 }
  | IMPORT error { failwith "Error: 'import' statement is malformed or incomplete." }
  | AS ID SEMICOLON
      { As $2 }
  | FROM ID SEMICOLON
      { From $2 }
  | WRITE expr SEMICOLON
      { Write $2 }
  | PRINT LPAREN expr RPAREN SEMICOLON
      { Expr (FunctionCall ("print", Some $3)) }
  | WRITE error { failwith "Error: 'write' statement is malformed or incomplete." }
  | PASS SEMICOLON
      { Pass }
  | BREAK SEMICOLON
      { Break }
  | CONTINUE SEMICOLON
      { Continue }
  | READ SEMICOLON
      { Read }
  | expr SEMICOLON
      { Expr $1 }
  | error { failwith "Error: Statement is malformed or incomplete." }

expr:
  | INT { Int $1 }
  | TRUE { Bool true }
  | FALSE { Bool false }
  | ID LPAREN RPAREN { FunctionCall ($1, None) }
  | ID LPAREN expr RPAREN { FunctionCall ($1, Some $3) }
  | ID { Var $1 }
  | expr PLUS expr { BinOp ("+", $1, $3) }
  | expr MINUS expr { BinOp ("-", $1, $3) }
  | expr TIMES expr { BinOp ("*", $1, $3) }
  | expr DIV expr { BinOp ("/", $1, $3) }
  | expr MOD expr { BinOp ("%", $1, $3) }
  | expr POW expr { BinOp ("**", $1, $3) }
  | expr AND expr { BinOp ("and", $1, $3) }
  | expr OR expr { BinOp ("or", $1, $3) }
  | NOT expr %prec NOT { UnOp ("not", $2) }
  | expr EQUALS expr { BinOp ("==", $1, $3) }
  | expr NEQ expr { BinOp ("!=", $1, $3) }
  | expr LT expr { BinOp ("<", $1, $3) }
  | expr GT expr { BinOp (">", $1, $3) }
  | expr LEQ expr { BinOp ("<=", $1, $3) }
  | expr GEQ expr { BinOp (">=", $1, $3) }
  | LPAREN expr RPAREN { $2 }
  | ID EQ expr { Assign ($1, $3) }
  | LBRACKET expr_list RBRACKET { ArrayLiteral $2 }
  | error { failwith "Error: Expression is malformed or incomplete." }

expr_list:
  | expr COMMA expr_list { $1 :: $3 }
  | expr { [$1] }

param_list_opt:
  | param_list { $1 }
  | /* empty */ { [] }

param_list:
  | ID COMMA param_list { $1 :: $3 }
  | ID { [$1] }
