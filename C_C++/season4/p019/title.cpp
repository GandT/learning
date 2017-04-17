#include "title.h"

//必要ライブラリ
#include <opencv2/opencv.hpp>
#include <GL/glut.h>

//必要処理
#include "system.h"

using namespace cv;



//タイトル画面キー入力処理
void GameTitleKey(unsigned char k, int x, int y)
{
     switch(k){
         //ゲーム開始
         case 'z':
         case 'Z':
             gamestate = GAME_PLAY;
             break;

         //終了
         case 'q':
         case 'Q':
         case '\033': //ESC
	     exit(0);
	     break;
    }  
}



//タイトル画面マウスクリック処理
void GameTitleMouseClick(int b, int s, int x, int y)
{
    //なし
}



//タイトル画面マウス移動処理
void GameTitleMouseMove(int x, int y)
{
    //なし
}



//タイトル画面フレーム処理
void GameTitleFrame()
{
    //フレームカウント
    ++frame;

    //ディスプレイの変化を通達
    glutPostRedisplay();
}



//タイトル画面ディスプレイ処理
void GameTitleDisplay()
{
    /*【注意】※※※各種変換はスタックに積まれるため実際の処理順序は記述の逆順※※※【注意】*/

    /***ビューポート変換***/
    //なし

    /***投影変換***/
    //投影変換行列モードに移行
    glMatrixMode(GL_PROJECTION);
    //単位行列を作成
    glLoadIdentity();
    //カメラの撮影空間を定義
    gluPerspective(30,            //カメラの画角
		   0.75,          //アスペクト比
		   0.1,           //最近奥行き
		   500);          //最遠奥行き

    /***モデルビュー変換***/
    //モデルビュー変換行列モードに移行
    glMatrixMode(GL_MODELVIEW);
    //単位行列を作成
    glLoadIdentity();
    //カメラ視点の固定
    gluLookAt( 0, 0, CAMERA_DIST,  //カメラの位置
	       0, 0,           0,   //注視座標
	       0, 1,           0);  //ウィンドウの上方向を表すベクトル

    //バッファの初期化
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    

/*
  写真背景を表示
  　↓
  Glオブジェクトを表示
  　↓
  cv判定情報に格納
  　↓
  全削除
  　↓
  背景を表示
  　↓
  枠を表示
*/

    //2D描画
    
    //デプスバッファ機能の有効化
    glEnable(GL_DEPTH_TEST);
  
    //3D描画

    //デプスバッファ無効化
    glDisable(GL_DEPTH_TEST);

    //2D描画

    //画面反映
    glFlush();

    //裏画面を表画面に描画
    glutSwapBuffers();  

}
