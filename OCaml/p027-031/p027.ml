(*
  2017.4.28
　リストの全要素加算
*)

olet rec inclist a = 
    match a with
        [] -> []
    | head :: rest -> (head+1) :: inclist rest
