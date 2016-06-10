#include <stdio.h>
#include <math.h>
#include <iostream>


using namespace std;


bool cross[101][101];
int  dim[101];

int main()
{
	//データ読み込み用変数
	int start,end;
	
	//メインループ
	while(~scanf("%d %d",&start,&end)){		//EOF==255より、リターン値のビット反転で受け取ったかどうかが判別できる
		
		//連結リストを連結行列に変換
		cross[start][end] = cross[end][start] = true;
		
		//読み込みループ
		for(int i = 1;i <= 5000;++i){
			//データ読み込み
			cin >>start >> end;
			
			//読み込み終了条件
			if(!start && !end)break;
			
			//連結リストを連結行列に変換
			cross[start][end] = cross[end][start] = true;
		}
		
		//頂点から出ている道の本数を数える
		for(int i=0;i<101;++i)
			for(int j=0;j<101;++j)if(cross[i][j])++dim[i];
		
		//オイラー閉路の判定
		if(dim[1]%2 && dim[2]%2){
			for(int i = 3;i < 101;++i){
				if(dim[i]%2){
					cout << "NG" << endl;
				}
			}
			cout << "OK" << endl;
		}else{
			cout << "NG" << endl;
		}
		
		//変数の初期化
		for(int i=0;i<101;++i){
			for(int j=0;j<101;++j)cross[i][j] = false;
			dim[i] = 0;
		}
	}

	//終了
	return 0;
}