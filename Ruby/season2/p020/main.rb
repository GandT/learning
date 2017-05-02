# -*- coding: utf-8 -*-
=begin
　2017.5.2
　オブジェクトID
=end


def main
  # オブジェクト宣言
  num  = 1
  num1 = 1
  num10 = 10
  flrt = 100.1001
  str = "日民貿易"
  s = str
  string = "日民貿易"
  str_ing = "日民" + "貿易"
  a = [10,20,30,10,20,30,"お早めに"]
  match = /国民×健康÷保険/

  # オブジェクトIDの表示
  puts "【オブジェクトID】"
  print "    num: ", num.object_id    , "\n"
  print "   num1: ", num1.object_id   , "\n"
  print "  num10: ", num10.object_id  , "\n"
  print "  float: ", flrt.object_id   , "\n"
  print "    str: ", str.object_id    , "\n"
  print "      s: ", s.object_id      , "\n"
  print "   s[0]: ", s[0].object_id   , "\n"
  print " string: ", string.object_id , "\n"
  print "str_ing: ", str_ing.object_id, "\n"
  print "      a: ", a.object_id      , "\n"
  print "   a[0]: ", a[0].object_id   , "\n"
  print "  match: ", match.object_id  , "\n"
end


main
