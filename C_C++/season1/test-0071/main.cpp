/*
  プログラム名：test-0071
  制作者：Ｇ＆Ｔ
  制作日時：2008年6月11日～2008年6月911日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：処理速度計測プログラム
*/
#include<stdio.h>
#include<time.h>
int main(){
	int test1,test2,test3;
//	printf("処理速度計測プログラム♪\n");
	for(test1 = 0;test1 < 200000000;test1++){
	}
	test2 = clock();
	test1 = 0;
	for(test1 = 0;test1 < 200000000;++test1){
	}
	test3 = clock();
	test3 -= test2;
//	test2 /= 1000;
//	test3 /= 1000;
	printf("test++の場合…%d\n++testの場合…%d\n",test2,test3);
	return 0;
}
//なんか実行結果がちょくちょく変わる