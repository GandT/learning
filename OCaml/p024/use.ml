(*
　2017.4.28
　高階関数
*)

let rec summention (f, n) =
  if n = 0 then
    0
  else
    f n + summention(f, n-1)
;;

let f1 x = 
  x
;;
let f2 x =
  x*x + x
;;
let f3 x = 
  x*x*x + x*x + x
;;
