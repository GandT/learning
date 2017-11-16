/*
  プログラム名：test-0066
  制作者：Ｇ＆Ｔ
  制作日時：2008年6月7日～2008年6月7日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
#include<time.h>
int main(){
	time_t test1;
	printf("西暦…%ld年",time(&test1));
	return 0;
}