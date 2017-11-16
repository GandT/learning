/*
  プログラム名：test-0082
  制作者：DxLibrary
  制作日時：2008年6月18日～2008年6月18日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：ピクチャー表示プログラム
*/
#include "DxLib.h"

// WinMain関数
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 ) return -1;

	// 0,0 座標にグラフィック『test1.bmp』を描画
	LoadGraphScreen( 0 , 0 , "Gewy001.bmp" , FALSE ) ;

	// キー入力を待つ
	WaitKey() ;

	// ＤＸライブラリ使用の終了処理
	DxLib_End() ;

	// ソフトの終了
	return 0 ;
}

