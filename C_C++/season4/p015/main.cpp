// -*- tab-width : 4 ; mode : C++ -*-

/*
  最終課題　[ライブラリ]「OpenCV/GLによるARゲーム制作支援改変型ライブラリ」

  【参考文献】
  福田 誠一郎, 勝元 甫(2016)「「OpenCV/OpenGLによる映像処理」　講義web 」,<http://www.nae-lab.org/b3exp/codes.html>
  satojkovic(2014)「OpenCVで画像を読み込んでOpenGLで描画する」,<http://stmind.hatenablog.com/entry/2014/03/14/024333>　2016.11.1閲覧
  工学ナビの中の人(2015)「OpenGLで描画された画面をOpenCVのcv::Mat形式の画像として取得する」,<http://d.hatena.ne.jp/kougaku-navi/20151212/p1>　2016.11.1閲覧
  寺西忠勝(発行年不明)「GLUT API リファレンス」,<http://www.asahi-net.or.jp/~yw3t-trns/opengl/glut/glut.htm#shapes>　2016.11.7閲覧
  KURINO Takashi(2015)「OpenCVで画像上に別の画像を描画する」,<http://qiita.com/kinojp/items/d2d9a68a962b34b62888>　2016.11.14閲覧
 */

//必要ライブラリ
#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <GL/glut.h>

//必要処理
#include "init.h"
#include "camera.h"
#include "callback.h"

//必要namespace
using namespace std;
using namespace cv;



//main関数
int main(int argc, char *argv[])
{
    //初期化処理
    InitGL(argc, argv);
	Initialization();
     
	//コールバック関数登録
	SetCallbackFunctions();

	//OpenGLのメインループに突入
	glutMainLoop();  
}
