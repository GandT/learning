class Message < ApplicationRecord
    belongs_to :person

    validates :message, presence: {message: "が……ない！！"}
end
