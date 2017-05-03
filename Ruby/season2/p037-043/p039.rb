# -*- coding: utf-8 -*-
=begin
　2017.5.3
　クラスメソッド
=end

class NovelWriter
  def initialize
  end

  # staticメンバ変数
  def NovelWriter::printing
    novel1 = File.read("novel1.txt")
    print novel1
  end

  # メンバ変数
  def printing
    novel2 = File.read("novel2.txt")
    print novel2
  end
end


def main
  num = ARGV[0].to_i
  if num == 3760
    nw = NovelWriter.new
    nw.printing
  elsif num == 9945
    NovelWriter::printing
  else
    puts "None."
  end
end

main
