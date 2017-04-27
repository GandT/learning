# -*- coding: utf-8 -*-
=begin
　2017.4.27
　配列操作
=end

def main
  # 配列作成
  array = [1,2,3,4,5,6,7,8,9,"パナソニック","Matsushita_denki",2.71828182846,[5,0,0,0,"兆","円"]];
  puts array
  print array
  p array
  # 配列要素数
  puts "[length]", array.length
  puts "[size]"  , array.size
  # 配列内アクセス
  p array[12]
  puts array[12][0]
  # 代入
  array[12] = "代表なくして課税なし"
  p array
end


main()
