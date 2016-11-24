/*
  2016.10.27
  OpenCV - 背景抽出演習

  【参考文献】
  福田 誠一郎, 勝元 甫(2016)「「OpenCV/OpenGLによる映像処理」　講義web 」,<http://www.nae-lab.org/b3exp/codes.html>
  OpenCV(発行年不明)「User Interface」,<http://docs.opencv.org/2.4.8/modules/highgui/doc/user_interface.html>
 */

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

//namespace宣言
using namespace std;
using namespace cv;

//各種define
#define PREP_TIME   50    //背景抽出用準備時間

#define B_PARAMETER 0.020
#define T_PARAMETER 0.005

#define INPUT_WIN_NAME "Input"
#define    FG_WIN_NAME "FG"
#define  MASK_WIN_NAME "mask"



//メイン関数
int main(int argc, char *argv[])
{
  //変数宣言
  double zeta = 10;

  //オブジェクト生成
  VideoCapture cap;             //入力動画データ
  Mat frame;                    //現フレーム画像
  Mat aveimg, sgmimg;           //平均画像 / ？
  Mat backimg, objimg, nowimg;  //背景画像 / 実体画像 / 現在画像
  Mat dest, mask;

  //キャプチャ用ビデオオブジェクトの用意
  if(argc > 1) cap.open(argv[1]);
  else         cap.open(1);
  if(!cap.isOpened()){
    cerr << "エラー：カメラまたはビデオ設定が誤っています。" << endl;
    return 0;
  }

  //(report用)出力用ビデオオブジェクトの用意
  //VideoWriter outvideo;
  //outvideo.open("1-4-1.avi", CV_FOURCC('M','J','P','G'), 30, Size(640,480));

  //画像表示用ウィンドウの設定
  namedWindow(INPUT_WIN_NAME, WINDOW_AUTOSIZE);
  namedWindow(   FG_WIN_NAME, WINDOW_AUTOSIZE);
  namedWindow( MASK_WIN_NAME, WINDOW_AUTOSIZE);

  //各種オブジェクトの初期化
  cap >> frame;
  Size s = frame.size();
   aveimg.create(s, CV_32FC3);
   sgmimg.create(s, CV_32FC3);
  backimg.create(s, CV_32FC3);
   objimg.create(s, CV_32FC3);
   nowimg.create(s, CV_32FC3);
     dest.create(s, CV_32FC3);
     mask.create(s, CV_32FC3);


  /***背景初期値計算***/
  cout << "背景分析を開始します。" << endl;
  aveimg = Scalar(0, 0, 0);
 
  //輝度累積ループ
  for(int i = 0; i < PREP_TIME; ++i){
    Mat temp;

    //現在フレーム画像取得
    cap >> frame;
    if(frame.empty())break;
    
    //輝度累積計算
    frame.convertTo(temp, aveimg.type());
    accumulate(temp, aveimg);
  }

  //正規化
  aveimg.convertTo(aveimg, -1, 1.0 / PREP_TIME);
  sgmimg = Scalar(0, 0, 0);

  //輝度の平均と振幅を計算
  for(int i = 0; i < PREP_TIME; ++i){
    cap >> frame;
    if(frame.empty())break;

    //平均振幅計算
    frame.convertTo(nowimg, aveimg.type());
    subtract(nowimg, aveimg, nowimg);      //差分計算
    pow(nowimg, 2.0, nowimg);              //差分輝度2乗
    nowimg.convertTo(nowimg, -1, 2.0);
    sqrt(nowimg, nowimg);                  //差分輝度0.5乗
    accumulate(nowimg, sgmimg);            //偏差の累積
  }

  //正規化
  sgmimg.convertTo(sgmimg, -1, 1.0 / PREP_TIME);
  
  cout << "背景分析を終了します。" << endl;


  /***メインループ***/
  while(true){
    //現在フレーム画像取得
    cap >> frame;
    if(frame.empty())break;
    frame.convertTo(nowimg, nowimg.type());

    //背景判定
    subtract( aveimg, sgmimg, backimg);
    subtract(backimg,   zeta, backimg);
         add( aveimg, sgmimg,  objimg);
         add( objimg,   zeta,  objimg);
     inRange( nowimg,backimg,  objimg, mask);

    //背景の更新
    subtract(nowimg, aveimg, nowimg);
    pow(nowimg, 2.0, nowimg);
    nowimg.convertTo(nowimg, -1, 2.0);
    sqrt(nowimg, nowimg);

    //輝度の平均および振幅を更新
    accumulateWeighted( frame, aveimg, B_PARAMETER, mask);
    accumulateWeighted(nowimg, sgmimg, T_PARAMETER, mask);
    bitwise_not(mask, mask);
    accumulateWeighted(nowimg, sgmimg, T_PARAMETER, mask);

    //黒背景マスク画像の生成
    dest = Scalar(0,0,255);
    frame.copyTo(dest, mask);

    //画面の更新
    cv::imshow(INPUT_WIN_NAME, frame);
    cv::imshow(   FG_WIN_NAME,  dest);
    cv::imshow( MASK_WIN_NAME,  mask);

    //(report用)スクリーンショット
    //imwrite("1-4-1.jpg", dest);
    //outvideo << dest;

    //キー入力待ち
    char key = cv::waitKey(10);
    if(key == 27)break;
  }

  return 0;
}
