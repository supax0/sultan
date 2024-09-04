open Colorizer

exception SelfError of string

(* Function to log an error message *)
let log_error msg =
  Printf.eprintf "%s\n" (error_msg ("SelfError: " ^ msg))

(* Function to log an error and raise a SelfError exception *)
let raise_error msg =
  log_error msg;
  raise (SelfError msg)

(* Function to handle errors within a provided function *)
let handle_error f =
  try
    f ()
  with
  | SelfError msg -> Printf.eprintf "%s\n" (error_msg ("Caught SelfError: " ^ msg))
  | e -> Printf.eprintf "%s\n" (error_msg ("Unexpected error: " ^ Printexc.to_string e))

(* Function to print a success message *)
let print_success msg =
  Printf.printf "%s\n" (success_msg msg)
