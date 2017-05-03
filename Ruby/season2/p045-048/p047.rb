# -*- coding: utf-8 -*-
=begin
　2017.5.3
　例外のやり直し
=end


def main
  i = 0
  begin
    fp = open("だからないってば.txt")
  rescue
    print i, "  "
    puts "残念！"
    sleep(1)
    i += 1
    retry if i < 10
  end
end


main
