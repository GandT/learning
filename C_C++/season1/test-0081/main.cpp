/*
  プログラム名：test-0081
  制作者：DxLibrary
  制作日時：2008年6月18日～2008年6月18日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：ピクチャー表示プログラム
*/
#include "DxLib.h"

// WinMain関数
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow )
{
	int GraphHandle ;

	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 ) return -1;

	// グラフィック『test1.bmp』をメモリにロード
	GraphHandle = LoadGraph( "Gewy001.bmp" ) ;

	// 0,0 座標にメモリに読みこんだグラフィックを描画
	DrawGraph( 0 , 0 , GraphHandle , FALSE ) ;

	// キー入力を待つ
	WaitKey() ;

	// ＤＸライブラリ使用の終了処理
	DxLib_End() ;

	// ソフトの終了
	return 0 ;
}