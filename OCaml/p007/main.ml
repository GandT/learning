(*
　2017.4.26
　エスケープシーケンス
*)

Printf.printf "%c\n" '\100'
;;
Printf.printf "%d\n" (int_of_char '@')
;;
Printf.printf "%c\n" (char_of_int 80)
;;
Printf.printf "\'\"\"\'\n"
;;
Printf.printf "H e l l o\r w o r l d\n"
;;
Printf.printf "pepepe\b\n"
;;
Printf.printf "\100\n"
;;
Printf.printf "\x50\n"
;;
