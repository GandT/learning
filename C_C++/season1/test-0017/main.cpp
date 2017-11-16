/*
  プログラム名：test-0016
  制作日時：2008年5月12日～2008年5月12日
  制作：Ｇ＆Ｔ
  制作ソフト：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：文字列表示プログラム
*/
#include<stdio.h>
int main(){
	int test1=132,test2=0;
	int* test3;
	test3=&test1;
	printf("中身…%d\nアドレス…%p\n\n\n",*test3,test3);
	while(test2!=100){
	  test3++;
	  test2++;
	  };
	  printf("中身…%d\nアドレス…%p\n\n\n\nまあ、あたりまえの結果ですね",*test3,test3);
	  return 0;
}