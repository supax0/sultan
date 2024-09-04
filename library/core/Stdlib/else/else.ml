let handle_else body =
  Ast.Else body

let handle_error_else () =
  failwith "Error: 'else' statement is malformed or incomplete."
