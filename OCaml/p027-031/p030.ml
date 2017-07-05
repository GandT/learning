(*
  2017.4.28
　リスト偶数抽出
*)

let rec evens =
    function
        [] -> []
    | head::rest ->
        if head mod 2 = 0 then 
            head :: evens rest 
        else
            evens rest

;;

let rec random_ints a n =
    if n = 0 then
        []
    else
        Random.int a :: random_ints a (n-1)

;;

evens (random_ints 100 10)
