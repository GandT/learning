(*
　2017.4.28
　反復的定義による階乗計算
*)


let rec factional2 n =
  let rec fact (next, nowans) = 
    if next > n then
      nowans
    else
      fact(next + 1, next * nowans)
  in
  fact(1,1)
