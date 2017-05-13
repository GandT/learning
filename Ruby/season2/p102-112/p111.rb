# -*- coding: utf-8 -*-
=begin
　2017.5.13
　一時ファイルライブラリ
=end

require "tempfile"

fp = Tempfile.new("モモンガ爆弾")
fp.puts "もももももん！"
fp.rewind
puts fp.path
puts fp.gets
fp.close
