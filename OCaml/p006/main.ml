(*
　2017.4.26
　小数計算
*)

let a = 1.5 +. 2.5
let b = 9. /. 3.
let c = 0.1 +. 0.1 +. 0.1 +. 0.1 +. 0.1 +. 0.1 +. 0.1 +. 0.1 +. 0.1 +. 0.1
;;
let d : float = float_of_int 3 +. 4.5
let e : int   = int_of_float 5.8 + 12
;;

Printf.printf "%f\n" a ;;
Printf.printf "%f\n" b ;;
Printf.printf "%f\n" c ;;
Printf.printf "%f\n" d ;;
Printf.printf "%d\n" e ;;
