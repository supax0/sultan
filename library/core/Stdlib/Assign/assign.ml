let handle_assign var expr =
  Ast.Assign (var, expr)

let handle_error_assign () =
  failwith "Error: Malformed assignment."
