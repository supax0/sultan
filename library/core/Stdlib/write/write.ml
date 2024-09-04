let handle_write expr =
  Ast.Write expr

let handle_error_write () =
  failwith "Error: 'write' statement is malformed or incomplete."
