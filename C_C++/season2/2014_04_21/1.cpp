#include <stdio.h>#include <algorithm>using namespace std;int card;			//カード枚数int cards[50];		//カード配列int main(void){	int cutstart = 0;		//シャッフル開始地点	int cutcard = 0;		//シャッフル枚数	int shuffles = 0;		//シャッフル回数	int now = 0;			//現在のシャッフル回数	bool shuffling = false;	//シャッフル中かどうかのフラグ		//メインループ	while(true)	{		//シャッフル中かどうかを判定		if(shuffling){						/*****シャッフル中*****/						//シャッフルスタート地点の取得			scanf("%d",&cutstart);						//シャッフル枚数の取得			scanf("%d",&cutcard);						//シャッフル処理−−回転関数を用いて			rotate(cards,cards + cutstart - 1,cards + cutstart + cutcard - 1);			//printf("test:%d %d %d %d %d\n",cards[0],cards[1],cards[2],cards[3],cards[4]);						//シャッフル回数のカウントを加算			++now;						//指定回数に到達するとシャッフル終了			if(now == shuffles){								//シャッフル終了フラグをたてる				shuffling = false;								//一番上のカードを出力				printf("%d\n",cards[0]);			}					}else{						/*****非シャッフル中*****/						//変数の初期化			now = 0;						//カード枚数取得			scanf("%d",&card);						//カードのセット			for(int i = 0;i < card;++i)cards[i] = card - i;						//シャッフル回数取得			scanf("%d",&shuffles);						//(0,0)で終了			if(!card && !shuffles)break;						//シャッフル中フラグをたてる			shuffling = true;		}	}		//終了	return 0;}