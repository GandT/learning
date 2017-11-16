/*
  プログラム名：test-0062
  制作者：DxLibrary
  制作日時：2008年6月5日～2008年6月5日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：画像表示プログラム
*/
#include "DxLib.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
			 LPSTR lpCmdLine, int nCmdShow )
{
	int i ;
	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 ) return -1 ;


	// 一番左上に絵を表示、２０分の１秒待つ、を１３回繰り返す
	for( i = 0 ; i < 80 ; i ++ )
	{
		// 絵を表示、絵を描くＸ座標は i が１増えるごとに１０ドットづつ右にずれてゆく
		LoadGraphScreen( i * 10 , 100 , "test1.bmp" , FALSE ) ;

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

