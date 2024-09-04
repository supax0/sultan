type expr =
  | Int of int
  | Bool of bool
  | Var of string
  | BinOp of string * expr * expr
  | UnOp of string * expr  (* Add this line *)
  | FunctionCall of string * expr option
  | Assign of string * expr
  | ArrayLiteral of expr list

type stmt =
  | Expr of expr
  | FunctionDef of string * string list * stmt list
  | ClassDef of string * stmt list
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

type program = stmt list