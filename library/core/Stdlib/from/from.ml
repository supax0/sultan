let handle_from module_name =
  Ast.From module_name

let handle_error_from () =
  failwith "Error: 'from' statement is malformed or incomplete."
