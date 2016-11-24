/*
  2016.10.25
  OpenCV - カメラ練習

  【参考文献】
  福田 誠一郎, 勝元 甫(2016)「「OpenCV/OpenGLによる映像処理」　講義web 」,<http://www.nae-lab.org/b3exp/codes.html>
  
 */

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

//namespace宣言
using namespace std;
using namespace cv;

//各種define
#define  INPUT_VIDEO_FILE "sample_video_input.avi"
#define OUTPUT_VIDEO_FILE "sample_video_output.avi"

//メイン関数
int main(int argc, char *argv[])
{
  //変数宣言
  Mat frame, cpyframe;   //現フレーム画像
  bool recmode = false;  //モード
  
  //キャプチャ用ビデオオブジェクトの用意
  VideoCapture cap;
  if(argc > 1) cap.open(argv[1]);
  else         cap.open(1);

  //録画用ビデオオブジェクトの用意
  namedWindow("video", 1);
  VideoWriter outvideo;  
  string ofilename = argc>2 ? argv[2] : OUTPUT_VIDEO_FILE;
  outvideo.open(ofilename, CV_FOURCC('M','J','P','G'), 30, Size(640,480));
  
  //オブジェクト生成成功判定
  if(!cap.isOpened() || !outvideo.isOpened()){
    cerr << "エラー：入力ビデオデータが存在しません。";
    return 0;
  }

  //メインループ
  bool loopfl = true;
  while(loopfl){
    //動画から現在フレームをキャプチャ
    cap >> frame;
    if(frame.empty())break;

    //録画モード時処理
    if(recmode){
      //現在フレームを保存
      outvideo << frame;
      
      //再生マークをつけて画面に表示
      frame.copyTo(cpyframe);
      rectangle(cpyframe, Point(0,0), Point(frame.size().width-1, frame.size().height-1), Scalar(0,0,255), 4, 8, 0);
      
      //画面に表示
      imshow("video", cpyframe);
    }

    //非録画モード時処理
    else{
      //画面に表示
      imshow("video", frame);
    }

    //キー入力待ち
    int inputkey = waitKey(33);  //1フレームのwaitを入れる
    
    //入力キー分岐
    switch(inputkey){
    //終了
    case 'q':
    case 'Q':
      loopfl = false;
      break;
    
    //録画⇔停止（本当は前フレームチェックが必要）（処理落ち前提？）
    case 'r':
      recmode = !recmode;
      break;
    }
  }
  
  return 0;
}
