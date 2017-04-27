# -*- coding: utf-8 -*-
=begin
　2017.4.27
　標準入力と条件分岐
=end

print "数字："
input = gets

print "my num: "
if(input.to_i > 10)
  puts input
else
  puts -input.to_i
end
