# -*- coding: utf-8 -*-
=begin
　2017.5.3
　クラスの継承による循環配列定義
=end


# 循環配列（循環バッファ）
class CircularBuffer < Array
  # []演算子の上書き
  def [](i)
    super(i % length)
  end
end


def main
  cb = CircularBuffer["く","ぁ","ｗ","せ","ｄ","ｒ","ｆ","ｔ","ｇ","ｙ","ふ","じ","こ","ｌ","ｐ","；","＠","："]
  p cb
  p cb[0]
  p cb[10]
  p cb[100]
  p cb[-1]
  p cb[-11]
  p cb[-111]
end


main
