//ファイル
#include "camera.h"

//必要処理
#include <iostream>
#include <opencv2/opencv.hpp>

//namespace宣言
using namespace std;
using namespace cv;


CameraClass::CameraClass()
{
    //２つのカメラにアクセス
    cap.open(1);
    if(!cap.isOpened())cap.open(0);

    //エラー処理
    if(!cap.isOpened()){
	cerr << "エラー：カメラまたはビデオ設定が誤っています。" << endl;
	return;
    }

    //データ取得
    cap >> frame;

#ifdef DEBUG_MODE
    //ウィンドウ準備・設定
    namedWindow(RESULT_WIN_NAME, WINDOW_AUTOSIZE);
#endif
}


CameraClass camera;
