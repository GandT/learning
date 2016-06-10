#include <stdio.h>
#include <iostream>

using namespace std;


int pay;								//合計支払額
int coin10, coin50, coin100, coin500;	//手持ち硬貨の枚数
int  pay10,  pay50,  pay100,  pay500;	//支払う硬貨の枚数


int main()
{
	//メインループ
	while(1)
	{
		//変数の初期化
		pay10 = pay50 = pay100 = pay500 = 0;
		
		//支払い金額を受け取る
		cin >> pay;
		
		//支払い金額が0円の場合終了
		if(pay == 0)break;
		
		//手持ちコインの枚数を受け取る
		cin >> coin10 >> coin50 >> coin100 >> coin500;
		
		/*****支払い枚数の解析*****/
		//500円玉
		while(coin500 && pay >= 500){
			--coin500;		//500円玉で一枚支払い
			pay -= 500;		//残り支払額から500円減らす
			++pay500;		//支払いを記録
		}
		//100円玉
		while(coin100 && pay >= 100){
			--coin100;		//100円玉で一枚支払い
			pay -= 100;		//残り支払額から100円減らす
			++pay100;		//支払いを記録
		}
		//50円玉
		while(coin50 && pay >= 50){
			--coin50;		//50円玉で一枚支払い
			pay -= 50;		//残り支払額から50円減らす
			++pay50;		//支払いを記録
		}
		//10円玉
		while(coin10 && pay >= 10){
			--coin10;		//10円玉で一枚支払い
			pay -= 10;		//残り支払額から10円減らす
			++pay10;		//支払いを記録
		}
		//支払いきれていなかったら釣り銭をもらう
		if(pay>0 && coin50 ){--coin50;  ++pay50;  pay -= 50;}
		if(pay>0 && coin100){--coin100; ++pay100; pay -= 100;}
		if(pay>0 && coin500){--coin500; ++pay500; pay -= 500;}
		//後の処理のために釣り銭を先に受け取ったことにしておく
		while(pay <= -100){++coin100;pay+=100;}
		while(pay <= -50 ){++coin50 ;pay+= 50;}
		while(pay <= -10 ){++coin10 ;pay+= 10;}
		//10円玉→50円玉
		while(coin10 >= 5 && pay50){
			coin10-=5; pay10+=5;
			--pay50; ++coin50;
		}
		//10円玉→100円玉
		while(coin10 >= 10 && pay100){
			coin10-=10; pay10+=10;
			--pay100; ++coin100;
		}
		//10円玉→500円玉　はコインが最大20枚までなのであり得ない
		//50円玉→100円玉
		while(coin50 >= 2 && pay100){
			coin50-=2; pay50+=2;
			--pay100; ++coin100;
		}
		//50円玉→500円玉
		while(coin50 >= 10 && pay500){
			coin50-=10; pay50+=10;
			--pay500; ++coin500;
		}
		//100円玉→500円玉
		while(coin100 >= 5 && pay500){
			coin100-=5; pay100+=5;
			--pay500; ++coin500;
		}
		
		//出力
		if(pay10 )cout <<  10 << " " << pay10  << endl;
		if(pay50 )cout <<  50 << " " << pay50  << endl;
		if(pay100)cout << 100 << " " << pay100 << endl;
		if(pay500)cout << 500 << " " << pay500 << endl;
		
		//区切り空行
		cout << endl;
	}
}