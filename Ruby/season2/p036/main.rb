# -*- coding: utf-8 -*-
=begin
　2017.5.3
　クラス属性の表示
=end

def main
  # 各種作成
  a = [1,4,6,8,9]
  b = "pipipiモンゴル"
  c = 30120
  d = 23.4
  e = [:pa => "夏", :pe => "殷", :pi => "周"]

  # 確認
  puts "【表示】"
  p a
  p b
  p c
  p d
  p e
  puts "【所属】"
  p a.class
  p b.class
  p c.class
  p d.class
  p e.class
  puts "【配列判定】"
  p a.instance_of?(Array)
  p b.instance_of?(Array)
  p c.instance_of?(Array)
  p d.instance_of?(Array)
  p e.instance_of?(Array)
  puts "【Objectを継承しているか】"
  p a.is_a?(Object)
  p b.is_a?(Object)
  p c.is_a?(Object)
  p d.is_a?(Object)
  p e.is_a?(Object)

end


main
