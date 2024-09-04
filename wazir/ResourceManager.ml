(* resourcemanager.ml *)
module ResourceManager : sig
  type t

  val create : unit -> t
  val use : t -> (unit -> 'a) -> 'a
  val release : t -> unit
end = struct
  type t = { mutable in_use : bool }

  let create () = { in_use = false }

  let use resource f =
    if resource.in_use then
      failwith "Resource is already in use"
    else (
      resource.in_use <- true;
      let result = f () in
      resource.in_use <- false;
      result
    )

  let release resource =
    if not resource.in_use then
      failwith "Resource is not currently in use"
    else
      resource.in_use <- false
end
