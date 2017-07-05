(*
  2017.4.28
　乱数によるリスト生成
*)

let rec random_ints a n =
    if n <= 0 then
        []
    else
        Random.int a :: random_ints a (n-1)

;;

random_ints 100 10
