# -*- coding: utf-8 -*-
=begin
　2017.5.13
　多重代入と配列
=end


s = ["welcome", "to", "ようこそ", ["HA","KA","TA","NO","NaCl","伯方の塩"]]
puts "【元配列】"
p s

a, b, c = s
puts "【先頭３つ】"
p a
p b
p c

puts "【配列からの分割取り出し】"
printf "%s %s %s %s %s %s\n" , *s[3]

puts "【入れ子配列の取り出し】"
r = Array.new
r[0], r[1], r[2], (r[3], r[4], r[5], r[6], r[7], r[8]) = s
p r
