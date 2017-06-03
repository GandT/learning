# 継承されていれば空でOK
class Person < ApplicationRecord
    has_many :message

    validates :name , presence:     { message: "を必ず入力しなければならない。" }
    validates :age  , numericality: { message: "の入力は数字で行わなければならない。"}
    validates :mail , email:        { message: "はメールアドレスであるとは到底思えない。"}
end
