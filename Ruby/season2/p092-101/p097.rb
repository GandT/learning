# -*- coding: utf-8 -*-
=begin
　2017.5.11
　入出力メソッド
=end


fp = open("test.txt", "r+")
puts fp.gets
sleep(1)
10.times {puts fp.gets(" ")}
sleep(1)
10.times {puts fp.gets("@")}
sleep(1)

# 完全にgets, each, each_line, readlinesが同じ関数だと勘違いしていましたm(__)m
=begin
fp = open("test.txt", "r+")
puts fp.each(" ")
fp.close
sleep(1)

fp = open("test.txt", "r+")
puts fp.each_line("@")
fp.close
sleep(1)

fp = open("test.txt", "r+")
puts fp.readlines
fp.close
sleep(1)
=end

puts "【終了？】"
puts fp.eof?
sleep(1)
puts "【何行読みました？】"
puts fp.lineno
sleep(1)
puts "【10行追加で読んだことにするわｗ】"
fp.lineno += 10
puts fp.lineno
sleep(1)
puts "【一文字ずつ読み出す】"
15.times{
  puts fp.getc
}
sleep(1)
puts "【100文字差し戻し〜〜〜〜】"
100.times{
  fp.ungetc(80)
}
sleep(1)
puts "【150文字表示】"
count = 0
fp.each_byte do |p|
  print p
  count += 1
  if count >= 75
    break
  end
end
count = 0
fp.each_char do |p|
  print p
  count += 1
  if count >= 75
    break
  end
end
sleep(1)
$stderr.puts "momomo"
$stderr.putc 100
$stderr << "er" << "err" << "error"
puts ""
sleep(1)
puts "【ところでファイルポインタどこいった？】"
puts fp.pos
sleep(1)
puts "【後ろから1000番目に移動して残りを出力】"
fp.seek(-1000, IO::SEEK_END)
puts fp.pos
p fp.read
