# -*- coding: utf-8 -*-
=begin
　2017.5.9
　文字列部分取り出し
=end


def main
  # 文字列設定
  s = "ニャッキはこの世の不条理と社会の無情さ、力なき者はただただ耐え忍ぶしかないということを幼児が最初に学ぶアニメ"

  # 分割取り出し
  p s[10..20]
  p s
  p s.slice(10..20)
  p s
  p s.slice!(10..20)
  p s
  p s.slice!(10,10)
  p s
end


main
