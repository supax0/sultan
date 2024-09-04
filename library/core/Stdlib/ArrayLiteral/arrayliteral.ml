let handle_arrayliteral expr_list =
  Ast.ArrayLiteral expr_list

let handle_error_arrayliteral () =
  failwith "Error: Malformed array literal."
