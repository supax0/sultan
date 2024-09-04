(* ast.mli - Interface for the Ast module *)

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
val expr_to_string : expr -> string
val stmt_to_string : stmt -> string

(* Visitor/Walker Functions *)
val walk_expr : (expr -> expr) -> expr -> expr
val walk_stmt : (stmt -> stmt) -> stmt -> stmt

(* Annotation Mechanism *)
val annotate_expr : ?debug:bool -> expr -> position -> expr annotated
val annotate_stmt : ?debug:bool -> stmt -> position -> stmt annotated

(* Type Definitions for Metadata *)
type scope_info = {
  mutable vars: (string * expr) list;
}

val create_scope : unit -> scope_info
val add_variable_to_scope : scope_info -> string -> expr -> unit
val find_variable_in_scope : scope_info -> string -> expr option
