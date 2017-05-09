# -*- coding: utf-8 -*-
=begin
　2017.5.9
　単語出現数カウント
=end

# 変数の設定
fp = open("g_eng.txt")
count = Hash.new(0)

# 検出ループ
while line = fp.gets do
  # 行を単語ごとの配列に変換
  words = line.split

  # 単語ごとの処理
  words.each do |w|
    # 個数カウント
    count[w] += 1
  end
end

# 結果集計ループ
count.sort{ |a, b|
  # 簡易正負生成
  -(a[1] <=> b[1])
}.each{ |key, value|
  print "#{key}\t#{value}回\n"
}
