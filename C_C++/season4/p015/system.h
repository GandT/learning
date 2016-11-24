#ifndef SYSTEM_H__
#define SYSTEM_H__

//ウィンドウ情報
#define WINDOW_WIDTH   853
#define WINDOW_HEIGHT  480
#define WINDOW_NAME    "Causal Network"

//座標変換
#define GL_X(x)   ((double)(x) / WINDOW_WIDTH)
#define GL_Y(y)   ((double)(y) / WINDOW_WIDTH)

//プレイエリア（GLUTデータ取り込み領域）情報
#define PLAYAREA_X_START  GL_X(0)
#define PLAYAREA_Y_START  GL_Y(0)
#define PLAYAREA_WIDTH    GL_X(400)
#define PLAYAREA_HEIGHT   GL_Y(300)

//ゲーム状態
#define GAME_TITLE 0
#define GAME_PLAY  1

//カメラ距離
#define CAMERA_DIST  20

//テクスチャ情報
#define TEXTURE_WIDTH  1024
#define TEXTURE_HEIGHT 1024


//各種変数宣言
extern int gamestate;    //ゲームの現在状態
extern int frame;        //フレームカウンター

#endif
