# -*- coding: utf-8 -*-
=begin
　2017.5.3
　クラスの拡張
=end


# 平均単語長概算機能の追加
class String
  def length_per_words
    splstr = self.split(/\s+/)
    return (1.0 * self.length / splstr.length) - 1
  end
end


def main
  # 文字列取得
  str = File.read("text.txt")

  p str.length_per_words
end


main
