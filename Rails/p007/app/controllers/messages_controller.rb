class MessagesController < ApplicationController
  # messages用のレイアウトを使う
  layout 'messages'

  def index
    @msg = '発言一覧'
    @data = Message.all
  end

  def show
    @msg = "発言詳細"
    @message = Message.find(params[:id])
  end

  def add
    @msg = "発言する"
    @message = Message.new()
  end

  def create
    @message = Message.new(message_params())
    if @message.save
      redirect_to '/messages'
    else
      render 'add'
    end
  end

  def edit
    @msg = "【" + params[:id] + "】を編集する"
    @message = Message.find(params[:id])
  end

  def update
    Message.find(params[:id]).update(message_params())
    redirect_to '/messages'
  end

  def delete
    Message.find(params[:id]).destroy()
    redirect_to '/messages'
  end


  private
  def message_params
    params.require(:message).permit(:person_id, :title, :message)
  end
end
