#include "picture.h"

//必要ライブラリ
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <GL/glut.h>

//必要処理
#include "system.h"

using namespace std;
using namespace cv;

//管理実体作成
PictureClass pic;


PictureClass::PictureClass()
{
    //背景・前景画像の作成
    back  = Mat::zeros(WINDOW_WIDTH, WINDOW_HEIGHT, CV_8U);
    front = Mat::zeros(WINDOW_WIDTH, WINDOW_HEIGHT, CV_8U);

    //GL受け渡し用情報の作成
    glGenTextures(MAX_PICTURE, tnum);

    //テクスチャオブジェクトの初期化
    for(int i=0; i<MAX_PICTURE; ++i){
        //操作対象テクスチャの指定
        glBindTexture(GL_TEXTURE_2D, tnum[i]);
        //テクスチャ画像画素メモリ格納方式の指定
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        //テクスチャの割り当て
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);   //(テクスチャ形式, 解像度, カラー形式, テクスチャ幅, テクスチャ高さ, テクスチャ境界線の太さ, 画像カラー形式, 画像データ型, 画像データ実体)
        //テクスチャ画像拡大縮小補完方法の設定（最近傍法）
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    }

}



void PictureClass::set(int num, string picname, bool textureflag)
{
    //画像読み込み
    pnum[num] = imread(picname, 1);
    //BGRからRGBへ
    cvtColor(pnum[num], pnum[num], CV_BGR2RGB);

    //テクスチャ設定
    if(textureflag){
        glBindTexture(GL_TEXTURE_2D, tnum[num]);
        //初期化したテクスチャの書き換え
        glTexSubImage2D(GL_TEXTURE_2D,
			0,
			0,   //テクスチャ貼り付け位置x座標指定	
			0,   //テクスチャ貼り付け位置x座標指定
			pnum[num].cols, pnum[num].rows,     //入力画像(x,y)
			GL_RGB,                             //画像形式
			GL_UNSIGNED_BYTE,                   //データ形式
			pnum[num].data                      //データ本体
			);
    }
}



void PictureClass::draw(int num, int x, int y, int type)
{
    //書き込み対象の指定
    Mat written;
    switch(type){
    case DRAW_TO_BACKYARD:  written = back;  break;
    case DRAW_TO_FRONTYARD: written = front; break;
    }

    //変換用アフィン行列
    Mat affine = (cv::Mat_<double>(2,3)<<1, 0, x,
                                         0, 1, y);

    //書き込み
    warpAffine(pnum[num], written, affine, written.size(), CV_INTER_LINEAR, BORDER_TRANSPARENT);
}
