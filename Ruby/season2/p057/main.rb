# -*- coding: utf-8 -*-
=begin
　2017.5.3
　乱数の利用
=end


def main
  srand(36784)
  print rand, "  ", rand(10), "  ",  rand(100), "\n"
  srand(36784)
  print rand, "  ", rand(10), "  ",  rand(100), "\n"
  srand(36784)
  print Random.rand, "  ", Random.rand(10), "  ", Random.rand(100), "\n"
end


main
