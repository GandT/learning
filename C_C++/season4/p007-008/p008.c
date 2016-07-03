/*
  2016.07.04
  popen関数挙動テスト
*/

#include <stdio.h>


int main()
{
  printf("mode:r\n");
  FILE *p = popen("ls","r");
  pclose(p);
  
  printf("mode:w\n");
  p = popen("ls","w");
  pclose(p);

  return 0;
}


//lsなどでもOKな模様
