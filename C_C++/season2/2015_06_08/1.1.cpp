/*
  参考資料：ALGORITHM NOTE（http://algorithms.blog55.fc2.com/blog-entry-132.html）
*/


#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;


int bar;			//入力される棒の数
long long bars[100001];	//棒の長さ
long long maxrect;	//長方形の最大面積

stack<long long> rectheight;
stack<long long> rectleft;


//長方形の最大面積をstackを用いて計算
void maxrectangle()
{
	//0からbarまでの順に調べる
	for(int i = 0;i < bar;++i){
		//スタックが空の場合
		if(rectheight.empty() == true){
			//スタックに新しい長方形情報をpush
			rectheight.push(bars[i]);
			  rectleft.push(i);
		}
			
		//スタックのトップのheightが現在の棒の高さより低い場合
		else if(rectheight.top() < bars[i]){
			//スタックに新しい長方形情報をpush
			rectheight.push(bars[i]);
			  rectleft.push(i);
		}
		
		//スタックのトップのheightが現在の棒の高さより高い場合
		else if(rectheight.top() > bars[i]){
			//面積計算用変数を準備
			long long height,left;
			
			//スタックが空でなくトップのheightが現在の棒の高さより高い限りループ
			while(rectheight.empty() == false && rectheight.top() > bars[i])
			{
				//スタックから長方形を取り出す
				height = rectheight.top(); rectheight.pop();
				  left =   rectleft.top();   rectleft.pop();
				
				//長方形の面積を計算
				long long l = (i - left) * height;
				
				//面積が今までで最大であれば最大値を更新
				if(maxrect < l)maxrect = l;
			}
			
			//スタックに新しい長方形情報をpush
			rectheight.push(bars[i]);
			  rectleft.push(left);
		}
	}
	
	//スタックに残った長方形を計算
	long long height,left;
	
	//スタックが空でなくトップのheightが現在の棒の高さより高い限りループ
	while(rectheight.empty() == false)
	{
		//スタックから長方形を取り出す
		height = rectheight.top(); rectheight.pop();
		  left =   rectleft.top();   rectleft.pop();
		
		//長方形の面積を計算
		long long l = (bar - left) * height;
		
		//面積が今までで最大であれば最大値を更新
		if(maxrect < l)maxrect = l;
	}
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
		for(int i = 0; i < bar; ++i)scanf("%lld",&bars[i]);
		
		//最大面積を計算
		maxrectangle();
		
		//最大面積を表示
		//printf("%lld\n",maxrect);
		cout << maxrect << endl;
		
		//変数を初期化
		for(int i = 0; i < bar; ++i)bars[i] = 0;
		bar = 0;
		maxrect = 0;
	}
}