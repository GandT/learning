# -*- coding: utf-8 -*-
=begin
　2017.5.9
　二次元ハッシュ
=end

require "pp"

h = {
  p: {pa: "ﾊﾟ", pe: "ﾍﾟ", pi: "ﾋﾟ", po: "ﾎﾟ", pu: "ﾌﾟ"},
  m: {ma: "ﾏ" , me: "ﾒ" , mi: "ﾐ" , mo: "ﾓ" , mu: "ﾑ" },
  k: {朝食: "バナナ", 昼食: "リンゴ", 夕食: "ボラティリティ"}
}

pp h

pp h[:p][:pa]
pp h[:m][:me]
pp h[:k][:夕食]
