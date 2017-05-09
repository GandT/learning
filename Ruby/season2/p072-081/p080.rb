# -*- coding: utf-8 -*-
=begin
　2017.5.9
　文字列操作メソッド
=end

def main
  s = "Justinianus no pest"
  p s
  puts "【delete:空白】"
  p s.delete!(" ")
  puts "【reverse】"
  p s.reverse!
  puts "【strip】"
  s[0] = s[-1] = " "
  p s.strip!
  puts "【upcase → downcase → capitalize → swapcase】"
  p s.upcase!
  p s.downcase!
  p s.capitalize!
  p s.swapcase!
  puts "【tr：文字列置き換え SUNA => suna】"
  p s.tr!("SUNA","suna")
  print (<<"[EOF]")


＿人人人人人人人人人人人人人＿
＞　セポン＝スナ＝イニッツ　＜
￣Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y￣


[EOF]
end

main
