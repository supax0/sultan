let handle_functioncall fname args =
  Ast.FunctionCall (fname, args)

let handle_error_functioncall () =
  failwith "Error: Malformed function call."
