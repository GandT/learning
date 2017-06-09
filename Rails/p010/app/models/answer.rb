class Answer < ApplicationRecord
    # questionとのアソシエーション
    belongs_to :question

    # バリデーション
    validates :content, :name, presence: {message: "は必ず記されなければならない。"}
end
