/*
  プログラム名：test-0019
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月13日～年月日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：演算プログラム
*/
#include<stdio.h>
#include<windows.h>
tester(int a,int b);
int main(){
	int mono;
	char c,d;
	kokonattu:
	printf("一文字目→");
	scanf("%d",c);
	printf("\n二文字目→");
	scanf("%d",d);
	mono=tester(c,d);
	printf("帰ってきたやつ→%d",mono);
	Sleep(5000);
	printf("さてもう一度");
	goto kokonattu;
}
tester(int a,int b){
	int testaning;
	printf("\n%d\n%d",a,b);
	testaning=a+b;
	testaning++;
	return testaning;
}