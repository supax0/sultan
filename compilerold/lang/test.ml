
let () =
  if Array.length Sys.argv <> 3 then
    failwith "Usage: <program> <file_path>.aec --<lang>"
  else
    let file_path = Sys.argv.(1) in
    let lang_flag = Sys.argv.(2) in
    if not (ends_with file_path ".aec") then
      failwith "Error: The file must have a .aec extension."
    else if not (List.mem lang_flag supported_langs) then
      failwith "Unsupported language or flag. Use one of the supported flags: --ar, --fr, --es."
    else
      match lang_flag with
      | "--ar" ->
          let syntax_map = load_syntax_map "syntax/syntax.ar" in
          let syntax_en_map = load_syntax_map "syntax/syntax.en" in
          translate_file file_path syntax_map syntax_en_map
      | "--fr" ->
          let syntax_map = load_syntax_map "syntax/syntax.fr" in
          let syntax_en_map = load_syntax_map "syntax/syntax.en" in
          translate_file file_path syntax_map syntax_en_map
      | "--es" ->
          let syntax_map = load_syntax_map "syntax/syntax.es" in
          let syntax_en_map = load_syntax_map "syntax/syntax.en" in
          translate_file file_path syntax_map syntax_en_map
      | _ ->
          failwith "Unsupported language or flag. Use one of the supported flags: --ar, --fr, --es."