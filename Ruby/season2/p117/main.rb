# -*- coding: utf-8 -*-
=begin
　2017.5.13
　コマンド出力
=end

command = `ruby do.rb`

command.each_line{ |l|
  p l.length
}
