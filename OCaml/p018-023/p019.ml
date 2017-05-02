(*
　2017.4.28
　タプル利用線形計算量フィボナッチ数列
*)

(* n番目フィボナッチ数列を求める *)
let fib n =
  let rec fibpair n = 
      if n = 1 then
	(1, 0)
      else
	let (n_1, n_2) = fibpair(n-1) in
	(n_1 + n_2, n_1)
  in
  let (ret,_) = fibpair n in
  ret;;
