(* colorizer.ml *)

type color =
  | Black
  | Red
  | Green
  | Yellow
  | Blue
  | Magenta
  | Cyan
  | White
  | Default

let color_to_string = function
| Black -> "\027[30m"
| Red -> "\027[31m"
| Green -> "\027[32m"
| Yellow -> "\027[33m"
| Blue -> "\027[34m"
| Magenta -> "\027[35m"
| Cyan -> "\027[36m"
| White -> "\027[37m"
| Default -> "\027[0m"

let colorize_text color text =
  let color_code = color_to_string color in
  let reset_code = color_to_string Default in
  color_code ^ text ^ reset_code

(* Configurable prefixes *)
let error_prefix = ref "Error: "
let warning_prefix = ref "Warning: "
let success_prefix = ref "Success: "
let info_prefix = ref "Info: "
let debug_prefix = ref "Debug: "
let note_prefix = ref "Note: "
let prompt_prefix = ref "> "

(* Tiger Mode toggle *)
let tiger_mode = ref true

let set_tiger_mode enabled =
  tiger_mode := enabled

let apply_tiger_mode prefix =
  if !tiger_mode then "=> " ^ prefix else prefix

(* Set custom prefix *)
let set_prefix message_type prefix =
  match message_type with
  | "error" -> error_prefix := prefix
  | "warning" -> warning_prefix := prefix
  | "success" -> success_prefix := prefix
  | "info" -> info_prefix := prefix
  | "debug" -> debug_prefix := prefix
  | "note" -> note_prefix := prefix
  | "prompt" -> prompt_prefix := prefix
  | _ -> failwith "Unknown message type"

(* Colorized message functions with Tiger Mode applied *)
let error_msg msg =
  colorize_text Red (apply_tiger_mode !error_prefix ^ msg)

let warning_msg msg =
  colorize_text Yellow (apply_tiger_mode !warning_prefix ^ msg)

let success_msg msg =
  colorize_text Green (apply_tiger_mode !success_prefix ^ msg)

let info_msg msg =
  colorize_text Blue (apply_tiger_mode !info_prefix ^ msg)

let debug_msg msg =
  colorize_text Cyan (apply_tiger_mode !debug_prefix ^ msg)

let note_msg msg =
  colorize_text Magenta (apply_tiger_mode !note_prefix ^ msg)

let prompt_msg msg =
  colorize_text White (apply_tiger_mode !prompt_prefix ^ msg)

(* Customizable message function *)
let custom_msg color prefix msg =
  colorize_text color (apply_tiger_mode prefix ^ msg)

(* New: Rust-style error underline *)
let rust_style_error msg line_content error_position =
  let underline = String.make (error_position - 1) ' ' ^ "^" in
  let error_msg = error_msg msg in
  let line = "  " ^ line_content in
  let underline_line = "  " ^ colorize_text Red underline in
  error_msg ^ "\n" ^ line ^ "\n" ^ underline_line
