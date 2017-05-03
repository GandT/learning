# -*- coding: utf-8 -*-
=begin
　2017.5.3
　スタックとキュー
=end

def main
  # 元配列
  array = [0,1,2,0]

  # プッシュ
  puts "push: 10,20"
  array.push(10)
  array.push(20)
  p array
  puts "push: [10,20]"
  array.push([10,20])
  p array

  # ポップ
  print "pop: ", array.pop, "\n"
  print "pop: ", array.pop, "\n"
  p array

  # シフト＝デキュー
  print "shift(dequeue): ", array.shift, "\n"
  print "shift(dequeue): ", array.shift, "\n"
  p array

  # 頭に挿入
  print "unshift: コク, キレ, 旨味"
  array.unshift "コク"
  array.unshift "キレ"
  array.unshift "旨味"
  p array
end


main
