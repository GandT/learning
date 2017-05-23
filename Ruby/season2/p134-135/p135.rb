# -*- coding: utf-8 -*-
=begin
　2017.5.23
　ブロックの明示的移動
=end

def block1(a, b, &bl)
  puts "1はじめ"
  # 2に突入
  block2(a, b, &bl)
  puts "1おわり"
end


def block2(a, b, &bl)
  puts "2はじめ"
  bl.call(a, b)
  puts "2おわり"
end

block1("国家総動員法", "治安維持法") do |law1, law2|
    5.times {print "コケコッコー"}
    print "\n"
    puts law1
    puts law2
end
