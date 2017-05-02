# coding: utf-8
load("Lines.rb")

#田園都市線の快速停止駅の駅数配列を作成
#def denspeed()
  #駅関数を記録する配列を作成（空配列）
  interstation = [];

  #田園都市線の駅名を読み込む
  t = denentoshisen();

  #快速停止駅配列の設定
  s = expressStops();

  #急行の駅数取得
  maxss = s.length();

  #急行の停車の停車駅数分だけループ
  for i in 1..maxss-1 do
    #配列に駅数を追加
    interstation<<( t.index(s[i]) - t.index(s[i-1]) - 1 );
  end

  #完成した配列を表示
  print "[";
  print interstation * ",";
  puts  "]";
#end

#####計算量はO(N)#####
