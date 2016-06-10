#include <stdio.h>
#include <iostream>

using namespace std;


int ds;			//データセット数

struct card{
	char col;		//色
	int num;		//番号
};
card cd[9];		//カード情報


#define gfor(X)		for(int g = 0;g < (X);++g)
#define hfor(X)		for(int h = 0;h < (X);++h)
#define ifor(X)		for(int i = 0;i < (X);++i)

#define RED		0
#define GREEN 	1
#define BLUE	2


/**********講義用pdfの関数を使用**********/
bool is_same_number(int a,int b,int c){
	return a == b && b == c;
}

bool is_sequence(int a,int b,int c){
	return a+2 == b+1 && b+1 == c;
}

bool is_good_set(int a,int b,int c){
	return is_same_number(a,b,c) || is_sequence(a,b,c);
}
/****************************************/


/*****main関数*****/
int main()
{
	//データセット数受け取り
	cin >> ds;
	
	//メインループ
	hfor(ds){
		
		//変数宣言
		int ccou[3] = {0,0,0};		//色ごとの枚数
		
		//情報受け取り
		ifor(9)cin >> cd[i].num;	//番号
		ifor(9){
			cin >> cd[i].col;		//色
			if(cd[i].col == 'R')++ccou[RED  ];
			if(cd[i].col == 'G')++ccou[GREEN];
			if(cd[i].col == 'B')++ccou[BLUE ];
		}
		
		//色の判定
		if(ccou[0] % 3 || ccou[1] % 3 || ccou[2] % 3){
			//不成立
			cout << 0 << endl;
			continue;
		}
		
		//番号の判定
		gfor(3){
			
			//色変数の設定
			char color;
			if(g == RED  )color = 'R';
			if(g == GREEN)color = 'G';
			if(g == BLUE )color = 'B';
			
			//色ごとのカードの番号だけ抽出
			int counter = 0;
			int cnum[9];
			ifor(9)if(cd[i].col == color){
				cnum[counter] = cd[i].num;
			}
			
			//ソート
			
			//全ての組み合わせを試す
			{
				//判定
				is_good_number(0,0,0);
			}
		}
	}
}