# -*- coding: utf-8 -*-
=begin
　2017.5.3
　イテレータ
=end

list = %w(q a w s e d r f t g y h u j i k o l p ; @ : )

# 要素番号のわかるループ
list.each_with_index do |word, i|
  print "list[", i, "] = ", word, "\n"
end
