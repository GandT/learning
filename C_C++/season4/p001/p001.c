/*
  Dijkstra algorythm
 */


#include <stdio.h>
#include <stdlib.h>


#define MAX_ARRAY   128
#define INFINITE    2147483648


//variable declaration
int distance[MAX_ARRAY];            //distance from s to [s]==u
int prev[MAX_ARRAY];                //previous node from v
int admat[MAX_ARRAY][MAX_ARRAY];    //adjacency matrix of the graph


//calculate distance by dijkstra algorytm
void Dijkstra(void)
{

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

  //variable declaration
  int i,j;             //loop counter
  FILE *fp;            //file pointer
  int from,to,weight;  //variables to make adjacency matrix

  //initialize variables
  for(i = 0;i < MAX_ARRAY;++i){
    distance[i] = INFINITE;
    prev[i] = INFINITE;
    for(j = 0;j < MAX_ARRAY;++j)admat[i][j] = INFINITE;
  }

  //open the input file
  fp = fopen(argv[1],"r");
  if(fp == NULL){
    fprintf(stderr,"File open failed.");
    exit(EXIT_FAILER);
  }
  
  //read lines loop
  while(fscanf(fp,"%d,%d,%d\n",&from,&to,&weight) != EOF)
  {
    //input data
    admat[from][to] = admat[to][from] = weight;   //because of undirected graph
  }
  

}
