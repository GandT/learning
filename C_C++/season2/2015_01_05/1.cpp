#include <stdio.h>#include <iostream>using namespace std;#define ifor(X)		for(int i = 0;i < (X);++i)#define jfor(X)		for(int j = 0;j < (X);++j)#define kfor(X)		for(int k = 0;k < (X);++k)int n,n1;			//項数,項数+1int a[5001];		//項int sum[5001];		//和int main(){	//nが0でなければ処理を行う	while(1){		//項数を受け取る		cin >> n;		n1 = n+1;				//nが0だったら終了		if(!n)break;				//aを受け取る		ifor(n)cin >> a[i+1];				//sumを設定する		ifor(n)sum[i+1] = sum[i] + a[i+1];				//最大値変数		int maxsum = 0;				//n1-i番目からj番目を引く形の調査		ifor(n1)jfor(n1-i){			if(maxsum < sum[n-i] - sum[j])maxsum = sum[n-i] - sum[j];		}				//最大値を出力		cout << maxsum << endl;	}}