(*
　2017.4.28
　再帰階乗
*)

let rec factorial (x)=
  if x <= 0 then
    1
  else
    x * factorial(x-1)
;;
