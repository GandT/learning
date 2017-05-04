# -*- coding: utf-8 -*-
=begin
　2017.5.4
　様々な文字列の作成様式
=end


x = "corn"
string1 = "#{x}に生まれたこの命"
string2 = "\vと\vん\vが\vり\vコ\vー\vン\v"
string3 = %Q(今日の天気："#{Math.exp(1)}")

puts x
puts string1
puts string2
puts string3
