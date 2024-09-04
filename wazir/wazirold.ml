(* wazir/wazir.ml *)

open Colorizer

open Loader
open Translator
open Utils
open Command_parser

(* Main function to handle the program's entry point *)
let () =
  try
    (* Parse the command-line arguments and execute the appropriate command *)
    let command = Command_parser.parse_args Sys.argv in
    let result = Command_parser.execute_command command in
    match result with
    | Ok msg -> print_endline (Utils.success_msg msg)
    | Error msg -> print_endline (Utils.error_msg msg)
  with
  | Command_parser.InvalidCommand msg ->
      print_endline (Utils.error_msg ("Invalid command: " ^ msg))
  | Sys_error msg ->
      print_endline (Utils.error_msg ("System error: " ^ msg))
  | Failure msg ->
      print_endline (Utils.error_msg ("Failure: " ^ msg))
  | ex ->
      print_endline (Utils.error_msg ("Unexpected error: " ^ Printexc.to_string ex))
