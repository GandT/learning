#include <stdio.h>#include <iostream>using namespace std;#define ifor(X)		for(int i = 0;i < X;++i)#define jfor(X)		for(int j = 0;j < X;++j)#define kfor(X)		for(int k = 0;k < X;++k)#define DELETE	-1int H;					//ブロックの高さint blocks[10][5];		//ブロックを示す配列int score;				//スコアint scoreup;			//スコアの上昇値int main(){		while(1){				//変数の初期化		ifor(10)jfor(5)blocks[i][j] = 0;		score = scoreup = 0;				//盤面の高さを受け取る		cin >> H;		if(!H)break;				//石のデータを受け取る		ifor(H)cin >> blocks[H-1-i][0] >> blocks[H-1-i][1] >> blocks[H-1-i][2] >> blocks[H-1-i][3] >> blocks[H-1-i][4];				/*****パズル計算*****/		//再び消去		start:				//一ラインずつチェックする		ifor(H){			//一ブロック目と同じものがあるかどうか			if(blocks[i][0])if(blocks[i][0] == blocks[i][1] && blocks[i][1] == blocks[i][2]){				if(blocks[i][2] == blocks[i][3]){					if(blocks[i][3] == blocks[i][4]){						//五連						scoreup += blocks[i][0] * 5;												//消去マークをつける						blocks[i][0] = blocks[i][1] = blocks[i][2] = blocks[i][3] = blocks[i][4] = DELETE;												//次のラインに進む						continue;					}										//四連					scoreup += blocks[i][0] * 4;										//消去マークをつける					blocks[i][0] = blocks[i][1] = blocks[i][2] = blocks[i][3] = DELETE;										//次のラインに進む					continue;				}								//三連				scoreup += blocks[i][0] * 3;								//消去マークをつける				blocks[i][0] = blocks[i][1] = blocks[i][2] = DELETE;								//次のラインに進む				continue;			}			//二ブロック目と同じものがあるかどうか			if(blocks[i][1])if(blocks[i][1] == blocks[i][2] && blocks[i][2] == blocks[i][3]){				if(blocks[i][3] == blocks[i][4]){					//四連					scoreup += blocks[i][1] * 4;										//消去マークをつける					blocks[i][1] = blocks[i][2] = blocks[i][3] = blocks[i][4] = DELETE;											//次のラインに進む					continue;				}								//三連				scoreup += blocks[i][1] * 3;								//消去マークをつける				blocks[i][1] = blocks[i][2] = blocks[i][3] = DELETE;								//次のラインに進む				continue;			}						//三ブロック目と同じものがあるかどうか			if(blocks[i][2])if(blocks[i][2] == blocks[i][3] && blocks[i][3] == blocks[i][4])			{				//三連				scoreup += blocks[i][2] * 3;								//消去マークをつける				blocks[i][2] = blocks[i][3] = blocks[i][4] = DELETE;								//次のラインに進む				continue;			}		}				//cout << "scoreup:" << scoreup << endl;				//DETELEがなければ終了		if(scoreup == 0)goto end;				//消されている部分を下げる		jfor(5)			ifor(10)				if(blocks[i][j] == DELETE){					recheck:					kfor(9-i)blocks[i+k][j] = blocks[i+k+1][j];					blocks[9][j] = 0;					if(blocks[i][j] == DELETE)goto recheck;				}				//score計算		score += scoreup;		scoreup = 0;				//再チェック		//ifor(10)cout << blocks[9-i][0] << blocks[9-i][1] << blocks[9-i][2] << blocks[9-i][3] << blocks[9-i][4] << endl;		goto start;				//消去完了		end:				//スコアを出力		cout << score << endl;	}}