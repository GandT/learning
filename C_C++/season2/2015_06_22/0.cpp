#include <stdio.h>#include <iostream>#include <complex>#include <algorithm>using namespace std;typedef complex<double> xy;	#define x real#define y imagint datasets;xy points[100];int main(){	//メインループ	while(1)	{		//データセット数を受け取る		cin >> datasets;				//データセット数が0なら終了		if(!datasets)break;				//それぞれのデータを受け取る		for(int i = 0; i < datasets; ++i){			//データを受けとる			double inx,iny;			cin >> inx >> iny;						//配列にデータを代入			points[i] = xy(inx,iny);		}				//座標をx座標でソート		//sort(points->real,(points + datasets)->real);										//変数の初期化		for(int i = 0; i < datasets; ++i)points[i] = xy(0,0);	}}