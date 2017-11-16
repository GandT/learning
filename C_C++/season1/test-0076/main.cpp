/*
  プログラム名：test-0076
  制作者：DxLibrary
  制作日時：2008年6月14日～2008年6月14日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：演算プログラム
*/
#include "Dxlib.h"
int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						 LPSTR lpCmdLine, int nCmdShow ){
	int i ;

	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 ) return -1 ;

	// 描画先を裏画面にする
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// 一番左上に絵を表示、２０分の１秒待つ、を１３回繰り返す
	for( i = 0 ; i < 45 ; i ++ )
	{
		// 画面に描かれているものを一回全部消す
		ClearDrawScreen() ;

		// 絵を表示
		LoadGraphScreen( i * 10 , 100 , "chaos2.bmp" , FALSE ) ;

		// 裏画面の内容を表画面に反映させる
		ScreenFlip() ;

		// ２０分の１秒待つ
		WaitTimer( 50 ) ;
	}

	// キーの入力待ち
	WaitKey() ;


	// ＤＸライブラリ使用の終了処理
	DxLib_End() ;

	// ソフトの終了
	return 0 ;
}