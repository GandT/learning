#coding: UTF-8
=begin
　2017.11.1
　Ruby CSVの逐次読み出し

　【参考文献】
　shizuma（2016）「Ruby CSVを扱うためのメモ」, <https://qiita.com/shizuma/items/7719172eb5e8c29a7d6e> 2017年11月1日アクセス.
=end

require "csv"

data = CSV.foreach('data.csv', headers: true){ |d|
    puts "#{d["age"]}年間#{d["station"]}駅にいる#{d["name"]}という人物を探して欲しい。"
}

