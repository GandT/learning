class BbsController < ApplicationController
  layout "bbs"

  # 初期化
  def initialize
    super
    begin
      # データファイルがある場合
      @bbs_data = JSON.parse(File.read("data.txt"))
    rescue
      # データファイルがない場合
      @bbs_data = Hash.new
    end

    # 不要データの削除
    @bbs_data.each do |key, pobj|
      # 24時間経過したら削除
      if Time.now.to_i - key.to_i > 24*60*60
        @bbs_data.delete(key)
      end
    end

    # 再書き込み
    File.write("data.txt", @bbs_data.to_json)
  end

  # アクセス時
  def index
    if request.post?
      # 書き込みデータを受け取る
      @bbs_data[Time.now.to_i] = InputData.new(text: params['text'], name: params['name'], mail: params['mail'])

      #JSON化してファイルに書き込み
      data = @bbs_data.to_json
      File.write("data.txt", data)
      @bbs_data = JSON.parse(data)
    end
  end
end


# 入力データクラス
class InputData
  attr_accessor :name
  attr_accessor :mail
  attr_accessor :text
  
  def initialize(text: text, name: name, mail: mail)
    self.name = name
    self.mail = mail
    self.text = text
  end
end