# -*- coding: utf-8 -*-
=begin
　2017.5.12
　カレントディレクトリの表示と移動
=end


puts "【カレントディレクトリ】"
puts Dir.pwd
puts "（移動〜）"
Dir.chdir "子羊のステーキ"
puts "【カレントディレクトリ】"
puts Dir.pwd
puts "（移動〜〜〜〜）"
Dir.chdir "../../../../"
puts "【カレントディレクトリ】"
puts Dir.pwd
