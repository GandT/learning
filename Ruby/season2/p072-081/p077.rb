# -*- coding: utf-8 -*-
=begin
　2017.5.9
　末尾文字列の処理
=end


def sharkread
  # ファイル識別子
  fp = open("shark_br.txt")

  # 読み出しループ
  puts "【通常表示】"
  while line = fp.gets do
    print line
  end
end


def sharkread2
  # ファイル識別子
  fp = open("shark_br.txt")

  # 読み出しループ
  puts "【改行除去表示】"
  while line = fp.gets do
    line.chomp!
    print line
  end
end


def sharkread3
  # ファイル識別子
  fp = open("shark_br.txt")

  # 読み出しループ
  puts "【乱数文字数除去表示】"
  while line = fp.gets do
    line.chomp!
    Random.rand(10).times do
      line.chop!
    end
    print line
  end
end


def main
  sharkread
  print "\n\n\n"
  sharkread2
  print "\n\n\n"
  sharkread3
  print "\n"
end


main
