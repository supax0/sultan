(* functiondef.ml *)
module FunctionDef = struct
  let handle_functiondef fname params body =
    Ast.FunctionDef (fname, params, body)

  let handle_main_block body =
    Ast.Expr (Ast.FunctionCall ("main", []))


  let handle_program stmts =
    stmts  (* Assuming program is defined as `type program = stmt list` *)

  let handle_stmt_list stmts stmt =
    stmts @ [stmt]

  let handle_empty_stmt_list () =
    []

  let handle_expr_stmt expr =
    Ast.Expr expr

  let handle_error_functiondef fname =
    failwith (Printf.sprintf "Error: Function definition '%s' is malformed or incomplete." fname)

  let handle_error_stmt () =
    failwith "Error: Malformed statement."

  let handle_error_expr () =
    failwith "Error: Malformed expression."

  let handle_parenthesized_expr expr =
    expr

  let handle_param_list params =
    params

  let handle_single_expr expr =
    [expr]

  let handle_empty_param_list () =
    []

  let handle_param param =
    [param]

  let handle_expr_list expr expr_list =
    expr :: expr_list
end
