# -*- coding: utf-8 -*-
=begin
　2017.5.3
　配列要素の取り出し
=end



def main
  array = File.read("text.txt").split
  
  p array[0]
  p array[10]
  p array[1000]
  p array[-1]
  p array[-2]
  p array[-1000]
  p array[10..20]
  p array[10...20]
  p array[10..1000]
  p array[5,5]
  p array[5,1000]
end


main
