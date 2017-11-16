/*
  プログラム名：test-0094
  制作者：Ｇ＆Ｔ
  制作日時：2008年6月28日～2008年7月5日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：テストプログラム
*/
#include"DxLib.h"
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	if(DxLib_Init() == -1){
		return -1;
	}

	DxLib_End();

	return 0;
}