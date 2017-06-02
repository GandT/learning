class CardsController < ApplicationController
  # /app/views/layouts 内の cards.scss を利用
  layout 'cards'

  # 全データ表示
  def index
    # ※※※複数形※※※
    @cards = Card.all      # See /app/models/card.rb
  end

  # 対象データを表示
  def show
    # ※※※単数形※※※
    @card = Card.find(params[:id])
  end

  # 追加処理
  def add
    if request.post?
      Card.create(card_params)
      goback()
    else
      @card = Card.new
    end
  end

  # 編集処理
  def edit
    @card = Card.find(params[:id])
    # 編集要求時
    if request.patch?
      @card.update(card_params)
      goback()
    end
  end

  # 削除処理
  def delete
    Card.find(params[:id]).destroy
    goback()
  end

  
  
  # パラメータにpermitを付ける
  private
  def card_params
    # パラメーターを生成し保証を付ける
    return params.require(:card).permit(:title, :author, :publisher, :star, :memo)
  end

  # タイトルに戻る
  private
  def goback
    redirect_to '/cards'
  end
end
