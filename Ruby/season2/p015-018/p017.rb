# -*- coding: utf-8 -*-
=begin
　2017.5.2
　テキストファイル分割読み込み
=end


# 読み込み・表示関数
def ptext (fn)
  # ファイルを開く
  fp = open(fn)

  # 行単位読み込み
  i = 0
  while line = fp.gets do
    i = i+1
    print "\t", i, "行目 : ", line, "\n"
  end
  print "\n\n\n合計", i , "行", "\n\n\n"
end


# メイン関数
def main
  if ARGV[0] then
    ptext ARGV[0]
  else
    ptext "dgrmgr.txt"
  end
end


main
