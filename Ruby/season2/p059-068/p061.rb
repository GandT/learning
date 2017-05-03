# -*- coding: utf-8 -*-
=begin
　2017.5.3
　配列アクセスメソッド
=end


array = File.read("text.txt").split

p array.at 0
p array.slice 0
p array.at 100
p array.slice 10..20
p array.slice 5,10 
