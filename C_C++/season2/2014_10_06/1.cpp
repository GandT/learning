#include <stdio.h>#include <math.h>#include <iostream>using namespace std;int main(void){	//ループ回数	int roop;		//ループ回数を入力	cin >> roop;		//求められた回数ループ処理を行う	for(int r = 0;r < roop;++r){				//変数宣言		int input;			//データ入力用		int first;			//分割前者		int second;			//分割後者		int answer = 0;		//計算結果保存用		int count = 0;		//回数カウント				//初期値を受け取る		cin >> input;				//やり直し地点		RETRY:				//2桁以上でなければ終了		if(input < 10)goto END;				//回数をカウント		++count;				//計算		for(int i = 0;i <= 6;++i){						//分割			second = input % int(pow(10,(i + 1)));			first  = input / int(pow(10,(i + 1)));						//分割完了なら終了			if(first == 0)break;						//値を計算し保存			if(answer < first * second)answer = first * second;		}				/*****DEBUG*****/		//cout << "***" << answer << "***" << endl;				//変数を初期化し次へ進む		input = answer;		answer = 0;		goto RETRY;				END:				//出力		cout << count << endl;	}}