/*
  プログラム名：test-0087
  制作者：DxLibrary、憂煉
  制作日時：2008年6月19日～2008年6月19日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：キーボード入力プログラム
*/

#include "DxLib.h"

#define TAMA_MAX 128
	int SikakuX , SikakuY , SikakuMuki , SikakuGraph , SikakuW ,SikakuH ;

struct TAMA
{
	int x,y;
	char exist;
	TAMA()
	{
		exist = 0;
		x = y = 0;
	}
	static int ShotX,ShotY,ShotW,ShotH;
};
int TAMA::ShotX = 0,TAMA::ShotY = 0;
int TAMA::ShotW = 0,TAMA::ShotH = 0;

TAMA JIKITAMA[TAMA_MAX];

int GetFreeTama()
{
	int i =0;
	for(; i < TAMA_MAX; ++i)
	{
		if(!JIKITAMA[i].exist)break;
	}
	if(i==TAMA_MAX-1&&JIKITAMA[i].exist)return -1;
	return i;
}

int HitCheck(int i)
{
	if(
		( ( JIKITAMA[i].x+TAMA::ShotX > SikakuX && JIKITAMA[i].x+TAMA::ShotX < SikakuX + SikakuW ) ||
		( SikakuX > JIKITAMA[i].x+TAMA::ShotX && SikakuX < JIKITAMA[i].x+TAMA::ShotX + TAMA::ShotW ) ) &&
		( ( JIKITAMA[i].y+TAMA::ShotY > SikakuY && JIKITAMA[i].y+TAMA::ShotY < SikakuY + SikakuH ) ||
		( SikakuY > JIKITAMA[i].y+TAMA::ShotY && SikakuY < JIKITAMA[i].y+TAMA::ShotY + TAMA::ShotH ) ) 
	)
	{
		// 接触している
		return 1;
	}
	else
	{
		// 接触していない
		return 0;
	}
}

// WinMain関数
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
					 LPSTR lpCmdLine, int nCmdShow )
{
	int BallX , BallY , BallGraph ;
	int ShotX , ShotY , ShotFlag , ShotGraph ;
	int Bw, Bh, Sw, Sh ;
	int ShotInterval = 0;

	// 画面モードの設定
	SetGraphMode( 640 , 480 , 16 ) ;

	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 ) return -1;

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen( DX_SCREEN_BACK ) ;

	// ボール君のグラフィックをメモリにロード＆表示座標をセット
	BallGraph = LoadGraph( "Gewy001.bmp" ) ;
	BallX = 288 ; BallY = 400 ;

	// 四角君のグラフィックをメモリにロード＆表示座標をセット
	SikakuGraph = LoadGraph( "コレクター.bmp" ) ;
	SikakuX = 0 ; SikakuY = 50 ;

	// 弾のグラフィックをメモリにロード
	ShotGraph = LoadGraph( "Gewyの弾②.bmp" ) ;
	
	//サイズ関連の初期化
	GetGraphSize( BallGraph , &Bw , &Bh ) ;
	GetGraphSize( ShotGraph , &Sw , &Sh ) ;
	GetGraphSize( SikakuGraph , &SikakuW , &SikakuH );
	
	TAMA::ShotW = Sw;
	TAMA::ShotH = Sh;
	TAMA::ShotX = -Sw/2;
	TAMA::ShotY = -Sh/2;

	// 弾が画面上に存在しているか保持する変数に『存在していない』を意味する０を代入しておく
	ShotFlag = 0 ;

	// 四角君の移動方向をセット
	SikakuMuki = 1 ;

	// 移動ルーチン
	while( 1 )
	{
		// 画面を初期化(真っ黒にする)
		ClearDrawScreen() ;

		// ボール君の操作ルーチン
		{
			// ↑キーを押していたらボール君を上に移動させる
			if( CheckHitKey( KEY_INPUT_UP ) == 1 ) BallY -= 1 ;

			// ↓キーを押していたらボール君を下に移動させる
			if( CheckHitKey( KEY_INPUT_DOWN ) == 1 ) BallY += 1 ;

			// ←キーを押していたらボール君を左に移動させる
			if( CheckHitKey( KEY_INPUT_LEFT ) == 1 ) BallX -= 1 ;

			// →キーを押していたらボール君を右に移動させる
			if( CheckHitKey( KEY_INPUT_RIGHT ) == 1 ) BallX += 1 ;

			// スペースキーを押していて、且弾が撃ち出されていなかったら弾を発射する
//			if( CheckHitKey( KEY_INPUT_SPACE ) == 1 && ShotFlag == 0 )
//			{
//				int Bw, Bh, Sw, Sh ;
//
				// ボール君と弾の画像のサイズを得る
//				GetGraphSize( BallGraph , &Bw , &Bh ) ;
//				GetGraphSize( ShotGraph , &Sw , &Sh ) ;
//
				// 弾の位置をセット、位置はボール君の中心にする
//				ShotX = ( Bw - Sw ) / 2 + BallX ;
//				ShotY = ( Bh - Sh ) / 2 + BallY ;
//
				// 弾は現時点を持って存在するので、存在状態を保持する変数に１を代入する
//				ShotFlag = 1 ;
//			}
			//憂煉が追加した発射ルーチン
			--ShotInterval;
			if (CheckHitKey(KEY_INPUT_SPACE) && ShotInterval <= 0)
			{
				//使われていない弾を探す
				int i = GetFreeTama();
				if(i!=-1)
				{
					//値を設定
					JIKITAMA[i].x = ( Bw - Sw ) / 2 + BallX -10;
					JIKITAMA[i].y = /*( Bh - Sh ) / 2*/ + BallY -5;
					JIKITAMA[i].exist = 1;
					ShotInterval = 32;
				}
				i = GetFreeTama();
				if (i!=-1)
				{
					JIKITAMA[i].x = ( Bw - Sw ) / 2 + BallX +10;
					JIKITAMA[i].y = /*( Bh - Sh ) / 2*/ + BallY -5;
					JIKITAMA[i].exist = 1;
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

		// 自機の弾の移動ルーチン( 存在状態を保持している変数の内容が１(存在する)の場合のみ行う )
//		if( ShotFlag == 1 )
//		{
			// 弾を１６ドット上に移動させる
//			ShotY -= 16 ;
//
			// 画面外に出てしまった場合は存在状態を保持している変数に０(存在しない)を代入する
//			if( ShotY < -80 )
//			{
//				ShotFlag = 0 ;
//			}
//
			// 画面に弾を描画する
//			DrawGraph( ShotX , ShotY , ShotGraph , true ) ;
//		}

		//憂煉が追加した自機弾の移動るーちん
		for(int i = 0;i < TAMA_MAX ; ++i )
		{
			if( JIKITAMA[i].exist )
			{
				JIKITAMA[i].y -= 4;
				if ( JIKITAMA[i].y < -80 )
				{
					JIKITAMA[i].exist = 0;
				}
				if(HitCheck(i))
				{
					JIKITAMA[i].exist = 0;
				}
				DrawGraph(JIKITAMA[i].x,JIKITAMA[i].y,ShotGraph,true);
			}
		}

		// 四角君の移動ルーチン
		{
			// 四角君の座標を移動している方向に移動する
			if( SikakuMuki == 1 ) SikakuX += 1 ;
			if( SikakuMuki == 0 ) SikakuX -= 1 ;

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
		if( ProcessMessage() < 0 ) break ;

		// もしＥＳＣキーが押されていたらループから抜ける
		if( CheckHitKey( KEY_INPUT_ESCAPE ) ) break ;
	}

	DxLib_End() ;				// ＤＸライブラリ使用の終了処理

	return 0 ;					// ソフトの終了
}


