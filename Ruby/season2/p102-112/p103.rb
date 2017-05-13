# -*- coding: utf-8 -*-
=begin
　2017.5.12
　ファイルのコピーと削除
=end

require "fileutils"

FileUtils.cp("おにぎり.txt", "子羊のステーキ/おにぎり.txt")
FileUtils.mv("おにぎり.txt", "子羊のステーキ/みつまめ.cpp")
FileUtils.cp("子羊のステーキ/みつまめ.cpp", "おにぎり.txt")
puts "作成！"
File.delete("子羊のステーキ/おにぎり.txt")
puts "削除！"
