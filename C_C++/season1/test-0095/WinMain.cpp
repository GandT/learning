/*
  プログラム名：test-0095
  制作者：Ｇ＆Ｔ
  制作日時：2008年6月28日～2008年7月5日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include"DxLib.h"
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	if( DxLib_Init() == -1 )
	{
		 return -1;
	}

	DrawString(100,100,"Ｃ愛好会",0xffffff);
	
	WaitTimer(5000);

	DxLib_End();

	return 0;
}