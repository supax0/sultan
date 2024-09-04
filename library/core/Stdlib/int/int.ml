let handle_int n =
  Ast.Int n

let handle_error_int () =
  failwith "Error: Malformed integer expression."
