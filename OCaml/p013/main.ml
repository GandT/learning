(*
　2017.4.26
　swap処理
*)
let x = 10
let y = 5
;;
print_int x;;
print_char ' ';;
print_int y;;
print_char '\n';;

let x = y and y = x
;;
print_int x;;
print_char ' ';;
print_int y;;
print_char '\n';;
