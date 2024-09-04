(* var.ml *)

module Var = struct
  let handle_var id =
    Ast.Var id

  let handle_error_var () =
    failwith "Error: Malformed variable."
end
