# -*- coding: utf-8 -*-
=begin
　2017.5.13
　組み込み変数
=end

puts "【セーフレベル】"
p $SAFE

puts "【レコードセパレータ】"
p $/
p $\

puts "【Arrayのjoinにおけるデフォルト区切り文字】"
p $,
puts "【Stringのsplitにおけるデフォルト区切り文字】"
p $;

puts "【現在実行中のrubyのpid】"
p $$

puts "【文字コード】"
p $KCODE    # 1.8までっぽい

puts "【実行中のRubyスクリプト名】"
p $PROGRAM_NAME

puts "【Rubyのライブラリパス】"
puts $LOAD_PATH

puts "【requireされたライブラリ一覧】"
puts $LOADED_FEATURES
