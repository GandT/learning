#include "init.h"
#include "system.h"

//必要ライブラリ
#include <opencv2/opencv.hpp>
#include <GL/glut.h>

//OpenGLの初期化処理
void InitGL(int argc, char *argv[])
{
    //OpenGL初期化処理
    glutInit(&argc,argv);
    
    //ディスプレイ設定
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

    //ウィンドウ作成
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow(WINDOW_NAME);
}


//プログラム固有の初期化処理
void Initialization()
{
    //背景色の設定
    glClearColor(0, 0, 0, 0);
}


