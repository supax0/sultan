(* loader.mli *)

val base_path : string
val load_supported_langs : string -> (string list, string) result
val load_syntax_map : string -> ((int * string) list, string) result
