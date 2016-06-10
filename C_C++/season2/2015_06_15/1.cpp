#include <stdio.h>
#include <iostream>
#include <queue>


using namespace std;


int vertexes;			//頂点数
bool graph[101][101];	//隣接行列


int main()
{
	//頂点数を受け取る
	cin >> vertexes;
	
	//隣接リストを受け取り隣接行列を作る
	for(int i = 0; i < vertexes; ++i){
		//始点を受け取る
		int start;
		cin >> start;
		
		//伸びている辺の数を受け取る
		int edges;
		cin >> edges;
		
		//辺の数だけループ
		for(int ii = 0; ii < edges; ++ii){
			//辺の向かう先を受け取る
			int end;
			cin >> end;
			
			//隣接行列に記録
			graph[start][end] = true;
		}
	}
	
	/*****1からiまでの最短距離を順に幅優先探索で求める*****/
	//幅優先探索用のキューと現在位置記録編数を作成
	queue<int> slist;				//search list
	int cursor = 1;					//now cursor
		
	//訪問確認の配列を作成
	int visited[101];
	for(int r=0;r<101;++r)visited[r]=-1;
	
	//現在位置をキューに設定
	slist.push(cursor);
	visited[cursor] = 0;
		
	//キューに中身がある限りループ
	while(slist.empty() == false){
		//キューの先頭を取り出す
		cursor = slist.front(); slist.pop();
		
		//行き先を列挙
		for(int dest = 1; dest <= vertexes; ++dest){
			//行き先が存在し、かつ未訪問であるかどうかを判定
			if(graph[cursor][dest] == true && visited[dest] == -1){
				//キューに行き先を新しい現在位置として設定
				slist.push(dest);
				
				//行き先の探索番号を設定
				visited[dest] = visited[cursor] + 1;
			}
		}
	}
	
	//見つかった距離を表示
	for(int i = 1; i <= vertexes; ++i)cout << i << " " << visited[i] << endl;
}