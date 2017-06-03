class BlogconfigsController < ApplicationController
  layout "blogconfigs"

  def index
    # uniqueのブログを表示
    @blogconfig = Blogconfig.find(1)
  end

  def edit
    @blogconfig = Blogconfig.find(1)

    # 編集確認
    if request.patch?()
      @blogconfig.update(blogconfig_params)
      redirect_to "/blogconfigs"
    end
  end


    # パラメータのデータチェック
    private
    def blogconfig_params
      return params.require(:blogconfig).permit(:title, :subtitle, :stylename)
    end
end
