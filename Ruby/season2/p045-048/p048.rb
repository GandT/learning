# -*- coding: utf-8 -*-
=begin
　2017.5.3
　例外クラスの表示
=end


def main
  fp = open("完全に虚無.txt")
rescue => ex
  puts "【例外】"
  puts ex
end

# メソッド内で定数は定義できない
Myerr = Class.new(StandardError)
M1 = Class.new(Myerr)
M2 = Class.new(Myerr)
M3 = Class.new(Myerr)
puts Myerr
puts M1
puts M2
puts M3


main
