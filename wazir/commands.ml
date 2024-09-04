(*wazir/command_parser.ml *)
open Colorizer

(* Exception for invalid commands *)
exception InvalidCommand of string

(* Type to represent the parsed command *)
type command =
  | TranslateOnly of string * string
  | OutputOnly of string
  | TranslateAndOutput of string * string
  | AddLang of string * string

(* Function to display usage information *)
let usage () =
  Printf.printf "%s" (info_msg "Usage:\n");
  Printf.printf "%s" (info_msg "  wazir -t <filename.sn> --<lang>    Translate only\n");
  Printf.printf "%s" (info_msg "  wazir -o <filename.sn>            Output only\n");
  Printf.printf "%s" (info_msg "  wazir -to <filename.sn> --<lang>  Translate then output\n");
  Printf.printf "%s" (info_msg "  wazir addlang <filename>.<langname>    Add a new language\n");
  exit 1

(* Function to parse command-line arguments *)
let parse_args argv =
  if Array.length argv < 3 then usage ();

  let flag = argv.(1) in
  let filename = argv.(2) in

  match flag with
  | "-t" when Array.length argv = 4 ->
      let lang_flag = argv.(3) in
      if Filename.check_suffix filename ".sn" then
        TranslateOnly (filename, lang_flag)
      else
        raise (InvalidCommand (error_msg "The file must have a '.sn' extension."))
  | "-o" when Array.length argv = 3 ->
      if Filename.check_suffix filename ".sn" then
        OutputOnly filename
      else
        raise (InvalidCommand (error_msg "The file must have a '.sn' extension."))
  | "-to" when Array.length argv = 4 ->
      let lang_flag = argv.(3) in
      if Filename.check_suffix filename ".sn" then
        TranslateAndOutput (filename, lang_flag)
      else
        raise (InvalidCommand (error_msg "The file must have a '.sn' extension."))
  | "addlang" when Array.length argv = 3 ->
      let langname = Filename.extension filename in
      if String.length langname > 1 && langname.[0] = '.' then
        AddLang (filename, String.sub langname 1 (String.length langname - 1))
      else
        raise (InvalidCommand (error_msg "The file must have a valid language extension, e.g., .langname."))
  | _ -> usage ()
