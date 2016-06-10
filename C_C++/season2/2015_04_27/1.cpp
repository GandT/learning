#include <stdio.h>
#include <iostream>

using namespace std;


int ds;			//データセット数

struct card{
	char col;		//色
	int num;		//番号
};
card cd[9];		//カード情報


#define hfor(X)		for(int h = 0;h < (X);++h)
#define ifor(X)		for(int i = 0;i < (X);++i)
#define efor(X)		for(int i = 0;i < (X);++i)


/*****main関数*****/
int main()
{
	//データセット数受け取り
	cin >> ds;
	
	//メインループ
	hfor(ds){
		
		//色判定用変数
		int r = 0,g = 0,b = 0;
		
		//情報受け取り
		ifor(9)cin >> cd[i].num;		//番号
		ifor(9){
			cin >> cd[i].col;		//色
			if(cd[i].col == 'R')++r;
			if(cd[i].col == 'G')++g;
			if(cd[i].col == 'B')++b;
		}
		
		//色判定
		if(r == 3 && g == 3 && b == 3){
			
			/*****数値判定*****/
			//同色カード値代入用配列
			int number[3];
			int in;
			
			/***赤***/
			//変数の初期化
			in = 0;
			
			//カード番号を代入
			ifor(9)if(cd[i].col == 'R'){
				number[in] = cd[i].num;
				++in;
			}
			
			//判定
			if(number[0] == number[1] && number[1] == number[2]){		//同値
				//ok
				goto red_ok;
			}else{														//連続
				if((number[0]+number[1]+number[2]) % 3 != 0){
					//駄目
					goto dame;
				}
				int average = (number[0] + number[1] + number[2]) / 3;
				efor(3)if(abs(number[i]) - average > 1)goto dame;
				
				//ok
				goto red_ok;
			}
			
			//赤ok
			red_ok:
			
			/***緑***/
			//変数の初期化
			in = 0;
			
			//カード番号を代入
			ifor(9)if(cd[i].col == 'G'){
				number[in] = cd[i].num;
				++in;
			}
			
			//判定
			if(number[0] == number[1] && number[1] == number[2]){		//同値
				//ok
				goto green_ok;
			}else{														//連続
				if((number[0]+number[1]+number[2]) % 3 != 0){
					//駄目
					goto dame;
				}
				int average = (number[0] + number[1] + number[2]) / 3;
				efor(3)if(abs(number[i]) - average > 1)goto dame;
				
				//ok
				goto green_ok;
			}
			
			//緑ok
			green_ok:
			
			/***青***/
			//変数の初期化
			in = 0;
			
			//カード番号を代入
			ifor(9)if(cd[i].col == 'B'){
				number[in] = cd[i].num;
				++in;
			}
			
			//判定
			if(number[0] == number[1] && number[1] == number[2]){		//同値
				//ok
				goto blue_ok;
			}else{														//連続
				if((number[0]+number[1]+number[2]) % 3 != 0){
					//駄目
					goto dame;
				}
				int average = (number[0] + number[1] + number[2]) / 3;
				efor(3)if(abs(number[i]) - average > 1)goto dame;
				
				//ok
				goto blue_ok;
			}
			
			//青ok
			blue_ok:
			
			//色問題なし
			cout << 1 << endl;
			
		}else{
			
			//駄目ラベル
			dame:
			
			//駄目
			cout << 0 << endl;
		}
	}
}