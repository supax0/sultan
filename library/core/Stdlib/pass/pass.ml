let handle_pass () =
  Ast.Pass

let handle_error_pass () =
  failwith "Error: 'pass' statement is malformed or incomplete."
