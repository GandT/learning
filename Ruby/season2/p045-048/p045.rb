# -*- coding: utf-8 -*-
=begin
　2017.5.3
　例外処理
=end


def main
  begin
    fp = open("そんなものはない.txt")
    fp.close
  rescue
    puts "そんなものはない"
  end
end


main
