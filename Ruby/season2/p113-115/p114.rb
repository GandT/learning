# -*- coding: utf-8 -*-
=begin
　2017.5.13
　TimeとDateTimeの比較
=end


require "time"
require "date"


# 現在時刻
t1 = Time.now
dt1 = DateTime.now
puts "【現在時刻】"
puts t1
puts dt1

# メソッド呼び出し時差
t2 = Time.now
dt2 = DateTime.now
puts "【メソッド呼び出し時差】"
puts t2 - t1
puts dt2 - dt1

# タイムゾーン変換
t2 = t1.utc
dt2 = dt1.new_offset(0)
puts "【タイムゾーン変換】"
puts t2
puts dt2

# 時間加算
t1.localtime
t2 = t1 + 3600
dt2 = dt1 + Rational(1,24)
puts "【時間加算】"
puts t2
puts dt2
