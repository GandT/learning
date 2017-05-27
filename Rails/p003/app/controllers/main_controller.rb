class MainController < ApplicationController
    # Cross Site Request Forgeryを受け付ける（？）
    # protect_from_forgery

    # 空のindexを作っておく
    def index
        # リダイレクトかどうかアドレスで判断
        if params['red'] == nil
            @title = "試験空間"
            @text = "何でもないような空間、そして空白へ。"
        else
            @title = params['red']
            @text = "何でもないような空間、新たなる空白へ。"
        end
        @gemversion = `gem list coffee-script-source`

        # フォーム
        if request.post?
            # テキストボックス
            @formstate = "出"
            @formtext = "子曰「" + params['input1'] + "」"
            @formvalue = params['input1']

            # チェックボックス
            if params['check1']
                @checktext = "あー"
            else
                @checktext = "う～ん……"
            end

            # ラジオボタン
            if params['r1']
                @radiotext = "だめ"
            else
                @radiotext = "ぜんぜんだめ" 
            end

            # 選択リスト
            if params['s1']
                @sltxt = "覇権：" + params['s1']
            else
                @sltxt = "共倒れ"
            end

            # 複数選択リスト
            if params['s2']
                @msltxt = "骨密度："
                params['s2'].each{ |s|
                    @msltxt += s
                }
            else
                @msltxt = "崩落"
            end
        else
            # テキストボックス
            @formstate = "入り"
            @formtext = "論ぜよ。"
            @formvalue = ""

            # チェックボックス
            @checktext = "これなんだけど"

            # ラジオボタン
            @radiotext = "攻略対象"

            # 選択リスト
            @sltxt = "誰？"

            # 複数選択リスト
            @msltxt = "次は？"
        end
    end

    # リダイレクトアドレス
    def redirect
        # indexにパラメータを付けてリダイレクトする
        redirect_to action: :index, params: {'red': 'そして再び降り立つ'}
    end
end
