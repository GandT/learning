/*
  プログラム名：test-0023
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月15日～2008年5月24日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：ギャンブルプログラム
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
int main(){
	int test1,test2;
	test2=0;
	srand((unsigned)time(NULL));
	printf("100がでたら終了するよ！\n何回で終了するかでギャンブルでもすれば？\n");
	while(test1!=100){
		test1=rand()%101;
		printf("発生した数…%d\n",test1);
		test2++;
		Sleep(100);
	}
	printf("計測終了！\n");
	Sleep(1000);
	printf("\n百がでるまでにかかった回数…%d回\nありがとうございました\nまたご利用ください\n",test2);
	Sleep(5000);
	return 0;
}