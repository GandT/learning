# -*- coding: utf-8 -*-
=begin
　2017.5.11
　正規表現練習
=end


def main
  # 必要文字列の読み込み
  s = File.read("test.txt")

  # 正規表現
  puts "【/a/】"
  puts /a/ =~ s
  puts "【%r(a)　上と同じ】"
  puts %r(a) =~ s
  puts "【%r(/a)】"
  puts %r(/a) =~ s
  puts "【/^/　行頭】"
  puts /^/ =~ s
  puts "【/$/　行末】"
  puts /$/ =~ s
  puts "【/xyz/】"
  puts /xyz/ =~ s
  puts "【/[xyz]/　xかyかz】"
  puts /[xyz]/ =~ s
  puts "【/[x-z]/ xからzのどれか】"
  puts /[x-z]/ =~ s
  puts "【/[x-z][a-c]/】"
  puts /[x-z][a-c]/ =~ s
  puts "【/a..a/　aで始まりaで終わる4文字】"
  puts /a..a/ =~ s
  puts "【/@*/　@から始まる0回以上の繰り返し】"
  puts /@*/ =~ s
  puts "【/@@*/　@から始まる1回以上の繰り返し】"
  puts /@@*/ =~ s
  puts "【/@+/　@から始まる1回以上の繰り返し　上と同じ】"
  puts /@+/ =~ s
  puts "【/@m+/】"
  puts /@m+/ =~ s
  puts "【/g.*t/　gとtで囲まれた部分】"
  puts /g.*t/ =~ s
  puts "【/g.?t/　gとtで一文字ぐらい囲まれた部分】"
  puts /g.*?/ =~ s
  puts "【/g.*t/　gとtで囲まれた最短部分】"
  puts /g.*?t/ =~ s
  puts "【/(ah)+/　ahの繰り返し】"
  puts /(ah)+/ =~ s
  puts "【/(a|h)*/　aかhの繰り返し】"
  puts /(a|h)+/ =~ s
  puts %w(【Regexp.quote("l*")　「l*」を探す】)
  puts Regexp.quote("l*") =~ s
  puts "【/AAA/i　大文字小文字を無視してaaaを探す】"
  puts /AAA/i =~ s/
end


main
