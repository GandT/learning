# -*- coding: utf-8 -*-
=begin
　2017.5.3
　配列の作成
=end

# テキストから配列を作成
def txtarray filename
  # テキストを読み込む
  text = File.read(filename)

  # 配列に分割
  array = text.split
rescue
  puts "そんなファイルはない"
  array = nil
ensure
  return array
end


def main
  # 簡易文字列配列
  a0 = %w(大 東 亜 共 栄 圏)
  # 読み込みテキストから
  a1 = txtarray "text.txt"

  # 表示
  p a0
  p a1
end


main
