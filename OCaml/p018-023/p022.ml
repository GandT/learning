(*
　2017.4.28
　log計算量による冪乗
*)

let rec pow (n,m) =
  if m = 1 then 
    n
  else if m mod 2 = 0 then
    pow(n,m/2) * pow(n,m/2)
  else
    pow(n,m/2) * pow(n,m/2+1)
