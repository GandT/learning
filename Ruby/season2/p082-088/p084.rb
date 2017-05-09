# -*- coding: utf-8 -*-
=begin
　2017.5.9
　ハッシュデフォルト値設定
=end


h1 = Hash.new("金")


h2 = Hash.new{ |hash, key|
  hash[key] = key
}


h3 = Hash.new("銅")


p h1[:mo]

p h2[:mo]

p h3[:mo]

p h3.fetch(:mo, "imo")
