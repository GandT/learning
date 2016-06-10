#include <stdio.h>
#include <iostream>
#include <string>


using namspace std;


int wnum;			//単語数
string word[100001]
int alphabet[128][128];


/*****main関数*****/
int main(void)
{
	//合計データセット数を受け取る
	int dataset;
	cin >> dataset;
	
	//データセット数分ループ
	for( int rp = 0 ; rp < dataset ; ++rp )
	{
		//単語数を受け取る
		cin >> wnum;
		
		//入力ループ
		for(int in = 0;in < wnum;++in){
			scanf("%s",word[in]);
		}
		
		
		
		
		
		//初期化
		wnum = 0;
		for(int i = 0;i < wnum;++i)word[i] = NULL;
		for(int i = 0;i < 128 ;++i)for(int j = 0;j < 128 ;++j)alphabet[i][j] = 0;
	}
}