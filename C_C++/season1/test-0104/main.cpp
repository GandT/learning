/*
  プログラム名：test-0104
  制作者：Ｇ＆Ｔ
  制作日時：2008年7月5日～2008年7月5日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include"DxLib.h"

int BGM = 100;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	int test1;
	if(DxLib_Init() == -1) return -1;
	
	BGM = LoadSoundMem("kbc.wav");
	test1 = PlaySoundMem(BGM,DX_PLAYTYPE_NORMAL);
	
	while(ProcessMessage() != -1 && CheckHitKeyAll() == 0 ){
		if(test1 == -1)LoadGraphScreen( BGM , 0 , "0120.bmp" , true);
		if(BGM == -1)LoadGraphScreen( BGM , 100 , "0120.bmp" , true);
	}
	
	DxLib_End() ;
	return 0;
}
