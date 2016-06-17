/*
  2016.06.17
  Dijkstra algorythm
  参考文献：
    http://www.hongo.wide.ad.jp/~jo2lxq/dm/
    http://miffysora.wikidot.com/dijkstra
*/


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <queue>


using namespace std;


#define MAX_ARRAY   128
#define INFINITE    99999999


//global arrays declaration
int d[MAX_ARRAY];                   //distance from s to [s]==u
int prev[MAX_ARRAY];                //previous node from v
bool exist[MAX_ARRAY];              //node exist flag
int admat[MAX_ARRAY][MAX_ARRAY];    //adjacency matrix of the graph

//global class declaration
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > H;            //confirmed node



//calculate distance by Dijkstra algorytm
void Dijkstra(int strtnd)
{
  //initialize priority queue
  for(int i = 0;i < MAX_ARRAY;++i){
    if(!exist[i])continue;
    if(i != strtnd)H.push(make_pair(INFINITE,i));
    else           H.push(make_pair(       0,i));
  }

  //setting start node
  d[strtnd] = 0;
  
  //dequeue loop
  while(H.size()){    //continue if H is not empty
    //dequeue minimam distance
    pair<int,int> check = H.top(); H.pop();

    //check distance
    for(int i = 0;i < MAX_ARRAY;++i){
      //updata distance if finding shorter way
      if(d[i] > check.first + admat[check.second][i]){
	d[i] = d[check.second] + admat[check.second][i];
	prev[i] = check.second;
      }
    }

    //restruct H
    int size = H.size();
    pair<int,int> *tempH = (pair<int,int> *)malloc(sizeof(pair<int,int>) * size);
    //dequeue all
    for(int i = 0;i < size;++i){
      tempH[i] = H.top();
      H.pop();
    }
    //change distance(first) according to node(first), and enqueue all
    for(int i = 0;i < size;++i){
      if(tempH[i].first != d[tempH[i].second])tempH[i].first = d[tempH[i].second];
      H.push(tempH[i]);
    }
    free(tempH);
  }
}



//Traverse the minimam cost road
void traverse(int check)
{
  //declare variables
  stack<int> travnum;
  int cost = d[check];
  
  //traverse loop
  while(prev[check]){
    travnum.push(check);
    check = prev[check];
  }
  travnum.push(check);

  //print root
  while(1){
    cout << travnum.top(); travnum.pop();
    if(travnum.size() == 0)break;
    cout << "--";
  }

  //print cost
  cout << "(cost:" << cost << ")" << endl;
}



//main function
int main(int argc, char *argv[])
{
  /* 
     argv[1] : file name
   */

  //variables declaration
  FILE *fp;            //file pointer
  int from,to,weight;  //variables to make adjacency matrix
  int startnode;       //node of starting Dijkstra
  int lastnode;        //most distant node from starting node

  //initialize variables
  for(int i = 0;i < MAX_ARRAY;++i){
    d[i] = INFINITE;
    for(int j = 0;j < MAX_ARRAY;++j)admat[i][j] = INFINITE;
  }
  

  //open the input file
  if(argc < 2){fprintf(stderr,"Input file missing.\n"); return -1;}
  fp = fopen(argv[1],"r");
  if(fp == NULL){
    fprintf(stderr,"File open failed.");
    return -1;
  }
  
  //loop to read lines
  while(fscanf(fp,"%d,%d,%d\n",&from,&to,&weight) != EOF)
  {
    //input data
    admat[from][to] = admat[to][from] = weight;   //because of undirected graph
    exist[from] = exist[to] = true;
  }
  
  //set starting node
  cout << "First node:";
  cin >> startnode;
  
  //Djkstra loop
  Dijkstra(startnode);

  //set last node
  cout << "Last node:";
  cin >> lastnode;

  //traverse print
  traverse(lastnode);

  //normal return
  return 0;
}
