let handle_as alias =
  Ast.As alias

let handle_error_as () =
  failwith "Error: 'as' statement is malformed or incomplete."
