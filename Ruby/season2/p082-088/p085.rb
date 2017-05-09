# -*- coding: utf-8 -*-
=begin
　2017.5.9
　ハッシュメソッド
=end


def main
  hash = {la: "ら", le: "り", li: "る", lo: "れ", lu: "ろ"}

  print %Q(【キー　:la】)
  p hash.key?(:la)
  print %Q(【キー　"la"】)
  p hash.key?("la")
  print %Q(【キー　:ra】)
  p hash.key?(:ra)

  puts ""

  print %Q(【値　"ら"】)
  p hash.value?("ら")
  print %Q(【値　:ら】)
  p hash.value?(:ら)
  print %Q(【値　"ラ"】)
  p hash.value?("ラ")
end


main
