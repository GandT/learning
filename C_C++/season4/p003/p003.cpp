/*
  Dijkstra algorythm
 */


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>


using namespace std;


#define MAX_ARRAY   128
#define INFINITE    2147483648

//structure definition
struct node{
  int node;
  int num;
};


//global arrays declaration
int distance[MAX_ARRAY];            //distance from s to [s]==u
int prev[MAX_ARRAY];                //previous node from v
int admat[MAX_ARRAY][MAX_ARRAY];    //adjacency matrix of the graph

//global class declaration
priority_queue<int, vector<int>, greater<int> > H;            //confirmed node


//calculate distance by dijkstra algorytm
void Dijkstra(int strtnd)
{
  //setting start node
  d[strtnd] = 0;
  //H.push(strtndの構造体);

  //
}



//traverse the minimam cost road
void traverse()
{

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
  int startnode;       //node of starting dijkstra

  //initialize variables
  for(int i = 0;i < MAX_ARRAY;++i){
    distance[i] = INFINITE;
    prev[i] = INFINITE;
    for(int j = 0;j < MAX_ARRAY;++j)admat[i][j] = INFINITE;
  }
  H = Hstart = makelist(,NULL);
  

  //open the input file
  if(argc < 2){fprintf(stderr,"Input file missing.\n"); retnrun -1;}
  fp = fopen(argv[1],"r");
  if(fp == NULL){
    fprintf(stderr,"File open failed.");
    exit(EXIT_FAILER);
  }
  
  //loop to read lines
  while(fscanf(fp,"%d,%d,%d\n",&from,&to,&weight) != EOF)
  {
    //input data
    admat[from][to] = admat[to][from] = weight;   //because of undirected graph
  }
  
  //set starting node
  cout << "First node:" << endl;
  cin >> startnode;
  
  //Djkstra loop
  Djkstra(startnode);
}
