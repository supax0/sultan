let handle_continue () =
  Ast.Continue

let handle_error_continue () =
  failwith "Error: 'continue' statement is malformed or incomplete."
