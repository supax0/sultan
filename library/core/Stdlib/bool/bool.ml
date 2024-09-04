let handle_bool b =
  Ast.Bool b

let handle_error_bool () =
  failwith "Error: Malformed boolean expression."
