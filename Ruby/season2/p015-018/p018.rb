# -*- coding: utf-8 -*-
=begin
　2017.5.2
　テキストファイルgrep出力
=end


def grep (fn, match)
  # 変数宣言
  i = 0

  # ファイルを開く
  fp = open fn
 
  # マッチング文字列を正規表現に変換
  check = Regexp.new(match)

  # 一行ずつ取得
  while line = fp.gets do
    # 行数カウント
    i = i+1

    # マッチング表示
    if check =~ line then
      print "\t", i, "行目:\t", line, "\n"
    end
  end

  # 終了
  fp.close
end


def main
  # デフォルト引数の設定
  if (ARGV[0] == nil)
    filename = "dgrmgr.txt";
  else 
    filename = ARGV[0];
  end
  if (ARGV[1] == nil)
    matching = "私";
  else
    matching = ARGV[1];
  end

  # grepメソッドの実行
  grep(filename, matching)
end


main()
