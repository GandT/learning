/*
  プログラム名：test-0036
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月17日〜2008年5月26日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
#include<windows.h>
int main(){
	short test1[80]={56,432,74,26,36,254,746,234,73,4352,765,42,64,534,5786,534,83,45,76,865,86,56,28,86,95,38,5734,435,43,1234,746,5366,4533,5346,45,4,255,28646,46,45465,83,547,454,735,7050,0,354,32,45,634,45,12,65,43,4536,7098,32657,21,23,39,87,59,403,7438,187,908,456,-12,1456,-489,-81,5464};
	int test2,test3;
	for(test2=0;test2<80;test2++){
		printf("%d\n",test1[test2]);
		Sleep(100);
		test3+=test1[test2];
	}
	printf("演算結果…%d\nまーた、訳の分からんプログラムを……",test3);
}