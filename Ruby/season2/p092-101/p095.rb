# -*- coding: utf-8 -*-
=begin
　2017.5.11
　open-uriライブラリ
=end

require "open-uri"


# htmlを読んで出力する
open("http://ppp-lab.sakura.ne.jp/cpp/library/000.html") do |fp|
  s = fp.read
  s.force_encoding("SHIFT_JIS")
  puts s.encode("UTF-8")
end
