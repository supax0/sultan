(* binop.ml *)
module BinOp = struct
  let handle_binop op left right =
    Ast.BinOp (op, left, right)

  let handle_error_binop () =
    failwith "Error: Malformed binary operation."
end
