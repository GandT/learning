/*
  2016.10.25
  OpenCV - マウス・コールバック処理演習

  【参考文献】
  福田 誠一郎, 勝元 甫(2016)「「OpenCV/OpenGLによる映像処理」　講義web 」,<http://www.nae-lab.org/b3exp/codes.html>
  ロベール(2000)「第２８章　静かなるメンバ」,<http://www7b.biglobe.ne.jp/~robe/cpphtml/html02/cpp02028.html>
  OpenCV(発行年不明)「その他の画像変換」,<http://opencv.jp/opencv-2svn/cpp/miscellaneous_image_transformations.html>
  OpenCV(発行年不明)「配列操作」,<http://opencv.jp/opencv-2.1/cpp/operations_on_arrays.html>
  OpenCV(発行年不明)「基本構造体」,<http://opencv.jp/opencv-2.1/cpp/basic_structures.html>
  OpenCV(発行年不明)「Operations on Arrays」,<http://docs.opencv.org/2.4.8/modules/core/doc/operations_on_arrays.html>
  
 */


#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <opencv2/opencv.hpp>

//namespace宣言
using namespace std;
using namespace cv;

//各種define
#define IMG_WIN_NAME "image"
#define INPAINT_MODE  0
#define REVERSE_MODE  1


struct imgdata{
  //画像変数
  static Mat orig;
  static Mat buff;
  static Mat mask;
  static Mat drawn;

  //座標変数
  static Point prevpt;

  //フラグ変数
  static int mode;

  //画像作成
  static bool init(string filename){
    //画像読み込み
    orig = imread(filename);
    if(orig.empty()){
      cerr << "エラー：" << filename << "が見つかりませんでした。";
      return false;
    }

    //ほか実体作成
    buff = orig.clone();
    drawn = orig.clone();
    mask.create(orig.size(), CV_8UC1);

    //初期化
    mask  = Scalar(0);
    drawn = Scalar(0);
    mode = INPAINT_MODE;

    return true;
  }

  //マウス入力処理
  static void mouse(int event, int x, int y, int flags, void *){
    //操作対象画像存在確認
    if(buff.empty())return;

    //ペイントモード
    if(mode == INPAINT_MODE){
      //右クリック開始時
      if(event == CV_EVENT_LBUTTONDOWN){
	//開始座標の設定
	prevpt = Point(x,y);
      }

      //右クリック継続時
      else if(flags & CV_EVENT_FLAG_LBUTTON){
	//現在座標の取得
	Point pt(x, y);

	//開始点から現在点までマスクに直線を引く
	line(mask, prevpt, pt, Scalar(255), 5, 8, 0);
	line(buff, prevpt, pt, Scalar::all(255), 5, 8, 0);

	//座標更新
	prevpt = pt;

	//描画
	imshow(IMG_WIN_NAME, buff);
      }
    }

    //反転モード
    else if(mode == REVERSE_MODE){
       //右クリック開始時
      if(event == CV_EVENT_LBUTTONDOWN){
	//開始座標の設定
	prevpt = Point(x,y);
      }

      //右クリック終了時
      else if(event == CV_EVENT_LBUTTONUP){
	//終了座標の設定
	Point pt(x,y);

	//座標大小調整
	int startx = pt.x<prevpt.x ? pt.x : prevpt.x;
	int starty = pt.y<prevpt.y ? pt.y : prevpt.y;
	int difx = abs(pt.x - prevpt.x);
	int dify = abs(pt.y - prevpt.y);

	//反転領域策定
	Rect revrect(startx, starty, difx, dify);
     	mask = Scalar(0);
	Mat rev = mask(revrect);
	rev = Scalar(255);

	//反転処理
	buff.copyTo(drawn);
	bitwise_not(buff, drawn, mask);

	//描画
	imshow("inpainted image", drawn);

	//画像を保存
	imwrite("output.jpg", drawn);
      }
    }
  }

  //画像リセット
  static void reset()
  {
    //初期化
    mask = Scalar(0);
    orig.copyTo(buff);

    //描画
    imshow(IMG_WIN_NAME, buff);
  }

  //インペイント
  static void inpainting()
  {
    //ウィンドウ用意
    namedWindow("inpainted image", 1);
    
    //インペイント処理
    inpaint(buff, mask, drawn, 3.0, cv::INPAINT_TELEA);

    //描画
    imshow("inpainted image", drawn);
  }

  //反転処理
  static void reversedraw()
  {
  }

};

Mat imgdata::orig;
Mat imgdata::buff;
Mat imgdata::mask;
Mat imgdata::drawn;
Point imgdata::prevpt;
int imgdata::mode;


int main(int argc, char *argv[])
{
  //ファイルから画像を読み込む
  string filename = (argc > 1) ? argv[1] : "fruits.jpg";

  //画像実体の作成
  if(!imgdata::init(filename))return 0;

  //操作説明
  cout << "【キー操作一覧（半角）】" << endl;
  cout << "\t ESC/q - プログラムを終了" << endl;
  cout << "\t i - インペイント(推測復元)処理" << endl;
  cout << "\t r - 編集をリセット" << endl;
  cout << "\t 0~1 - モード変更" << endl;

  //ウィンドウ準備
  namedWindow(IMG_WIN_NAME, 1);

  //ウィンドウに画像表示
  imshow(IMG_WIN_NAME, imgdata::buff);

  //コールバック関数を登録（登録後は自動で呼び出される）
  setMouseCallback(IMG_WIN_NAME, imgdata::mouse, 0);

  //メインループ
  bool loopfl = true;
  while(loopfl){
    //このあたりでコールバック関数が呼ばれた時は自動処理

    //キーボード入力の受付
    int keyinput = waitKey(0);

    //キーボード入力で処理分岐
    switch(keyinput){
    //終了
    case 27:
    case 'q':
      loopfl = false;
      break;

    //編集リセット
    case 'r':
      imgdata::reset();
      break;

    //インペイント処理
    case 'i':
      imgdata::inpainting();
      break;

    //モード変更
    case '0': imgdata::mode = INPAINT_MODE; break;
    case '1': imgdata::mode = REVERSE_MODE; break;
    }
  }
}
