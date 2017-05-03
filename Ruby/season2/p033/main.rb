# -*- coding: utf-8 -*-
=begin
　2017.5.3
　二次元配列の作成
=end


require "pp"


def make2d (a, b)
  # 一次元目
  array = Array.new(a)

  # 二次元目
  a.times do |i|
    array[i] = Array.new(b)
  end

  return array;
end


def main
  a = make2d 10,10
  pp a
end


main
  
