/*
  プログラム名：test-0033
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月17日～2008年5月26日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：謎の演算プログラム
*/
#include<stdio.h>
#include<windows.h>
int main(){
	int test1;
	g6t:
	printf("数字入力しなさい→");
	scanf("%d",&test1);
	printf("最初の数…%d\n",test1);
	test1*=24;
	test1--;
	test1+=39;
	test1*test1;
	test1++;
	test1%=487;
	test1-=34;
	test1+=65;
	printf("演");
	Sleep(1000);
	printf("算");
	Sleep(1000);
	printf("中");
	Sleep(1000);
	printf("…");
	Sleep(1000);
	printf("…");
	Sleep(1000);
	printf("…\n\n\n");
	Sleep(1000);
	printf("演算後の数…%d\n",test1);
	Sleep(5000);
	printf("さてもう一度");
	goto g6t;
	return 0;
}