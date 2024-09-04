(* almostashar.mli - Interface for the Almostashar module *)

val debug_expr : 'expr -> ('expr -> string) -> unit
val debug_stmt : 'stmt -> ('stmt -> string) -> unit
val debug_scope : ('name * 'expr) list -> ('expr -> string) -> unit
val debug_annotated_expr : 'expr -> ('expr -> string) -> string -> unit
val debug_annotated_stmt : 'stmt -> ('stmt -> string) -> string -> unit
val set_debug : bool -> unit

val conditional_debug_expr : 'expr -> ('expr -> string) -> unit
val conditional_debug_stmt : 'stmt -> ('stmt -> string) -> unit
val conditional_debug_scope : ('name * 'expr) list -> ('expr -> string) -> unit
val conditional_debug_annotated_expr : 'expr -> ('expr -> string) -> string -> unit
val conditional_debug_annotated_stmt : 'stmt -> ('stmt -> string) -> string -> unit
