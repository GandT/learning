class PeopleController < ApplicationController
  # 表示データのセット
  def index
    @msg = "個人情報"
    # 全データ取得
    @data = Person.all
  end

  # 表示
  def show
    @msg = "詳細情報"
    # 対応id番号の個人を取得
    @data = Person.find(params[:id])
  end

  # 追加メッセージ
  def add
    @msg = "新しいデータを追加しまつ。"
    @person = Person.new
  end

  # データ生成
  def create
    if request.post?
      obj = Person.create(person_params)
    end
    redirect_to '/people'
  end

  # 編集
  def edit
    @msg = "データを編集しまつ【id = #{params[:id]}】"
    @person = Person.find(params[:id])
  end

  # 編集情報を反映
  def update
    obj = Person.find(params[:id])
    obj.update(person_params)
    redirect_to '/people'
  end

  # 削除
  def delete
    obj = Person.find(params[:id])
    obj.destroy
    redirect_to '/people'
  end


  # 以下プライベート
  private
  # パラメータ情報が完備であることを保証
  def person_params
    params.require(:person).permit(:name, :age, :mail)
  end
end
