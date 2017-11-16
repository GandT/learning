/*
  プログラム名：test-0084
  制作者：DxLibrary
  制作日時：2008年6月18日～2008年6月18日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：キーボード入力プログラム
*/
#include "DxLib.h"

// WinMain関数
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	int BallX , BallY , BallGraph ;
	int SikakuX , SikakuY , SikakuGraph ;
	int i ;

	// 画面モードの設定
	SetGraphMode( 640 , 480 , 16 ) ;

	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 ) return -1;

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// ボール君のグラフィックをメモリにロード＆表示座標をセット
	BallGraph = LoadGraph( "エレキシューター.bmp" ) ;
	BallX = -32 ; BallY = 10 ;

	// 四角君のグラフィックをメモリにロード＆表示座標をセット
	SikakuGraph = LoadGraph( "コレクター.bmp" ) ;
	SikakuX = 540 ; SikakuY = 400 ;

	// 移動ルーチン
	for( i = 0 ; i < 400 ; i ++ )
	{
		// 画面を初期化(真っ黒にする)
		ClearDrawScreen() ;

		// ボール君の座標を少しずらす
		BallX += 1 ;

		// ボール君を描画
		DrawGraph( BallX , BallY , BallGraph , true ) ;

		// 四角君の座標を少しずらす
		SikakuX -= 1 ;
		SikakuY -= 1 ;

		// 四角君を描画
		DrawGraph( SikakuX , SikakuY , SikakuGraph , true ) ;

		// 裏画面の内容を表画面にコピーする
		ScreenFlip() ;

		// Windows 特有の面倒な処理をＤＸライブラリにやらせる
		// -1 が返ってきたらループを抜ける
		if( ProcessMessage() < 0 ) break;
	}
	WaitTimer(5000);

	// ＤＸライブラリ使用の終了処理
	DxLib_End() ;

	// ソフトの終了
	return 0 ;
}


