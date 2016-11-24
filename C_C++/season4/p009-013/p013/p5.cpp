/*
  2016.10.31
  OpenCV - 領域加工演習

  【参考文献】
  福田 誠一郎, 勝元 甫(2016)「「OpenCV/OpenGLによる映像処理」　講義web 」,<http://www.nae-lab.org/b3exp/codes.html>
  OpenCV(発行年不明)「User Interface」,<http://docs.opencv.org/2.4.8/modules/highgui/doc/user_interface.html>
  OpenCV(発行年不明)「Cascade Classification」,<http://docs.opencv.org/2.4.8/modules/objdetect/doc/cascade_classification.html>
  OpenCV(発行年不明)「Drawing Functions」,<http://docs.opencv.org/2.4.8/modules/core/doc/drawing_functions.html>
  OpenCV(発行年不明)「Inpainting」,<http://docs.opencv.org/2.4.8/modules/photo/doc/inpainting.html>
  Nobuhide Tsuda(2014)「C++11 範囲ベース for ループ」,<http://vivi.dyndns.org/tech/cpp/range-for.html>
  NATIONAL INSTRUMENTS(2010)「関心領域（ROI)　よく聞かれる質問（FAQ)」,<http://digital.ni.com/public.nsf/allkb/2A6F2F6890BAA28386257669001D5F21>
  notani(2009)「縮小アルゴリズムの比較」,<http://d.hatena.ne.jp/tnn-jp/20090325/1237975581>
  著者不明(2016)「処理系 - cpprefjp C++日本語リファレンス」,<http://cpprefjp.github.io/implementation.html>
 */

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

//namespace宣言
using namespace std;
using namespace cv;

//各種define
#define RESULT_WIN_NAME   "result"
#define MOSAIC_MODE     0
#define INPAINT_MODE    1

//モザイク設定
double scale = 4.0;
int mosize = 20;    //モザイクサイズ



//モザイク処理
void rectmosaic(Mat& frame, vector<Rect>& faces)
{
    //顔数ループ
    for(Rect &fs: faces){
      //変数定義
      Point c; //中央点
      int r;   //半径
      
      //領域情報計算
      c.x = saturate_cast<int>( (fs.x+fs.width  * 0.5) * scale );
      c.y = saturate_cast<int>( (fs.y+fs.height * 0.5) * scale );
      r   = saturate_cast<int>( (fs.width+fs.height) * 0.25 * scale );

      //データ整理 / オブジェクト宣言
      if(mosize < 1)mosize = 1;
      Rect roi(c.x-r, c.y-r, r*2, r*2);    //region of interest　　Rectにより領域そのものを書き換える
      Mat mosaic = frame(roi);
      Mat temp;
      
      //モザイク処理（縮小→拡大）
      resize(mosaic, temp, Size(r/mosize,r/mosize), 0, 0);
      resize(temp, mosaic, Size(r*2,r*2)          , 0, 0, CV_INTER_NN);  //ニアレストネイバー法による補完
    }
}



//インペイント処理
void rectinpaint(Mat& frame, vector<Rect>& faces)
{
  //マスク作成
  Mat mask(frame.rows, frame.cols, CV_8UC1);
  mask = Scalar(0);
  
  //顔数ループ
  for(Rect &fs: faces){
    //マスク領域に顔部分の四角形を描画
    rectangle(mask, Point(fs.x*scale,fs.y*scale), 
	      Point( (fs.x+fs.width) * scale, (fs.y+fs.height) * scale ),
	      Scalar(255), CV_FILLED);
    
    //インペイント処理
    inpaint(frame, mask, frame, 2, INPAINT_TELEA);
  }
}



//メイン関数
int main(int argc, char *argv[])
{
  //顔認識用分類データの読み込み
  CascadeClassifier cascade;
  if(!cascade.load("/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml")){
    cerr << "エラー：カスケードファイルが見つかりませんでした。OpenCVをインストールしてください。" << endl;
  }

  //カメラ準備
  Mat frame;
  VideoCapture cap;
  if(argc > 1) cap.open(argv[1]); //ビデオファイルを開く
  else         cap.open(1);       //外付けカメラにアクセス
  if(!cap.isOpened()){
    cerr << "エラー：カメラまたはビデオ設定が誤っています。" << endl;
    return 0;
  }
  cap >> frame;

  //(report用)出力用ビデオオブジェクトの用意
  VideoWriter outvideo;
  outvideo.open("output.avi", CV_FOURCC('M','J','P','G'), 30, Size(640,480));

  //ウィンドウ準備・設定
  namedWindow(RESULT_WIN_NAME, WINDOW_AUTOSIZE);

  //編集抽出画像の設定
  Mat gray;
  Mat miniimg(saturate_cast<int>(frame.rows / scale), saturate_cast<int>(frame.cols / scale), CV_8UC1);    //saturate_cast<int>≒(int)

  //モード設定
  int mode = MOSAIC_MODE;

  //メインループ
  while(true){
    cap >> frame;
    //灰色化
    cvtColor(frame, gray, CV_BGR2GRAY);

    //縮小（処理高速化のため）
    resize(gray, miniimg, miniimg.size(), 0, 0, INTER_LINEAR);
    //コントラスト調整（正確化のため）
    equalizeHist(miniimg, miniimg);

    //顔データの可変長配列を用意
    vector<Rect> faces;

    //顔認識
    cascade.detectMultiScale(
			     miniimg,              //調査対象（小画像）
			     faces,                //出力vector
			     1.1,                  //ウィンドウの大きさ方向の刻み
			     2,                    //どの程度近接する長方形を同一とみなすか
			     CV_HAAR_SCALE_IMAGE,  //分類
			     Size(30,30)           //最小探索領域
			     );
    
    //加工処理
    switch(mode){
    case MOSAIC_MODE:
      rectmosaic(frame, faces);
      break;
    case INPAINT_MODE:
      rectinpaint(frame, faces);
      break;
    }
    //編集済み画像を表示
    imshow(RESULT_WIN_NAME, frame);

    //(report用)スクリーンショット
    imwrite("output.jpg", frame);
    outvideo << frame;

    //fps維持
    int key = waitKey(10);

    //終了条件
    if(key == 'q' || key == 'Q')break;

    //モード変更
    if(key == 'i' || key == 'I')mode = INPAINT_MODE;
    if(key == 'm' || key == 'M')mode =  MOSAIC_MODE;
  }

  return 0;
}
