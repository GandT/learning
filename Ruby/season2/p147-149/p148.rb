#coding: UTF-8
=begin
　2017.11.2
　Ruby CSVの一括読み出し

　【参考文献】
　shizuma（2016）「Ruby CSVを扱うためのメモ」, <https://qiita.com/shizuma/items/7719172eb5e8c29a7d6e> 2017年11月2日アクセス.
=end

require "csv"

csv = CSV::read("data.csv")
p csv
csv.each{ |c|
    p c[1]
}

csv = CSV::read("data.csv", headers: true)
p csv
csv.each{ |c|
    puts c[1]
    puts c["name"]
}