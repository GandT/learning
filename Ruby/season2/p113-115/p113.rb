# -*- coding: utf-8 -*-
=begin
　2017.5.13
　時刻の表示
=end

require "time"

puts "【通常】"
p Time.new
p Time.now

puts "【年月日分秒int値二進数】"
t = Time.now
print "年；", t.year, "\n"
print "月：", t.month, "\n"
print "日：", t.day, "\n"
print "時：", t.hour, "\n"
print "分：", t.hour, "\n"
print "秒：", t.hour, "\n"
print "int：", t.to_i, "\n"
print "二進数：", t.to_i.to_s(2), "\n"

puts "【タイムゾーン】"
print t.zone, "\n"

puts "【メソッド呼び出し時差】"
t1 = Time.now
t2 = Time.now
print t2 - t1, "\n"

puts "【世界共通時と日本時間】"
t.utc
p t
t.localtime
p t

puts "【2017/5/13　16:48:30】"
p Time.parse("2017/5/13　16:48:30")
