# -*- coding: utf-8 -*-
=begin
　2017.5.3
　クラス変数
=end


class Cls
  # static変数（クラス変数）
  @@static
  attr_accessor :static

  def initialize
    @@static = 0
  end

  def add
    @@static += 1
  end

  # クラス変数へのアクセサは独自実装が必要
  def static
    @@static
  end
  def static= (val)
    @@static = val
  end
end


def main
  # 宣言
  a = Cls.new
  b = Cls.new
  c = Cls.new

  a.add
  b.add
  c.add

  puts a.static
end


main
