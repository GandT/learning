(* aからb-1までのリスト生成 *)
let rec list_range a b =
    if a >= b then
        []
    else
        a :: list_range (a+1) b
    ;;

