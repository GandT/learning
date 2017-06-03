class BlogpostsController < ApplicationController
  layout "blogposts"

  def index
    @data = Blogpost.all.order("created_at desc")
  end

  def add
    @blogpost = Blogpost.new
    @genre = Bloggenre.all()

    # post時に追加
    if request.post?()
      @blogpost = Blogpost.create blogposts_params()
      redirect_to "/blogposts"
    end
  end

  def edit
    @blogpost = Blogpost.find(params[:id])
    @genre = Bloggenre.all()

    # patch時に編集
    if request.patch?()
      @blogpost.update blogposts_params()
      redirect_to "/blogposts"
    end
  end

  def delete
    @blogpost = Blogpost.find(params[:id])

    # post時に削除
    if request.post?()
      @blogpost.destroy()
      redirect_to "/blogposts"
    end
  end


  # パラメータのデータチェック
  private
  def blogposts_params
    return params.require(:blogpost).permit(:title, :read, :content, :bloggenre_id)
  end
end
