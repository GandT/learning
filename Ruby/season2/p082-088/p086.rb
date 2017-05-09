# -*- coding: utf-8 -*-
=begin
　2017.5.9
　ハッシュの除去と初期化
=end


p hash = {ko: "ko", ke: "ke", ki: "ki", ku: "ku", ka: "ka", 大日本印刷: "区民センター", 飛騨高山: "みゅー＾＾みゅー＾＾"}

p hash.delete(:飛騨高山){ |i|
  "#{i}、ではなし"
}
p hash.delete(:鈴鹿御前){ |i|
  "#{i}、ではなし"
}

p hash.length

p hash.clear

p hash.length
