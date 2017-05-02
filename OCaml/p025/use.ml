(*
　2017.4.28
　匿名関数
*)

let rec summention (f, n) =
  if n = 0 then
    0
  else
    f n + summention(f, n-1)
;;


summention ((fun x -> x*x), 2)
