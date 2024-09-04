let handle_import module_name =
  Ast.Import module_name

let handle_error_import () =
  failwith "Error: 'import' statement is malformed or incomplete."
