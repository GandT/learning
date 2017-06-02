class PeopleController < ApplicationController
  layout 'people'

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
    @person = Person.new(person_params)
    if @person.save
      redirect_to '/people'
    else
=begin
      @msg = "ダメ入力ですね。<br>".html_safe
      re = ""
      @person.errors.messages.each do |k, vals|
        vals.each do |val|
          re += '<span stype="color:red">' + k.to_s + '</span> ' + val + '<br>'
        end
      end
      @msg += re.html_safe
=end
      render "add"
    end
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

  # 検索
  def find
    @msg = "検索したいワードを入力してください。"
    @people = Array.new()

    # 検索実行時処理
    if request.post?()
      #@people = Person.where name: params[:find]
      #@people = Person.where "age >= ?", params[:find]
      #@people = Person.where "mail like ? ", '%' +params[:find]+ '%'
      #s = params[:find].split(",")
      #@people = Person.where("age >= ? and age <= ?", s[0], s[1])
      s = '%' + params[:find] + '%'
      @people = Person.where("name like ? or mail like ?", s, s).order("name asc").limit(5)
    end
  end


  # 以下プライベート
  private
  # パラメータ情報が完備であることを保証
  def person_params
    params.require(:person).permit(:name, :age, :mail)
  end
end
