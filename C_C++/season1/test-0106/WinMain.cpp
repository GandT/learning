/*
  プログラム名：test-0106
  制作者：Ｇ＆Ｔ
  制作日時：2008年7月16日～2008年7月16日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include"DxLib.h"
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	if(DxLib_Init() != 0)return -1;
	LoadGraphScreen(0,0,"Gewy001.png",true);
	LoadGraphScreen(235,168,"Gewy001.png",true);
	LoadGraphScreen(0,300,"Gewy001.png",true);
	LoadGraphScreen(256,0,"Gewy001.png",true);
	WaitTimer(5000);
	DxLib_End();
	return 0;
}