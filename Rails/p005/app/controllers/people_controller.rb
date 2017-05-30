class PeopleController < ApplicationController
  # 表示データのセット
  def index
    @msg = "個人情報"
    @data = Person.all
  end
end
