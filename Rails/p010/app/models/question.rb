class Question < ApplicationRecord
    # answerとのアソシエーション
    has_many :answer

    # バリデーション
    validates :content, :name, presence: {message: "は必ず入力しなければならない。"}
end
