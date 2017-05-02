# -*- coding: utf-8 -*-
=begin
　2017.5.2
　ハッシュの作成とループ
=end

def main
  hash = {
    :hin => 0,
    :min => 100,
    :gai => 1000,
    :国民 => 128000000
  }

  # 表示
  puts "【ハッシュ】"
  p hash
  
  #ひとつずつ表示
  puts "【表示】"
  hash.each do |key,num|
    print key , ",", num, "\n"
  end

  # 日本語対応
  p hash[:国民]
end


main
