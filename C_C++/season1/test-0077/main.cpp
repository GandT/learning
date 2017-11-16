/*
  プログラム名：test-0077
  制作者：Ｇ＆Ｔ
  制作日時：2008年6月14日～2008年6月14日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：演算プログラム
*/
#include<stdio.h>
#include<time.h>
int main(){
	unsigned __int64 test1 = 0,test2;
	while(test1 != 4200000000){
	if(test1%1000000==0)printf("%d\n",test1);
	++test1;
	
	}
	test2 = clock();
	test2 /= 1000;
	printf("\n\n終了までにかかった時間…%d",test2);
}