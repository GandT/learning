(*
  2017.4.28
　リストの全要素操作
*)

(* 全要素操作 *)
let rec apply_list a f = 
    match a with
        [] -> []
    | head :: rest -> (f head) :: apply_list rest f

;;

(* リスト生成 *)
let rec list_range a b =
    if a >= b then
        []
    else
        a :: list_range (a+1) b

;;

apply_list (list_range 0 10) (fun x->x*x)
