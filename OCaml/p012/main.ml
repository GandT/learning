(*
　2017.4.26
　長方形求積
*)

let rect (a:int) (b:int) = 
  if a > 0 then
    if b > 0 then
      a * b
    else
      -1
  else
    -1;;

print_int (rect 5 10);;
print_char '\n' ;;
print_int (rect (-5) 10);;
print_char '\n' ;;
print_int (rect 5 (-10));;
print_char '\n' ;;
