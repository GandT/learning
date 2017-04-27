(*
　2017.4.26
　求積関数（型明示）
*)

(* 円の面積 *)
let circle (r : float) = 
  r *. r *. 3.14
;;

(* 長方形の面積 *)
let rectangle (a : float) (b : float) = 
  a *. b
;;

let rad = 3.
let x = 10.
let y = 30.
;;

print_float (circle rad) ;;
print_char '\n' ;;
print_float (rectangle x y) ;;
print_char '\n' ;;
