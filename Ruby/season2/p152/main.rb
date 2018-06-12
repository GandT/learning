#coding: UTF-8
=begin
  2018.5.17
  クリップボード

  【参考文献】
    - 廣野秀樹（2011）「LinuxとRubyでのクリップボード操作」, <https://hirono0001.wordpress.com/2011/05/14/linux%E3%81%A8ruby%E3%81%A7%E3%81%AE%E3%82%AF%E3%83%AA%E3%83%83%E3%83%97%E3%83%9C%E3%83%BC%E3%83%89%E6%93%8D%E4%BD%9C/>
    - janlelis（2017）「Ruby Clipboard」, <https://github.com/janlelis/clipboard>
=end

require "clipboard"

text = "text"

Clipboard.clear
Clipboard.copy(text)
puts Clipboard.paste(text)
