# -*- coding: utf-8 -*-
=begin
　2017.5.9
　日本語操作メソッド
=end


require "nkf"
require "iconv"

def nkffilter
  str = File.read("鮫.txt")
  p str
  str = NKF.nkf("-W -e -xm0", str)
  p str
end


def iconvfilter
  fp = open("鮫.txt")
  cd = Iconv.open("EUC-JP", "UTF-8")
  while line = fp.gets do
    p line
    p cd.iconv(line)
  end
end


nkffilter
iconvfilter

sleep(1)

print Encoding.name_list
