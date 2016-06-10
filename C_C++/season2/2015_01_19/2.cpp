#include <stdio.h>#include <iostream>#include <math.h>using namespace std;#define ifor(X)	for(int i = 0;i < (X);++i)#define kfor(X)	for(int k = 0;k < (X);++k)//変数群int d;			//次数double v[10];	//受け取った値（最大d+3だが多めにとってある）double interpolate(int n,int e){	//(n,v[n])と(e,v[e])を除いたd+1点で補間多項式	double sum = 0;		kfor(d+3){		//使わないものが出たらやり直し		if(k == n || k == e)continue;				//補完多項式の最終乗算結果用変数		double p = v[k];				//0をかけないように注意しながら補完多項式を構築		ifor(d+3){			if(!(i == k || i == n || i == e)) p *= ((n - i) / (k - i));		}				//合計値を足す		sum += p;	}		//計算結果を返す	return sum;}bool outlier(int e){	//(e,v[e])が異常だと仮定したときにほかのd+2個が異常ではないかどうかを判別する	ifor(d+3){		//eが来たらはじく		if(i == e)continue;				//i,eをはじいてiのときの多項式計算		double p = interpolate(i,e);		//cout<< i << ":" << p << endl;				//ずれが生じた要素があればeは異常ではない		if(fabs(p - v[i]) >= 1.0){return false;}	}		//いっさいずれが生じなければ異常なのはe	return true;}int main(){	//メインループ	while(1){		//次数を受け取る		cin >> d;				//dが0なら終わり		if(d == 0)break;				//点を受け取る		ifor(d+3)cin >> v[i];				//判定		ifor(d+3){			//iを無視したときに全てが整合するならばiが答え			if(outlier(i)){				//正解の表示				cout << i << endl;								//終了				break;			}						//cout << "----------" << endl;		}	}}