let handle_classdef cname body =
  Ast.ClassDef (cname, body)

let handle_error_classdef cname =
  failwith (Printf.sprintf "Error: Class definition '%s' is malformed or incomplete." cname)
