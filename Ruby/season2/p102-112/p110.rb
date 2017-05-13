# -*- coding: utf-8 -*-
=begin
　2017.5.13
　ファイル状態確認・変更
=end


fn = "./おにぎり.txt"
stt = File.stat(fn)
printf "%o\n", stt.mode

File.chmod(0000, fn)
stt = File.stat(fn)
printf "%o\n", stt.mode

File.chmod(0777, fn)
stt = File.stat(fn)
printf "%o\n", stt.mode

