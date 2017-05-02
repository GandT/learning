# -*- coding: utf-8 -*-
=begin
　2017.5.2
　繰り返し制御
=end


def main
  # ソースコードを開く
  fp = open("p032.rb")
  
  # 表示
  PrintCode fp
end


def PrintCode fp
  # 行数
  l = 0

  # 行読み込み
  loop do
    # 読み込み
    line = fp.gets

    # 抜け判定
    unless line then break end

    # 行数カウント
    l += 1
    print l, "\t"

    # 3と5の倍数で特殊処理
    if l%3==0 then redo end
    if l%5==0 then next end

    # 内容表示
    print line , "\n"

  end
end  


main
