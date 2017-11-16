/*
  プログラム名：test-0075
  制作者：Ｇ＆Ｔ、John
  制作日時：2008年6月11日～2008年6月11日
  制作：ＢＣＣ
  コンパイラ：ＢＣＣ
  プログラムの種類：演算プログラム
*/
#include<stdio.h>
int kouyakusuu(int y1,int y2){
	int count/*for文カウンター*/,kakunou1/*y1を入れるもの*/,kakunou2/*y2を入れるもの*/,save/*初期判断*/,memo = 0,kiroku;
	if(y1>y2){
		save = y1;
		kiroku = 0;
	} else if(y1 < y2){
		save = y2;
		kiroku = 1;
	} else{
		return y1;
	}
	for(count = 1/*初期割り数*/;;++count){
		kakunou1 = (y1 % count);
		kakunou2 = (y2 % count);
		if(kakunou1 == kakunou2){
			if(kakunou1 == 0) memo = count;
			}
			if(count > y1+y2) break;
		}
	return memo;
}
int main(){
	int test1,test2,test3;
	printf("最大公約数を求めたい数字を入力二つしてください\n一つ目→");
	scanf("%d",&test1);
	printf("二つ目→");
	scanf("%d",&test2);
	test3 = kouyakusuu(test1,test2);
	printf("最大公約数→%d",test3);
	return 0;
}