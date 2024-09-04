(* command_parser.mli *)

exception InvalidCommand of string

module ResourceManager : sig
  type t
  val create : unit -> t
  val use : t -> (unit -> 'a) -> 'a
  val release : t -> unit
end

type command =
  | TranslateOnly of string * string
  | OutputOnly of string * string
  | TranslateAndOutput of string * string * string
  | AddLang of string
  | Help

val parse_args : string array -> command
val usage : unit -> unit

(* Updated handle_translation to return a result type *)
val handle_translation : string -> string -> (string, string) result

(* Updated execute_command to return a result type *)
val execute_command : command -> (string, string) result
