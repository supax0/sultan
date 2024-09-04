let handle_break () =
  Ast.Break

let handle_error_break () =
  failwith "Error: 'break' statement is malformed or incomplete."
