/*****E-macsの練習用*****//*****解けそうな問題があれば後でもう一問解く*****/

#include <stdio.h>

//せっかくなので(?)Cっぽく
int main(void)
{
  int i , ii;
  for(i=1;i<10;++i){
    for(ii=1;ii<10;++ii){
      printf("%dx%d=%d\n",i,ii,ii*i);
    }
  }
  return 0;
}
