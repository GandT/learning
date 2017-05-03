# -*- coding: utf-8 -*-
=begin
　2017.5.3
　複数配列への同時アクセス
=end

def main
  # 配列宣言
  a = %w(赤 黄 緑 青 紫)
  a1 = [1,2,3,4,5]
  a2 = [1,3,5,7,9]
  a3 = [2,4,6,8,10]

  # 解答用配列の作成
  ans = Array.new(0)

  # 並列アクセス
  a.zip(a1, a2, a3) do |w, x, y, z|
    ans << w + x.to_s + y.to_s + z.to_s
  end

  # 結果表示
  p ans

end

main
