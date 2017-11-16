/*
  プログラム名：test-0105
  制作者：DxLibrary、Ｇ＆Ｔ
  制作日時：2008年7月16日～2008年7月16日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include"DxLib.h"
#include "DxLib.h"

// WinMain関数
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
					 LPSTR lpCmdLine, int nCmdShow )
{
	int BallX , BallY , BallGraph ;
	int SikakuX , SikakuY , SikakuMuki , SikakuGraph ;
	int Shot1X , Shot1Y , Shot1Flag , ShotGraph ;
	int Shot2X , Shot2Y , Shot2Flag ;

	// 画面モードの設定
	SetGraphMode( 640 , 480 , 16 ) ;
//	ChangeWindowMode(1);
	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 ) return -1;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,255);

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// ボール君のグラフィックをメモリにロード＆表示座標をセット
	BallGraph = LoadGraph( "Gewy001.png" ) ;
	BallX = 288 ; BallY = 400 ;

	// 四角君のグラフィックをメモリにロード＆表示座標をセット
	SikakuGraph = LoadGraph( "インセクトボックス.png" ) ;
	SikakuX = 0 ; SikakuY = 50 ;

	// 弾のグラフィックをメモリにロード
	ShotGraph = LoadGraph( "Gewyの弾①.png" ) ;
	
	//背景読み込み
	int bh = LoadGraph("背景２.bmp");

	// 弾１・２が画面上に存在しているか保持する変数に『存在していない』を意味する０を代入しておく
	Shot1Flag = 0 ;
	Shot2Flag = 0 ;

	// 四角君の移動方向をセット
	SikakuMuki = 1 ;

	// 移動ルーチン
	while( 1 )
	{
		//ＦＰＳコントロール
		static float a,b;//ここから
		b = a;
		while(GetNowCount() - b <16)Sleep(0);
		a = GetNowCount();
		clsDx();
		printfDx("FPS::%f\n",1000/(a-b));//ここまで
		
		
		// 画面を初期化(真っ黒にする)
		ClearDrawScreen() ;
		
		//背景描写
		DrawGraph( 0 , 0 , bh , true ) ;

		// ボール君の操作ルーチン
		{
			// ↑キーを押していたらボール君を上に移動させる
			if( CheckHitKey( KEY_INPUT_UP ) == 1 ) BallY -= 3 ;

			// ↓キーを押していたらボール君を下に移動させる
			if( CheckHitKey( KEY_INPUT_DOWN ) == 1 ) BallY += 3 ;

			// ←キーを押していたらボール君を左に移動させる
			if( CheckHitKey( KEY_INPUT_LEFT ) == 1 ) BallX -= 3 ;

			// →キーを押していたらボール君を右に移動させる
			if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 ) BallX += 3 ;

			// Zかスペースキーを押した場合は処理を分岐
			if( CheckHitKey( KEY_INPUT_Z ) || CheckHitKey(KEY_INPUT_SPACE))
			{
				if( Shot1Flag == 0 )
				{
					// 弾１が画面に存在していない場合は弾１を出す

					int Bw, Bh, Sw, Sh ;

					// ボール君と弾の画像のサイズを得る
					GetGraphSize( BallGraph , &Bw , &Bh ) ;
					GetGraphSize( ShotGraph , &Sw , &Sh ) ;

					// 弾１の位置をセット、位置はボール君の中心にする
					Shot1X = ( Bw - Sw ) / 2 + BallX ;
					Shot1Y = ( Bh - Sh ) / 2 + BallY ;

					// 弾１は現時点を持って存在するので、存在状態を保持する変数に１を代入する
					Shot1Flag = 1 ;
				}
				else if( Shot2Flag == 0 )
				{
					// 弾２が画面に存在していない場合は弾２を出す

					int Bw, Bh, Sw, Sh ;

					// ボール君と弾の画像のサイズを得る
					GetGraphSize( BallGraph , &Bw , &Bh ) ;
					GetGraphSize( ShotGraph , &Sw , &Sh ) ;

					// 弾２の位置をセット、位置はボール君の中心にする
					Shot2X = ( Bw - Sw ) / 2 + BallX ;
					Shot2Y = ( Bh - Sh ) / 2 + BallY ;

					// 弾２は現時点を持って存在するので、存在状態を保持する変数に１を代入する
					Shot2Flag = 1 ;
				}
			}

			// ボール君が画面左端からはみ出そうになっていたら画面内の座標に戻してあげる
			if( BallX < 0 ) BallX = 0 ;

			// ボール君が画面右端からはみ出そうになっていたら画面内の座標に戻してあげる
			if( BallX > 640 - 64 ) BallX = 640 - 64  ;

			// ボール君が画面上端からはみ出そうになっていたら画面内の座標に戻してあげる
			if( BallY < 0 ) BallY = 0 ;

			// ボール君が画面下端からはみ出そうになっていたら画面内の座標に戻してあげる
			if( BallY > 480 - 64 ) BallY = 480 - 64 ;

			// ボール君を描画
			DrawGraph( BallX , BallY , BallGraph , true ) ;
		}

		// 自機の弾１の移動ルーチン( 存在状態を保持している変数の内容が１(存在する)の場合のみ行う )
		if( Shot1Flag == 1 )
		{
			// 弾１を１６ドット上に移動させる
			Shot1Y -= 16 ;

			// 画面外に出てしまった場合は存在状態を保持している変数に０(存在しない)を代入する
			if( Shot1Y < -80 )
			{
				Shot1Flag = 0 ;
			}

			// 画面に弾１を描画する
			DrawGraph( Shot1X , Shot1Y , ShotGraph , true ) ;
		}

		// 自機の弾２の移動ルーチン( 存在状態を保持している変数の内容が１(存在する)の場合のみ行う )
		if( Shot2Flag == 1 )
		{
			// 弾２を１６ドット上に移動させる
			Shot2Y -= 16 ;

			// 画面外に出てしまった場合は存在状態を保持している変数に０(存在しない)を代入する
			if( Shot2Y < -80 )
			{
				Shot2Flag = 0 ;
			}

			// 画面に弾２を描画する
			DrawGraph( Shot2X , Shot2Y , ShotGraph , true ) ;
		}


		// 四角君の移動ルーチン
		{
			// 四角君の座標を移動している方向に移動する
			if( SikakuMuki == 1 ) SikakuX += 3 ;
			if( SikakuMuki == 0 ) SikakuX -= 3 ;

			// 四角君が画面右端からでそうになっていたら画面内の座標に戻してあげ、移動する方向も反転する
			if( SikakuX > 576 )
			{
				SikakuX = 576 ;
				SikakuMuki = 0 ;
			}

			// 四角君が画面左端からでそうになっていたら画面内の座標に戻してあげ、移動する方向も反転する
			if( SikakuX < 0 )
			{
				SikakuX = 0 ;
				SikakuMuki = 1 ;
			}

			// 四角君を描画
			DrawGraph( SikakuX , SikakuY , SikakuGraph , true ) ;
		}

		// 裏画面の内容を表画面にコピーする
		ScreenFlip() ;


		// Windows 特有の面倒な処理をＤＸライブラリにやらせる
		// -1 が返ってきたらループを抜ける
		if( ProcessMessage() == -1 ) break ;

		// もしＥＳＣキーが押されていたらループから抜ける
		if( CheckHitKey( KEY_INPUT_ESCAPE ) ) break ;
	}

	DxLib_End() ;				// ＤＸライブラリ使用の終了処理

	return 0 ;					// ソフトの終了
}


