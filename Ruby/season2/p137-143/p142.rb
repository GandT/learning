# -*- coding: utf-8 -*-
=begin
　2017.5.25
　extendメソッド
=end

module Monmon
  def mo
    puts "ショートケーキのような夏を焼くパラグアイのお化け"
  end
  def me
    self.length.times{
      p "それサバンナでも同じことです。"
    }
  end
end


str = "金木犀のゴジラ"

# 特異メソッド組み込み
str.extend(Monmon)

# 実行
str.mo
str.me
