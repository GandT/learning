# -*- coding: utf-8 -*-
=begin
　2017.5.2
　ppメソッド
=end

require "pp"

def main
  # 配列とハッシュ
  array = [1,3,67,0.213,"もごもご",[2,4,5,"コメダ笑"]]
  hash = {
    :国民 => "kokumin",
    :健康 => "kenkou",
    :保険 => "hoken"
  }

  # 表示
  p array
  pp array
  p hash
  pp hash
end

main
