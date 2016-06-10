#include <stdio.h>
#include <iostream>


using namespace std;


int pq[2000002];			//priority queue　親：n/2　左子：2n　右子：2n+1
int dnum;					//（おおむね）現在のデータ数


void insert(int in);
void extract(int in);
void pqex(int a,int b);


int main()
{
	//メインループ
	while(1){
		//命令読み込み
		string cmd;
		cin >> cmd;
		
		//end命令なら終了
		if(cmd == "end")break;
		
		//命令分岐
		if(cmd == "insert"){
			//現在のデータ数を増やす
			++dnum;
			
			//データを受け取る
			cin >> pq[dnum];
			
			//調整
			insert(dnum);
		}
		else if(cmd == "extract"){
			//値を取り出す
			cout << pq[1] << endl;
			
			//穴を埋める
			pq[1] = pq[dnum];
			pq[dnum] = 0;
			
			
			//現在のデータ数を減らす
			--dnum;
			
			//調整
			extract(1);
		}
	}
}


//挿入時調整
void insert(int in)
{
	//親と比較し大きい場合
	if(pq[in] > pq[in/2] && in/2){
		//交換
		pqex(in,in/2);
		
		//更に調整
		insert(in/2);
	}
}


//排出時調整
void extract(int in)
{
	//どちらかの子よりも小さければ交換
	if(in*2 <= dnum && pq[in] < pq[in*2] && pq[in*2] >= pq[in*2+1]){
		//交換
		pqex(in,in*2);
		
		//再調整
		extract(in*2);
	}else if(in*2+1 <= dnum && pq[in] < pq[in*2+1] && pq[in*2+1] >= pq[in*2]){
		//交換
		pqex(in,in*2+1);
		
		//再調整
		extract(in*2+1);
	}
}


//交換
void pqex(int a,int b)
{
	int c = pq[a];
	pq[a] = pq[b];
	pq[b] = c;
}
