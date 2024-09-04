(* compiler/lang/translator.ml *)

open Colorizer

let load_supported_langs file_path =
  try
    let ic = open_in file_path in
    let rec read_lines langs =
      try
        let line = input_line ic in
        read_lines (line :: langs)
      with
      | End_of_file -> langs
    in
    let langs = read_lines [] in
    close_in ic;
    Ok (List.rev langs)
  with
  | Sys_error err -> Error (error_msg ("Failed to load supported languages: " ^ err))

let ends_with str suffix =
  let len_str = String.length str in
  let len_suffix = String.length suffix in
  len_str >= len_suffix && String.sub str (len_str - len_suffix) len_suffix = suffix

let load_syntax_map file_path =
  try
    let ic = open_in file_path in
    let rec read_lines map =
      try
        let line = input_line ic in
        match String.split_on_char '=' line with
        | [num; word] -> read_lines ((int_of_string num, String.trim word) :: map)
        | _ -> read_lines map
      with
      | End_of_file -> map
    in
    let map = read_lines [] in
    close_in ic;
    Ok (List.rev map)
  with
  | Sys_error err -> Error (error_msg ("Failed to load syntax map: " ^ err))
  | Failure err -> Error (error_msg ("Failed to parse syntax map: " ^ err))

let translate_line line syntax_map syntax_en_map =
  List.fold_left (fun acc (num, ar_word) ->
    let en_word = List.assoc_opt num syntax_en_map in
    match en_word with
    | Some en -> Str.global_replace (Str.regexp_string ar_word) en acc
    | None -> acc
  ) line syntax_map

let translate_file file_path syntax_map syntax_en_map =
  try
    let ic = open_in file_path in
    let oc = open_out (String.sub file_path 0 (String.length file_path - 3) ^ "aect") in
    let rec translate_lines () =
      try
        let line = input_line ic in
        let translated_line = translate_line line syntax_map syntax_en_map in
        output_string oc (translated_line ^ "\n");
        translate_lines ()
      with
      | End_of_file -> ()
    in
    translate_lines ();
    close_in ic;
    close_out oc;
    Ok (success_msg "File translated successfully")
  with
  | Sys_error err -> Error (error_msg ("Failed to translate file: " ^ err))
  | Failure err -> Error (error_msg ("Failed to process translation: " ^ err))
