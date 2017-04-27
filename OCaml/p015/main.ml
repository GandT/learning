(*
　2017.4.26
　大文字化関数
*)

let func (c : char) = 
  (* 文字コード取得 *)
  let intc = (int_of_char c) in

  (* 文字コード比較 *)
  if intc >= (int_of_char 'a') && intc <= (int_of_char 'z') then
    (* 修正 *)
    let diff = ((int_of_char 'A') - (int_of_char 'a'))  in
    char_of_int (intc + diff)
  else
    c
;;

print_char (func 'a');;
print_char '\n';;
print_char (func 'A');;
print_char '\n';;
print_char (func 's');;
print_char '\n';;
print_char (func 'x');;
print_char '\n';;
print_char (func '1');;
print_char '\n';;
print_char (func '@');;
print_char '\n';;
print_char (func '\n');;
print_char '\n';;

