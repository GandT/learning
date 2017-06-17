class Questionary < ApplicationRecord
    # 従データ：質問内容 / 質問結果
    has_many :questionary_item
    has_many :questionary_result

    # 全データが存在することが必要
    validates :title, :description, :deadline, presence: {
        message: 'の存在が要請されています。'
    }
end
