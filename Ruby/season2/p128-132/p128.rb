# -*- coding: utf-8 -*-
=begin
　2017.5.16
　論理演算子の応用
=end


# コマンドライン引数の表示
s = ARGV[0] || "default"
puts s
c = ARGV[0] && ARGV[0][0] || "d"
puts c
