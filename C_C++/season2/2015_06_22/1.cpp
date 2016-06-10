#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>


using namespace std;


#define RIGHT	true
#define LEFT	false

struct graph
{
	int vertexes;		//頂点数（3〜10）
	/*****************************************/
	int x[10],y[10];	//座標
	/*****************************************/
	double llength[9];	//線の長さ
	bool turn[8];		//曲がる方向
};


int main()
{
	//メインループ
	while(1)
	{
		//折れ線構造体を作成
		graph lines[51];
		
		//データセット数を受け取る
		int datasets;
		cin >> datasets;
		
		//データセット数が0なら終了
		if(!datasets)break;
		
		//データセットを受け取る
		for(int i = 0; i <= datasets; ++i){
			//頂点数を受け取る
			cin >> lines[i].vertexes;
			
			//頂点数分だけ座標を受け取る
			for(int j = 0; j < lines[i].vertexes; ++j)cin >> lines[i].x[j] >> lines[i].y[j];
		}
		
		//データセットを判定可能な形に変換する
		for(int i = 0;i <= datasets; ++i){
			//頂点を確認して長さと曲がる方向を設定
			for(int j = 1; j < lines[i].vertexes; ++j){
				
				/*****長さ配列を設定*****/
				//x座標が同じ場合
				if(lines[i].x[j] == lines[i].x[j-1]){
					lines[i].llength[j-1] = abs(lines[i].y[j] - lines[i].y[j-1]);
				}
				//y座標が同じ場合
				else{
					lines[i].llength[j-1] = abs(lines[i].x[j] - lines[i].x[j-1]);
				}
				/*****左右配列を設定*****/
				//最初は向きが存在しないので次のループへ
				if(j-1 == 0){
					continue;
				}
				
				/***二つ目以降の向きを外積で判定***/
				//変数を準備を計算
				int x1 = lines[i].x[j-1] - lines[i].x[j-2];
				int x2 = lines[i].x[j-0] - lines[i].x[j-2];
				int y1 = lines[i].y[j-1] - lines[i].y[j-2];
				int y2 = lines[i].y[j-0] - lines[i].y[j-2];
				
				//外積（符号付き面積）を計算
				int S = x1*y2 - x2*y1;
				
				//正ならば左、負ならば右に曲がっていることがわかる
				if(S > 0)	lines[i].turn[j-2] = LEFT;
				else		lines[i].turn[j-2] = RIGHT;
			}
		}
		
		//最初に受け取ったデータと同じものがあればその配列番号を出力
		for(int i = 1; i <= datasets; ++i){
			//頂点数が同じでない場合はやり直し
			if(lines[0].vertexes != lines[i].vertexes)continue;
			
			//線の長さと曲がる方向が同じかどうか判定（前から）
			for(int j = 0; j < lines[0].vertexes-1; ++j){
				//線の長さ
				if(lines[0].llength[j] != lines[i].llength[j]){
					//cout << "lines[0].llength[" << j << "]=" << lines[0].llength[j] << endl << "lines[" << i << "].llength[" << j << "]=" << lines[i].llength[j] << endl << endl;
					goto failed1;
				}
			}
			for(int j = 0; j < lines[0].vertexes-2; ++j){
				//曲がる向き
				if(lines[0].turn[j]    != lines[i].turn[j]   ){
					//cout << "lines[0].turn[" << j << "]=" << lines[0].turn[j] << endl << "lines[" << i << "].turn[" << j << "]=" << lines[i].turn[j] << endl << endl;
					goto failed1;
				}
			}
			
			//成功なので画面表示処理へ飛ぶ
			goto succeeded;
			
			//第一失敗時ラベル
			failed1:
			
			//線の長さと曲がる方向が同じかどうか判定（後ろから）
			for(int j = 0; j < lines[0].vertexes-1; ++j){
				//線の長さ
				if(lines[0].llength[j] != lines[i].llength[lines[0].vertexes-1-1-j]){
					//cout << "lines[0].llength[" << j << "]=" << lines[0].llength[j] << endl << "lines[" << i << "].llength[" << lines[0].vertexes-1-1-j << "]=" <<  lines[i].llength[lines[0].vertexes-1-1-j] << endl << endl;
					goto failed2;
				}
			}
			for(int j = 0; j < lines[0].vertexes-2; ++j){
				//曲がる向き（正しい場合は一致しない）
				if(lines[0].turn[j]    == lines[i].turn[lines[0].vertexes-2-1-j]   ){
					//cout << "lines[0].turn[" << j << "]=" << lines[0].turn[j] << endl << "lines[" << i << "].turn[" << lines[0].vertexes-2-1-j << "]=" <<  lines[i].turn[lines[0].vertexes-2-1-j] << endl << endl;
					goto failed2;
				}
			}
			
			//成功時ラベル
			succeeded:
			
			//同じ折れ線図であると判定されたので要素番号を表示
			cout << i << endl;
			
			//失敗時ラベル（駄目な場合はここに飛ぶ）
			failed2:;
		}
		
		//区切り線を表示
		cout << "+++++" << endl;
	}
}