# -*- coding: utf-8 -*-
=begin
　2017.5.13
　名前再定義
=end


def main
  puts "ココココココココココ！！！！"
end


alias man main

man

undef man

begin
  man
rescue
  puts "ないです！！！！"
end
