(* Ispeak.ml *)
open Translator

(* Configuration paths *)
let ispeak_path = "settings"
let supported_langs_file = ispeak_path ^ "/LangSettings.sns"
let syntax_core_maps_path = ispeak_path ^ "/Ispeak/Native/"
let syntax_core_base_lang_file = syntax_core_maps_path ^ "syntax.en"

(* Function to parse flags from LangSettings.sns, ignoring comments and extracting flags *)
let parse_flags line =
  if String.starts_with ~prefix:"#" line then
    None  (* Ignore comment lines *)
  else
    match String.split_on_char ';' line with
    | _ :: _ :: flag :: _ -> Some (String.trim flag)  (* Extract the flag part *)
    | _ -> None  (* In case of improperly formatted lines *)

(* Load the supported languages from file, extracting flags *)
let load_flags file_path =
  try
    let ic = open_in file_path in
    let rec read_flags acc =
      try
        let line = input_line ic in
        match parse_flags line with
        | Some flag -> read_flags (flag :: acc)
        | None -> read_flags acc
      with
      | End_of_file -> acc
    in
    let flags = read_flags [] in
    close_in ic;
    Ok (List.rev flags)
  with
  | Sys_error err -> Error ("Failed to load flags: " ^ err)

(* Load the supported languages flags *)
let supported_flags = 
  match load_flags supported_langs_file with
  | Ok flags -> flags
  | Error msg -> failwith msg

(* Function to load and return the syntax map from the specified file path *)
let load_map file_path =
  match load_syntax_map file_path with
  | Ok map -> map
  | Error msg -> failwith ("Failed to load syntax map from " ^ file_path ^ ": " ^ msg)

(* Function to translate a file given its path, language flag, and optional output folder *)
let translate_sn_file file_path lang_flag output_folder_opt =
  if not (List.mem lang_flag supported_flags) then
    failwith ("Unsupported language or flag. Use one of the supported flags: " ^ String.concat ", " supported_flags)
  else
    let lang_code = String.sub lang_flag 1 (String.length lang_flag - 1) in
    let syntax_map_file = syntax_core_maps_path ^ "syntax." ^ lang_code in
    let syntax_en_map = load_map syntax_core_base_lang_file in
    let syntax_map = load_map syntax_map_file in
    match translate_file file_path syntax_map syntax_en_map output_folder_opt with
    | Ok msg -> print_endline msg  (* Successfully translated the file *)
    | Error msg -> failwith ("Failed to translate file: " ^ msg)

(* Function to process Ispeak.sn, each line containing a path, a tag, and optionally an output folder *)
let process_ispeak_file file_path =
  let ic = open_in file_path in
  try
    while true do
      let line = input_line ic in
      match String.split_on_char ' ' line with
      | [sn_path; lang_flag; output_folder] -> translate_sn_file sn_path lang_flag (Some output_folder)
      | [sn_path; lang_flag] -> translate_sn_file sn_path lang_flag None
      | _ -> failwith "Each line must contain at least a file path and a language flag, optionally an output folder."
    done
  with
  | End_of_file -> close_in ic
  | Sys_error msg -> failwith ("Error processing Ispeak.sn: " ^ msg)

(* Main entry point *)
let () =
  match Array.length Sys.argv with
  | 2 -> 
    let ispeak_file_path = Sys.argv.(1) in
    if String.lowercase_ascii ispeak_file_path = "ispeak.sn" then
      process_ispeak_file ispeak_file_path
    else
      failwith "Usage: <program> Ispeak.sn or <program> <file_path>.sn <lang_flag>"
  | 3 -> 
    let file_path = Sys.argv.(1) in
    let lang_flag = Sys.argv.(2) in
    translate_sn_file file_path lang_flag None
  | _ -> failwith "Incorrect number of arguments. Usage: <program> Ispeak.sn or <program> <file_path>.sn <lang_flag>"
