# -*- coding: utf-8 -*-
=begin
　2017.4.27
　eachメソッド
=end

def main()
  # 配列宣言
  sarray = ["東京", "横浜", "大阪", "名古屋", "札幌", "京都", "メンソレータム", 30000000000000000000000000];
  p sarray;

  # ループ書き換え
  for i in 0..sarray.length
    sarray[i] = i;
  end
  p sarray

  # eachによる書き換え
  sarray.each do |i|
    sarray[i] = (1000-i).to_s;
  end
  p sarray

  # eachで取り出したもの中身
  i = 0
  sarray.each do |s|
    s = (i*10).to_s
    puts s
    puts sarray[i]
    i = i+1
  end
end


main()
