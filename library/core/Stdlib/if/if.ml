let handle_if cond body =
  Ast.If (cond, body)

let handle_error_if () =
  failwith "Error: 'if' statement is malformed or incomplete."
