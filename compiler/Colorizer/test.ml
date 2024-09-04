(* test_colorizer.ml *)

let () =
  (* Test default error message *)
  print_endline (Colorizer.error_msg "This is an error message.");

  (* Test default warning message *)
  print_endline (Colorizer.warning_msg "This is a warning message.");

  (* Test default success message *)
  print_endline (Colorizer.success_msg "This is a success message.");

  (* Test default info message *)
  print_endline (Colorizer.info_msg "This is an info message.");

  (* Test default debug message *)
  print_endline (Colorizer.debug_msg "This is a debug message.");

  (* Test default note message *)
  print_endline (Colorizer.note_msg "This is a note message.");

  (* Test default prompt message *)
  print_endline (Colorizer.prompt_msg "This is a prompt message.");

  (* Test custom message with a different color *)
  print_endline (Colorizer.custom_msg Colorizer.Magenta "[CUSTOM] " "This is a custom message.");

  (* Test Tiger Mode enabled *)
  Colorizer.set_tiger_mode true;
  print_endline (Colorizer.error_msg "This is an error message with Tiger Mode.");
  print_endline (Colorizer.success_msg "This is a success message with Tiger Mode.");

  (* Test Tiger Mode disabled *)
  Colorizer.set_tiger_mode false;
  print_endline (Colorizer.info_msg "This is an info message without Tiger Mode.");

  (* Test setting a custom prefix *)
  Colorizer.set_prefix "error" "Critical Error: ";
  print_endline (Colorizer.error_msg "This is a critical error message.");

  (* Test Rust-style error underline *)
  let rust_error = Colorizer.rust_style_error "Unexpected token" "let x = 42;" 9 in
  print_endline rust_error;
