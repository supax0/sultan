let handle_unop op expr =
  Ast.UnOp (op, expr)

let handle_error_unop () =
  failwith "Error: Malformed unary operation."
