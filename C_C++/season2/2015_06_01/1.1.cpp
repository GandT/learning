#include <stdio.h>
#include <math.h>
#include <iostream>


using namespace std;


int  dim[101];

int main()
{
	//データ読み込み用変数
	int start,end;
	
	//メインループ
	while(~scanf("%d %d",&start,&end)){		//EOF==255より、リターン値のビット反転で受け取ったかどうかが判別できる
		
		//道の本数を増やす
		dim[start]++; dim[end]++;
		
		//読み込みループ
		for(int i = 1;i <= 5000;++i){
			//データ読み込み
			cin >>start >> end;
			
			//読み込み終了条件
			if(!start && !end)break;
			
			//道の本数を増やす
			dim[start]++; dim[end]++;
			
		}
		
		//判定ループ
		if(dim[1]%2 && dim[2]%2){
			
			for(int i = 3;i <= 100;++i){
				if(dim[i]%2){
					cout << "NG" << endl;
					goto roopend;
				}
			}
			
			cout << "OK" <<endl;
			
		}else{
			cout << "NG" << endl;
		}
		
		roopend:
		
		//変数の初期化
		for(int i=0;i<101;++i){
			dim[i] = 0;
		}
	}

	//終了
	return 0;
}