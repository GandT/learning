#include <stdio.h>#include <math.h>#include <iostream>using namespace std;int n;					//読み込み個数double x[20],y[20];		//頂点座標double s;				//面積int main(){	//読み込み用変数	double inx,iny;		//読み込みループ	while(~scanf("%lf,%lf",&inx,&iny)){		//EOF==255より、リターン値のビット反転で受け取ったかどうかが判別できる		//受け取った座標を代入		x[n] = inx;		y[n] = iny;				//カウンタの値を1つ増やす		++n;	}		//面積計算	for(int i = 0;i+2 < n;++i){			//三角形の個数分ループをまわす		//座標の設定		double ax = x[0];		double ay = y[0];		double bx = x[i+1];		double by = y[i+1];		double cx = x[i+2];		double cy = y[i+2];				//ABベクトル		double abx = bx - ax;		double aby = by - ay;				//ACベクトル		double acx = cx - ax;		double acy = cy - ay;				//外戚から面積を計算して加算		s += (abx*acy - aby*acx);	}		//画面に出力	printf("%.6f\n",fabs(s) * 0.5);		//終了	return 0;}