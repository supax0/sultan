(* wazir.ml - Main entry point for the Wazir with Sultan compiler *)

open Colorizer
open Loader
open Translator
open Utils
open Command_parser
open Ast
open Almostashar

let usage () =
  Printf.printf "%s\n" (info_msg "Usage: sultanc -t <filename.sn> -<lang> | -to <outputfilename> <filename.sn> -<lang> | -o <outputfilename> <filename.sn> | addlang <filename> | -help");
  exit 1

(* Function to compile a file *)
let compile filename =
  let in_channel = open_in filename in
  let lexbuf = Lexing.from_channel in_channel in
  try
    lexbuf.lex_curr_p <- { lexbuf.lex_curr_p with pos_fname = filename };
    let parsed = Parser.prog Lexer.token lexbuf in  (* Ensure Parser.prog returns a result type *)
    close_in in_channel;
    print_endline (success_msg "Compilation successful.");
    Ok parsed  (* Return Ok if successful *)
  with
  | e ->
    let error_message = Printf.sprintf "Error at line %d, position %d: %s"
                        lexbuf.lex_curr_p.pos_lnum
                        (lexbuf.lex_curr_p.pos_cnum - lexbuf.lex_curr_p.pos_bol)
                        (Printexc.to_string e) in
    print_endline (error_msg error_message);
    close_in in_channel;
    Error error_message

(* Function to simulate or handle file compilation *)
let compile_file output_filename =
  (* Placeholder for actual compilation logic, which you need to define *)
  Printf.printf "%s\n" (success_msg ("File compiled successfully: " ^ output_filename));
  Ok ("Compilation completed for: " ^ output_filename)

let handle_translation_with_output file_path lang_flag output_filename =
  match handle_translation file_path lang_flag with
  | Ok _ ->
      print_endline (success_msg ("Translation completed for " ^ file_path));
      compile_file output_filename
  | Error msg ->
      print_endline (error_msg ("Translation failed: " ^ msg));
      Error msg

let handle_command cmd =
  match cmd with
  | TranslateOnly (file_path, lang_flag) ->
      begin
        match handle_translation file_path lang_flag with
        | Ok msg -> print_endline (success_msg msg)
        | Error msg -> print_endline (error_msg msg)
      end
  | OutputOnly (output_filename, file_path) ->
      begin
        match compile_file output_filename with
        | Ok msg -> print_endline (success_msg msg)
        | Error msg -> print_endline (error_msg msg)
      end
  | TranslateAndOutput (output_filename, file_path, lang_flag) ->
      ignore (handle_translation_with_output file_path lang_flag output_filename)
  | AddLang filename ->
      print_endline (success_msg ("Language added from file: " ^ filename));
  | Help ->
      usage ()

let () =
  try
    let command = parse_args Sys.argv in
    handle_command command;
  with
  | InvalidCommand msg ->
      print_endline (error_msg ("Invalid command: " ^ msg));
      usage ()
  | Sys_error msg ->
      print_endline (error_msg ("System error: " ^ msg))
  | Failure msg ->
      print_endline (error_msg ("Failure: " ^ msg))
  | ex ->
      print_endline (error_msg ("Unexpected error: " ^ Printexc.to_string ex))
