# -*- coding: utf-8 -*-
=begin
　2017.5.12
　フォルダの作成と削除
=end

$stdout.sync = true
IO.popen("ls","w")
sleep(1)
puts "----------"
Dir.mkdir("プププランド政府ガバメント委員会統治機構")
IO.popen("ls","w")
sleep(1)
puts "----------"
Dir.rmdir("プププランド政府ガバメント委員会統治機構")
IO.popen("ls","w")
