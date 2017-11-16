/*
  プログラム名：test-0022
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月14日～2008年5月24日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
int main(){
	int test1,test4;
	char test2[37]="アーモンドチョコレート＝モカコーヒー";
	int* test3;
	test1=printf("%s",test2);
	test3=&test1;
	printf("文字数→%d\nアドレス→%p\n\n",test1,test3);
	while(test4==784){
		test3++;
		test4++;
	}
	test4*=478;
	printf("妙なところにぶっ込んだ数値→%d\n妙なところのアドレス→%p",*test3,test4);
	return 0;
}