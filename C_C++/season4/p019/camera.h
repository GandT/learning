#ifndef CAMERA_H__
#define CAMERA_H__

#include <opencv2/opencv.hpp>

using namespace cv;

//カメラ映像保持クラス
class CameraClass{
    Mat frame;
    VideoCapture cap;

 public:
    //開始・終了時処理
    CameraClass();

    //毎フレームキャプチャ処理
    inline Mat getframe(){
      return frame.clone();
    }
    inline void capture(){
      cap >> frame;
    }
};

extern CameraClass camera;


#endif
