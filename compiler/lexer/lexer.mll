(* lexer.mll - Lexer for Sultan Language *)
{
  exception Eof
  exception Error of string * Lexing.position
  open Parser
  let current_line = ref 1

  (* Include the Almostashar Debugger Module *)
  open Almostashar
}

rule token = parse
  [' ' '\t']            { token lexbuf }    (* Skip whitespace *)
| ['\n']                { incr current_line; EOL }  (* Handle newlines *)
| ['0'-'9']+ as lxm     { INT(int_of_string lxm) }  (* Integers *)
| ['a'-'z' 'A'-'Z' '_']['a'-'z' 'A'-'Z' '0'-'9' '_']* as lxm {
    match lxm with
    | "def"      -> DEF
    | "class"    -> CLASS
    | "import"   -> IMPORT
    | "as"       -> AS
    | "from"     -> FROM
    | "init"     -> INIT
    | "if"       -> IF
    | "else"     -> ELSE
    | "else_if"  -> ELSE_IF
    | "while"    -> WHILE
    | "print"    -> PRINT
    | "main"     -> MAIN   (* Handling main function *)
    | "read"     -> READ
    | "write"    -> WRITE
    | "in"       -> IN
    | "at"       -> AT
    | "for"      -> FOR
    | "return"   -> RETURN
    | "pass"     -> PASS
    | "break"    -> BREAK
    | "continue" -> CONTINUE
    | "and"      -> AND
    | "or"       -> OR
    | "not"      -> NOT
    | "true"     -> TRUE
    | "false"    -> FALSE
    | "public"   -> PUBLIC
    | "struct"   -> STRUCT
    | _          -> ID lxm  (* Recognize anything else as an identifier *)
  }
| '@'                  { ANNOT }  (* Recognize Python-style decorators *)
| '#' [^'\n']*         { token lexbuf }  (* Ignore comments starting with # *)
| "->"                 { ARROW }  (* Recognize the '->' operator *)
| '='                  { EQ }
| '{'                  { LBRACE }
| '}'                  { RBRACE }
| ','                  { COMMA }
| ':'                  { COLON }
| '.'                  { DOT }
| ';'                  { SEMICOLON }
| '('                  { LPAREN }
| ')'                  { RPAREN }
| '['                  { LBRACKET }
| ']'                  { RBRACKET }
| "f\"" [^'\"']* "\"" as fstr { FSTRING (String.sub fstr 2 (String.length fstr - 3)) }  (* Recognize fstrings *)
| '"'[^'"']*'"' as str { STRING (String.sub str 1 (String.length str - 2)) }
| '\''[^'\'']*'\'' as str { STRING (String.sub str 1 (String.length str - 2)) }
| '+'                  { PLUS }
| '-'                  { MINUS }
| '*'                  { TIMES }
| '/'                  { DIV }
| '%'                  { MOD }
| "**"                 { POW }
| "=="                 { EQUALS }
| "!="                 { NEQ }
| '<'                  { LT }
| '>'                  { GT }
| "<="                 { LEQ }
| ">="                 { GEQ }
| _                    { raise (Error (Printf.sprintf "Unexpected character: '%s'" (Lexing.lexeme lexbuf), Lexing.lexeme_start_p lexbuf)) }
| eof                  { raise Eof }
