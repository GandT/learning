/*
  2016.10.18
  「プロセススケジューリング」
  【参考文献】
  田浦健次朗(2016)「スレッド・プロセスプログラミング」,<http://www.eidos.ic.i.u-tokyo.ac.jp/~tau/lecture/operating_systems/gen/ex/threads_processes/index.html>
  大前良介(2015)「時間情報の取得 gettimeofday()」,<http://www.mm2d.net/main/prog/c/time-04.html>
  LRESULT(2008)「C言語 浮動小数点 「float」型 と 「double」型の最大値と最小値」,<http://simd.jugem.jp/?eid=31>
  Nobuhide Tsuda(2014)「C++ 動的配列クラス std::vector 入門」,<http://vivi.dyndns.org/tech/cpp/vector.html>
*/

//通常include
#include <iostream>
#include <vector>
#include <cfloat>

//Linux用include
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>


using namespace std;


#if 0
  //時間構造体
  struct　timeval　{
    long　tv_sec;
    long　tv_usec;
  };
#endif


//現在時刻をdouble型で返す
double getnowtime() {
  //現在時刻情報を受け取る
  struct timeval tp[1];
  gettimeofday(tp, NULL);   //第二引数は必ずNULL

  //double型で現在時刻を返す
  return tp->tv_sec + tp->tv_usec * 0.000001;
}


//進行情報管理用構造体
struct rundata{
  double start;
  double end;
};

int main() {
  //情報管理用動的配列
  vector<struct rundata> runm;       //runing management
  int vrunnum = 0;            //要素数

  //プロセスIDを受け取る
  int pid = getpid();

  //起動時時刻を受け取る
  double origt = getnowtime();
  double t = origt;
  double t2;
  double start = t;

  //5秒ループ
  while (origt + 5 > t) {
    t2 = getnowtime();
    
    //5マイクロ秒以上の空きがあればプロセスが停止していたと判断
    if(t2 - t > 0.00005){
      //動的配列に追加
      struct rundata temp = {start,t};
      runm.push_back(temp);
      ++vrunnum;

      //再度開始時刻を設定
      start = t2;
    }
    //時間更新
    t = t2;
  }
  
  //割り当て時間の表示
  if(vrunnum > 0){
    for(int i = 0;i < vrunnum;++i)cout << pid << " " << runm[i].start << " " << runm[i].end << endl;
  }
}
