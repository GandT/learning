# -*- coding: utf-8 -*-
=begin
　2017.5.11
　バイナリモード
=end

File.open("test.txt") do |fp|
  puts "【テキストモード】"
  puts fp.read(100)
  fp.rewind
  fp.binmode
  puts "【バイナリモード】"
  puts fp.read(100)
end
