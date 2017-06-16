class QuestionaryItem < ApplicationRecord
    # 主データ：質問概要
    belongs_to  :questionary
    # 従データ：選択肢
    has_many    :questionary_choice

    validates :content, presence: {
        message: 'の存在が要請されています。'
    }
end
