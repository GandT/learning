# -*- coding: utf-8 -*-
=begin
　2017.5.2
　case文の発展
=end


def main
  array = [12, 25.01, "国家と社会", [5,5,5], [:mo =>"も", :me => "め"],'@', /__momonmo__/, false]

  # 配列型判定
  i = 0
  array.each do |e|
    print i, ": "
    case e
    when Numeric ; print "数字   ", e, "\n"
    when String  ; print "文字列   ", e, "\n"
    when Hash    ; print "ハッシュ   ", e, "\n"
    when Array   ; print "配列   ", e, "\n"
    when Regexp  ; print "正規表現   ", e, "\n"
    when File    ; print "ファイル   ", e, "\n"
    else           print "それ以外   ", e, "\n"
    end
    i=i+1
  end
end


main
