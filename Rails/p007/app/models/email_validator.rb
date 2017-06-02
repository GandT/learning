class EmailValidator < ActiveModel::EachValidator
    # バリデーション実行時呼び出しメソッド
    def validate_each(record, attribute, value)
        # record    : バリデーション実行モデルの実体（インスタンス）
        # attribute : バリデーションが設定されているモデル項目
        # value     : バリデーションにおいてチェックする値
        unless value =~ /\A([^@\s]+)@((?:[-a-z0-9]+\.)+[a-z]{2,})\z/i
            #1: 先頭から@または空白来るまで
            #2: @
            #3: 「-またはa～zまたは0～9の後に.」、という文字列の1回以上の繰り返し
            #4: a～zの2文字以上の繰り返し
            #5: 終端
            record.errors[attribute] << (options[:message] || "is not an email")    # orの高度な用法を用いている（返り値のアレ）
        end
    end
end
