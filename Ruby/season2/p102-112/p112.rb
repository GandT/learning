# -*- coding: utf-8 -*-
=begin
　2017.5.13
　ファイル処理ライブラリ
=end


require "fileutils"

puts "【おにぎり・みつ豆比較】"
p FileUtils.cmp("./おにぎり.txt", "./子羊のステーキ/みつまめ.cpp")
puts "【ディレクトリまとめ作成】"
FileUtils.mkdir_p(["金閣/寺/ドラグーン", "シルバー/温泉考古学/peppon"])
sleep(5)
puts "【ディレクトリまとめ削除】"
FileUtils.rm_r(["金閣", "シルバー"])
