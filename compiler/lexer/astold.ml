(* ast.ml - Implementation for the Ast module *)

(* Expression types *)
type expr =
  | Int of int
  | Bool of bool
  | Var of string
  | BinOp of string * expr * expr
  | UnOp of string * expr
  | FunctionCall of string * expr list
  | Assign of string * expr
  | ArrayLiteral of expr list
  | StructFieldAccess of string * string
  | FString of string * expr list

(* Statement types *)
type stmt =
  | Expr of expr
  | FunctionDef of string * (string * string) list * stmt list
  | StructDef of string * (string * expr) list
  | If of expr * stmt list
  | Else of stmt list
  | ElseIf of expr * stmt list
  | While of expr * stmt list
  | For of string * expr * stmt list
  | Return of expr
  | Import of string
  | As of string
  | From of string
  | Pass
  | Break
  | Continue
  | Read
  | Write of expr
  | AnnotatedStmt of string * stmt
  | ClassDef of string * stmt list  (* Add this line *)

(* Program type representing a list of statements *)
type program = stmt list

(* Position Information *)
type position = { line: int; column: int }

(* Annotated Expression with position *)
type 'a annotated = { node: 'a; pos: position }

(* Utility Functions *)

let rec expr_to_string = function
  | Int n -> string_of_int n
  | Bool b -> string_of_bool b
  | Var v -> v
  | BinOp (op, e1, e2) -> "(" ^ expr_to_string e1 ^ " " ^ op ^ " " ^ expr_to_string e2 ^ ")"
  | UnOp (op, e) -> op ^ expr_to_string e
  | FunctionCall (f, args) -> 
    f ^ "(" ^ String.concat ", " (List.map expr_to_string args) ^ ")"
  | Assign (v, e) -> v ^ " = " ^ expr_to_string e
  | ArrayLiteral el -> "[" ^ String.concat ", " (List.map expr_to_string el) ^ "]"
  | StructFieldAccess (s, field) -> s ^ "." ^ field
  | FString (fmt, exprs) -> "f\"" ^ fmt ^ "\"" ^ " {" ^ String.concat ", " (List.map expr_to_string exprs) ^ "}"

let rec stmt_to_string = function
  | Expr e -> expr_to_string e
  | FunctionDef (name, params, body) -> 
    "def " ^ name ^ "(" ^ String.concat ", " (List.map (fun (p, t) -> p ^ " -> " ^ t) params) ^ ") { " ^ stmts_to_string body ^ " }"
  | StructDef (name, fields) ->
    "public struct " ^ name ^ " = { " ^ String.concat "; " (List.map (fun (field, value) -> field ^ " -> " ^ expr_to_string value) fields) ^ " }"
  | If (cond, body) -> "if (" ^ expr_to_string cond ^ ") { " ^ stmts_to_string body ^ " }"
  | Else body -> "else { " ^ stmts_to_string body ^ " }"
  | ElseIf (cond, body) -> "else if (" ^ expr_to_string cond ^ ") { " ^ stmts_to_string body ^ " }"
  | While (cond, body) -> "while (" ^ expr_to_string cond ^ ") { " ^ stmts_to_string body ^ " }"
  | For (var, expr, body) -> "for (" ^ var ^ " in " ^ expr_to_string expr ^ ") { " ^ stmts_to_string body ^ " }"
  | Return expr -> "return " ^ expr_to_string expr
  | Import name -> "import " ^ name
  | As name -> "as " ^ name
  | From name -> "from " ^ name
  | Pass -> "pass"
  | Break -> "break"
  | Continue -> "continue"
  | Read -> "read"
  | Write expr -> "write " ^ expr_to_string expr
  | AnnotatedStmt (annotation, stmt) -> "@" ^ annotation ^ " " ^ stmt_to_string stmt
  | ClassDef (name, body) -> "class " ^ name ^ " { " ^ stmts_to_string body ^ " }"  (* Add this line *)

and stmts_to_string stmts = String.concat "; " (List.map stmt_to_string stmts)

(* The rest of the code remains unchanged *)

(* Visitor/Walker Functions *)

let rec walk_expr f expr =
  Almostashar.conditional_debug_expr expr expr_to_string;
  match expr with
  | Int _ | Bool _ | Var _ -> f expr
  | BinOp (op, e1, e2) -> f (BinOp (op, walk_expr f e1, walk_expr f e2))
  | UnOp (op, e) -> f (UnOp (op, walk_expr f e))
  | FunctionCall (name, args) -> f (FunctionCall (name, List.map (walk_expr f) args))
  | Assign (v, e) -> f (Assign (v, walk_expr f e))
  | ArrayLiteral el -> f (ArrayLiteral (List.map (walk_expr f) el))
  | StructFieldAccess (s, field) -> f (StructFieldAccess (s, field))
  | FString (fmt, exprs) -> f (FString (fmt, List.map (walk_expr f) exprs))

let rec walk_stmt f stmt =
  Almostashar.conditional_debug_stmt stmt stmt_to_string;
  let walk_stmts stmts = List.map (walk_stmt f) stmts in
  match stmt with
  | Expr e -> Expr (walk_expr (fun e -> match f (Expr e) with Expr e' -> e' | _ -> e) e)
  | FunctionDef (name, params, body) -> f (FunctionDef (name, params, walk_stmts body))
  | StructDef (name, fields) ->
    f (StructDef (name, List.map (fun (field, value) -> (field, walk_expr (fun e -> match f (Expr e) with Expr e' -> e' | _ -> e) value)) fields))
  | If (cond, body) -> f (If (walk_expr (fun e -> match f (Expr e) with Expr e' -> e' | _ -> e) cond, walk_stmts body))
  | Else body -> f (Else (walk_stmts body))
  | ElseIf (cond, body) -> f (ElseIf (walk_expr (fun e -> match f (Expr e) with Expr e' -> e' | _ -> e) cond, walk_stmts body))
  | While (cond, body) -> f (While (walk_expr (fun e -> match f (Expr e) with Expr e' -> e' | _ -> e) cond, walk_stmts body))
  | For (var, expr, body) -> f (For (var, walk_expr (fun e -> match f (Expr e) with Expr e' -> e' | _ -> e) expr, walk_stmts body))
  | Return expr -> f (Return (walk_expr (fun e -> match f (Expr e) with Expr e' -> e' | _ -> e) expr))
  | Import _ | As _ | From _ | Pass | Break | Continue | Read -> f stmt
  | Write expr -> f (Write (walk_expr (fun e -> match f (Expr e) with Expr e' -> e' | _ -> e) expr))
  | AnnotatedStmt (annotation, stmt) -> f (AnnotatedStmt (annotation, walk_stmt f stmt))
  | ClassDef (name, body) -> f (ClassDef (name, walk_stmts body))  (* Add this case *)

(* Expression and Statement Printers *)

let print_expr (expression: expr) = print_endline (expr_to_string expression)
let print_stmt (statement: stmt) = print_endline (stmt_to_string statement)

(* Annotation Mechanism *)

let annotate_expr ?(debug=false) (expression: expr) (pos: position) =
  let annotated = { node = expression; pos } in
  if debug then Almostashar.conditional_debug_annotated_expr expression expr_to_string (string_of_int pos.line ^ ":" ^ string_of_int pos.column);
  annotated

let annotate_stmt ?(debug=false) (statement: stmt) (pos: position) =
  let annotated = { node = statement; pos } in
  if debug then Almostashar.conditional_debug_annotated_stmt statement stmt_to_string (string_of_int pos.line ^ ":" ^ string_of_int pos.column);
  annotated

(* Metadata Functions *)

type scope_info = {
  mutable vars: (string * expr) list;
}

let create_scope () = { vars = [] }

let add_variable_to_scope (scope: scope_info) (name: string) (value: expr) = 
  scope.vars <- (name, value) :: scope.vars

let find_variable_in_scope (scope: scope_info) (name: string) : expr option =
  List.assoc_opt name scope.vars
