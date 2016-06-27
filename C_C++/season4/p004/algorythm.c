/*
  2016.06.17-27
  再瀕文字列抽出プログラム（UNIX系専用）
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>


#define ARRAY_LENGTH   10007  //1万以上の最小の素数

#define BOTH   0    //単語出現情報：両方
#define FIRST  1    //単語出現情報：前半のみ
#define SECOND 2    //単語出現情報：後半のみ

#define OUT_WORD      1   //読み出し情報：単語外
#define IN_WORD       2   //読み出し情報：単語内
#define MAYBE_START   3   //読み出し情報：先頭アポストロフィ等
#define MAYBE_END     4   //読み出し情報：末尾アポストロフィ等
#define DEVIDING      0   //読み出し情報：文章区切り（@文字）


/* 連結リスト構造体宣言 */
struct worddata{
  char word[64];    //単語
  short num;        //出現個数
  short length;     //単語長
  short state;      //状態（0:両方　1：前半　2：後半）
  struct worddata *next;
};


/* グローバル変数宣言 */
char *inaddr;                             //ファイルアドレス
int inlen;                                //入力文字列長
struct worddata *wordhash[ARRAY_LENGTH];  //単語ハッシュ
struct worddata *firstwords[5];           //前半再頻出五単語
struct worddata *secondwords[5];          //後半再頻出五単語



/* 標準入力UNIX式高速ファイルアクセス */
void getinput(void)
{
  //変数宣言
  int fsize, psize, msize;      //ファイルサイズ / ページサイズ / マップサイズ

  //標準入力に対するUNIX式高速ファイルアクセスアドレスの取得
  fsize = lseek(0, 0, SEEK_END);
  psize = getpagesize();
  msize = (fsize + (psize-1)) / psize * psize;
  inaddr = mmap(0, msize, PROT_READ, MAP_PRIVATE, 0, 0);
  inlen = fsize;
}



/* ハッシュ値を計算する */
int calchash(const char *word, short len)
{
  //変数宣言
  int i;                 //ループカウンタ
  unsigned int ans = 0;  //ハッシュ関数値

  //計算ループ
  for(i = 0;i < len;++i){
    //関数計算式 ： {Σ(文字コード×2^頭から数えた文字数)} mod 配列サイズ(＝素数)
    ans = (ans + (word[i]<<i)) % ARRAY_LENGTH;
  }  

  //計算結果を返す
  return ans;
}



/* 単語を登録する */
void registerword(int start, int len, int area)
{
  //変数宣言
  int i;                //ループカウンタ
  struct worddata *p;   //現在参照している単語構造体アドレス
  char rword[64];       //読み出した単語  read word

  //読み出した単語を取得
  strncpy(rword,&inaddr[start],len);    //単語の読み出し
  rword[len] = '\0';                    //終端文字の付与

  //大文字を小文字に変換
  for(i = 0;i < len;++i)if('A'<=rword[i]&&rword[i]<='Z')rword[i] -= ('A'-'a');

  //ハッシュ値計算
  int hash = calchash(rword, len);

  //非ハッシュ衝突時新単語登録
  if(wordhash[hash] == NULL){
    p = wordhash[hash] = (struct worddata *)malloc(sizeof(struct worddata));
    strncpy(p->word,rword,len+1);    //単語の読み出し
    p->num = 1;
    p->length = len;
    p->state = area;
    p->next = NULL;

    //登録したため終了
    return;
  }

  //単語登録ループ
  p = wordhash[hash];
  while(1){
    //一致判定
    if(p->length == len && strcmp(p->word,rword) == 0){  //一致の場合
      //発見位置判定
      if(area != p->state){
	p->state = BOTH;
	break;            //以後処理不要のためループから抜けて終了
      }
      //個数加算
      ++p->num;
      //ループから抜ける
      break;
    }else{ //不一致の場合
      //次が存在すれば確認位置を進める
      if(p->next != NULL)p = p->next;
      //次が存在しない場合は新単語登録
      else{
	p->next = (struct worddata *)malloc(sizeof(struct worddata));
	strncpy(p->next->word,rword,len+1);
	p->next->num = 1;
	p->next->length = len;
	p->next->state = area;
	p->next->next = NULL;
	
	//終了
	break;
      }
    }
  }
}



/* 単語を数える */
void countwords(void)
{
  /*
    方針
    ・チェイン法＝ハッシュ＋連結リスト構造体（文字列・出現個数・次リストアドレス・状態フラグ(前半/後半/重複)）
    ・前半部分：長さ1万の連結リスト型のハッシュ配列に入れる（前後半共通）
    　　　　　　ハッシュ値を計算し連結リストをたどる…文字列比較を行い一致すれば数値加算/一致がなければ新しい連結リスト生成
    ・後半部分：同様にハッシュ配列格納。ただし前半と重なる語に当たった場合は状態フラグを書き換える
    ・最後に前半フラグのものから5つ、後半フラグのものから5つ出現頻度の多い順に持ってくる（showanswer関数）
   */

  //変数宣言
  int i;                    //ループカウンタ
  int readstate = OUT_WORD; //読み出しの状態変数
  int wstart = 0, wlen = 0; //単語開始位置 / （現在読み出し分の）単語長
  int symlen = 0;           //記号長（'や-などの長さ） symbol length
  int rarea = FIRST;        //読出中区域  reading area

  //文字列長だけループを回す
  for(i = 0;i < inlen;++i){
    //状態変化により行う処理を変える
    switch(readstate){  
    //単語外
    case OUT_WORD:
      //アルファベットまたは数字
      if( ('0'<=inaddr[i]&&inaddr[i]<='9') || ('A'<=inaddr[i]&&inaddr[i]<='Z') || ('a'<=inaddr[i]&&inaddr[i]<='z') ){
	//単語開始位置を設定
	wstart = i;
	//単語長を初期化
	wlen = 1;
	//状態遷移
	readstate = IN_WORD;
      }

      //ハイフンまたはアポストロフィ
      else if(inaddr[i]=='\'' || inaddr[i]=='-'){
	//状態遷移
	readstate = MAYBE_START;
      }

      //区切り文字
      else if(inaddr[i]=='@'){
	//状態遷移
	readstate = DEVIDING;
      }

      //終了
      break;    
    
    //単語内
    case IN_WORD:
      //アルファベットまたは数字
      if( ('0'<=inaddr[i]&&inaddr[i]<='9') || ('A'<=inaddr[i]&&inaddr[i]<='Z') || ('a'<=inaddr[i]&&inaddr[i]<='z') ){
	//単語長を加算
	++wlen;
      }

      //ハイフンまたはアポストロフィ
      else if(inaddr[i]=='\'' || inaddr[i]=='-'){
	//記号長を初期化
	symlen = 1;
	//状態遷移
	readstate = MAYBE_END;
      }

      //区切り文字
      else if(inaddr[i]=='@'){
	//単語登録
	registerword(wstart, wlen, rarea);
	//状態遷移
	readstate = DEVIDING;
      }

      //それ以外（空白など）
      else{
	//単語登録
	registerword(wstart, wlen, rarea);
	//状態遷移
	readstate = OUT_WORD;
      }

      //終了
      break;
    

    case MAYBE_START:   //単語先頭アポストロフィ等の可能性あり
      if( ('0'<=inaddr[i]&&inaddr[i]<='9') || ('A'<=inaddr[i]&&inaddr[i]<='Z') || ('a'<=inaddr[i]&&inaddr[i]<='z') ){
	wstart = i;
	wlen = 1;
	readstate = IN_WORD;
      }
      else if(inaddr[i]=='\'' || inaddr[i]=='-'){
	//何も行わない
      }
      else if(inaddr[i]=='@'){ readstate = DEVIDING; }
      else { readstate = OUT_WORD; }
      break;
    

    case MAYBE_END:     //単語末尾アポストロフィ等の可能性あり
      if( ('0'<=inaddr[i]&&inaddr[i]<='9') || ('A'<=inaddr[i]&&inaddr[i]<='Z') || ('a'<=inaddr[i]&&inaddr[i]<='z') ){
	//単語長に記号長+1（今読んだ文字）を加算
	wlen += (symlen+1);
	//状態遷移
	readstate = IN_WORD;
      }
      else if(inaddr[i]=='\'' || inaddr[i]=='-'){
	//記号長を加算
	++symlen;
      }
      else if(inaddr[i]=='@') { readstate = DEVIDING; }
      else { registerword(wstart, wlen, rarea); readstate = OUT_WORD; }
      break;
    

    case DEVIDING:      //前後半区切り文字@
      //読み出し位置変化
      rarea = SECOND;

      //状態遷移
      if( ('0'<=inaddr[i]&&inaddr[i]<='9') || ('A'<=inaddr[i]&&inaddr[i]<='Z') || ('a'<=inaddr[i]&&inaddr[i]<='z') ){
	wstart = i;
	wlen = 1;
	readstate = IN_WORD;
      }
      else if(inaddr[i]=='\'' || inaddr[i]=='-') { readstate = MAYBE_START; }
      else { readstate = OUT_WORD; }
      break;
    

    }
  }
}


/* 最大値更新（関数呼び出し遅延対策のため更新されると決定した場合のみ呼び出す） */
void insert(struct worddata *ins)
{
  //変数宣言
  int i;                   //変数宣言
  struct worddata *temp;   //交換用一時保存変数

  //挿入先決定
  if(ins->state == FIRST){
    //更新
    firstwords[4] = ins;
    //引き上げ
    for(i = 4;i > 0;--i){
      if(firstwords[i]->num > firstwords[i-1]->num){
	temp = firstwords[i-1];
	firstwords[i-1] = firstwords[i];
	firstwords[i] = temp;
      }
    }
  }else if(ins->state == SECOND){
    //更新
    secondwords[4] = ins;
    //引き上げ
    for(i = 4;i > 0;--i){
      if(secondwords[i]->num > secondwords[i-1]->num){
	temp = secondwords[i-1];
	secondwords[i-1] = secondwords[i];
	secondwords[i] = temp;
      }
    }
  }
}



/* 正解を表示する */
void showanswer(void)
{
  //変数宣言
  int i;                //ループカウンタ
  struct worddata *p;   //連結リスト探索位置

  //探索ループ
  for(i = 0;i < ARRAY_LENGTH;++i){
    //ハッシュの中身がなければ次に進む
    if(wordhash[i] == NULL)continue;
    
    //ハッシュをたどる
    p = wordhash[i];
    while(p != NULL){
      //前後半かで分岐（両方出現は無視）
      if(p->state == FIRST){
	//前半第五位より出現頻度が高ければ交換
	if(p->num > firstwords[4]->num)insert(p);
      }else if(p->state == SECOND){
	//後半第五位より出現頻度が高ければ交換
	if(p->num > secondwords[4]->num)insert(p);
      }
      //ポインタを進める
      p = p->next;
    }
  }

  //5単語を表示
  //printf("前半に出現する単語：\n");
  for(i = 0;i < 5;++i){printf("%s\n", firstwords[i]->word);  /*printf("　　出現回数：%d回\n", firstwords[i]->num);*/}
  //printf("後半に出現する単語：\n");
  for(i = 0;i < 5;++i){printf("%s\n",secondwords[i]->word);  /*printf("　　出現回数：%d回\n",secondwords[i]->num);*/}
}



/* 実行関数 */
int main(void)
{
  //変数宣言
  int i;
  
  //配列初期化
  for(i = 0;i < ARRAY_LENGTH;++i)wordhash[i] = NULL;
  for(i = 0;i < 5;++i){
     firstwords[i] = (struct worddata *)malloc(sizeof(struct worddata));
    secondwords[i] = (struct worddata *)malloc(sizeof(struct worddata));
    firstwords[i]->num = secondwords[i]->num = 0;  //大小比較にしか使わないためnumのみ決定すれば残りは不要
  }

  //標準入力受け取り
  getinput();

  //単語数カウント
  countwords();

  //正解表示
  showanswer();

  //正常終了
  return 0;
}
