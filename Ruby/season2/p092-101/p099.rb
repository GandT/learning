# -*- coding: utf-8 -*-
=begin
　2017.5.11
　バッファリング対策
=end
$stdout.puts "mo"
$stderr.puts "核"
$stdout.puts "mo"
$stderr.puts "核"
$stdout.puts "mo"
$stderr.puts "核"
$stdout.puts "mo"
$stderr.puts "核"
sleep(1)
$stdout.puts "mo"
$stdout.flush
$stderr.puts "核"
$stdout.puts "mo"
$stdout.flush
$stderr.puts "核"
$stdout.puts "mo"
$stdout.flush
$stderr.puts "核"
$stdout.puts "mo"
$stdout.flush
$stderr.puts "核"
$stdout.puts "mo"
$stdout.flush
$stderr.puts "核"
sleep(1)
$stdout.sync = true
$stdout.puts "mo"
$stderr.puts "核"
$stdout.puts "mo"
$stderr.puts "核"
$stdout.puts "mo"
$stderr.puts "核"
$stdout.puts "mo"
$stderr.puts "核"


# 結果、変わらず。
