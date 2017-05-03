# -*- coding: utf-8 -*-
=begin
　2017.5.3
　アクセサの作成
=end


class Acces1
  # メンバ変数宣言
  @n

  # コンストラクタ
  def initialize n = 0
    @n = n
  end

  # アクセサ
  def n
    @n
  end
  def n=(value)
    @n = value
  end

  # メンバ関数
  def print
    puts @n
  end
end


class Acces2
  # メンバ変数
  @n
  @m

  # コンストラクタ
  def initialize (n = 0, m = nil)
    @n = n
    @m = m
  end

  # アクセサ
  attr_reader   :n
  attr_accessor :m

  # メンバ関数
  def print
    puts n
    puts m
  end
end


def main
  # 作成
  nn = Acces1.new(100)
  mm = Acces2.new(404,"Not Found.")

  # アクセス
  p nn.n
  nn.n = "金科玉条"
  mm.m = mm.n.to_s + " " + mm.m + " and more..."

  # 表示
  nn.print
  mm.print
end


main
