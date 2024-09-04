let handle_while cond body =
  Ast.While (cond, body)

let handle_error_while () =
  failwith "Error: 'while' statement is malformed or incomplete."
