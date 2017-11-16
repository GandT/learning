/*
  プログラム名：test-0015
  制作日時：2008年5月12日～2008年5月12日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：文字列表示プログラム
*/
#include<stdio.h>
#include<windows.h>
struct GandT{
	int a[30];
	int b;
	float c;
};
int main(){
	n:
	struct GandT aa;
	aa.a[0]=846;
	aa.a[12]=213;
	aa.a[5]=15;
	aa.b=15;
	aa.c=15.325;
	printf("%d\n%d\n%d\n",aa.a,aa.b,aa.c);
	Sleep(1000);
	goto n;
	return 0;
}