class Message < ApplicationRecord
    validates :message, presence: {message: "が……ない！！"}
end
