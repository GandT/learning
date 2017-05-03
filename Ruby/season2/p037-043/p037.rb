# -*- coding: utf-8 -*-
=begin
　2017.5.3
　基本的なクラスの作成
=end

class Kyomu
  # 定数
  Void = nil
  VoidArray = []
  
  # 変数
  @null = nil

  # コンストラクタ（initializeメソッド）
  def initialize(n = nil)
    @null = n
    p "NULL IS DONE."
  end

  # 独自定義メソッド
  def print
    p Void
    p VoidArray
    p @null
  end
end


v = Kyomu.new("NULL")
v.print
