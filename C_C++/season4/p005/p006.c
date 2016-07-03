/*
  「man -s 2 select」のテストプログラムの挙動確認
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
  fd_set rfds;       //監視対象の読み出しファイル記述子集合 read file descripters
  struct timeval tv; //時間を指定する構造体
  int retval;        //

  //監視対象の設定
  /* stdin (fd 0) を監視し、入力があった場合に表示する。*/
  FD_ZERO(&rfds);    //監視ファイル記述子の初期化
  FD_SET(0, &rfds);  //stdinを監視ファイル記述子に追加

  //監視時間の設定
  /* 5 秒間監視する。*/
  tv.tv_sec = 5;    //秒
  tv.tv_usec = 0;   //マイクロ秒

  retval = select(1, &rfds, NULL, NULL, &tv);   //監視を行い結果を受け取る
  /* この時点での tv の値を信頼してはならない。*/

  if (retval == -1)
    perror("select()");
  else if (retval)
    printf("今、データが取得できました。\n");
  /* FD_ISSET(0, &rfds) が true になる。*/
  else
    printf("5 秒以内にデータが入力されませんでした。\n");

  exit(EXIT_SUCCESS);

}
