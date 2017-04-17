#ifndef PICTURE_H__
#define PICTURE_H__

//クラス用include
#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <GL/glut.h>

//画像数
#define MAX_PICTURE   128

//書き込み先
#define DRAW_TO_BACKYARD  0  //背景領域に書き込み
#define DRAW_TO_FRONTYARD 1  //前景領域に書き込み

using namespace std;
using namespace cv;


//画像情報保持クラス
struct PictureClass{
    //基本画像
    Mat back;       //背景
    Mat front;      //前景
    GLuint backh;   //背景のテクスチャハンドル
    GLuint fronth;  //前景のテクスチャハンドル    

    //画像データ
    Mat pnum[MAX_PICTURE];

    //テクスチャデータ（画像データと番号対応）
    GLuint tnum[MAX_PICTURE];

    //コンストラクタ
    PictureClass();

    //各種処理
    void set(int num, string picname, bool textureflag = false);
    void draw(int num, int x, int y, int type = DRAW_TO_BACKYARD);
};

extern PictureClass pic;




#endif
