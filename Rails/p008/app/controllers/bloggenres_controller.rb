class BloggenresController < ApplicationController
  layout "bloggenres"

  def index
    @data = Bloggenre.all()
  end

  def add
    # 追加インスタンス
    @bloggenre = Bloggenre.new

    # post時に追加
    if request.post?()
      @bloggenre = Bloggenre.create bloggenre_params()
      redirect_to "/bloggenres"
    end
  end

  def edit
    # 編集インスタンス
    @bloggenre = Bloggenre.find(params[:id])

    # patch時に編集
    if request.patch?()
      @bloggenre.update bloggenre_params()
      redirect_to "/bloggenres"
    end
  end


  # パラメータのデータチェック
  private
  def bloggenre_params
    return params.require(:bloggenre).permit(:name, :memo)
  end
end
