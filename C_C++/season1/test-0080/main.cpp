/*
  プログラム名：test-0080
  制作者：DxLibrary
  制作日時：2008年6月18日～2008年6月18日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：キーボード入力プログラム
*/
#include "DxLib.h"
// WinMain関数
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
	int x , y ;

	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 ) return -1;

	// 描画先画面を裏画面にする
	SetDrawScreen( DX_SCREEN_BACK ) ;

	x = 0 ; y = 0 ; 
	while( 1 )
	{
		// 画面に描かれているものをすべて消す
		ClearDrawScreen() ;

		// 上下左右のキー入力に対応して x, y の座標値を変更する
		if( CheckHitKey( KEY_INPUT_LEFT ) == 1 ) x -= 8 ;
		if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 ) x += 8 ;
		if( CheckHitKey( KEY_INPUT_UP ) == 1 ) y -= 8 ;
		if( CheckHitKey( KEY_INPUT_DOWN ) == 1 ) y += 8 ;

		// x , y が示す画面座標にＢＭＰ画像 test1.bmp を描画する
		LoadGraphScreen( x , y , "エレキシューター.bmp" , TRUE ) ;

		// 裏画面の内容を表画面に反映させる
		ScreenFlip() ;

		// 待たないと処理が早すぎるのでここで２０ミリ秒待つ
		WaitTimer( 20 ) ;

		// Windows システムからくる情報を処理する
		if( ProcessMessage() == -1 ) break ;

		// ＥＳＣキーが押されたらループから抜ける
		if( CheckHitKey( KEY_INPUT_ESCAPE ) == 1 ) break ;
	}

	// ＤＸライブラリ使用の終了処理
	DxLib_End() ;

	// ソフトの終了
	return 0 ;
}