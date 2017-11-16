/*
  プログラム名：test-0062
  制作者：DxLibrary
  制作日時：2008年6月5日～2008年6月5日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：画像表示プログラム
*/
#include<stdio.h>
#include "DxLib.h"
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	if( DxLib_Init() == -1 ) return -1 ;
	printf("#include<stdio.h>");
	WaitKey();
	return 0;
}