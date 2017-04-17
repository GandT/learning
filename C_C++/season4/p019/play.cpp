#include "play.h"

//必要ライブラリ
#include <opencv2/opencv.hpp>
#include <GL/glut.h>

//必要処理
#include "system.h"
#include "camera.h"
#include "picture.h"

using namespace cv;



//ゲーム画面キー入力処理
void GamePlayKey(unsigned char k, int x, int y)
{
     switch(k){
         //タイトルに戻る
         case '\033': //ESC
	     gamestate = GAME_TITLE;
	     break;
    }  
}



//ゲーム画面マウスクリック処理
void GamePlayMouseClick(int b, int s, int x, int y)
{
  
}



//ゲーム画面マウス移動処理
void GamePlayMouseMove(int x, int y)
{
  
}



//ゲーム画面フレーム処理
void GamePlayFrame()
{
    //フレームカウント
    ++frame;

    //ディスプレイの変化を通達
    glutPostRedisplay();
}



//ゲーム画面ディスプレイ処理
void GamePlayDisplay()
{
    /*【注意】※※※各種変換はスタックに積まれるため実際の処理順序は記述の逆順※※※【注意】*/

    /***ビューポート変換***/
    //なし

    /***投影変換***/
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30,            //カメラの画角
		   0.75,          //アスペクト比
		   0.1,           //最近奥行き
		   500);          //最遠奥行き

    /***モデルビュー変換***/
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //カメラ視点移動
    //gluLookAt();

    //バッファの初期化
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
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
