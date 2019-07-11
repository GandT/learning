# coding: UTF-8
"""
　2019.7.12
　Flask簡易ページ
"""
from flask import Flask
from flask import render_template
 
app = Flask(__name__)
 
@app.route('/')
def hello_world():
    values = {"salt": 5, "pepper" :2500, "water": 7, "count": 2}
    return render_template('index.html', values=values)
 
if __name__ == '__main__':
    app.run()