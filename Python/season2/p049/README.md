# ノート
## 参考文献
- [Flaskで作る簡易分析ツール2 学習環境の構築](https://www.python.ambitious-engineer.com/archives/1645)
- 上記に沿って作成
- 著作権の関係上Git収録は本ノートのみ


## 構成
flask_sample  
├── models.py  
├── requirements.txt  
├── run.py  
├── schema.sql  
├── static  
│   ├── result  
│   └── style.css  
└── templates  
    ├── base.html  
    ├── edit.html  
    ├── index.html  
    └── view.html  


## 初期設定
```
sudo apt install python-tk tk-dev
cd flask_init_sample
pip3 install -r requirements.txt
```


## モック
- テンプレート : templates/base.html
    * bootstrap4のCDNを使用
- htmlファイル
    * 全体像を記述し埋め込み部分を定義
        + base.hmtl
    * base.htmlを継承し埋め込み内容をそれぞれ記述
        * index.html
        * edit.html
        * view.html


## 分析処理
### データベース

### データ分析


# その他の参考文献
- [CDNってそもそも何？なんかサーバの負荷が下がるって聞いたんだけど！〜Web制作/運営の幅が広がるCDNを知ろう第1回〜](https://knowledge.sakura.ad.jp/19191/)
