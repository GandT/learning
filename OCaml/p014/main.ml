(*
　2017.4.26
　関数内関数
*)

(* 二次式 *)
let f a b c x= 
  (* 二乗の項 *)
  let g x = 
    x * x
  in
  (* 一乗の項 *)
  let h x =
    x
  in
  a * g x + b * h x + c
  ;;

print_int (f 1 1 0 4) ;;
print_char '\n' ;;
print_int (f 1 1 0 5) ;;
print_char '\n' ;;
print_int (f 2 2 9 6) ;;
print_char '\n' ;;
