/*
  2016.07.04
  popen関数挙動テスト
*/

#include <stdio.h>


int main()
{
  FILE *p = popen("play play.wav","w");
  pclose(p);

  return 0;
}
