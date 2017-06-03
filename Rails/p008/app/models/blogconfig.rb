class Blogconfig < ApplicationRecord
    # 必須：タイトル・スタイル
    validates :title, :stylename, presence: {message: "を書かないやつは何をやってもダメ。"}
end
