(* elseif.ml *)
let handle_elseif cond body =
  Ast.ElseIf (cond, body)

let handle_error_elseif () =
  failwith "Error: 'else if' statement is malformed or incomplete."
