# -*- coding: utf-8 -*-
=begin
　2017.5.3
　nil関数
=end


def nilmaker a = nil
  if a
    array = Array.new(a)
  else
    return 
  end
end

def main
  p nilmaker
  p nilmaker 10
end

main
