# -*- coding: utf-8 -*-
=begin
　文字列検索
　2017.5.9
=end

def searchshark
  s = File.read("shark.txt")

  print "shark(冒頭から)\t", s.index("shark"), "\n"
  print "shark(末尾から)\t", s.rindex("shark"), "\n"
  print "Shark判定\t", s.include?("Shark"), "\n"
end


def searchsame
  s = File.read("鮫.txt")

  print "サメ(冒頭から)\t", s.index("サメ"), "\n"
  print "サメ(末尾から)\t", s.rindex("サメ"), "\n"
  print "鮫判定\t\t", s.include?("鮫"), "\n"
end


def main
  puts File.read("shark.txt")
  searchshark
  puts File.read("鮫.txt")
  searchsame
end


main
