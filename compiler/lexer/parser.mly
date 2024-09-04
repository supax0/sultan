%{
(* Import the AST module *)
open Ast

(* Import the Almostashar debugger module *)
open Almostashar
%}

%token <int> INT
%token <string> ID STRING FSTRING  (* Added FSTRING token *)
%token DEF CLASS IMPORT AS FROM INIT IF ELSE ELSE_IF WHILE READ WRITE IN AT FOR RETURN PASS BREAK CONTINUE
%token TRUE FALSE AND OR NOT
%token PLUS MINUS TIMES DIV MOD POW
%token EQ EQUALS NEQ LT GT LEQ GEQ EOL
%token LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE COMMA COLON DOT SEMICOLON
%token PRINT  (* PRINT token already added *)
%token MAIN   (* MAIN token defined here *)
%token PUBLIC STRUCT  (* Tokens for struct support *)
%token ANNOT  (* Token for annotations *)
%token ARROW

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
%type <(string * string) list> param_list_opt

%%

prog:
  | MAIN LBRACE stmt_list RBRACE   { 
      let stmts = $3 in
      conditional_debug_stmt (FunctionDef ("main", [], stmts)) stmt_to_string;
      FunctionDef ("main", [], stmts) :: []
    }
  | stmt_list                      { 
      List.iter (fun stmt -> conditional_debug_stmt stmt stmt_to_string) $1;
      $1 
    }

stmt_list:
  | stmt_list stmt                 { 
      let stmts = $1 @ [$2] in
      conditional_debug_stmt $2 stmt_to_string;
      stmts 
    }
  | /* empty */                    { [] }

stmt:
  | DEF ID LPAREN param_list_opt RPAREN COLON LBRACE stmt_list RBRACE
      { 
        let fn = FunctionDef ($2, $4, $8) in
        conditional_debug_stmt fn stmt_to_string;
        fn 
      }
  | CLASS ID COLON LBRACE stmt_list RBRACE
      { 
        let cls = ClassDef ($2, $5) in
        conditional_debug_stmt cls stmt_to_string;
        cls 
      }
  | IF expr COLON LBRACE stmt_list RBRACE
      { 
        let if_stmt = If ($2, $5) in
        conditional_debug_stmt if_stmt stmt_to_string;
        if_stmt 
      }
  | ELSE COLON LBRACE stmt_list RBRACE
      { 
        let else_stmt = Else ($4) in
        conditional_debug_stmt else_stmt stmt_to_string;
        else_stmt 
      }
  | ELSE_IF expr COLON LBRACE stmt_list RBRACE
      { 
        let elseif_stmt = ElseIf ($2, $5) in
        conditional_debug_stmt elseif_stmt stmt_to_string;
        elseif_stmt 
      }
  | WHILE expr COLON LBRACE stmt_list RBRACE
      { 
        let while_stmt = While ($2, $5) in
        conditional_debug_stmt while_stmt stmt_to_string;
        while_stmt 
      }
  | FOR ID IN expr COLON LBRACE stmt_list RBRACE
      { 
        let for_stmt = For ($2, $4, $7) in
        conditional_debug_stmt for_stmt stmt_to_string;
        for_stmt 
      }
  | RETURN expr SEMICOLON
      { 
        let return_stmt = Return ($2) in
        conditional_debug_stmt return_stmt stmt_to_string;
        return_stmt 
      }
  | IMPORT ID SEMICOLON
      { 
        let import_stmt = Import ($2) in
        conditional_debug_stmt import_stmt stmt_to_string;
        import_stmt 
      }
  | AS ID SEMICOLON
      { 
        let as_stmt = As ($2) in
        conditional_debug_stmt as_stmt stmt_to_string;
        as_stmt 
      }
  | FROM ID SEMICOLON
      { 
        let from_stmt = From ($2) in
        conditional_debug_stmt from_stmt stmt_to_string;
        from_stmt 
      }
  | WRITE expr SEMICOLON
      { 
        let write_stmt = Write ($2) in
        conditional_debug_stmt write_stmt stmt_to_string;
        write_stmt 
      }
  | PRINT LPAREN expr RPAREN SEMICOLON
      { 
        let print_stmt = Expr (FunctionCall ("print", [$3])) in
        conditional_debug_stmt print_stmt stmt_to_string;
        print_stmt 
      }
  | PASS SEMICOLON
      { 
        let pass_stmt = Pass in
        conditional_debug_stmt pass_stmt stmt_to_string;
        pass_stmt 
      }
  | BREAK SEMICOLON
      { 
        let break_stmt = Break in
        conditional_debug_stmt break_stmt stmt_to_string;
        break_stmt 
      }
  | CONTINUE SEMICOLON
      { 
        let continue_stmt = Continue in
        conditional_debug_stmt continue_stmt stmt_to_string;
        continue_stmt 
      }
  | READ SEMICOLON
      { 
        let read_stmt = Read in
        conditional_debug_stmt read_stmt stmt_to_string;
        read_stmt 
      }
  | PUBLIC STRUCT ID EQ LBRACE struct_fields RBRACE
      { 
        let struct_def = StructDef ($3, $6) in
        conditional_debug_stmt struct_def stmt_to_string;
        struct_def 
      }
  | ANNOT ID stmt
      { 
        let annotated_stmt = AnnotatedStmt ($2, $3) in
        conditional_debug_stmt annotated_stmt stmt_to_string;
        annotated_stmt 
      }
  | expr SEMICOLON
      { 
        let expr_stmt = Expr ($1) in
        conditional_debug_stmt expr_stmt stmt_to_string;
        expr_stmt 
      }
  | error
      { 
        let error_stmt = Pass in
        conditional_debug_stmt error_stmt stmt_to_string;
        error_stmt 
      }

expr:
  | INT                           { 
        let int_expr = Int ($1) in
        conditional_debug_expr int_expr expr_to_string;
        int_expr 
      }
  | TRUE                          { 
        let true_expr = Bool (true) in
        conditional_debug_expr true_expr expr_to_string;
        true_expr 
      }
  | FALSE                         { 
        let false_expr = Bool (false) in
        conditional_debug_expr false_expr expr_to_string;
        false_expr 
      }
  | ID LPAREN RPAREN              { 
        let call_expr = FunctionCall ($1, []) in
        conditional_debug_expr call_expr expr_to_string;
        call_expr 
      }
  | ID LPAREN expr_list RPAREN    { 
        let call_expr = FunctionCall ($1, $3) in
        conditional_debug_expr call_expr expr_to_string;
        call_expr 
      }
  | ID                            { 
        let var_expr = Var ($1) in
        conditional_debug_expr var_expr expr_to_string;
        var_expr 
      }
  | expr PLUS expr                { 
        let binop_expr = BinOp ("+", $1, $3) in
        conditional_debug_expr binop_expr expr_to_string;
        binop_expr 
      }
  | expr MINUS expr               { 
        let binop_expr = BinOp ("-", $1, $3) in
        conditional_debug_expr binop_expr expr_to_string;
        binop_expr 
      }
  | expr TIMES expr               { 
        let binop_expr = BinOp ("*", $1, $3) in
        conditional_debug_expr binop_expr expr_to_string;
        binop_expr 
      }
  | expr DIV expr                 { 
        let binop_expr = BinOp ("/", $1, $3) in
        conditional_debug_expr binop_expr expr_to_string;
        binop_expr 
      }
  | expr MOD expr                 { 
        let binop_expr = BinOp ("%", $1, $3) in
        conditional_debug_expr binop_expr expr_to_string;
        binop_expr 
      }
  | expr POW expr                 { 
        let binop_expr = BinOp ("**", $1, $3) in
        conditional_debug_expr binop_expr expr_to_string;
        binop_expr 
      }
  | expr AND expr                 { 
        let binop_expr = BinOp ("and", $1, $3) in
        conditional_debug_expr binop_expr expr_to_string;
        binop_expr 
      }
  | expr OR expr                  { 
        let binop_expr = BinOp ("or", $1, $3) in
        conditional_debug_expr binop_expr expr_to_string;
        binop_expr 
      }
  | NOT expr %prec NOT            { 
        let unop_expr = UnOp ("not", $2) in
        conditional_debug_expr unop_expr expr_to_string;
        unop_expr 
      }
  | expr EQUALS expr              { 
        let binop_expr = BinOp ("==", $1, $3) in
        conditional_debug_expr binop_expr expr_to_string;
        binop_expr 
      }
  | expr NEQ expr                 { 
        let binop_expr = BinOp ("!=", $1, $3) in
        conditional_debug_expr binop_expr expr_to_string;
        binop_expr 
      }
  | expr LT expr                  { 
        let binop_expr = BinOp ("<", $1, $3) in
        conditional_debug_expr binop_expr expr_to_string;
        binop_expr 
      }
  | expr GT expr                  { 
        let binop_expr = BinOp (">", $1, $3) in
        conditional_debug_expr binop_expr expr_to_string;
        binop_expr 
      }
  | expr LEQ expr                 { 
        let binop_expr = BinOp ("<=", $1, $3) in
        conditional_debug_expr binop_expr expr_to_string;
        binop_expr 
      }
  | expr GEQ expr                 { 
        let binop_expr = BinOp (">=", $1, $3) in
        conditional_debug_expr binop_expr expr_to_string;
        binop_expr 
      }
  | LPAREN expr RPAREN            { 
        let paren_expr = $2 in
        conditional_debug_expr paren_expr expr_to_string;
        paren_expr 
      }
  | ID EQ expr                    { 
        let assign_expr = Assign ($1, $3) in
        conditional_debug_expr assign_expr expr_to_string;
        assign_expr 
      }
  | LBRACKET expr_list RBRACKET   { 
        let array_expr = ArrayLiteral ($2) in
        conditional_debug_expr array_expr expr_to_string;
        array_expr 
      }
  | FSTRING                       { 
        let fstring_expr = FString ($1, []) in
        conditional_debug_expr fstring_expr expr_to_string;
        fstring_expr 
      }
  | FSTRING LBRACE expr_list RBRACE
                                  { 
        let fstring_expr = FString ($1, $3) in
        conditional_debug_expr fstring_expr expr_to_string;
        fstring_expr 
      }
  | ID DOT ID                     { 
        let field_access_expr = StructFieldAccess ($1, $3) in
        conditional_debug_expr field_access_expr expr_to_string;
        field_access_expr 
      }
  | error
      { 
        let error_expr = Var ("error") in
        conditional_debug_expr error_expr expr_to_string;
        error_expr 
      }

expr_list:
  | expr COMMA expr_list          { $1 :: $3 }
  | expr                          { [$1] }

param_list_opt:
  | param_list                    { $1 }
  | /* empty */                   { [] }

param_list:
  | ID COLON ID COMMA param_list { ($1, $3) :: $5 }
  | ID COLON ID { [($1, $3)] }

struct_fields:
  | ID ARROW expr SEMICOLON struct_fields { ($1, $3) :: $5 }
  | ID ARROW expr SEMICOLON                { [($1, $3)] }
