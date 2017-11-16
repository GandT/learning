/*
  プログラム名：test-0103
  制作者：Ｇ＆Ｔ
  制作日時：2008年7月5日～2008年7月5日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include"DxLib.h"
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	if(DxLib_Init() == -1){
		return -1;
	}
	
	PlayMovie("キーボードクラッシャー.wmv",1,DX_MOVIEPLAYTYPE_NORMAL);
	
	DxLib_End();

	return 0;
}