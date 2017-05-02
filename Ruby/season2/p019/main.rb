# -*- coding: utf-8 -*-
=begin
　2017.5.2
　変数のスコープ確認
=end

# グローバル変数
$main = 1

# 外部ファイル読み込み
require "./do"

# 各種変数表示
def PrintAll get
  # ローカル変数
  print_all = 10
  main = 100

  # 表示
  print "    $main: ", $main      , "\n"
  print "print_all: ", print_all  , "\n"
  print "     main: ", main       , "\n"
  print "      get: ", get        , "\n"
  print "  $global: ", $global    , "\n"
  print "      $do: ", $do        , "\n"
end


# main関数
def main
  doing
  PrintAll 1000
end


main
