/*
  プログラム名：test-0057
  制作者：Ｇ＆Ｔ
  制作日時：2008年6月2日～2008年6月2日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
#include<string.h>
int main(){
	char test1[100]="はっはっはになった";
	char test2[]="ヌルポット";
	strcat(test1,test2);
	printf("%s,%d",test1,test2);
	return 0;
}