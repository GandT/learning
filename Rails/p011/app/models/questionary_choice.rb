class QuestionaryChoice < ApplicationRecord
    # 主データ：質問内容
    belongs_to :questionary_item

    validates :content, presence:       {message: 'の存在が要請されています。'}
    validates :value,   numericality:   {message: 'は数字表現でなければなりません。'}
end
