class PostsController < ApplicationController
    def index
        # すべての投稿データを取得（この辺の詳しい話はActiveRecodeの授業を受けろとのこと）（有料なのだが）（げきど）
        @posts = Post.all.order(created_at: "desc")
    end

    def show
        # @post変数にurlで来るidを渡す
        @post = Post.find(params[:id])
    end

    def new
    end

    def created_at

    end
end
