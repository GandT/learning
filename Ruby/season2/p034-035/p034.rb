# -*- coding: utf-8 -*-
=begin
　2017.5.3
　デフォルト引数の設定
=end


def looptext (a = 10, b = 20, c = 30)
  a.times do
    b.times do
      c.times do
        print "ペンギン"
      end
      print "天神！"
    end
    print "\n"
  end
end

def main
  puts "looptext(5,5,5)"
  looptext(5, 5, 5)
  sleep(1)
  puts "looptext"
  looptext
  sleep(1) 
end

main
