# -*- coding: utf-8 -*-
=begin
　2017.5.9
　ハッシュの作成
=end

h1 = {:国家 => "National", :総動員 => "Mobilization", 法: "Law"}
p h1

h2 = Hash.new("void")
h2["日本"] = "nichi"
h2["中国"] = "min"
h2["貿易"] = "trade"
p h2
p h2["虚無"]
