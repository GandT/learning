#include <stdio.h>
#include <string>

using namespace std;


int bar;			//入力される棒の数
int bars[100001];	//棒の長さ
long long maxrect;	//長方形の最大面積

long long rectangle(int start,int end)
{
	//範囲内の最小値を求める
	int min = 1000000000;
	for(int i = start;i <= end;++i)if(bars[i] < min)min = bars[i];
	
	//長方形の最大面積を計算して返す
	return min * (end - start + 1);
}


int main()
{
	//メインループ
	while(1)
	{
		//入力される棒の数を受け取る
		scanf("%d",&bar);
		
		//入力棒が0なら終了
		if(bar == 0)break;
		
		//棒の長さを受けとる
		for(int i = 0; i < bar; ++i)scanf("%d",&bars[i]);
		
		//最大面積を計算
		for(int s = 0; s < bar; ++s)for(int e = s; e < bar; ++e)
			if(maxrect < rectangle(s,e))maxrect = rectangle(s,e);
		
		//最大面積を表示
		printf("%ll\n",maxrect);
		
		//初期化
		for(int i = 0; i < bar; ++i)bars[i] = 0;
		bar = 0;
		maxrect = 0;
	}
}