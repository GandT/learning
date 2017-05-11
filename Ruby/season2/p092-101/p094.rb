# -*- coding: utf-8 -*-
=begin
　2017.5.11
　openとclose
=end

puts "【開く(open)】"
fp = open("test.txt")
puts fp.closed?
puts "【閉じる(.close)】"
fp.close
puts fp.closed?
puts "【開く(File.open)】"
fp = File.open("test.txt")
puts fp.closed?
puts "【閉じる(.closeの返り値)】"
puts fp.close
puts "【開いたデータ(File.read)　冒頭100】"
data = File.read("test.txt")
p data[0..100]
