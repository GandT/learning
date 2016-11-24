/*
  2016.10.24
  OpenCV - 各種フィルタ関数演習
  【参考文献】
  OpenCV(発行年不明)「画像フィルタリング」,<http://opencv.jp/opencv-2.2/cpp/imgproc_image_filtering.html>
  OpenCV(発行年不明)「Image Filtering」,<http://docs.opencv.org/2.4.8/modules/imgproc/doc/filtering.html>
  大山昇太(2012)「画像を平滑化する（ぼかす）GaussianBlur」,<http://blog.goo.ne.jp/nobotta50/e/7b689425708a192ac82e46e494a207ac>
  大山昇太(2012)「微分画像・エッジ画像を求める(Sobel)」,<http://blog.goo.ne.jp/nobotta50/e/087c9ffc4d23e416f8d271efd4526d9a>
 */


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <opencv2/opencv.hpp>

//namespace宣言
using namespace std;
using namespace cv;


//変換法則のdefine
#define COLOR_TO_GRAY          0
#define COLOR_TO_GRAY_MANUAL   1
#define GAUSSIAN               2
#define GAUSSIAN_MANUAL        3
#define SOBEL                  4
#define SOBEL_MANUAL           5

//画像変換関数
void imgconvert(Mat &input, Mat &output,int style = COLOR_TO_GRAY)    //引数はポインタではなく参照渡しを用いる
{
  //灰色変換（自動）
  if(style == COLOR_TO_GRAY){
    //オブジェクト生成
    Mat ycrcbimg;          //YCrCbデータ一時保存用
    vector<Mat> splitdata; //分割データ一時保存用

    //RGBからYCrCbへ変換
    cvtColor(input, ycrcbimg, CV_BGR2YCrCb);

    //成分分解
    split(ycrcbimg, splitdata);

    //出力結果に輝度成分を代入
    output = splitdata[0];

  }

  //灰色変換（手動）
  else if(style == COLOR_TO_GRAY_MANUAL){
    //変数宣言 / オブジェクト生成
    Size s = input.size();
    output.create(s, CV_8UC1);

    //画像アクセス（y座標）ループ
    for(int y = 0; y < s.height; ++y){
      //アクセス用ポインタ設定
      uchar *ptr1 = input.ptr<uchar>(y);
      uchar *ptr2 = output.ptr<uchar>(y);

      //画像アクセス（x座標）ループ
      for(int x = 0; x < s.width; ++x){
	//輝度を計算
	double Y = 0.114 * (double)ptr1[0] + 0.587 * (double)ptr1[1] + 0.299 * (double)ptr1[2];

	//超過分を切り落とす
	if(Y > 255)Y = 255;
	if(Y <   0)Y =   0;

	//輝度情報を代入
	*ptr2 = (uchar)Y;

	//ポインタを進める
	ptr1 += 3;
	ptr2 += 1;
      }
    }
  }

  //平滑化＝ぼかし（自動）
  else if(style == GAUSSIAN){
    //オブジェクト生成
    Size s = input.size();
    output.create(s, CV_8UC3);

    //ガウスぼかし
    Size gs(9,9);
    GaussianBlur(input, output, gs, 5, 5);
  }


  //エッジ抽出（自動）
  else if(style == SOBEL){
    //エッジ抽出
    Sobel(input, output, input.depth(), 1, 1);
  }
}


//メイン関数
int main(int argc, char *argv[])
{
  //ファイル名
  string imgname, outname;

  //OpenCV画像データオブジェクト
  Mat input, output;
  
  //画像読み込み
  if(argc >= 2)imgname = argv[1];
  else         imgname = "fruits.jpg";

  //画像を読み込む
  input = imread(imgname, 1);    //memo：第一引数はchar配列ではなくstring型
  if(input.empty()){
    cerr << "error:" << imgname << "が開けませんでした。" << endl;
    return -1;
  }

  //画像をグレースケールに変更
  int mode = (argc >= 4) ? atoi(argv[3]) : COLOR_TO_GRAY;
  imgconvert(input, output, mode);

  //表示用ウィンドウ生成
  namedWindow("入力画像", CV_WINDOW_AUTOSIZE);  //ウィンドウサイズの自動調整
  namedWindow("出力画像", CV_WINDOW_AUTOSIZE);  //（画像のオリジナルサイズ表示）

  //画像表示
  imshow("入力画像", input);
  imshow("出力画像", output);

  //キー入力待ち
  waitKey(5000);   //キーが押されるまでor5秒待つ

  //画像を保存
  if(argc >= 3)outname = argv[2];
  else         outname = "output.jpg";
  imwrite(outname, output);

  //正常終了
  return 0;
}
