#coding: UTF-8
=begin
　2017.11.2
　Ruby CSVの生成

　【参考文献】
　shizuma（2016）「Ruby CSVを扱うためのメモ」, <https://qiita.com/shizuma/items/7719172eb5e8c29a7d6e> 2017年11月2日アクセス.
=end

require "csv"

arr = [[0,1,2,3,4],[1,2,3,4,5],[2,3,4,5,6],[3,4,5,6,7]]

puts CSV::generate { |c|
    arr.each{ |d|
        c << d
    }
}