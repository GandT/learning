/*
  プログラム名：test-0108
  制作者：Ｇ＆Ｔ
  制作日時：2008年8月2日～年月日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：シューティングＲＰＧ
*/

#include"DxLib.h"
#include"gazoukanri.h"

#define CHARAMAX 128


//プロトタイプ宣言
#include "system.h" //システム関係
int GetFreeTama(void); //system.cpp
int GewySpeed(int Gewyspeed); //system.cpp
void GewyShot(void); //system.cpp
void ShotITI(void); //system.cpp

//グローバル変数
char speed;//自機のスピード
int ShotInterval;//弾を出すときに使う
short gx; //GewyのX座標
short gy; //GewyのY座標
int Bw; //弾を出すのに使う
int Sw; //弾を出すのに使う

chara[CHARAMAX];

void stage1to1(void)
{
	// 描画先画面を裏画面にセット
	SetDrawScreen( DX_SCREEN_BACK );
	
	gx = 370; //X座標設定
	gy = 705; //Y座標設定

	while(1)
	{
		
		speed = 3;//Gewyの移動速度
	
		
		//FPSを制御する
		FPSCheck();
				
		//全てがパー
		ClearDrawScreen();
	
		//Windowsが壊れていないかチェックする(謎
		WindowsCheck();
		
		//加速する気か？
		speed = GewySpeed(speed);
		
		//動けるぞ！やった！
		if(CheckHitKey( KEY_INPUT_LEFT) == 1) gx -= speed;
		if(CheckHitKey( KEY_INPUT_RIGHT) == 1) gx += speed;
		if(CheckHitKey( KEY_INPUT_UP) == 1) gy -= speed;
		if(CheckHitKey( KEY_INPUT_DOWN) == 1) gy += speed;
		
		//行き過ぎじゃヴォクェ
		//←にょら
		if(gx < -1)gx = 0;
		//→にょら
		if(gx > 728)gx = 728;
		//↑にょら
		if(gy < -1)gy = 0;
		//↓にょら
		if(gy > 705)gy = 705;

		//灰色の狂った世界
		Cgazoukanri.draw(5,0,0);
		
		//右のあれ　名前は知らない
		Cgazoukanri.draw(6,780,0);
		
		//Gewy参上！
		Cgazoukanri.draw(1,gx,gy);
		
		//弾発射！
		GewyShot();
		ShotITI();
		
		//裏から表へ大移動
		ScreenFlip();
	}
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	ChangeWindowMode(1);
	SetGraphMode ( 1024 , 768 , 32 ) ;//Johnさんにもらったフルスクリーンモード
	if(DxLib_Init() == -1)return -1;
	pictureinput();
	stage1to1();
	
	DxLib_End();
	return 0;
}

//製作を断念