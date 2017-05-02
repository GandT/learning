(*
  2017.4.28
　リストのマッチ演習
*)

let rec sum_of_list list = 
  match list with
    [] -> 0
  | head :: other -> head + (sum_of_list other)
