(*
　2017.4.28
　クイックソート
*)

let rec qs l = 
    match l with
        [] -> []
    | head::rest ->
        let slist = List.filter(fun x -> x <  head) rest  in
        let llist = List.filter(fun x -> x >= head) rest  in
        (qs slist) @ head :: (qs llist)

;;

qs (random_ints 10000 20)

;;

let check_sorted l = 
    let rec cs l c = 
        match l with 
            [] ->  true
        | head::rest ->
            if c <= head then cs rest head else false
    in
    cs l min_int

;;

let test_qs n = 
    check_sorted (qs (random_ints 100000 n))

;;

test_qs 100000

;;

let measure_qs n = 
    let start = Unix.gettimeofday () in
    let trash = check_sorted (qs (random_ints 100000 n)) in
    let dif = Unix.gettimeofday () -. start in
    Printf.printf "%d要素のソートに%f秒を要しました" n dif

;;

measure_qs 202980
