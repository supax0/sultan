(* almostashar.ml - The debugger module for Sultan *)

(* Function to print debugging information for expressions *)
let debug_expr expr expr_to_string_fn =
  print_endline ("[almostashar] Debugging expression: " ^ expr_to_string_fn expr)

(* Function to print debugging information for statements *)
let debug_stmt stmt stmt_to_string_fn =
  print_endline ("[almostashar] Debugging statement: " ^ stmt_to_string_fn stmt)

(* Function to print the current scope information *)
let debug_scope (scope : ('name * 'expr) list) expr_to_string_fn =
  print_endline "[almostashar] Current scope variables:";
  List.iter (fun (name, expr) ->
    print_endline ("  " ^ (Obj.magic name : string) ^ " = " ^ expr_to_string_fn expr)
  ) scope

(* Function to debug an annotated expression *)
let debug_annotated_expr expr expr_to_string_fn pos =
  print_endline ("[almostashar] Debugging annotated expression at " ^ pos ^ ": " ^
                 expr_to_string_fn expr)

(* Function to debug an annotated statement *)
let debug_annotated_stmt stmt stmt_to_string_fn pos =
  print_endline ("[almostashar] Debugging annotated statement at " ^ pos ^ ": " ^
                 stmt_to_string_fn stmt)

(* Function to enable or disable debugging globally *)
let debug_enabled = ref true

let set_debug mode =
  debug_enabled := mode;
  if mode then
    print_endline "[almostashar] Debugging enabled"
  else
    print_endline "[almostashar] Debugging disabled"

(* Wrapper functions to conditionally print debug information based on the debug flag *)
let conditional_debug_expr expr expr_to_string_fn =
  if !debug_enabled then debug_expr expr expr_to_string_fn

let conditional_debug_stmt stmt stmt_to_string_fn =
  if !debug_enabled then debug_stmt stmt stmt_to_string_fn

let conditional_debug_scope scope expr_to_string_fn =
  if !debug_enabled then debug_scope scope expr_to_string_fn

let conditional_debug_annotated_expr expr expr_to_string_fn pos =
  if !debug_enabled then debug_annotated_expr expr expr_to_string_fn pos

let conditional_debug_annotated_stmt stmt stmt_to_string_fn pos =
  if !debug_enabled then debug_annotated_stmt stmt stmt_to_string_fn pos
