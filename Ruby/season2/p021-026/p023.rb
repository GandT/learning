# -*- coding: utf-8 -*-
=begin
　2017.5.2
　case文
=end


def main
  # 受け取り数字変換
  num = ARGV[0].to_i

  # 範囲チェック
  if(num > 100 || num < -100) 
    print "範囲外"
  else
    # case文＝switch文
    case num
    when 23,45,98,-70
      print "大当たり！"
    when -51,-32,-69,4
      print "当たり！"
    when 60,42,1,-99
      print "まあまあ"
    when -64,-29,-6,-78
      print "うーん"
    else
      print "おしまい"
    end
  end
  print "\n"
end


main
