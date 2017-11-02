#coding: UTF-8
=begin
　2017.11.2
　標準エラー出力

　【参考文献】
　zenpou（2016）「rubyで標準エラー出力に出力する方法」, <https://qiita.com/zenpou/items/d498db79d36e507b2080> 2017年11月2日アクセス.
=end

STDOUT.puts "----------ここまで標準出力----------".encode("UTF-8")
STDERR.puts "-------ここから標準エラー出力-------".encode("UTF-8")

STDERR.puts "発言".encode("UTF-8")
STDERR.print "発言だよ～\n".encode("UTF-8")
STDERR.printf "%d回目の発言だねぇ\n".encode("UTF-8"), 3

sleep(1.2)

warn "\n\nあのですね……？\n".encode("UTF-8")
puts "まあまあ（＾＾；".encode("UTF-8")

# powershellから標準出力すると意味不明が発生するのですが……
# →cmdおよびbashでは問題なしなのでpowershellが悪い。我々は悪くない。