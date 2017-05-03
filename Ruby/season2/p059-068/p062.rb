# -*- coding: utf-8 -*-
=begin
　2017.5.3
　配列の要素変更
=end


# 配列作成
array = File.read("text.txt").split
p array
print "\n\n\n"

# 要素書き換え
array[5] = "ああああああああ"
array[8] = "うぎゃあああああああああ"
array[11..15] = ["夏","殷","周","ポストアポカリプス","?_india_?"]
p array
print "\n\n\n"

# 要素挿入
array[5,0] = %w(観 自 在 菩 薩)
array[100,0] = %w(おおん おん おおおんおおおん おんおんおん ｷﾞｪﾋﾟｰｰｰｰｰｰｰｰｰｰｰｰｰｰｰ)
p array
print "\n\n\n"

# 配列の再編集
a = array.values_at(2,4,6,8,11,20,100,10000)
p a
print "\n\n\n"
