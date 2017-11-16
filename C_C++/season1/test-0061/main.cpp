/*
  プログラム名：test-0061
  制作者：DxLibrary
  制作日時：2008年6月5日～2008年6月5日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：画像表示プログラム
*/
#include<stdio.h>
#include "DxLib.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	// ＤＸライブラリ初期化
	if( DxLib_Init() == -1 ) return -1 ;


	// 画面に絵を表示
	LoadGraphScreen(120,156,"test1.bmp",FALSE);

	// キーの入力待ち
	WaitKey();


	// ＤＸライブラリ使用の終了
	DxLib_End() ;

	// ソフトの終了
	return 0 ;
}
