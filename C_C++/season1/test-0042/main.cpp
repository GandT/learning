/*
  プログラム名：test-0042
  制作者：Ｇ＆Ｔ
  制作日時：2008年5月20日～2008年5月26日
  制作：メモ帳、ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：文字列表示プログラム
*/
#include<stdio.h>
#include<string.h>
int main(){
	int test1,test2;
	char test3[49];
	printf("テキトーに数字をぶっ込め\n");
	scanf("%d",&test1);
	if(test1==0){
		test2=57;
		strcpy(test3,"もきょ～ん");
	}else if(test1<0){
		test2=36598;
		strcpy(test3,"もぎゃもぎゃり～～ん");
	}else if(test1<-657){
		test2=89;
		strcpy(test3,"蛇須子＝邪我利子");
	}else if(test1<-3656){
		test2=327;
		strcpy(test3,"jut,xjgrely");
	}else if(test1>0){
		test2=-8947;
		strcpy(test3,"づぃみゃいちょ");
	}else if(test1>74){
		test2=987;
		strcpy(test3,"hahhahhaninatta");
	}else if(test1>945){
		test2=-9456;
		strcpy(test3,"わああ～～");
	}
	printf("\n%d%s",test2,test3);
	return 0;
}