# -*- coding: utf-8 -*-
=begin
　2017.5.9
　文字列の大小比較
=end

p "日民貿易"
p "日民貿易".encode("euc-jp")
p "日民貿易".force_encoding("euc-jp")
p "日民貿易" == "日民貿易".encode("euc-jp")
p "日民貿易" == "日民貿易".force_encoding("euc-jp")
p "日民貿易" >= "日民貿易".encode("euc-jp")
p "日民貿易" >= "日民貿易".force_encoding("euc-jp")
p "日民貿易" <= "日民貿易".encode("euc-jp")
p "日民貿易" <= "日民貿易".force_encoding("euc-jp")

