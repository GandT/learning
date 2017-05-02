# -*- coding: utf-8 -*-
=begin
　2017.5.2
　テキストファイル読み込み
=end

def textread (fn)
  # ファイル指定子の作成
  fp = open(fn)

  # 文字列読み出し
  s = fp.read

  # 表示
  print s

  # ファイルを閉じる
  fp.close
end


def main
  # 指定されたファイルを開いて表示
  textread ARGV[0]
end


main
