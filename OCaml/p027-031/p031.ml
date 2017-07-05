(*
  2017.4.28
　リスト条件抽出
*)

let rec filter_list l filter =
    match l with
        [] -> []
    | head::rest ->
        if filter head then
            head :: filter_list rest filter
        else
            filter_list rest filter

;;

filter_list [1;2;3;4;5;6;7;8;9;14;45;12432525;-23432;37] (fun x -> x mod 3 = 0)
