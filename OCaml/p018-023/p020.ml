(*
　2017.4.28
　再帰的偶奇判定
*)

let rec is_even n = 
  (* 偶数判定で0になるなら偶数 *)
  if n = 0 then 
    true
  else
    is_odd (n-1)
and is_odd n = 
  (* 奇数判定で0になるなら奇数 *)
  if n = 0 then
    false
  else
    is_even (n-1)
