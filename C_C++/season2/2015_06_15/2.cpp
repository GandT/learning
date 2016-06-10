#include <stdio.h>
#include <iostream>
#include <queue>


using namespace std;


int width,highth;		//島の横と縦の長さ
bool island[52][52];	//島データ
int landnum;			//島の数


int main()
{
	//メインループ
	while(1){
		//島の横と縦の長さを受け取る
		cin >> width >> highth;
		
		//島が存在していなければ終了
		if(width == 0 && highth == 0)break;
		
		//島データの初期化
		for(int i = 0; i < 52; ++i)for(int j = 0 ;j < 52; ++j)island[i][j] = false;
		landnum = 0;
		
		//島のデータを受け取る
		for(int j = 1 ;j <= highth; ++j)for(int i = 1; i <= width; ++i)
			cin >> island[i][j];
		
		//探索用変数を宣言
		queue<int> ilist,jlist;		//幅優先探索用キュー
		bool visited[52][52];		//既訪問場所管理用配列
			for(int i = 0; i < 52; ++i)for(int j = 0 ;j < 52; ++j)visited[i][j] = false;
		int nowi,nowj;				//探索基準点
		
		//始点を変えながら幅優先探索
		for(int i = 1; i <= width; ++i)for(int j = 1 ;j <= highth; ++j){
			//海か既に訪れたことがあった場合はやり直し
			if(!island[i][j] || visited[i][j])continue;
			
			//現在地を設定
			nowi = i; nowj = j;
			
			//島を数える
			++landnum;
			
			//キューの値を設定
			ilist.push(i); jlist.push(j);
//			printf("(%d,%d)",nowi,nowj);						//DEBUG
			
			//現在地を既訪問に
			visited[i][j] = true;
			
			//キューがなくなるまでループ
			while(!ilist.empty() && !jlist.empty()){
				//現在地をキューから更新
				nowi = ilist.front(); ilist.pop(); 
				nowj = jlist.front(); jlist.pop(); 
				
				//隣接部分を調査
				for(int x=-1;x<=1;++x)for(int y=-1;y<=1;++y){
					//隣接部分が陸地かつ未訪問かを判定
					if(island[nowi+x][nowj+y] && !visited[nowi+x][nowj+y]){
						//足跡を付ける
						visited[nowi+x][nowj+y] = true;
						
						//陸地をキューに追加
						ilist.push(nowi+x); jlist.push(nowj+y);
//						printf("(%d,%d)",nowi+x,nowj+y);			//DEBUG
					}
				}
			}
			
//			cout << endl;	//DEBUG
		}
		
		//島の数を表示
		cout << landnum << endl;
	}
}