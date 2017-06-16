class QuestionaryResult < ApplicationRecord
    # 主データ：質問概要
    belongs_to :questionary

    validates :result, presence: {message: 'の存在が要請されています。'}
end
