# -*- coding: utf-8 -*-
=begin
　2017.5.11
　標準入出力
=end

def main
  # 標準入力から受け取る
  puts "入力"
  s = gets
  s.chomp!
  $stdout.printf "標準出力：%s\n", s
  $stderr.printf "標準エラー出力：%s\n", s
end


main
