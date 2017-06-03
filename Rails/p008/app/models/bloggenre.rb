class Bloggenre < ApplicationRecord
    has_many :blogpost

    # 必須：ジャンル名
    validates :name, presence: {message: "が入力されてなかったのでこの話はなかったことになりました。さようなら。"}
end
