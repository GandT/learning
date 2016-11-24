/*
  2016.11.7
  OpenGL - テクスチャマッピング演習

  【参考文献】
  福田 誠一郎, 勝元 甫(2016)「「OpenCV/OpenGLによる映像処理」　講義web 」,<http://www.nae-lab.org/b3exp/codes.html>
 */

// -*- tab-width : 4 ; mode : C++ -*-

#include <cmath>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <GL/glut.h>

using namespace std;
using namespace cv;

//各種define
#define WINDOW_WIDTH   500
#define WINDOW_HEIGHT  500
#define WINDOW_NAME    "pic"
#define TEXTURE_WIDTH  640
#define TEXTURE_HEIGHT 640
#define DRAW_PICTURE_MODE  0
#define DRAW_MOVIE_MODE    1

//プロトタイプ宣言
void InitGL(int argc, char *argv[]);
void Initialization();
void SetTexture();
void SetCallbackFunctions();
void CheckHitKey(unsigned char k, int x, int y);
void CheckMouseClick(int b, int s, int x, int y);
void CheckMouseMove(int x, int y);
void UpdateDisplay();
void PrepareAnimation();
void DrawPyramid();

//変数宣言
double ang1, ang2;
double dist = 20;
bool mlfl = false;  //マウス左ボタン押下フラグ
bool mrfl = false;  //マウス右ボタン押下フラグ
GLuint th[4] = {0,0,0,0};
int objmode = DRAW_PICTURE_MODE;

Mat frame;
VideoCapture cap;



//main関数
int main(int argc, char *argv[])
{
  InitGL(argc, argv);
  Initialization();

  SetCallbackFunctions();

  glutMainLoop();  
}



//OpenGLの初期化処理
void InitGL(int argc, char *argv[])
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutCreateWindow(WINDOW_NAME);
}



//プログラムの初期化処理
void Initialization()
{
  //背景色の設定
  glClearColor(0, 0, 0, 0);

  //テクスチャ識別番号の生成
  glGenTextures(3, th);

  //テクスチャオブジェクトの初期化
  for(int i=0; i<4; ++i){
    //操作対象テクスチャの指定
    glBindTexture(GL_TEXTURE_2D, th[i]);
    //テクスチャ画像画素メモリ格納方式の指定
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    //テクスチャの割り当て
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, TEXTURE_WIDTH, TEXTURE_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);   //(テクスチャ形式, 解像度, カラー形式, テクスチャ幅, テクスチャ高さ, テクスチャ境界線の太さ, 画像カラー形式, 画像データ型, 画像データ実体)
    //テクスチャ画像拡大縮小補完方法の設定（最近傍法）
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  }

  //テクスチャの読み込み
  SetTexture();
}


void SetTexture()
{
  //読み込み画像名の設定
  string fn[3] = {"fruits.jpg","fruits2.jpg","fruits3.jpg"};
  
  //OpenCVによる読み込みループ
  for(int i=0; i<3; ++i){
    //データを読み込み
    Mat input = imread(fn[i], 1);
    //BGRからRGBへ
    cvtColor(input, input, CV_BGR2RGB);

    //操作対象設定
    glBindTexture(GL_TEXTURE_2D, th[i]);
    //初期化したテクスチャの書き換え
    glTexSubImage2D(GL_TEXTURE_2D,
		    0,
		    (TEXTURE_WIDTH - input.cols) / 2,   //テクスチャ貼り付け位置x座標指定	
		    (TEXTURE_HEIGHT- input.rows) / 2,   //テクスチャ貼り付け位置x座標指定
		    input.cols, input.rows,             //入力画像(x,y)
		    GL_RGB,                             //画像形式
		    GL_UNSIGNED_BYTE,                   //データ形式
		    input.data                          //データ本体
		    );
  }

  //カメラ接続
  cap.open(1);
  if(!cap.isOpened())cap.open(0);
  if(!cap.isOpened()){
    cerr << "エラー：カメラまたはビデオ設定が誤っています。" << endl;
    return;
  }
  cap >> frame;
  //テクスチャ化
  cvtColor(frame, frame, CV_BGR2RGB);
  glBindTexture(GL_TEXTURE_2D, th[3]);
  glTexSubImage2D(GL_TEXTURE_2D,
		  0,
		  (TEXTURE_WIDTH - frame.cols) / 2,   //テクスチャ貼り付け位置x座標指定	
		  (TEXTURE_HEIGHT- frame.rows) / 2,   //テクスチャ貼り付け位置x座標指定
		  frame.cols, frame.rows,             //入力画像(x,y)
		  GL_RGB,                             //画像形式
		  GL_UNSIGNED_BYTE,                   //データ形式
		  frame.data                          //データ本体
		  );
}



//コールバック関数登録処理
void SetCallbackFunctions()
{
  //キーボード入力時コールバック関数
  glutKeyboardFunc(CheckHitKey);

  //マウス入力時コールバック関数
  glutMouseFunc(CheckMouseClick);

  //マウスドラッグ時コールバック関数
  glutMotionFunc(CheckMouseMove);

  //マウス移動時コールバック関数
  glutPassiveMotionFunc(CheckMouseMove);

  //画面変化時コールバック関数登録
  glutDisplayFunc(UpdateDisplay);

  //フレーム処理コールバック関数登録
  glutIdleFunc(PrepareAnimation);
}



//キーボード入力対応処理
void CheckHitKey(unsigned char k, int x, int y)
{
  switch(k){
  //モード変更 
  case 'n':
  case 'N':
  case 'p':
  case 'P':
    objmode = DRAW_PICTURE_MODE;
    break;
  case 'm':
  case 'M':
    objmode = DRAW_MOVIE_MODE;
    break;
  //終了
  case 'q':
  case 'Q':
  case '\033': //ESC
    exit(0);
  }

  //ディスプレイの変化を通達
  glutPostRedisplay();
}



//マウス入力対応処理
void CheckMouseClick(int b, int s, int x, int y)
{
  //ボタンのクリック状況を更新
  if(b == GLUT_LEFT_BUTTON){
         if(s == GLUT_UP  )mlfl = false;
    else if(s == GLUT_DOWN)mlfl =  true;
  }
  if(b == GLUT_RIGHT_BUTTON){
         if(s == GLUT_UP  )mrfl = false;
    else if(s == GLUT_DOWN)mrfl =  true;
  }
}



//マウス移動時対応処理
void CheckMouseMove(int x, int y)
{
  //前回マウス座標
  static int x0 = -1;
  static int y0 = -1;

  //左クリック時
  if(mlfl){
    //前回クリック時処理
    if(x0 >= 0 && y0 >= 0){
      ang1 += (double)-(x-x0)/20;
      ang2 += (double)+(y-y0)/20;
    }
    //座標更新
    x0 = x;
    y0 = y;
  }

  //右クリック時
  else if(mrfl){
    //前回クリック時処理
    if(x0 >= 0 && y0 >= 0){
      dist += (double)+(y-y0)/20;
    }
    //座標更新
    x0 = x;
    y0 = y;
  }

  //非クリック時
  else{
    x0 = y0 = -1;
  }

  //画面更新
  glutPostRedisplay();
}



//ディスプレイ更新処理
void UpdateDisplay()
{
  /*【注意】※※※各種変換はスタックに積まれるため実際の処理順序は記述の逆順※※※【注意】*/

  /***ビューポート変換***/
  //なし

  /***投影変換***/
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(30,    //カメラの画角
		 1,     //アスペクト比
		 0.1,   //最近奥行き
		 100);  //最遠奥行き

  /***モデルビュー変換***/
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  //カメラ視点移動
  if(cos(ang2) > 0){
    gluLookAt(dist * cos(ang2) * sin(ang1), dist * sin(ang2) , dist * cos(ang2) * cos(ang1) ,
	      0,  0, 0,
	      0, +1, 0
	      );
  }else{
    gluLookAt(dist * cos(ang2) * sin(ang1), dist * sin(ang2) , dist * cos(ang2) * cos(ang1) ,
	      0,  0, 0,
	      0, -1, 0
	      );
  }

  //バッファの初期化
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //デプスバッファ機能の有効化
  glEnable(GL_DEPTH_TEST);
  
  //ピラミッドを描画
  DrawPyramid();

  glFlush();
  glDisable(GL_DEPTH_TEST);
  glutSwapBuffers();
}



//アニメーション処理
void PrepareAnimation()
{
  //フレームカウンタ
  static int fr = 0;

  //カメラテクスチャの編集
  cap >> frame;
  cvtColor(frame, frame, CV_BGR2RGB);
  glBindTexture(GL_TEXTURE_2D, th[3]);
  glTexSubImage2D(GL_TEXTURE_2D,
		  0,
		  (TEXTURE_WIDTH - frame.cols) / 2,   //テクスチャ貼り付け位置x座標指定	
		  (TEXTURE_HEIGHT- frame.rows) / 2,   //テクスチャ貼り付け位置x座標指定
		  frame.cols, frame.rows,             //入力画像(x,y)
		  GL_RGB,                             //画像形式
		  GL_UNSIGNED_BYTE,                   //データ形式
		  frame.data                          //データ本体
		  );

  //基本対象テクスチャの設定
       if(fr % 300 < 100)glBindTexture(GL_TEXTURE_2D, th[0]);
  else if(fr % 300 < 200)glBindTexture(GL_TEXTURE_2D, th[1]);
  else if(fr % 300 < 300)glBindTexture(GL_TEXTURE_2D, th[2]);

  //フレームカウント
  ++fr;

  //ディスプレイの変化を通達
  glutPostRedisplay();
}



//ピラミッド体を描画
void DrawPyramid()
{
  //GL座標設定
  GLdouble O[] = {   0, +1,    0};
  GLdouble A[] = {+1.5, -1, +1.5};
  GLdouble B[] = {-1.5, -1, +1.5};
  GLdouble C[] = {-1.5, -1, -1.5};
  GLdouble D[] = {+1.5, -1, -1.5};

  /* 各種面作成 */
  glColor3d(1, 0, 0);

  glEnable(GL_TEXTURE_2D);
  glBegin(GL_POLYGON);
  glTexCoord2d(1.0, 0.0);
  glVertex3dv(O);
  glTexCoord2d(0.0, 0.0);
  glVertex3dv(O);
  glTexCoord2d(0.0, 1.0);
  glVertex3dv(A);
  glTexCoord2d(1.0, 1.0);
  glVertex3dv(B);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  
  glBegin(GL_TRIANGLES);
  glColor3d(1, 1, 0);
  glVertex3dv(O);
  glVertex3dv(B);
  glVertex3dv(C);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3d(0, 1, 1);
  glVertex3dv(O);
  glVertex3dv(C);
  glVertex3dv(D);
  glEnd();

  glBegin(GL_TRIANGLES);
  glColor3d(1, 0, 1);
  glVertex3dv(O);
  glVertex3dv(D);
  glVertex3dv(A);
  glEnd();

  glColor3d(1, 1, 1);

  glBindTexture(GL_TEXTURE_2D, th[3]);
  glEnable(GL_TEXTURE_2D);
  glBegin(GL_POLYGON);
  glTexCoord2d(1.0, 0.0);
  glVertex3dv(A);
  glTexCoord2d(0.0, 0.0);
  glVertex3dv(B);
  glTexCoord2d(0.0, 1.0);
  glVertex3dv(C);
  glTexCoord2d(1.0, 1.0);
  glVertex3dv(D);
  glEnd();
  glDisable(GL_TEXTURE_2D);
}
