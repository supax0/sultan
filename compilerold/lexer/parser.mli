type token =
  | INT of (
# 8 "compiler/lexer/parser.mly"
        int
# 6 "compiler/lexer/parser.mli"
)
  | ID of (
# 9 "compiler/lexer/parser.mly"
        string
# 11 "compiler/lexer/parser.mli"
)
  | STRING of (
# 9 "compiler/lexer/parser.mly"
        string
# 16 "compiler/lexer/parser.mli"
)
  | DEF
  | CLASS
  | IMPORT
  | AS
  | FROM
  | INIT
  | IF
  | ELSE
  | ELSE_IF
  | WHILE
  | READ
  | WRITE
  | IN
  | AT
  | FOR
  | RETURN
  | PASS
  | BREAK
  | CONTINUE
  | TRUE
  | FALSE
  | AND
  | OR
  | NOT
  | PLUS
  | MINUS
  | TIMES
  | DIV
  | MOD
  | POW
  | EQ
  | EQUALS
  | NEQ
  | LT
  | GT
  | LEQ
  | GEQ
  | EOL
  | LPAREN
  | RPAREN
  | LBRACKET
  | RBRACKET
  | LBRACE
  | RBRACE
  | COMMA
  | COLON
  | DOT
  | SEMICOLON
  | PRINT
  | MAIN

val prog :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> Ast.program
