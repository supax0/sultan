(* utils.ml *)

let ends_with str suffix =
  let len_str = String.length str in
  let len_suffix = String.length suffix in
  len_str >= len_suffix && String.sub str (len_str - len_suffix) len_suffix = suffix

let info_msg msg = "[INFO] " ^ msg

let error_msg msg = "[ERROR] " ^ msg

let success_msg msg = "[SUCCESS] " ^ msg
