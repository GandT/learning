# -*- coding: utf-8 -*-
=begin
　2017.5.11
　ランダム単語列生成プログラム
=end


txt = ""

10000.times{
  # 単語長
  wlen = rand(10) + 1

  wlen.times{
    # 文字
    txt << (33 + rand(93)).chr
  }

  # 空白or改行
  if rand(100) == 0 then
    txt << "\n"
  else
    txt << " "
  end
}

print txt
