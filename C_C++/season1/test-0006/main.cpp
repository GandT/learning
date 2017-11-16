/*
  プログラム名：test-0006
  制作日時：2008年5月6日～2008年5月7日
  制作：Ｇ＆Ｔ
  制作ソフト：メモ帳,ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの内容：文字列表示プログラム
*/
#include <stdio.h>
char nanasi[]="(嘘";
int gt1(void){
	printf("Ｇ\a＆\aＴ\aの\aテ\aス\aト\aプ\aロ\aグ\aラ\aム\a\n\aた\aだ\aの\a関\a数\aテ\aス\aト\aだ\aよ\a！\a");
	printf("%s\n",nanasi);
}
int main(){
	gt1();
	return 0;
}