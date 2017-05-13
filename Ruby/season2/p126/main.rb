# -*- coding: utf-8 -*-
=begin
　2017.5.13
　ブロック変数のスコープ
=end


puts "【初期】"
x = y = z = 8765
a = ["全", "労", "災"]
p [x,y,z]
p a

a.each { |x; y|
  p [x,y]
  y = x
  z = x
}

puts "【事後】"
p [x,y,z]
