# -*- coding: utf-8 -*-
=begin
　2017.5.2
　シンボルの作成と表示
=end

def main
  # シンボルと文字列の宣言
  symb0 = :po
  symb1 = :"popo"
  str = "popopo"
  
  # 表示
  puts "【表示】"
  p symb0
  p symb1
  p str

  # 操作
  puts "【操作】"
  p symb0.to_s + symb1.to_s + str
end

main
