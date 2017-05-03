# -*- coding: utf-8 -*-
=begin
　2017.5.3
　FixnumとBignum
=end

def main
  num = 1
  100.times do |i|
    num *= 2
    print "2の", i+1, "乗：", num, "\n"
    print "　…型：", num.class, "\n"
    sleep(0.5)
  end 
end


main
