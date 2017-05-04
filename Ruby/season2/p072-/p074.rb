# -*- coding: utf-8 -*-
=begin
　2017.5.4
　文字列結合
=end


str1 = "日本"
str2 = "レンタカー"
str3 = str1

puts %Q(【str1 + str2】)
puts str1 + str2
puts str1
puts str2
puts str3

puts %Q(【str1 << str2】)
puts str1 << str2
puts str1
puts str2
puts str3

puts %Q(【str3.concat(str2)】)
puts str3.concat(str2)
puts str1
puts str2
puts str3

puts %Q(【str1 += str2】)
puts str1 += str2
puts str1
puts str2
puts str3
