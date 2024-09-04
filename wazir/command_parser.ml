(* Wazir/command_parser.ml *)

(* Enable Tiger Mode globally *)
Colorizer.set_tiger_mode true

(* Exception for invalid commands *)
exception InvalidCommand of string

(* Base path pointing to the syntax folder *)
let base_path = "./syntax/"  (* Change this path as needed *)

(* ResourceManager module definition *)
module ResourceManager = struct
  type t = { mutable in_use : bool }

  let create () = { in_use = false }

  let use resource f =
    if resource.in_use then
      failwith (Colorizer.rust_style_error "Resource is already in use" "use resource f" 1)
    else (
      resource.in_use <- true;
      let result = f () in
      resource.in_use <- false;
      result
    )

  let release resource =
    if not resource.in_use then
      failwith (Colorizer.rust_style_error "Resource is not currently in use" "release resource" 1)
    else
      resource.in_use <- false
end

(* Type to represent the parsed command *)
type command =
  | TranslateOnly of string * string
  | OutputOnly of string * string
  | TranslateAndOutput of string * string * string
  | AddLang of string
  | Help

(* Function to display usage information *)
let usage () =
  Printf.printf "%s" (Colorizer.info_msg "Usage:\n");
  Printf.printf "%s" (Colorizer.info_msg "  wazir -t <filename.sn> -<lang>           Translate only\n");
  Printf.printf "%s" (Colorizer.info_msg "  wazir -to <outputfilename> <filename.sn> -<lang>  Translate, then output and compile\n");
  Printf.printf "%s" (Colorizer.info_msg "  wazir -o <outputfilename> <filename.sn>  Compile file without translation (assumed in English)\n");
  Printf.printf "%s" (Colorizer.info_msg "  wazir addlang <filename>                 Add a new language\n");
  Printf.printf "%s" (Colorizer.info_msg "  wazir -help                              Display help information\n");
  exit 1

(* Function to parse command-line arguments *)
let parse_args argv =
  if Array.length argv < 2 then usage ();

  let flag = argv.(1) in
  match flag with
  | "-t" when Array.length argv = 4 ->
      let filename = argv.(2) in
      let lang_flag = argv.(3) in
      if String.length lang_flag > 1 && lang_flag.[0] = '-' then
        let lang = String.sub lang_flag 1 (String.length lang_flag - 1) in
        if Filename.check_suffix filename ".sn" then
          TranslateOnly (filename, lang)
        else
          raise (InvalidCommand (Colorizer.rust_style_error "The file must have a '.sn' extension." "Filename.check_suffix filename \".sn\"" 1))
      else
        raise (InvalidCommand (Colorizer.rust_style_error "Language flag must start with a '-' (e.g., -ar)." "String.length lang_flag > 1 && lang_flag.[0] = '-'" 1))

  | "-to" when Array.length argv = 5 ->
      let output_filename = argv.(2) in
      let filename = argv.(3) in
      let lang_flag = argv.(4) in
      if String.length lang_flag > 1 && lang_flag.[0] = '-' then
        let lang = String.sub lang_flag 1 (String.length lang_flag - 1) in
        if Filename.check_suffix filename ".sn" then
          TranslateAndOutput (output_filename, filename, lang)
        else
          raise (InvalidCommand (Colorizer.rust_style_error "The file must have a '.sn' extension." "Filename.check_suffix filename \".sn\"" 1))
      else
        raise (InvalidCommand (Colorizer.rust_style_error "Language flag must start with a '-' (e.g., -ar)." "String.length lang_flag > 1 && lang_flag.[0] = '-'" 1))

  | "-o" when Array.length argv = 4 ->
      let output_filename = argv.(2) in
      let filename = argv.(3) in
      if Filename.check_suffix filename ".sn" then
        OutputOnly (output_filename, filename)
      else
        raise (InvalidCommand (Colorizer.rust_style_error "The file must have a '.sn' extension." "Filename.check_suffix filename \".sn\"" 1))

  | "addlang" when Array.length argv = 3 ->
      let filename = argv.(2) in
      AddLang filename

  | "-help" ->
      Help

  | _ -> usage ()

(* Function to handle translation *)
let handle_translation file_path lang_flag =
  let lang_map_path = base_path ^ "syntax." ^ lang_flag in
  let en_map_path = base_path ^ "syntax.en" in
  match Translator.load_supported_langs (base_path ^ "supported_langs.txt") with
  | Ok supported_langs ->
      if not (Filename.check_suffix file_path ".sn") then
        Error (Colorizer.rust_style_error "The file must have a '.sn' extension." "Filename.check_suffix file_path \".sn\"" 1)
      else if not (List.mem lang_flag supported_langs) then
        Error (Colorizer.rust_style_error "Unsupported language or flag. Use one of the supported flags." "List.mem lang_flag supported_langs" 1)
      else
        let resource = ResourceManager.create () in
        ResourceManager.use resource (fun () ->
          match (Translator.load_syntax_map lang_map_path,
                 Translator.load_syntax_map en_map_path) with
          | (Ok syntax_lang_map, Ok syntax_en_map) ->
              Translator.translate_file file_path syntax_lang_map syntax_en_map
          | (Error msg, _) | (_, Error msg) ->
              Error (Colorizer.rust_style_error ("Error loading syntax maps: " ^ msg) "Translator.load_syntax_map" 1)
        )
  | Error err_msg -> Error (Colorizer.rust_style_error ("Error loading supported languages: " ^ err_msg) "Translator.load_supported_langs" 1)

(* Placeholder function to simulate file compilation *)
let compile_file output_filename =
  Printf.printf "%s\n" (Colorizer.success_msg ("File compiled successfully: " ^ output_filename));
  Ok ("File compiled successfully: " ^ output_filename)

(* Function to execute the parsed command *)
let execute_command cmd =
  match cmd with
  | TranslateOnly (file_path, lang_flag) ->
      handle_translation file_path lang_flag

  | OutputOnly (output_filename, file_path) ->
      Printf.printf "%s\n" (Colorizer.success_msg ("Output completed: " ^ output_filename));
      compile_file output_filename

  | TranslateAndOutput (output_filename, file_path, lang_flag) ->
      let translation_result = handle_translation file_path lang_flag in
      begin
        match translation_result with
        | Ok _ ->
            Printf.printf "%s\n" (Colorizer.success_msg ("Translation and output completed for " ^ file_path));
            compile_file output_filename
        | Error _ as e -> e
      end

  | AddLang filename ->
      Printf.printf "%s\n" (Colorizer.success_msg ("Language added from file: " ^ filename));
      Ok ("Language added from file: " ^ filename)

  | Help ->
      usage ()
