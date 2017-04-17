#include "callback.h"

//必要ライブラリ
#include <opencv2/opencv.hpp>
#include <GL/glut.h>

//必要処理
#include "system.h"
#include "title.h"
#include "play.h"


//キーボード入力対応処理
void CheckHitKey(unsigned char k, int x, int y)
{
    //モード依存
    switch(gamestate){
         case GAME_TITLE:
	     GameTitleKey(k, x, y);
             break;
         case GAME_PLAY:
	     GamePlayKey(k, x, y);
             break;
    }
}



//マウス入力対応処理
void CheckMouseClick(int b, int s, int x, int y)
{
    //モード依存
    switch (gamestate){
         case GAME_TITLE:
             GameTitleMouseClick(b, s, x, y);
             return;
         case GAME_PLAY:
             GamePlayMouseClick(b, s, x, y);
             break;
    }
}



//マウス移動時対応処理
void CheckMouseMove(int x, int y)
{
    //モード依存
    switch(gamestate){
         case GAME_TITLE:
             GameTitleMouseMove(x, y);
             return;
         case GAME_PLAY:
             GamePlayMouseMove(x, y);
             break;
    }
}



//毎フレーム処理
void DoAllFrame()
{
    //モード依存
    switch(gamestate){
         case GAME_TITLE:
	     GameTitleFrame();
             return;
         case GAME_PLAY:
	     GamePlayFrame();
             break;
    }
}



//ディスプレイ変化時対応処理
void UpdateDisplay()
{
    //モード依存
    switch(gamestate){
         case GAME_TITLE:
	     GameTitleDisplay();
             return;
         case GAME_PLAY:
	     GamePlayDisplay();
             break;
    }
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

    //フレーム処理コールバック関数登録
    glutIdleFunc(DoAllFrame);

    //画面変化時コールバック関数登録
    glutDisplayFunc(UpdateDisplay);
}
