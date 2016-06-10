#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;


int houses;		//家の戸数
int generators;	//発電機の数
int x[100000];	//家の座標
int d[100000];	//家と家の間の距離
int answer;


int main()
{
	//合計データセット数を受け取る
	int dsets;
	cin >> dsets;
	
	//メインループ
	for(int lp = 0;lp < dsets;++lp){
		//変数の初期化
		answer = 0;
		for(int i = 0;i < 100000;++i)x[i] = d[i] = 0;
		
		//家の戸数と発電機の個数を受け取る
		cin >> houses >> generators;
		
		//家の座標を受け取る
		for(int i = 0;i < houses;++i)cin >> x[i];
		
		//家と家の間の距離を求める
		for(int i = 1;i < houses;++i)d[i-1] = x[i] - x[i-1];
		
		//距離配列を降順にソート
		sort(d,d+houses-1);				//昇順ソート
		reverse(d,d+houses-1);			//反転
		
		//最初の発電機数-1個の要素を無視して家と家の間の距離を足し合わせる
		for(int i = generators-1;i < houses-1;++i)answer += d[i];
		
		//答えを出力
		cout << answer << endl;
	}
}
