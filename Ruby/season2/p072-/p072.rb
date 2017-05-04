# -*- coding: utf-8 -*-
=begin
　2017.5.4
　文字列長と日本語処理
=end

eng = File.read("shark.txt")
jpn = File.read("鮫.txt")
emp = ""

puts "【English】"
p eng.length
p eng.bytesize
p eng.empty?

puts "【日本語】"
p jpn.length
p jpn.bytesize
p jpn.empty?

puts "【空】"
p emp.length
p emp.bytesize
p emp.empty?
