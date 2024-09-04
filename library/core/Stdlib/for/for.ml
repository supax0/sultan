let handle_for var expr body =
  Ast.For (var, expr, body)

let handle_error_for () =
  failwith "Error: 'for' loop is malformed or incomplete."
