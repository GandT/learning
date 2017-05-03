# -*- coding: utf-8 -*-
=begin
　2017.5.3
　モジュールの作成
=end


module NameSpace
  def p
    100.times {print "p"}
    print "\n"
  end
  def s
    print self, "\n"
  end

  module_function :p
  module_function :s
end

NameSpace.p
NameSpace.s
