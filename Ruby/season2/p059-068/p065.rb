# -*- coding: utf-8 -*-
=begin
　2017.5.3
　配列操作メソッド
=end


# 初期設定
array = [1, 2, 4, 5, "みちのく", ["100$","@"],-20.5]
a1 = [nil,5,1,5]
a2 = [2,2,6,nil]

# 連結
puts "【連結】"
array += a1 + a2
p array

# nil削除
puts "【掃除】"
array.compact!
p array

# 各種削除
puts "【削除・除去】"
print "1を削除: ", array.delete(1), " -> ", array, "\n"
print "5番目を削除: ", array.delete_at(5), " -> ", array, "\n"
print "4番目から6番目を除去: ", array.slice!(4..6), " -> ", array, "\n"
print "重複除去: ", array.uniq!, "\n"
print "多重化: ", array.collect!{|i| [i,i,i]}, "\n"
print "書き換え: ", array.fill("金色", 5, 5), "\n"
print "平坦化: ", array.flatten!, "\n"
print "逆順化: ", array.reverse!, "\n"
print "文字列除去: ", array.reject!{|i| i.instance_of?(String)}, "\n"
print "ソート: ", array.sort!, "\n"
print "逆順ソート: ", array.sort_by{|i| (-i)>>2}, "\n"

