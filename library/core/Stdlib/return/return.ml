let handle_return expr =
  Ast.Return expr

let handle_error_return () =
  failwith "Error: 'return' statement is malformed or incomplete."
