# -*- coding: utf-8 -*-
=begin
　2017.5.12
　ファイル検索ライブラリ
=end


include FileTest

puts "存在：./おにぎり.txt"
p exist?("./おにぎり.txt")
puts "存在：./みつまめ.cpp"
p exist?("./みつまめ.cpp")
puts "ファイル：./おにぎり.txt"
p file?("./おにぎり.txt")
puts "ディレクトリ：./おにぎり.txt"
p directory?("./おにぎり.txt")
puts "実行可能：./子羊のステーキ/みつまめ.cpp"
p executable?("./子羊のステーキ/みつまめ.cpp")
puts "サイズ：./p102.rb"
p size("./p102.rb")
