# -*- coding: utf-8 -*-
=begin
　2017.5.3
　例外の後処理
=end


def main
  begin
    fp = open("そんなものはない.txt")
  rescue => ex
    txt = ex.to_s
    puts txt
  ensure
    puts "おしまい"
  end
end


main
