# -*- coding: utf-8 -*-
=begin
　2017.5.2
　簡易テキストファイル読み込み
=end

def main
  if ARGV[0] == nil then
    p File.read("dgrmgr.txt")
  elsif ARGV[1] == "hidden" then
    puts File.read(ARGV[0])
  else
    p File.read(ARGV[0])
  end
end


main
