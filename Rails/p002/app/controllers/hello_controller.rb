# coding: utf-8

# 末尾がControllerならコントローラークラス
class HelloController < ApplicationController
    # アクションメソッド（アクション≒アドレスに応じて呼び出されるメソッド）
    def index
        # クエリパラメータを受け取る
        name = "モモンガ"                                   # デフォルト名
        name = params["name"] if params["name"] != nil      # 受け取り名

        # 表示文字列を作る
        htmltxt = '
<html>
    <body>
        <h1>今日のおかず</h1>
        <p>クリームシチューごはん</p>
        <p>そして、' + name + '。</p>
    <body>
</html>
'
        # renderメソッドでレンダリングする
        # render plain: "今日のクリームシチュー"
        render html: htmltxt.html_safe
   end
end



=begin
【メモ】
- plain: ってハッシュのキー的なやつですかね。全然ちがう？
- html_safeメソッドはStringクラスのインスタンスメソッド
    * ただし普通のRubyで実行してもはじかれるのでRailsにおいて定義されている模様
- そもそも""で改行含めて文字列化できるRubyにおいてわざわざヒアドキュメント使う必要があるのかはまあ微妙
=end