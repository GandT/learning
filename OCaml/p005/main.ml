(*
　2017.4.26
　小数・文字列表示練習
　参考文献：http://ocaml.jp/refman/libref/Printf.html
*)

(* 変数宣言 *)
let fa = 5.
let fb : float = 4.9
let fc = fa +. fb
;;

(* 表示 *)
Printf.printf "【浮動小数表示】\n";;
Printf.printf "5.\t%f\n"  fa ;;
Printf.printf "4.9\t%f\n" fb ;;
Printf.printf "c\t%f\n"   fc ;;

(* 変数宣言 *)
let ca = 'a'
let sa = "hello"
let sb = " "
let sc = "world"
let sd = sa ^ sb ^ sc
let cb = sa.[0]
;;

(* 表示 *)
Printf.printf "【文字表示】\n";;
Printf.printf "%c\n" ca;;
Printf.printf "%s\n" sa;;
Printf.printf "%s\n" sb;;
Printf.printf "%s\n" sc;;
Printf.printf "%s\n" sd;;
Printf.printf "%c\n" cb;;
