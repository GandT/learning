# -*- coding: utf-8 -*-
=begin
　2017.5.11
　マッチとキャプチャ
=end


def main
  s = File.read("test.txt")

  puts "【[数字][アルファベット][数字]でマッチング】"
  puts /((?:\d)+)((?:\w)+)((?:\d)+)/ =~ s
  puts "マッチ部分の取り出し"
  puts $1
  puts $2
  puts $3
  puts $&
  puts "マッチ前"
  puts $`
  # puts "マッチ後"
  # puts $'
end


main
