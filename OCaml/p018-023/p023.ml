(*
　2017.4.28
　最大文字コード検出
*)

let rec maxascii (s : string) =
  (* 文字列長 *)
  let len = String.length s in

  (* (最大文字,現在のチェックポイント) *)
  let rec maxasciiin (maxchara, nowcheck) = 
    if nowcheck = len then
      maxchara
    else if s.[nowcheck] > maxchara then
      maxasciiin(s.[nowcheck], nowcheck+1)
    else
      maxasciiin(maxchara, nowcheck+1)
  in
  
  maxasciiin (char_of_int 0, 0)
