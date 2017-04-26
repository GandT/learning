(* コメント *)

(* aからb-1まで足す *)
let rec summention a b = 
    if a >= b then 
        0
    else 
        a + summention (a+1) b
    ;;

Printf.printf "%d\n" (summention 1 10)
