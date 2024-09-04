let handle_read () =
  Ast.Read

let handle_error_read () =
  failwith "Error: 'read' statement is malformed or incomplete."
