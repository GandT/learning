class Blogpost < ApplicationRecord
    belongs_to :bloggenre

    # 必須：表題・本文
    validates :title, :content, presence: {message: "を入力せずに世に送り出す気か？？　ん？？？"}
end
