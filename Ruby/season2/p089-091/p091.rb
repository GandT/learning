# -*- coding: utf-8 -*-
=begin
　2017.5.11
　正規表現関連メソッド
=end


def main
  puts "【初期状態】"
  s = "aaaaddddl sjdg oiahsi oefio afjij@@ @@@@@@skfjl ksahfilwehoi etejw2q43 598iosfdfu"
  puts s

  puts "【空白除去】"
  puts s = s.gsub(/\s+/,"")

  puts "【aをすべて$に】"
  s = s.gsub(/a/) do |m|
    "$"
  end
  puts s

  puts "【アルファベットのカウント】"
  count = 0
  s.scan(/[a-z]/i){
    count += 1
  }
  puts count
end


main
