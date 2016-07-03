/*
  UNIXシステム・コール挙動確認プログラム
*/


//C library
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

//UNIX library
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>

int main()
{
  //variable declaration
  int rb, wb;  //read byte / write byte
  char str[16];   //string

  //initialize
  rb = wb = 0;

  //read and write loop
  while(1){
    rb =  read(0, str, 16);
    if(rb)wb = write(1, str, 16);
    printf("read:%d  write:%d\n",rb,wb);
  }
}
