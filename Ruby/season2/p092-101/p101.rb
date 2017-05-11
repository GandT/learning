# -*- coding: utf-8 -*-
=begin
　2017.5.11
　内外エンコーディングの確認
=end

fp = open("test.txt")

puts "【内部円弧】"
puts fp.external_encoding
puts "【外部円弧】"
puts fp.internal_encoding
puts fp.read(100)

puts "-----"
fp.rewind
fp.set_encoding("UTF-8:SHIFT_JIS")

puts "【内部円弧】"
puts fp.external_encoding
puts "【外部円弧】"
puts fp.internal_encoding
puts fp.read(100)
