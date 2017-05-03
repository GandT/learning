# -*- coding: utf-8 -*-
=begin
　2017.5.3
　数学関数の利用
=end

def main
  # 数学関数の利用
  include Math

  # 各種演算
  puts "sin(x)^2 + cos(x)^2"
  puts sin(10)**2 + cos(10)**2
  puts "atan2(y=8,x=10)"
  puts atan2(8,11)
  puts "√10"
  puts sqrt(10)
  puts "10^(1/3)"
  puts cbrt(10)
  puts 10 ** Rational(1,3)
  puts "ベクトル(10,20)の大きさ"
  puts hypot(10,20)
  puts "e^i"
  # puts exp(Complex(0,sqrt(2)))
  puts "→無理ぽい"
end


main
