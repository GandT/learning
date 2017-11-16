/*
  プログラム名：test-0113
  制作者：Ｇ＆Ｔ
  制作日時：2009年8月12日～2009年8月12日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：３Ｄ描画プログラム
*/

#include "DxLib.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
			 LPSTR lpCmdLine, int nCmdShow )
{
	int GrHandle ;
	float Z;
	VERTEX_3D Vertex[6] ;// ポリゴン２枚なので、頂点は６個

	// ＤＸライブラリ初期化処理
	if( DxLib_Init() == -1 )	
		 return -1 ;	// エラーが起きたら直ちに終了

	// 描画先を裏画面にする
	SetDrawScreen( DX_SCREEN_BACK ) ;
	
	SetGraphMode(1024,768,32) ;

	// テクスチャの読み込み
	GrHandle = LoadGraph( "Gewy001.png" ) ;

	// Ｚ値の初期化
	Z = 0.0F ;
	
	// 頂点情報のセット
	{
		// 画面の中央に幅・高さ100で描画
		Vertex[0].pos.x = 512 - 50;	Vertex[0].pos.y = 768;	Vertex[0].pos.z = 0 ;
		Vertex[0].u = 0.0F ;
		Vertex[0].v = 0.0F ;

		Vertex[1].pos.x = 512 + 50;	Vertex[1].pos.y = 768;	Vertex[1].pos.z = 0 ;
		Vertex[1].u = 1.0F ;
		Vertex[1].v = 0.0F ;

		Vertex[2].pos.x = 512 - 50;	Vertex[2].pos.y = 668;	Vertex[2].pos.z = 0 ;
		Vertex[2].u = 0.0F ;
		Vertex[2].v = 1.0F ;

		Vertex[3].pos.x = 512 + 50;	Vertex[3].pos.y = 668;	Vertex[3].pos.z = 0 ;
		Vertex[3].u = 1.0F ;
		Vertex[3].v = 1.0F ;

		Vertex[4].pos.x = 512 - 50;	Vertex[4].pos.y = 668;	Vertex[4].pos.z = 0 ;
		Vertex[4].u = 0.0F ;
		Vertex[4].v = 1.0F ;

		Vertex[5].pos.x = 512 + 50;	Vertex[5].pos.y = 768;	Vertex[5].pos.z = 0 ;
		Vertex[5].u = 1.0F ;
		Vertex[5].v = 0.0F ;

		
		// 輝度は全要素100%
		for(int i = 0;i < 6;++i)Vertex[i].r = Vertex[i].g = Vertex[i].b = 255 ;

		// a も最大値
		for(int i = 0;i < 6;++i)Vertex[i].a = 255 ;
	}

	// 何かキーが押されるまでループ
	while( CheckHitKeyAll() == 0 )
	{
		// メッセージ処理
		if( ProcessMessage() != 0 ) break ;

		// 画面の初期化
		ClearDrawScreen() ;

		//どんどん大きくなる
		for(int i = 0;i < 6;++i){
			/*if(Vertex[i].pos.z > -128.0f)*/--Vertex[i].pos.z;//else Vertex[i].pos.z = 0.0f;
		}
		
		//上下移動
		for(int i = 0;i < 6;++i){
			--Vertex[i].pos.y;
		}

		// ポリゴンを透過色無しで２枚描画
		DrawPolygon3D( Vertex, 2, GrHandle, true ) ;

		// 裏画面の内容を表画面に反映
		ScreenFlip() ;
	}

	// ＤＸライブラリ使用の終了処理
	DxLib_End() ;

	// ソフトの終了
	return 0 ;
}

