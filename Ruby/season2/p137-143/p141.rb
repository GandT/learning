# -*- coding: utf-8 -*-
=begin
　2017.5.25
　特異メソッド定義
=end


str = "もにゅもにゅカーネル大行進"

def str.loop(n)
  s = ""
  n.times{
    s += "#{self}"
  }
  return s
end

class << str
  def lenloop
    s = ""
    self.size.times{
      s += "#{self}"
    }
    return s
  end
end

puts str.loop(5)
puts str.lenloop
