# -*- coding: utf-8 -*-
=begin
　2017.5.2
　while文とuntil文
=end

def main
  i = 1;
  while i < 2000 do
    p i
    i *= 2
  end

  3.times { puts "-----------------------------" }

  i = 1
  until i > 20000 do
    p i
    i *= 3
  end

end


main
