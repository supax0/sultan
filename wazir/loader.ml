(* wazir/loader.ml *)

let base_path = "./"  (* Define the base path as needed *)

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
  | Sys_error err -> Error (Utils.error_msg ("Failed to load supported languages: " ^ err))

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
  | Sys_error err -> Error (Utils.error_msg ("Failed to load syntax map: " ^ err))
  | Failure err -> Error (Utils.error_msg ("Failed to parse syntax map: " ^ err))
