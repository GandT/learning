# -*- coding: utf-8 -*-
=begin
　2017.5.13
　Encodingクラス
=end

p s = "Good morning andaramadras of THDKE"
p l = "市立カピチュレーションねむねむ神秘主義学園"

puts "【英語：UTF-8　日本語：SHIFT_JIS】"
p Encoding.compatible?(s, l.encode("SHIFT_JIS"))
puts "【英語：SHIFT_JIS　英語：UTF-8】"
p Encoding.compatible?(l, s.encode("SHIFT_JIS"))

puts "【外部エンコーディング/内部エンコーディング】"
p Encoding.default_external
p Encoding.default_internal

puts "【エンコードを探す：EUC-JP】"
e = Encoding.find("EUC-JP")
p e

puts "【エンコーディング一覧の表示】"
puts "①名前"
puts Encoding.name_list
puts "②本体"
puts Encoding.list

puts "【さっき探したエンコーディング名】"
p e.name

puts "【SHIFT_JISの別名】"
p Encoding.find("SHIFT_JIS").names
puts "【SJISの別名】"
p Encoding.find("SJIS").names
