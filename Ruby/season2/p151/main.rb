#coding: UTF-8
=begin
  2017.12.25
  Twitter API

  【参考文献】
    - 廣幡（2014）「RubyでTwitterAPIを叩いてみたら彼女が…」, <http://labs.septeni.co.jp/entry/20141029/1414537803>
    - SYNCER（2017）「Twitter REST APIの使い方」, <https://syncer.jp/Web/API/Twitter/REST_API/>
=end

require "oauth"


consumer_key        = ARGV[0]
consumer_secret     = ARGV[1]
access_token        = ARGV[2]
access_token_secret = ARGV[3]


# 初期設定
def setting
    # consumerの公開鍵/秘密鍵セットからOAuthを（？）生成
    consumer = OAuth::Consumer.new(
      consumer_key, consumer_secret,
      {site: 'http://api.twitter.com', scheme: :header}
    )

    # アクセストークンの公開鍵/秘密鍵をハッシュ化
    token = {access_token: access_token, access_token_secret: access_token_secret}
    
    # リクエストトークンを作成
    request_token = OAuth::AccessToken.from_hash(consumer, token)

    return request_token
end



def trend(token)
    # 日本のWOEID取得
    woeid = nil
    trend_areas = JSON.parse(token.request(:get, 'https://api.twitter.com/1.1/trends/available.json').body)
    trend_areas.each{ |area|
      if area["name"] == "Japan"
        woeid = area["woeid"]
        break
      end
    }

    # トレンド取得
    trends_json = JSON.parse(request_token.request(:get, "https://api.twitter.com/1.1/trends/place.json?id=#{woeid}").body)[0]["trends"]
    trends = ""
    trends_json.each{ |trend|
      trends += (trend["name"] + ',')
    }
    trends.chop! # 末尾のコンマを除去

    puts trends
end




def main
    # アクセストークンの作成
    token = setting

    # タイムラインを表示

    # トレンドを表示

end