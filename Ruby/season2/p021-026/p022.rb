# -*- coding: utf-8 -*-
=begin
　2017.5.2
　if文とunless文
=end


def main
  # 数字変換
  num = ARGV[0].to_i

  print "受け取り：", num, "\n"

  #if表示
  if(num > 0) 
    print "金"
  elsif(num == 0)
    print "銅"
  elsif(num > -10000)
    print "銅"
  else
    print "ゴミ"
  end

  print "＆"

  #unless表示
  unless num > 10000
    print "優勝"
  else
    print "( ｀д´) ｹｯ!"
  end

  print "\n"
end


main
