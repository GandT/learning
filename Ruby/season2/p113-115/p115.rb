# -*- coding: utf-8 -*-
=begin
　2017.5.13
　日付データの処理
=end

require "date"

puts "【今日】"
puts d = Date.today
puts "今週何日目？"
p    d.wday
puts "今月何日目？"
p    d.mday
puts "今年何日目？"
p    d.yday

puts "【1789年7月14日】"
puts d = Date.new(1789,7,14)

puts "【2000年の2月の月末】"
puts d = Date.new(2000,2,-1)

puts "【100ヶ月ずつ】"
15.times{
  puts d = d>>100
}
