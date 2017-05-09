# -*- coding: utf-8 -*-
=begin
　2017.5.9
　ハッシュ値の取り出し
=end


begin
  h = {pe: "ペ", pa: "パ", pi: "ピ", po: "ポ", pu: "プ"}
  p h
  p h[:pi]
  p h.fetch(:pi)
  h.store("mo", "も")
  p h
  p h.fetch("mo")
  p h.fetch(:mo)
rescue
  puts "例外！"
end


p h.keys
p h.values
